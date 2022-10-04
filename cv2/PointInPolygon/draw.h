#ifndef DRAW_H
#define DRAW_H

#include <QWidget>

class Draw : public QWidget
{
    Q_OBJECT

private:
    bool mode;
    QPointF q;
    QPolygonF pol;

public:
    explicit Draw(QWidget *parent = nullptr);
    void mousePressEvent(QMouseEvent *event);
    void paintEvent(QPaintEvent *event);
    void clearScreen();
    QPolygonF getPolygon(){return pol;}
    void changeMode();
    QPointF getPoint(){return q;}

signals:

public slots:
};

#endif // DRAW_H
