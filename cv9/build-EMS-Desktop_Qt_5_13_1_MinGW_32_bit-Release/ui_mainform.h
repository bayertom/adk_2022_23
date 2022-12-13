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
#include <draw.h>

QT_BEGIN_NAMESPACE

class Ui_MainForm
{
public:
    QAction *actionOpen;
    QAction *actionDisplace;
    QAction *actionSettings;
    QAction *actionElement_Barrier;
    QAction *actionDisplace_2_elements;
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout;
    Draw *Canvas;
    QMenuBar *menubar;
    QMenu *menuFile;
    QMenu *menuSimplify;
    QMenu *menuInput;
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
        actionElement_Barrier = new QAction(MainForm);
        actionElement_Barrier->setObjectName(QString::fromUtf8("actionElement_Barrier"));
        actionElement_Barrier->setCheckable(true);
        actionDisplace_2_elements = new QAction(MainForm);
        actionDisplace_2_elements->setObjectName(QString::fromUtf8("actionDisplace_2_elements"));
        centralwidget = new QWidget(MainForm);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        horizontalLayout = new QHBoxLayout(centralwidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        Canvas = new Draw(centralwidget);
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
        menuInput = new QMenu(menubar);
        menuInput->setObjectName(QString::fromUtf8("menuInput"));
        MainForm->setMenuBar(menubar);
        statusbar = new QStatusBar(MainForm);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainForm->setStatusBar(statusbar);
        toolBar = new QToolBar(MainForm);
        toolBar->setObjectName(QString::fromUtf8("toolBar"));
        MainForm->addToolBar(Qt::TopToolBarArea, toolBar);

        menubar->addAction(menuFile->menuAction());
        menubar->addAction(menuInput->menuAction());
        menubar->addAction(menuSimplify->menuAction());
        menuFile->addAction(actionOpen);
        menuFile->addSeparator();
        menuSimplify->addSeparator();
        menuSimplify->addAction(actionDisplace);
        menuSimplify->addAction(actionDisplace_2_elements);
        menuSimplify->addSeparator();
        menuSimplify->addAction(actionSettings);
        menuInput->addAction(actionElement_Barrier);

        retranslateUi(MainForm);

        QMetaObject::connectSlotsByName(MainForm);
    } // setupUi

    void retranslateUi(QMainWindow *MainForm)
    {
        MainForm->setWindowTitle(QCoreApplication::translate("MainForm", "Energy minimizing splines", nullptr));
        actionOpen->setText(QCoreApplication::translate("MainForm", "Open", nullptr));
        actionDisplace->setText(QCoreApplication::translate("MainForm", "Displace 1 element", nullptr));
        actionSettings->setText(QCoreApplication::translate("MainForm", "Settings", nullptr));
        actionElement_Barrier->setText(QCoreApplication::translate("MainForm", "Element/Barrier", nullptr));
        actionDisplace_2_elements->setText(QCoreApplication::translate("MainForm", "Displace 2 elements", nullptr));
        menuFile->setTitle(QCoreApplication::translate("MainForm", "File", nullptr));
        menuSimplify->setTitle(QCoreApplication::translate("MainForm", "Simplify", nullptr));
        menuInput->setTitle(QCoreApplication::translate("MainForm", "Input", nullptr));
        toolBar->setWindowTitle(QCoreApplication::translate("MainForm", "toolBar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainForm: public Ui_MainForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINFORM_H
