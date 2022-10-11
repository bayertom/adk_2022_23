#include "draw.h"

#include <QtGui>

Draw::Draw(QWidget *parent) : QWidget(parent)
{

}

void Draw::mousePressEvent(QMouseEvent *event)
{
    //Get x,y coordinate
    double x = event->pos().x();
    double y = event->pos().y();

    //Create new point
    QPointF p(x, y);

    //Add as a new vertex
    building.push_back(p);

    //Repaint screen
    repaint();
}


void Draw::paintEvent(QPaintEvent *event)
{
    //Draw polygon
    QPainter painter(this);

    //Start draw
    painter.begin(this);

    //Draw polygon
    painter.drawPolygon(building);

    //Draw convex hull
    painter.setPen(Qt::red);
    painter.drawPolygon(ch);

    //Draw minimum area enclosing rectangle
    painter.setPen(Qt::green);
    painter.drawPolygon(er);

    //End draw
    painter.end();
}


