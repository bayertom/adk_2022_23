#ifndef ALGORITHMS_H
#define ALGORITHMS_H
#include <vector>
#include "qpoint3d.h"
#include "edge.h"

class Algorithms
{
public:
    Algorithms();
    int getPointLinePosition(const QPoint3D &p1,const QPoint3D &p2,const QPoint3D &q);
    double getTwoLinesAngle(const QPoint3D &p1,const QPoint3D &p2,const QPoint3D &p3,const QPoint3D &p4);
    int getNearestPoint(const QPoint3D &p, const std::vector<QPoint3D> &points);
    int getDelaunayPoint(const QPoint3D &p1, const QPoint3D &p2,const std::vector<QPoint3D> &points);
    std::vector<Edge> dT(const std::vector<QPoint3D> &points);
};

#endif // ALGORITHMS_H
