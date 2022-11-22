#ifndef ALGORITHMS_H
#define ALGORITHMS_H
#include <tuple>
#include "matrix.h"

class Algorithms
{
public:
    Algorithms();

    double getEuclDistance(double x1,double y1,double x2,double y2);
    std::tuple<double, double, double> getPointLineDistance(double x, double y, double x1, double y1, double x2, double y2);
    std::tuple<double, double, double> getPointLineSegmentDistance(double x, double y, double x1, double y1, double x2, double y2);
    std::tuple<int, double, double, double> getNearestLineSegmentPoint(double xq, double yq, Matrix &X, Matrix &Y);
};

#endif // ALGORITHMS_H
