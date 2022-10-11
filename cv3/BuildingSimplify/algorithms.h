#ifndef ALGORITHMS_H
#define ALGORITHMS_H

#include <QtGui>
#include <tuple>

class Algorithms
{
public:
    Algorithms();
    int getPointLinePosition(QPointF &p1, QPointF &p2, QPointF &q);
    double getTwoLinesAngle(QPointF &p1,QPointF &p2,QPointF &p3,QPointF &p4);
    QPolygonF createCH(QPolygonF &pol);
    QPolygonF rotate(QPolygonF &pol, double sig);
    double getArea(QPolygonF &pol);
    std::tuple<QPolygonF, double> minMaxBox(QPolygonF &pol);
    QPolygonF minAreaEnclosingRectangle(QPolygonF &pol);

};

#endif // ALGORITHMS_H
