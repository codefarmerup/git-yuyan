/********************************************************************************
** Form generated from reading UI file 'qt_samp_01.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QT_SAMP_01_H
#define UI_QT_SAMP_01_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_qt_samp_01Class
{
public:
    QWidget *centralWidget;
    QPushButton *btnConnect;
    QPushButton *btnDisconnect;
    QGroupBox *groupBox;
    QLabel *Led_IsConnected;
    QGroupBox *groupBox_2;
    QLabel *Led_isEnabled;
    QPushButton *btnDisable;
    QPushButton *btnEnable;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *qt_samp_01Class)
    {
        if (qt_samp_01Class->objectName().isEmpty())
            qt_samp_01Class->setObjectName(QStringLiteral("qt_samp_01Class"));
        qt_samp_01Class->resize(600, 400);
        centralWidget = new QWidget(qt_samp_01Class);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        btnConnect = new QPushButton(centralWidget);
        btnConnect->setObjectName(QStringLiteral("btnConnect"));
        btnConnect->setGeometry(QRect(80, 80, 141, 41));
        btnDisconnect = new QPushButton(centralWidget);
        btnDisconnect->setObjectName(QStringLiteral("btnDisconnect"));
        btnDisconnect->setGeometry(QRect(250, 80, 141, 41));
        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(70, 50, 381, 91));
        Led_IsConnected = new QLabel(groupBox);
        Led_IsConnected->setObjectName(QStringLiteral("Led_IsConnected"));
        Led_IsConnected->setGeometry(QRect(330, 40, 31, 16));
        groupBox_2 = new QGroupBox(centralWidget);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setGeometry(QRect(70, 160, 381, 91));
        Led_isEnabled = new QLabel(groupBox_2);
        Led_isEnabled->setObjectName(QStringLiteral("Led_isEnabled"));
        Led_isEnabled->setGeometry(QRect(330, 40, 31, 16));
        btnDisable = new QPushButton(centralWidget);
        btnDisable->setObjectName(QStringLiteral("btnDisable"));
        btnDisable->setGeometry(QRect(250, 190, 141, 41));
        btnEnable = new QPushButton(centralWidget);
        btnEnable->setObjectName(QStringLiteral("btnEnable"));
        btnEnable->setEnabled(true);
        btnEnable->setGeometry(QRect(80, 190, 141, 41));
        qt_samp_01Class->setCentralWidget(centralWidget);
        groupBox->raise();
        btnConnect->raise();
        btnDisconnect->raise();
        groupBox_2->raise();
        btnDisable->raise();
        btnEnable->raise();
        menuBar = new QMenuBar(qt_samp_01Class);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 600, 22));
        qt_samp_01Class->setMenuBar(menuBar);
        mainToolBar = new QToolBar(qt_samp_01Class);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        qt_samp_01Class->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(qt_samp_01Class);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        qt_samp_01Class->setStatusBar(statusBar);

        retranslateUi(qt_samp_01Class);

        QMetaObject::connectSlotsByName(qt_samp_01Class);
    } // setupUi

    void retranslateUi(QMainWindow *qt_samp_01Class)
    {
        qt_samp_01Class->setWindowTitle(QApplication::translate("qt_samp_01Class", "\345\237\272\344\272\216QT\347\232\204\344\270\212\344\275\215\346\234\272\345\274\200\345\217\221\347\244\272\344\276\213\357\274\210\344\270\200\357\274\211", Q_NULLPTR));
        btnConnect->setText(QApplication::translate("qt_samp_01Class", "\350\277\236\346\216\245", Q_NULLPTR));
        btnDisconnect->setText(QApplication::translate("qt_samp_01Class", "\346\226\255\345\274\200\350\277\236\346\216\245", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("qt_samp_01Class", "\350\277\236\346\216\245\346\216\247\345\210\266\345\231\250", Q_NULLPTR));
        Led_IsConnected->setText(QApplication::translate("qt_samp_01Class", "Led1", Q_NULLPTR));
        groupBox_2->setTitle(QApplication::translate("qt_samp_01Class", "\344\275\277\350\203\275\344\274\272\346\234\215\350\275\264", Q_NULLPTR));
        Led_isEnabled->setText(QApplication::translate("qt_samp_01Class", "Led2", Q_NULLPTR));
        btnDisable->setText(QApplication::translate("qt_samp_01Class", "\346\226\255\345\274\200\344\275\277\350\203\275", Q_NULLPTR));
        btnEnable->setText(QApplication::translate("qt_samp_01Class", "\344\275\277\350\203\275", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class qt_samp_01Class: public Ui_qt_samp_01Class {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QT_SAMP_01_H
