#include "mainform.h"
#include "ui_mainform.h"
#include "algorithms.h"

MainForm::MainForm(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainForm)
{
    ui->setupUi(this);


    // Initialization
    zmin = 0;
    zmax = 1000;
    dz = 10;

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
    // Clear contour lines
    ui->Canvas->clearContours();

    // Get points
    std::vector <QPoint3D> points = ui->Canvas->getPoints();

    // Create DT
    Algorithms a;

    //Get Delaunay triangulation
    std::vector <Edge> dt = ui->Canvas->getDT();

    // DT wasn't created yet
    if(dt.size()==0)
    {
        dt = a.createDT(points);

        // Update DT
        ui->Canvas->setDT(dt);
    }

    // Generate contour lines
    std::vector<Edge> contours = a.createContourLines(dt, zmin, zmax, dz);

    // Update DT
    ui->Canvas->setContours(contours);

    repaint();
}


void MainForm::on_actionAnalyze_slope_triggered()
{
    //Analyze slope
    // Clear triangles
    ui->Canvas->clearTriangles();

    // Get points
    std::vector <QPoint3D> points = ui->Canvas->getPoints();

    // Create DT
    Algorithms a;

    //Get Delaunay triangulation
    std::vector <Edge> dt = ui->Canvas->getDT();

    // DT wasn't created yet
    if(dt.size()==0)
    {
        dt = a.createDT(points);

        // Update DT
        ui->Canvas->setDT(dt);
    }

    // Compute slope
    std::vector<Triangle> triangles = a.analyzeSlope(dt);

    // Update DT
    ui->Canvas->setTriangles(triangles);

    repaint();
}


void MainForm::on_actionAnalyze_aspect_triggered()
{
    //Analyze exposition
}


void MainForm::on_action_2_triggered()
{
    //OK button
    if (settings.exec() == QDialog::Accepted)
    {
        //Set properties
        zmin = settings.getZmin();
        zmax = settings.getZmax();
        dz =   settings.getDz();
    }
}
