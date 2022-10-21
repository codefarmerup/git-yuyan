#pragma once

#include <QtWidgets/QMainWindow>
#include <QMessageBox>
#include "ui_qt_samp_01.h"
#include "ACSC.h"


class qt_samp_01 : public QMainWindow
{
    Q_OBJECT

public:
    qt_samp_01(QWidget *parent = Q_NULLPTR);
    void setLED(QLabel* label, int color, int size);

private:
    Ui::qt_samp_01Class ui;
    
    // 声明槽函数：
private slots:
    bool btnConnectClicked();
    bool btnDisconnectClicked();
    void btnEnableClicked();
    void btnDisableClicked();
public:
    HANDLE m_hComm= ACSC_INVALID;	     //连接句柄
    bool isConnected = false;        //控制器是否连接成功标志位
    bool isEnabled = false;             //轴是否使能的标志位

};
