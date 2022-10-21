/********************************************************************************
** Form generated from reading UI file 'qt_samp_01.ui'
**
** Created by: Qt User Interface Compiler version 6.0.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QT_SAMP_01_H
#define UI_QT_SAMP_01_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_qt_samp_01Class
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *qt_samp_01Class)
    {
        if (qt_samp_01Class->objectName().isEmpty())
            qt_samp_01Class->setObjectName(QString::fromUtf8("qt_samp_01Class"));
        qt_samp_01Class->resize(600, 400);
        menuBar = new QMenuBar(qt_samp_01Class);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        qt_samp_01Class->setMenuBar(menuBar);
        mainToolBar = new QToolBar(qt_samp_01Class);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        qt_samp_01Class->addToolBar(mainToolBar);
        centralWidget = new QWidget(qt_samp_01Class);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        qt_samp_01Class->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(qt_samp_01Class);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        qt_samp_01Class->setStatusBar(statusBar);

        retranslateUi(qt_samp_01Class);

        QMetaObject::connectSlotsByName(qt_samp_01Class);
    } // setupUi

    void retranslateUi(QMainWindow *qt_samp_01Class)
    {
        qt_samp_01Class->setWindowTitle(QCoreApplication::translate("qt_samp_01Class", "qt_samp_01", nullptr));
    } // retranslateUi

};

namespace Ui {
    class qt_samp_01Class: public Ui_qt_samp_01Class {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QT_SAMP_01_H
