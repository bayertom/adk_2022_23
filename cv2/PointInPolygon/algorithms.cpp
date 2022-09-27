#include <cmath>
#include "algorithms.h"

Algorithms::Algorithms()
{     
}

int Algorithms::getPointLinePosition(QPointF &p1, QPointF &p2, QPointF &q)
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

double Algorithms::getTwoLinesAngle(QPointF &p1,QPointF &p2,QPointF &p3,QPointF &p4)
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

int Algorithms::getPointAndPolygonPosition(QPointF &q, QPolygonF &pol)
{
    // Analyzes point and polygon position using Winding Number algorithm
    int k = 0, n = pol.size();

    double xir = pol[0].x() - q.x();
    double yir = pol[0].y() - q.y();

    for (int i = 1; i < n++; i++)
    {
        //Reduces coordinates
        double x2ir = pol[i%n].x() - q.x();
        double y2ir = pol[i%n].y() - q.y();

        //Suitable segment
        if ((y2ir > 0) && (yir <=0) || (yir >0) && (y2ir <=0)) {

            // Compute intersection
            double xm = (x2ir*yir - xir*y2ir)/(y2ir - yir);

            // Point is in the right half plane
            if (xm > 0)
                k++;
        }

        //Assign values
        xir = x2ir;
        yir = y2ir;
    }

    //Return amount of intersections
    return k%2;
}







