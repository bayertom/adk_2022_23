#include "draw.h"
#include <QtGui>

Draw::Draw(QWidget *parent) : QWidget(parent)
{
    draw_element = true;
}


void Draw::mousePressEvent(QMouseEvent *event)
{

    //Get x,y coordinates
    double x = event->pos().x();
    double y = event->pos().y();

    //Create new point
    QPointF p(x, y);

    //Add point to the element
    if (draw_element)
        element.push_back(p);

    //Add point to the barrier
    else
        barrier.push_back(p);

    //Repaint screen
    repaint();

}


void Draw::paintEvent(QPaintEvent *event)
{
    //Draw polygon
    QPainter painter(this);

    //Start draw
    painter.begin(this);

   // Draw element
    painter.setPen(Qt::blue);

    for(int i =0; (i < element.size()-1) && (element.size() > 1) ; i++)
        painter.drawLine(element[i].x(),element[i].y(),element[i+1].x(),element[i+1].y());

    // Draw barrier
    painter.setPen(Qt::red);
    for(int i =0; (i < barrier.size()-1) &&(barrier.size() > 1); i++)
        painter.drawLine(barrier[i].x(),barrier[i].y(),barrier[i+1].x(),barrier[i+1].y());

    // Draw displaced
    painter.setPen(Qt::green);
    for(int i =0; (i < displaced.size()-1) && (displaced.size() > 1); i++)
        painter.drawLine(displaced[i].x(),displaced[i].y(),displaced[i+1].x(),displaced[i+1].y());

    // Draw displaced2
    painter.setPen(Qt::yellow);
    for(int i =0; (i < displaced2.size()-1) && (displaced2.size() > 1); i++)
        painter.drawLine(displaced2[i].x(),displaced2[i].y(),displaced2[i+1].x(),displaced2[i+1].y());

    // End draw
    painter.end();
}
