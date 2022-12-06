#include "mainform.h"
#include "ui_mainform.h"
#include "algorithms.h"

MainForm::MainForm(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainForm)
{
    ui->setupUi(this);
}

MainForm::~MainForm()
{
    delete ui;
}


void MainForm::on_actionDisplace_triggered()
{
    //Run displacement
    std::vector<QPointF> element = ui->Canvas->getElement();
    std::vector<QPointF> barrier = ui->Canvas->getBarrier();

    //Set parameters
    double dmin = 100;
    double alfa = 0.3;
    double beta = 1000;
    double gamma = 1000;
    double lambda = 20;
    int iter = 500;

    //Run displacement
    Algorithms a;
    std::vector<QPointF> displaced = a.minEnergySpline1Element1Barrier(element, barrier, alfa, beta, gamma, lambda, dmin, iter);

    //Set results
    ui->Canvas->setDisplaced(displaced);

    repaint();
}


void MainForm::on_actionElement_Barrier_changed()
{
    //Change drawn element
    ui->Canvas->switchDrawnElement();
}

