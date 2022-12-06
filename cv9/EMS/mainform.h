#ifndef MAINFORM_H
#define MAINFORM_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainForm; }
QT_END_NAMESPACE

class MainForm : public QMainWindow
{
    Q_OBJECT

public:
    MainForm(QWidget *parent = nullptr);
    ~MainForm();

private slots:

    void on_actionDisplace_triggered();

    void on_actionElement_Barrier_changed();

private:
    Ui::MainForm *ui;
};
#endif // MAINFORM_H
