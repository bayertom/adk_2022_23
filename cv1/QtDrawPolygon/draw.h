#ifndef DRAW_H
#define DRAW_H

#include <QWidget>

class Draw : public QWidget
{
    Q_OBJECT

private:
    QPolygonF pol;

public:
    explicit Draw(QWidget *parent = nullptr);
    void mousePressEvent(QMouseEvent *event);
    void paintEvent(QPaintEvent *event);
    void clearScreen();
    QPolygonF getPolygon(){return pol;}

signals:

public slots:
};

#endif // DRAW_H
