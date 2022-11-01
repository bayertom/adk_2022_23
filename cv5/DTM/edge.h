#ifndef EDGE_H
#define EDGE_H
#include "qpoint3d.h"

class Edge
{

private:
    QPoint3D p1, p2;

public:

    Edge(const QPoint3D &p1_, const QPoint3D &p2_): p1(p1_), p2(p2_){};
    QPoint3D getP1() const {return p1;}
    QPoint3D getP2() const {return p2;}
    void setP1(const QPoint3D &p1_){p1 = p1_;}
    void setP2(const QPoint3D &p2_){p2 = p2_;}
    Edge switchOrientation()const{return Edge(p2,p1);}

    bool operator == (const Edge &e)
    {
        return (p1 == e.getP1()) && (p2 == e.getP2());
    }
};

#endif // EDGE_H
