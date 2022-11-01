#include "draw.h"

#include <QtGui>

Draw::Draw(QWidget *parent) : QWidget(parent)
{

}


void Draw::mousePressEvent(QMouseEvent *event)
{
    //Get x,y coordinates
    double x = event->pos().x();
    double y = event->pos().y();

    //Create new point
    QPoint3D p(x, y, 0);

    //Add as a new vertex
    points.push_back(p);

    //Repaint screen
    repaint();
}


void Draw::paintEvent(QPaintEvent *event)
{
    //Draw polygon
    QPainter painter(this);

    //Start draw
    painter.begin(this);

    //Draw points, old
    double r = 5; //px
    /*
    for (int i = 0; i < points.size(); i++){

        //Draw point
        painter.drawEllipse(points[i].x()-r, points[i].y()-r, 2*r, 2*r);
    }
    */
    //Draw points, new
    for (QPoint3D p:points)
    {
        //Draw point
        painter.drawEllipse(p.x()-r, p.y()-r, 2*r, 2*r);
    }

    //Draw DT represented by edges
    for(Edge e : dt)
    {
       // Get end points
       QPoint3D p1 = e.getP1();
       QPoint3D p2 = e.getP2();

       // Draw line
       painter.drawLine(p1,p2);
    }

    //End draw
    painter.end();
}
