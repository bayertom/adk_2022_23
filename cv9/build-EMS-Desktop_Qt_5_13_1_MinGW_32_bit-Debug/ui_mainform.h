/********************************************************************************
** Form generated from reading UI file 'mainform.ui'
**
** Created by: Qt User Interface Compiler version 5.13.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINFORM_H
#define UI_MAINFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainForm
{
public:
    QAction *actionOpen;
    QAction *actionDisplace;
    QAction *actionSettings;
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout;
    QWidget *Canvas;
    QMenuBar *menubar;
    QMenu *menuFile;
    QMenu *menuSimplify;
    QStatusBar *statusbar;
    QToolBar *toolBar;

    void setupUi(QMainWindow *MainForm)
    {
        if (MainForm->objectName().isEmpty())
            MainForm->setObjectName(QString::fromUtf8("MainForm"));
        MainForm->resize(1217, 714);
        actionOpen = new QAction(MainForm);
        actionOpen->setObjectName(QString::fromUtf8("actionOpen"));
        actionDisplace = new QAction(MainForm);
        actionDisplace->setObjectName(QString::fromUtf8("actionDisplace"));
        actionSettings = new QAction(MainForm);
        actionSettings->setObjectName(QString::fromUtf8("actionSettings"));
        centralwidget = new QWidget(MainForm);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        horizontalLayout = new QHBoxLayout(centralwidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        Canvas = new QWidget(centralwidget);
        Canvas->setObjectName(QString::fromUtf8("Canvas"));

        horizontalLayout->addWidget(Canvas);

        MainForm->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainForm);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1217, 21));
        menuFile = new QMenu(menubar);
        menuFile->setObjectName(QString::fromUtf8("menuFile"));
        menuSimplify = new QMenu(menubar);
        menuSimplify->setObjectName(QString::fromUtf8("menuSimplify"));
        MainForm->setMenuBar(menubar);
        statusbar = new QStatusBar(MainForm);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainForm->setStatusBar(statusbar);
        toolBar = new QToolBar(MainForm);
        toolBar->setObjectName(QString::fromUtf8("toolBar"));
        MainForm->addToolBar(Qt::TopToolBarArea, toolBar);

        menubar->addAction(menuFile->menuAction());
        menubar->addAction(menuSimplify->menuAction());
        menuFile->addAction(actionOpen);
        menuFile->addSeparator();
        menuSimplify->addAction(actionDisplace);
        menuSimplify->addSeparator();
        menuSimplify->addAction(actionSettings);

        retranslateUi(MainForm);

        QMetaObject::connectSlotsByName(MainForm);
    } // setupUi

    void retranslateUi(QMainWindow *MainForm)
    {
        MainForm->setWindowTitle(QCoreApplication::translate("MainForm", "MainForm", nullptr));
        actionOpen->setText(QCoreApplication::translate("MainForm", "Open", nullptr));
        actionDisplace->setText(QCoreApplication::translate("MainForm", "Displace", nullptr));
        actionSettings->setText(QCoreApplication::translate("MainForm", "Settings", nullptr));
        menuFile->setTitle(QCoreApplication::translate("MainForm", "File", nullptr));
        menuSimplify->setTitle(QCoreApplication::translate("MainForm", "Simplify", nullptr));
        toolBar->setWindowTitle(QCoreApplication::translate("MainForm", "toolBar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainForm: public Ui_MainForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINFORM_H
