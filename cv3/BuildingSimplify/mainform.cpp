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


void MainForm::on_pushButton_3_clicked()
{
    // Get building
    QPolygonF building = ui->Canvas->getBuild();

    //Get CH
    Algorithms a;
    QPolygonF ch = a.createCH(building);

    //Set CH and repaint
    ui->Canvas->setCH(ch);
    repaint();
}

void MainForm::on_pushButton_4_clicked()
{
    // Get building
    QPolygonF building = ui->Canvas->getBuild();

    //Get MAER
    Algorithms a;
    QPolygonF er = a.minAreaEnclosingRectangle(building);

    //Set CH and repaint
    ui->Canvas->setMAER(er);
    repaint();
}
