#ifndef SORTPOINTSBYY_H
#define SORTPOINTSBYY_H

#include <QtGui>

class SortPointsByY
{
public:
    SortPointsByY();
    bool operator () (QPointF &p, QPointF &q)
    {
        return p.y() < q.y();
    }
};

#endif // SORTPOINTSBYY_H
