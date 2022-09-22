#include "algorithms.h"

Algorithms::Algorithms()
{

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
