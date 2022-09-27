#include "mainform.h"
#include "ui_mainform.h"

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

    //Analyze position

    //Print results
}
