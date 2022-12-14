#include "draw.h"

#include <QtGui>

Draw::Draw(QWidget *parent) : QWidget(parent)
{
    srand((unsigned)time(0));
}


void Draw::mousePressEvent(QMouseEvent *event)
{
    //Get x,y coordinates
    double x = event->pos().x();
    double y = event->pos().y();

    //Create new point
    QPoint3D p(x, y, rand() % 1000 );

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

    //Draw triangles
    for(Triangle t : triangles){
        //Get points and slope of a triangle
        QPoint3D p1 = t.getP1();
        QPoint3D p2 = t.getP2();
        QPoint3D p3 = t.getP3();

        double slope = t.getSlope();

        // Convert slope to RGB
        double k = 255/M_PI;
        int col = 255-slope*k;

        //Set color
        QColor color(col, col, col);
        painter.setPen(color);
        painter.setBrush(color);

        //Create polygon
        QPolygonF poly;
        poly.push_back(p1);
        poly.push_back(p2);
        poly.push_back(p3);

        //Draw polygon
        painter.drawPolygon(poly);
    }

    //Draw points, new
    for (QPoint3D p:points)
    {
        //Draw point
        painter.drawEllipse(p.x()-r, p.y()-r, 2*r, 2*r);
    }

    //Draw DT represented by edges
    painter.setPen(Qt::green);
    for(Edge e : dt)
    {
       // Get end points
       QPoint3D p1 = e.getP1();
       QPoint3D p2 = e.getP2();

       // Draw line
       painter.drawLine(p1, p2);
    }

    // Draw contour lines
    painter.setPen(Qt::gray);
    for(Edge e : contours)
    {
       // Get end points
       QPoint3D p1 = e.getP1();
       QPoint3D p2 = e.getP2();

       // Draw line
       painter.drawLine(p1,p2);
    }

    // End draw
    painter.end();
}
