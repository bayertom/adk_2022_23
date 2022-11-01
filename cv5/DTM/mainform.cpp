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


void MainForm::on_actionOpen_triggered()
{
    //Open file
}


void MainForm::on_actionCreate_DT_triggered()
{
    //Create Delaunay triangulation
    // Get points
    std::vector <QPoint3D> points = ui->Canvas->getPoints();

    // Create DT
    Algorithms a;
    std::vector <Edge> dt = a.createDT(points);

    // Update DT
    ui->Canvas->setDT(dt);

    repaint();
}


void MainForm::on_actionExit_triggered()
{
    //Exit application
}


void MainForm::on_actionCreate_contour_lines_triggered()
{
    //Create contour lines
}


void MainForm::on_actionAnalyze_slope_triggered()
{
    //Analyze slope
}

void MainForm::on_actionAnalyze_aspect_triggered()
{
    //Analyze exposition
}


void MainForm::on_action_2_triggered()
{
    //Set properties
}
