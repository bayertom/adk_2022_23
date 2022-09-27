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
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "draw.h"

QT_BEGIN_NAMESPACE

class Ui_MainForm
{
public:
    QHBoxLayout *horizontalLayout;
    Draw *Canvas;
    QVBoxLayout *verticalLayout;
    QPushButton *pushButton;
    QSpacerItem *verticalSpacer_2;
    QPushButton *pushButton_2;
    QLabel *label;
    QSpacerItem *verticalSpacer;
    QPushButton *pushButton_3;
    QSpacerItem *verticalSpacer_3;

    void setupUi(QWidget *MainForm)
    {
        if (MainForm->objectName().isEmpty())
            MainForm->setObjectName(QString::fromUtf8("MainForm"));
        MainForm->resize(1210, 760);
        horizontalLayout = new QHBoxLayout(MainForm);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        Canvas = new Draw(MainForm);
        Canvas->setObjectName(QString::fromUtf8("Canvas"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Canvas->sizePolicy().hasHeightForWidth());
        Canvas->setSizePolicy(sizePolicy);

        horizontalLayout->addWidget(Canvas);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        pushButton = new QPushButton(MainForm);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        verticalLayout->addWidget(pushButton);

        verticalSpacer_2 = new QSpacerItem(20, 28, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);

        pushButton_2 = new QPushButton(MainForm);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));

        verticalLayout->addWidget(pushButton_2);

        label = new QLabel(MainForm);
        label->setObjectName(QString::fromUtf8("label"));

        verticalLayout->addWidget(label);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        pushButton_3 = new QPushButton(MainForm);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));

        verticalLayout->addWidget(pushButton_3);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_3);


        horizontalLayout->addLayout(verticalLayout);


        retranslateUi(MainForm);

        QMetaObject::connectSlotsByName(MainForm);
    } // setupUi

    void retranslateUi(QWidget *MainForm)
    {
        MainForm->setWindowTitle(QCoreApplication::translate("MainForm", "Point in polygon", nullptr));
        pushButton->setText(QCoreApplication::translate("MainForm", "Load file", nullptr));
        pushButton_2->setText(QCoreApplication::translate("MainForm", "Analyze position", nullptr));
        label->setText(QString());
        pushButton_3->setText(QCoreApplication::translate("MainForm", "Clear", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainForm: public Ui_MainForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINFORM_H
