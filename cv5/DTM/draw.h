#ifndef DRAW_H
#define DRAW_H

#include <QWidget>
#include <vector>
#include "qpoint3d.h"
#include "edge.h"

class Draw : public QWidget
{
    Q_OBJECT

    private:

        std::vector <QPoint3D> points;
        std::vector <Edge> dt;

public:
    explicit Draw(QWidget *parent = nullptr);
    void mousePressEvent(QMouseEvent *event);
    void paintEvent(QPaintEvent *event);
    std::vector <QPoint3D> getPoints(){return points;}
    std::vector <Edge> getDT(){return dt;}
    void setPoints(const std::vector <QPoint3D> &points_){points = points_;}
    void setDT(const std::vector <Edge> &dt_){dt = dt_;}



signals:

public slots:
};

#endif // DRAW_H
