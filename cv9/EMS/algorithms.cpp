#include "algorithms.h"
#include <cmath>

Algorithms::Algorithms()
{    
}


double Algorithms::getEuclDistance(double x1,double y1,double x2,double y2)
{
    // Euclidean distance
    double dx = x1-x2;
    double dy = y1-y2;
    return sqrt(dx*dx + dy*dy);
}


std::tuple<double, double, double> Algorithms::getPointLineDistance(double x, double y, double x1, double y1, double x2, double y2)
{
    // Point and line distance
    double d12 = getEuclDistance(x1, y1, x2, y2);

    //Distance point p and line (p1, p2)
    double dist = (x*(y1 - y2) + x1*(y2 - y) + x2*(y - y1))/d12;

    //Coordinates of the point on (p1, p2) nearest to p
    double d1 = getEuclDistance(x1,y1,x,y);
    double k = sqrt(d1*d1-dist*dist);

    double rx = x1 + k*(x2-x1)/d12;
    double ry = y1 + k*(y2-y2)/d12;

    return {dist, rx, ry};
}

std::tuple<double, double, double> Algorithms::getPointLineSegmentDistance(double x, double y, double x1, double y1, double x2, double y2)
{
    // Point and line segment distance
    double ux = x2 - x1;
    double uy = y2 - y1;

    // Normal vector
    double nx = y2 - y1;
    double ny = x1 - x2;

    //Supplementary point P3, P4
    double x3 = x1 + nx;
    double y3 = y1 + ny;
    double x4 = x2 + nx;
    double y4 = y2 + ny;

    // Position Q to P1,P3
    auto [dqp13, xi1, yi1] = getPointLineDistance(x, y, x1, y1, x3, y3);
    auto [dqp24, xi2, yi2] = getPointLineDistance(x, y, x2, y2, x4, y4);
    double crit = dqp13 * dqp24;

    // Point Q and line (P1, P2) distance
    if (crit < 0)
    {
        auto [d, xi, yi] = getPointLineDistance(x, y, x1, y1, x2, y2);
        return {d, xi, yi};
    }
    // Point Q left from P1, P3
    if (dqp13 > 0)
        return {getEuclDistance(x, y, x1, y1), x1, y1};

    // Point Q left from P2, P4
    return {getEuclDistance(x, y, x2, y2), x2, y2};
}

std::tuple<int, double, double, double> Algorithms::getNearestLineSegmentPoint(double xq, double yq, Matrix &X, Matrix &Y)
{
     //Get nearest point and its coordinates
    int imin = -1;
    double dmin = 1.0e10;
    double xn, yn;

    auto [m,n] = X.size();

    //Browse all points
    for (int i = 0; i < m; i++)
    {
        //Compute distance
        auto [d, xi, yi] = getPointLineSegmentDistance(xq, yq, X(i, 0), Y(i, 0), X(i+1, 0), Y(i+1, 0));

        //Actualize minimum
        if (d < dmin)
        {
                dmin = d;
                imin = i;
                xn = xi;
                yn = yi;
        }
    }
    return {imin, dmin, xn, yn};
}














