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
    pol.push_back(p);

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
    painter.drawPolygon(pol);

    //End draw
    painter.end();
}

void Draw::clearScreen()
{
    //Clear screen
    pol.clear();

    repaint();
}
