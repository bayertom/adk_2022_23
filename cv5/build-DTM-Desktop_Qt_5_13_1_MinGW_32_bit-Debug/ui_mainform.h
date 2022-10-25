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
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>
#include "draw.h"

QT_BEGIN_NAMESPACE

class Ui_MainForm
{
public:
    QAction *actionOpen;
    QAction *actionCreate_DTM;
    QWidget *centralwidget;
    Draw *Canvas;
    QMenuBar *menubar;
    QMenu *menuFile;
    QMenu *menuAnalyze;
    QStatusBar *statusbar;
    QToolBar *toolBar;

    void setupUi(QMainWindow *MainForm)
    {
        if (MainForm->objectName().isEmpty())
            MainForm->setObjectName(QString::fromUtf8("MainForm"));
        MainForm->resize(1155, 777);
        actionOpen = new QAction(MainForm);
        actionOpen->setObjectName(QString::fromUtf8("actionOpen"));
        actionCreate_DTM = new QAction(MainForm);
        actionCreate_DTM->setObjectName(QString::fromUtf8("actionCreate_DTM"));
        centralwidget = new QWidget(MainForm);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        Canvas = new Draw(centralwidget);
        Canvas->setObjectName(QString::fromUtf8("Canvas"));
        Canvas->setGeometry(QRect(20, 40, 1111, 661));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Canvas->sizePolicy().hasHeightForWidth());
        Canvas->setSizePolicy(sizePolicy);
        MainForm->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainForm);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1155, 21));
        menuFile = new QMenu(menubar);
        menuFile->setObjectName(QString::fromUtf8("menuFile"));
        menuAnalyze = new QMenu(menubar);
        menuAnalyze->setObjectName(QString::fromUtf8("menuAnalyze"));
        MainForm->setMenuBar(menubar);
        statusbar = new QStatusBar(MainForm);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainForm->setStatusBar(statusbar);
        toolBar = new QToolBar(MainForm);
        toolBar->setObjectName(QString::fromUtf8("toolBar"));
        MainForm->addToolBar(Qt::TopToolBarArea, toolBar);

        menubar->addAction(menuFile->menuAction());
        menubar->addAction(menuAnalyze->menuAction());
        menuFile->addAction(actionOpen);
        menuAnalyze->addAction(actionCreate_DTM);

        retranslateUi(MainForm);

        QMetaObject::connectSlotsByName(MainForm);
    } // setupUi

    void retranslateUi(QMainWindow *MainForm)
    {
        MainForm->setWindowTitle(QCoreApplication::translate("MainForm", "MainForm", nullptr));
        actionOpen->setText(QCoreApplication::translate("MainForm", "Open", nullptr));
        actionCreate_DTM->setText(QCoreApplication::translate("MainForm", "Create DTM", nullptr));
        menuFile->setTitle(QCoreApplication::translate("MainForm", "File", nullptr));
        menuAnalyze->setTitle(QCoreApplication::translate("MainForm", "Analyze", nullptr));
        toolBar->setWindowTitle(QCoreApplication::translate("MainForm", "toolBar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainForm: public Ui_MainForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINFORM_H
