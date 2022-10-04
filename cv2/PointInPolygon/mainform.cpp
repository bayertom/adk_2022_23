#include "mainform.h"
#include "ui_mainform.h"
#include "algorithms.h"

MainForm::MainForm(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::MainForm)
{
    ui->setupUi(this);
}

MainForm::~MainForm()
{
    delete ui;
}


void MainForm::on_pushButton_2_clicked()
{

    //Get point + polygon
    QPointF q = ui-> Canvas -> getPoint();
    QPolygonF pol = ui -> Canvas ->getPolygon();

    //Analyze position
    Algorithms a;
    int pos = a.getPointAndPolygonPosition(q, pol);

    //Print results
    if(pos == 0)
        ui->label->setText("Point outside");
    else
        ui->label->setText("Point inside");

}

void MainForm::on_pushButton_4_clicked()
{
    ui-> Canvas->changeMode();
}
