#ifndef DRAW_H
#define DRAW_H

#include <QWidget>

class Draw : public QWidget
{ 
    Q_OBJECT

private:
    bool draw_element;
    std::vector<QPointF>element, barrier, displaced;


public:
    explicit Draw(QWidget *parent = nullptr);
    void mousePressEvent(QMouseEvent *event);
    void paintEvent(QPaintEvent *event);
    void switchDrawnElement(){draw_element=!draw_element;}
    std::vector<QPointF>getElement(){return element;}
    std::vector<QPointF>getBarrier(){return barrier;}
    std::vector<QPointF>getDisplaced(){return displaced;}
    void setElement(std::vector<QPointF> &element_){element=element_;}
    void setBarrier(std::vector<QPointF> &barrier_){barrier=barrier_;}
    void setDisplaced(std::vector<QPointF> &displaced_){displaced=displaced_;}
signals:

public slots:
};

#endif // DRAW_H
