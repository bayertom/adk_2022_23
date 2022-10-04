#ifndef ALGORITHMS_H
#define ALGORITHMS_H
#include <QtGui>

class Algorithms
{
public:
    Algorithms(){};

    int getPointLinePosition(QPointF &p1, QPointF &p2, QPointF &q);
    double getTwoLinesAngle(QPointF &p1,QPointF &p2,QPointF &p3,QPointF &p4);
    int getPointAndPolygonPosition(QPointF &q, QPolygonF &pol);

};

#endif // ALGORITHMS_H
