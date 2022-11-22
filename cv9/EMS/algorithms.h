#ifndef ALGORITHMS_H
#define ALGORITHMS_H
#include <tuple>

class Algorithms
{
public:
    Algorithms();

    double getEuclDistance(double x1,double y1,double x2,double y2);
    std::tuple<double, double, double> getPointLineDistance(double x, double y, double x1, double y1, double x2, double y2);

};

#endif // ALGORITHMS_H
