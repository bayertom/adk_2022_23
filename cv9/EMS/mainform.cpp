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


void MainForm::on_actionDisplace_2_elements_triggered()
{
    //Run displacement
    std::vector<QPointF> element1 = ui->Canvas->getElement();
    std::vector<QPointF> element2 = ui->Canvas->getBarrier();

    //Set parameters
    double dmin = 100;
    double alfa = 0.3;
    double beta = 10000;
    double gamma = 10000;
    double lambda = 20;
    int iter = 500;

    //Run displacement
    Algorithms a;
    auto [displaced1, displaced2] = a.minEnergySpline2Elements(element1, element2, alfa, beta, gamma, lambda, dmin, iter);

    //Set results
    ui->Canvas->setDisplaced(displaced1);
    ui->Canvas->setDisplaced2(displaced2);

    repaint();
}
