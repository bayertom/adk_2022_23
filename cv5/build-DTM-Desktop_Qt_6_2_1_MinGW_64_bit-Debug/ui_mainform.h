/********************************************************************************
** Form generated from reading UI file 'mainform.ui'
**
** Created by: Qt User Interface Compiler version 6.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINFORM_H
#define UI_MAINFORM_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "draw.h"

QT_BEGIN_NAMESPACE

class Ui_MainForm
{
public:
    QAction *actionOpen;
    QAction *actionCreate_DT;
    QAction *actionExit;
    QAction *actionCreate_contour_lines;
    QAction *actionAnalyze_slope;
    QAction *actionAnalyze_aspect;
    QAction *action_2;
    QAction *actionAbout;
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    Draw *Canvas;
    QMenuBar *menubar;
    QMenu *menuFile;
    QMenu *menuAnalyze;
    QMenu *menuOptions;
    QMenu *menuHelp;
    QStatusBar *statusbar;
    QToolBar *toolBar;

    void setupUi(QMainWindow *MainForm)
    {
        if (MainForm->objectName().isEmpty())
            MainForm->setObjectName(QString::fromUtf8("MainForm"));
        MainForm->resize(1155, 777);
        actionOpen = new QAction(MainForm);
        actionOpen->setObjectName(QString::fromUtf8("actionOpen"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/icons/open_file.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionOpen->setIcon(icon);
        actionCreate_DT = new QAction(MainForm);
        actionCreate_DT->setObjectName(QString::fromUtf8("actionCreate_DT"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/images/icons/triangles2.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionCreate_DT->setIcon(icon1);
        actionExit = new QAction(MainForm);
        actionExit->setObjectName(QString::fromUtf8("actionExit"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/images/icons/exit.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionExit->setIcon(icon2);
        actionCreate_contour_lines = new QAction(MainForm);
        actionCreate_contour_lines->setObjectName(QString::fromUtf8("actionCreate_contour_lines"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/images/icons/contours2.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionCreate_contour_lines->setIcon(icon3);
        actionAnalyze_slope = new QAction(MainForm);
        actionAnalyze_slope->setObjectName(QString::fromUtf8("actionAnalyze_slope"));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/images/icons/slope2.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionAnalyze_slope->setIcon(icon4);
        actionAnalyze_aspect = new QAction(MainForm);
        actionAnalyze_aspect->setObjectName(QString::fromUtf8("actionAnalyze_aspect"));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/images/icons/orientation2.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionAnalyze_aspect->setIcon(icon5);
        action_2 = new QAction(MainForm);
        action_2->setObjectName(QString::fromUtf8("action_2"));
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/images/icons/settings.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_2->setIcon(icon6);
        actionAbout = new QAction(MainForm);
        actionAbout->setObjectName(QString::fromUtf8("actionAbout"));
        centralwidget = new QWidget(MainForm);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        Canvas = new Draw(centralwidget);
        Canvas->setObjectName(QString::fromUtf8("Canvas"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Canvas->sizePolicy().hasHeightForWidth());
        Canvas->setSizePolicy(sizePolicy);

        verticalLayout->addWidget(Canvas);

        MainForm->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainForm);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1155, 21));
        menuFile = new QMenu(menubar);
        menuFile->setObjectName(QString::fromUtf8("menuFile"));
        menuAnalyze = new QMenu(menubar);
        menuAnalyze->setObjectName(QString::fromUtf8("menuAnalyze"));
        menuOptions = new QMenu(menubar);
        menuOptions->setObjectName(QString::fromUtf8("menuOptions"));
        menuHelp = new QMenu(menubar);
        menuHelp->setObjectName(QString::fromUtf8("menuHelp"));
        MainForm->setMenuBar(menubar);
        statusbar = new QStatusBar(MainForm);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainForm->setStatusBar(statusbar);
        toolBar = new QToolBar(MainForm);
        toolBar->setObjectName(QString::fromUtf8("toolBar"));
        MainForm->addToolBar(Qt::TopToolBarArea, toolBar);

        menubar->addAction(menuFile->menuAction());
        menubar->addAction(menuAnalyze->menuAction());
        menubar->addAction(menuOptions->menuAction());
        menubar->addAction(menuHelp->menuAction());
        menuFile->addAction(actionOpen);
        menuFile->addSeparator();
        menuFile->addAction(actionExit);
        menuAnalyze->addAction(actionCreate_DT);
        menuAnalyze->addAction(actionCreate_contour_lines);
        menuAnalyze->addAction(actionAnalyze_slope);
        menuAnalyze->addAction(actionAnalyze_aspect);
        menuOptions->addAction(action_2);
        menuHelp->addAction(actionAbout);
        toolBar->addAction(actionOpen);
        toolBar->addSeparator();
        toolBar->addAction(actionCreate_DT);
        toolBar->addAction(actionCreate_contour_lines);
        toolBar->addAction(actionAnalyze_slope);
        toolBar->addAction(actionAnalyze_aspect);
        toolBar->addSeparator();
        toolBar->addAction(action_2);

        retranslateUi(MainForm);

        QMetaObject::connectSlotsByName(MainForm);
    } // setupUi

    void retranslateUi(QMainWindow *MainForm)
    {
        MainForm->setWindowTitle(QCoreApplication::translate("MainForm", "DTM analysis", nullptr));
        actionOpen->setText(QCoreApplication::translate("MainForm", "Open", nullptr));
#if QT_CONFIG(tooltip)
        actionOpen->setToolTip(QCoreApplication::translate("MainForm", "Open file", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(shortcut)
        actionOpen->setShortcut(QCoreApplication::translate("MainForm", "Ctrl+O", nullptr));
#endif // QT_CONFIG(shortcut)
        actionCreate_DT->setText(QCoreApplication::translate("MainForm", "Create DT", nullptr));
#if QT_CONFIG(tooltip)
        actionCreate_DT->setToolTip(QCoreApplication::translate("MainForm", "Create Delaunay triangulation", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(shortcut)
        actionCreate_DT->setShortcut(QCoreApplication::translate("MainForm", "Ctrl+T", nullptr));
#endif // QT_CONFIG(shortcut)
        actionExit->setText(QCoreApplication::translate("MainForm", "Exit", nullptr));
#if QT_CONFIG(tooltip)
        actionExit->setToolTip(QCoreApplication::translate("MainForm", "Exit application", nullptr));
#endif // QT_CONFIG(tooltip)
        actionCreate_contour_lines->setText(QCoreApplication::translate("MainForm", "Create contour lines", nullptr));
#if QT_CONFIG(tooltip)
        actionCreate_contour_lines->setToolTip(QCoreApplication::translate("MainForm", "Create contour lines with specific interval", nullptr));
#endif // QT_CONFIG(tooltip)
        actionAnalyze_slope->setText(QCoreApplication::translate("MainForm", "Analyze slope", nullptr));
#if QT_CONFIG(tooltip)
        actionAnalyze_slope->setToolTip(QCoreApplication::translate("MainForm", "Analyze slope of the terrain", nullptr));
#endif // QT_CONFIG(tooltip)
        actionAnalyze_aspect->setText(QCoreApplication::translate("MainForm", "Analyze aspect", nullptr));
#if QT_CONFIG(tooltip)
        actionAnalyze_aspect->setToolTip(QCoreApplication::translate("MainForm", "Analyze aspect of the terrain", nullptr));
#endif // QT_CONFIG(tooltip)
        action_2->setText(QCoreApplication::translate("MainForm", "Options", nullptr));
#if QT_CONFIG(tooltip)
        action_2->setToolTip(QCoreApplication::translate("MainForm", "Set options", nullptr));
#endif // QT_CONFIG(tooltip)
        actionAbout->setText(QCoreApplication::translate("MainForm", "About", nullptr));
#if QT_CONFIG(tooltip)
        actionAbout->setToolTip(QCoreApplication::translate("MainForm", "About the software", nullptr));
#endif // QT_CONFIG(tooltip)
        menuFile->setTitle(QCoreApplication::translate("MainForm", "File", nullptr));
        menuAnalyze->setTitle(QCoreApplication::translate("MainForm", "Analyze", nullptr));
        menuOptions->setTitle(QCoreApplication::translate("MainForm", "Settings", nullptr));
        menuHelp->setTitle(QCoreApplication::translate("MainForm", "Help", nullptr));
        toolBar->setWindowTitle(QCoreApplication::translate("MainForm", "toolBar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainForm: public Ui_MainForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINFORM_H
