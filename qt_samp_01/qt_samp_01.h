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
    
    // �����ۺ�����
private slots:
    bool btnConnectClicked();
    bool btnDisconnectClicked();
    void btnEnableClicked();
    void btnDisableClicked();
public:
    HANDLE m_hComm= ACSC_INVALID;	     //���Ӿ��
    bool isConnected = false;        //�������Ƿ����ӳɹ���־λ
    bool isEnabled = false;             //���Ƿ�ʹ�ܵı�־λ

};
