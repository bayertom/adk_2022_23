#include "draw.h"

#include <QtGui>

Draw::Draw(QWidget *parent) : QWidget(parent)
{
    mode = true;
    q.setX(100);
    q.setY(100);

}


void Draw::mousePressEvent(QMouseEvent *event)
{
    //Get x,y coordinate
    double x = event->pos().x();
    double y = event->pos().y();

    //Add to polygon
    if(mode){

        //Create new point
        QPointF p(x, y);

        //Add as a new vertex
        pol.push_back(p);
    }

    // Shift point
    else {
        q.setX(x);
        q.setY(y);
    }

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

    //Draw point
    double r = 5; //px
    painter.drawEllipse(q.x()-r, q.y()-r, 2*r, 2*r);

    //End draw
    painter.end();
}

void Draw::clearScreen()
{
    //Clear screen
    pol.clear();

    repaint();
}

void Draw::changeMode()
{
    // Switch mode: draw point/add vertex
    mode = !mode;
}


