#ifndef TRIANGLE_H
#define TRIANGLE_H
#include "qpoint3d.h"


class Triangle
{
private:
    QPoint3D p1, p2, p3;
    double slope, aspect;

public:
    Triangle(const QPoint3D &p1_, const QPoint3D &p2_, const QPoint3D &p3_, const double slope_, const double aspect_);

    QPoint3D getP1(){return p1;}
    QPoint3D getP2(){return p2;}
    QPoint3D getP3(){return p3;}
    double getSlope(){return slope;}
    double getAspect(){return aspect;}


};

#endif // TRIANGLE_H
