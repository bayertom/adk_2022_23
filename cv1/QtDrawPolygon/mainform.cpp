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


void MainForm::on_pushButton_clicked()
{
    //Clear screen
    ui->Canvas->clearScreen();
}

void MainForm::on_pushButton_2_clicked()
{
    //Compute area

    //Get polygon
    QPolygonF pol = ui->Canvas->getPolygon();

    //New object
    Algorithms a;
    double area = a.getArea(pol);

    //Print to label
    ui->label->setText( QString::number(area));
}
