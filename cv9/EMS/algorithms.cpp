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

