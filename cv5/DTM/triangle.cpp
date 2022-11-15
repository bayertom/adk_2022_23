#include "triangle.h"

Triangle::Triangle(const QPoint3D &p1_, const QPoint3D &p2_, const QPoint3D &p3_, const double slope_, const double aspect_)
{
    p1 = p1_;
    p2 = p2_;
    p3 = p3_;
    slope = slope_;
    aspect = aspect_;

}
