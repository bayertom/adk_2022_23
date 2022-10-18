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
    // Get building
    QPolygonF building = ui->Canvas->getBuild();
    Algorithms a;
    QPolygonF err;

    // MAER
    if (ui->comboBox->currentIndex() == 0)
    {
        err = a.resMinAreaEnclosingRectangle(building);
    }

    // Wall average
    else
    {
        err = a.wallAverage(building);
    }

    //Set result and repaint
    ui->Canvas->setMinimumAreaEnclosingRectangle(err);
    repaint();
}


void MainForm::on_pushButton_2_clicked()
{
    //Clear all
    ui->Canvas->clearAll();
    repaint();
}
