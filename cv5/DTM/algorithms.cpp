#include "algorithms.h"
Algorithms::Algorithms()
{

}


int Algorithms::getPointLinePosition(const QPoint3D &q, const QPoint3D &p1, const QPoint3D &p2)
{
    //Analyze point and line position
    double ux = p2.x() - p1.x();
    double uy = p2.y() - p1.y();

    double vx = q.x() - p1.x();
    double vy = q.y() - p1.y();

    // Determinant
    double t = ux*vy - uy*vx;

    // Left half plane
    if (t > 0)
        return 1;

    // Right half plane
    else if (t < 0)
        return 0;

    // On the line
    return -1;
}


double Algorithms::getTwoLinesAngle(const QPoint3D &p1,const QPoint3D &p2,const QPoint3D &p3,const QPoint3D &p4)
{
    //Gets the angle between 2 lines
    double ux = p2.x() - p1.x();
    double uy = p2.y() - p1.y();

    double vx = p4.x() - p3.x();
    double vy = p4.y() - p3.y();

    // Dot product
    double dot = ux*vx+uy*vy;

    // Norms u,v
    double nu = sqrt(ux*ux+uy*uy);
    double vu = sqrt(vx*vx+vy*vy);

    return acos(dot/(nu*vu));
}


int Algorithms::getNearestPoint(const QPoint3D &p, const std::vector<QPoint3D> &points)
{
    //Find nearest point in point cloud
    double dmin = 1.0e16;
    int imin = -1;

    // Browse the point cloud
    for(int i = 0; i<points.size(); i++){

        // Point p is different from points[i]
        if (p != points[i]){

            // Coordinate differences
            double dx = p.x() - points[i].x();
            double dy = p.y() - points[i].y();

            // Distance
            double d = sqrt(dx*dx + dy*dy);

            // Update minimum
            if (d < dmin)
            {
                dmin = d;
                imin = i;
            }
        }
    }
    return imin;
}


int Algorithms::getDelaunayPoint(const QPoint3D &p1, const QPoint3D &p2,const std::vector<QPoint3D> &points)
{
    // Find Delaunay point (maximize angle)
    double ommax = 0;
    int imax = -1;

    // Browse the point cloud
    for(int i = 0; i<points.size(); i++){

        // Point is different from edge (p1, p2)
        if ((p1 != points[i]) && (p2 != points[i])) {

            //Point in the left half plane
            if (getPointLinePosition(points[i], p1, p2) == 1)
            {
                // Compute angle
                double om = getTwoLinesAngle(points[i], p1, points[i], p2);

                // Update maximum
                if (om > ommax)
                {
                    ommax = om;
                    imax = i;
                }
            }
        }
    }

    return imax;
}


std::vector<Edge> Algorithms::createDT(const std::vector<QPoint3D> &points)
{
    // Delaunay triangulation - incremental construction
    std::vector<Edge> dt;
    std::list<Edge> ael;
    //Get initial point
    QPoint3D p1 = points[0];

    // Find nearest point to p1
    int imin = getNearestPoint(p1, points);
    QPoint3D p2 = points[imin];

    // Create Edge and opposite edge
    Edge e(p1,p2);
    Edge eo = e.switchOrientation();

    // Add edges to AEL
    ael.push_back(e);
    ael.push_back(eo);

    // Repeat until ael is empty
    while(!ael.empty())
    {
        // Get last edge
        Edge e1 = ael.back();
        ael.pop_back();

        // Switch orientation
        Edge e1s = e1.switchOrientation();

        // Find optimal Delaunay point
        int idx = getDelaunayPoint(e1s.getP1(), e1s.getP2(),points);

        // Optimal point was found
        if (idx != -1)
        {
            // Get 3rd vertex of triangle
            QPoint3D p3 =points[idx];

            // Create remaining edges of triangle
            Edge e2(e1s.getP2(), p3);
            Edge e3(p3, e1s.getP1());

            // Add to dt
            dt.push_back(e1s);
            dt.push_back(e2);
            dt.push_back(e3);

            // Update AEL
            updateAEL(e2, ael);
            updateAEL(e3, ael);
        }
    }

    return dt;
}


void Algorithms::updateAEL(const Edge &e, std::list<Edge> &ael)
{
    // Update AEL
    Edge es = e.switchOrientation();

    // Find in AEL
    auto res = find(ael.begin(), ael.end(), es);

    // Edge es is NOT in AEL
    if (res == ael.end())
        ael.push_back(e);

    // Edge es is IN AEL
    else
        ael.erase(res);
}


