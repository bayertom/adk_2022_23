#ifndef DRAW_H
#define DRAW_H

#include <QWidget>

class Draw : public QWidget
{
    Q_OBJECT

private:
    QPolygonF building;
    QPolygonF ch;
    QPolygonF er;

public:
    explicit Draw(QWidget *parent = nullptr);
    void mousePressEvent(QMouseEvent *event);
    void paintEvent(QPaintEvent *event);

    QPolygonF getCH(){return ch;}
    QPolygonF getMAER(){return er;}
    QPolygonF getBuild(){return building;}
    void setCH(QPolygonF &ch_){ch=ch_;};
    void setMinimumAreaEnclosingRectangle(QPolygonF &er_){er=er_;};
    void clearAll();

signals:

public slots:
};

#endif // DRAW_H
