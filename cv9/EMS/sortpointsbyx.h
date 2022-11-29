#ifndef SORTPOINTSBYX_H
#define SORTPOINTSBYX_H
#include <QtGui>


class SortPointsByX
{
public:
    SortPointsByX();
    bool operator () (QPointF &p, QPointF &q)
    {
        return p.x() < q.x();
    }
};

#endif // SORTPOINTSBYX_H