QPoint3D Algorithms::getContourPoint(const QPoint3D &p1, const QPoint3D &p2, double z)
{
    //Calculate intersection of triangle and plane
    double xA = (p2.x()-p1.x())/(p2.getZ()-p1.getZ()) * (z - p1.getZ()) + p1.x();
    double yA = (p2.y()-p1.y())/(p2.getZ()-p1.getZ()) * (z - p1.getZ()) + p1.y();

    return QPoint3D(xA, yA, z);
}

std::vector<Edge> Algorithms::createContourLines(const std::vector<Edge> &dt, double zmin, double zmax, double dz)
{
    //Create  contour lines from DT
    std::vector<Edge> contours;

    //Process each triangle in DT
    for(int i = 0; i < dt.size(); i +=3)
    {
        // Vertices of a triangle
        QPoint3D p1 = dt[i].getP1();
        QPoint3D p2 = dt[i].getP2();
        QPoint3D p3 = dt[i+1].getP2();

        // Intersection of triangle and horizontal planes Z=z
        for(double z = zmin; z <= zmax; z +=dz)
        {
            // Height differences
            double dz1 = z - p1.getZ();
            double dz2 = z - p2.getZ();
            double dz3 = z - p3.getZ();

            // Test of intersected edges
            double dz12 = dz1*dz2;
            double dz23 = dz2*dz3;
            double dz31 = dz3*dz1;

            //Triangle is coplanar
            if ((dz1 == 0) && (dz2 == 0) && (dz3 == 0))
                continue;

            // Edge p1-p2 is colinear
            else if (dz1 == 0 && dz2 == 0)
                contours.push_back(dt[i]);

            // Edge p2-p3 is colinear
            else if (dz2 == 0 && dz3 == 0)
                contours.push_back(dt[i+1]);

            // Edge p3-p1 is colinear
            else if (dz3 == 0 && dz1 == 0)
                contours.push_back(dt[i+2]);

            // Plane intersects edges p1-p2, p2-p3
            else if ((dz12 <= 0) && (dz23 < 0) || (dz12 < 0) && (dz23 <= 0))
            {
                // Compute intersection A and B
                QPoint3D A = getContourPoint(p1, p2, z);
                QPoint3D B = getContourPoint(p2, p3, z);

                // Create edge A-B
                Edge AB(A, B);

                // Add to contour list
                contours.push_back(AB);
            }

            // Plane intersects edges p2-p3, p3-p1
            else if ((dz23 <= 0) && (dz31 < 0) || (dz23 < 0) && (dz31 <= 0))
            {
                // Compute intersection A and B
                QPoint3D A = getContourPoint(p2, p3, z);
                QPoint3D B = getContourPoint(p3, p1, z);

                // Create edge A-B
                Edge AB(A, B);

                // Add to contour list
                contours.push_back(AB);
            }

            // Plane intersects edges p3-p1, p1-p2
            else if ((dz31 <= 0) && (dz12 < 0) || (dz31 < 0) && (dz12 <= 0))
            {
                // Compute intersection A and B
                QPoint3D A = getContourPoint(p3, p1, z);
                QPoint3D B = getContourPoint(p1, p2, z);

                // Create edge A-B
                Edge AB(A, B);

                // Add to contour list
                contours.push_back(AB);
            }
        }
    }

    return contours;

}

double Algorithms::computeSlope(const QPoint3D &p1, const QPoint3D &p2, const QPoint3D &p3)
{
    // Compute slope of triangle
    double ux = p2.x() - p1.x();
    double uy = p2.y() - p1.y();
    double uz = p2.getZ() - p1.getZ();

    double vx = p3.x() - p1.x();
    double vy = p3.y() - p1.y();
    double vz = p3.getZ() - p1.getZ();

    // Compute cross product
    double nx = uy*vz - uz*vy;
    double ny = -ux*vz + uz*vx;
    double nz = ux*vy - uy*vx;

    // Norm of vector
    double n1 = sqrt(nx*nx + ny*ny + nz*nz);

    // Angle phi (slope)
    return acos(nz/n1);
}


std::vector<Triangle> Algorithms::analyzeSlope(const std::vector<Edge> &dt)
{
    // Analyze slope
    std::vector<Triangle> triangles;

    for(int i = 0; i < dt.size(); i += 3)
    {
        // Vertices of a triangle
        QPoint3D p1 = dt[i].getP1();
        QPoint3D p2 = dt[i].getP2();
        QPoint3D p3 = dt[i+1].getP2();

        // Compute slope
        double slope = computeSlope(p1, p2, p3);

        // Create triangle and add it to list
        Triangle t(p1,p2,p3,slope,0);
        triangles.push_back(t);
    }

    return triangles;
}




