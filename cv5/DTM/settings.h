#ifndef SETTINGS_H
#define SETTINGS_H

#include <QDialog>

namespace Ui {
class Settings;
}

class Settings : public QDialog
{
    Q_OBJECT
private:
    double zmin, zmax, dz;

public:
    explicit Settings(QWidget *parent = nullptr);
    ~Settings();

    double getZmin() {return zmin; }
    double getZmax() {return zmax; }
    double getDz()   {return dz; }

private slots:
    void on_lineEdit_editingFinished();

    void on_lineEdit_2_editingFinished();

    void on_lineEdit_3_editingFinished();

private:
    Ui::Settings *ui;
};

#endif // SETTINGS_H
