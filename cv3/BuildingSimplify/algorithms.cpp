#include "algorithms.h"
#include "sortpointsbyy.h"
#include "sortpointsbyx.h"

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

QPolygonF Algorithms::createCH(QPolygonF &pol)
{
    //Create convex hull using Jarvis algorithm
    QPolygonF ch;

    //Search for pivot
    QPointF q = *std::min_element(pol.begin(), pol.end(), SortPointsByY());

    // Add point to CH
    ch.push_back(q);

    // Search for pivot (x)
    QPointF p = *std::min_element(pol.begin(), pol.end(), SortPointsByX());

    //Create r
    QPointF r(p.x(),q.y());

    // Assign points to r-pjj, q-pj
    QPointF pjj = r;
    QPointF pj = q;

    // Find all points of convex hull
    do {

        // Supplementary variables
        int imax = -1;
        double ommax = 0;

        // Browse all points of polygon
        for(int i = 0; i < pol.size(); i++) {
            //Measure angle
            double om = getTwoLinesAngle(pj, pjj, pj, pol[i]);

            // Update maximum
            if (om > ommax){
                ommax = om;
                imax = i;
            }
        }

        // Point added to CH
        ch.push_back(pol[imax]);

        // Update vertices
        pjj= pj;
        pj = pol[imax];

    } while (pj!=q);

    return ch;
}


QPolygonF Algorithms::rotate(QPolygonF &pol, double sig)
{
    // Rotate polygon by angle
    QPolygonF polr;

    //Process all vertices
    for(int i =0; i < pol.size(); i++)
    {
        // Rotate coordinates
        double xr = cos(sig)* pol[i].x()-sin(sig)*pol[i].y();
        double yr = sin(sig)* pol[i].x()+cos(sig)*pol[i].y();

        //Create point
        QPointF pr(xr, yr);

        //Add points to polygon
        polr.push_back(pr);
    }
    /*
    for(QPointF p: pol)
    {
        // Rotate coordinates
        double xr = cos(-sig)* p.x()-sin(-sig)*p.y();
        double yr = sin(-sig)* p.x()+cos(-sig)*p.y();

        //Create point
        QPointF pr(xr, yr);

        //Add points to polygon
        polr.push_back(pr);
    }
    */

    return polr;
}

double Algorithms::getArea(QPolygonF &pol)
{
    //compute polygon area using LH method
    int n = pol.size();
    double area = 0;

    //Process all points
    for (int i = 0; i<pol.size();i++)
    {
        area += pol[i].x() * (pol[(i+1)%n].y()-pol[(i-1+n)%n].y());
    }

    return 0.5 * fabs(area);
}


std::tuple<QPolygonF, double> Algorithms::minMaxBox(QPolygonF &pol)
{
    // Create min-max box and compute ist area
    QPointF px_min = *std::min_element(pol.begin(), pol.end(), SortPointsByX());
    QPointF px_max = *std::max_element(pol.begin(), pol.end(), SortPointsByX());
    QPointF py_min = *std::min_element(pol.begin(), pol.end(), SortPointsByY());
    QPointF py_max = *std::max_element(pol.begin(), pol.end(), SortPointsByY());

    // Points
    QPointF v1(px_min.x(),py_min.y());
    QPointF v2(px_max.x(),py_min.y());
    QPointF v3(px_max.x(),py_max.y());
    QPointF v4(px_min.x(),py_max.y());

    // Create polygon
    QPolygonF mmb;
    mmb.push_back(v1);
    mmb.push_back(v2);
    mmb.push_back(v3);
    mmb.push_back(v4);

    //Compute area
    double area = getArea(mmb);

    return {mmb, area};
}

QPolygonF Algorithms::minAreaEnclosingRectangle(QPolygonF &pol)
{
    // Create minimum area enclosing rectangle
    QPolygonF ch = createCH(pol);

    //Initialize min max box
    double sigma_min = 0;
    auto [mmb_min, area_min] = minMaxBox(pol);

    //Process all segments of CH
    int n = ch.size();
    for(int i = 0; i < n; i++)
    {
        // Compute direction sigma
        double dx = ch[(i+1)%n].x() - ch[i].x();
        double dy = ch[(i+1)%n].y() - ch[i].y();
        double sigma = atan2(dy, dx);

        // Rotate by -sigma
        QPolygonF pol_r = rotate(pol,-sigma);

        // Find new MMB
        auto [mmb,area] = minMaxBox(pol_r);

        // Update min MMB
        if(area < area_min)
        {
           mmb_min = mmb;
           area_min = area;
           sigma_min = sigma;
        }
    }

    // Convert min MMB to MAER
    return rotate(mmb_min, sigma_min);

}






