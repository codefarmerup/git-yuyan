#include "qt_samp_01.h"
#include<atlstr.h>
qt_samp_01::qt_samp_01(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);

    //��UI�Ͽؼ���ť����Ӧ���������
    //connect(ui.btnConnect, SIGNAL(clicked), this, SLOT(on_btnConnectClicked()));
    connect(ui.btnConnect, SIGNAL(clicked()), this, SLOT(btnConnectClicked()));
    connect(ui.btnDisconnect, SIGNAL(clicked()), this, SLOT(btnDisconnectClicked()));
    connect(ui.btnEnable, SIGNAL(clicked()), this, SLOT(btnEnableClicked()));
    connect(ui.btnDisable, SIGNAL(clicked()), this, SLOT(btnDisableClicked()));

   
    //��ָʾ�Ƴ�ʼ��Ϊ��ɫ
    setLED(ui.Led_IsConnected, 0, 16);
    setLED(ui.Led_isEnabled, 0, 16);

    //��ʼ״̬�½���ʹ�ܰ�ť
    ui.btnEnable->setEnabled(false);
    ui.btnDisable->setEnabled(false);
}

/// <summary>
/// ���ӿ�����
/// </summary>
/// <returns></returns>
bool qt_samp_01::btnConnectClicked()
{
    if (m_hComm == ACSC_INVALID)//���ν�������
    {
        try
        {

            CString strAddress = ("10.0.0.100");
            //���ӿ�����
            m_hComm = acsc_OpenCommEthernetTCP((char*)LPCTSTR(strAddress), 701);
            //���ӳɹ�
            if (m_hComm == 0)
            {
                isConnected = true;//���ӳɹ���־λ
                setLED(ui.Led_IsConnected, 2, 16);//ָʾ������Ϊ��ɫ
                ui.btnEnable->setEnabled(true);//���ʹ�ܰ�ť
                ui.btnDisable->setEnabled(true);//�����ʹ�ܰ�ť
                return true;
            }
            //����ʧ��
            else
            {
                isConnected = false;
                return false;
            }
            
        }
        catch (const std::exception&)
        {
            isConnected = false;
            return false;
        }
        
    }
    else //ǰ���Ѿ���һ������
    {
        try
        {
            btnDisconnectClicked();//�ȹص�֮ǰ������
            CString strAddress = ("10.0.0.100");
            //���ӿ�����
            m_hComm = acsc_OpenCommEthernetTCP((char*)LPCTSTR(strAddress), 701);
            if (m_hComm == 0)
            {
                isConnected = true;//���ӳɹ���־λ
                setLED(ui.Led_IsConnected, 2, 16);//ָʾ������Ϊ��ɫ
                ui.btnEnable->setEnabled(true);//���ʹ�ܰ�ť
                ui.btnDisable->setEnabled(true);//�����ʹ�ܰ�ť
                return true;
            }
            else
            {
                isConnected = false;
                return false;
            }

        }
        catch (const std::exception&)
        {
            isConnected = false;
            return false;
        }
        
    }
}
/// <summary>
/// �Ͽ�������
/// </summary>
/// <returns></returns>
bool qt_samp_01::btnDisconnectClicked()
{
    try
    {
        acsc_CloseComm(m_hComm);
        isConnected = false;
        setLED(ui.Led_IsConnected, 0, 16);//ָʾ�ƻָ���ɫ
        ui.btnEnable->setEnabled(false);//���ð�ť
        ui.btnDisable->setEnabled(false);//���ð�ť
        return true;
    }
    catch (const std::exception&)
    {
        return false;
    }
   
}

/// <summary>
/// ���ʹ��
/// </summary>
void qt_samp_01::btnEnableClicked()
{
    if (isConnected == true)
    {
        acsc_Enable(m_hComm, 0, NULL);
        isEnabled = true;
        setLED(ui.Led_isEnabled, 2, 16);//ʹ��ָʾ������Ϊ��ɫ
    }
    else
    {
        QMessageBox msgBox;   // ���ɶ���
        msgBox.setText("Please Connect to Controller First!");    // �����ı�
        msgBox.exec();  // ִ��
    }
}

/// <summary>
/// �Ͽ�ʹ��
/// </summary>
void qt_samp_01::btnDisableClicked()
{
    acsc_Disable(m_hComm, 0, NULL);
    isEnabled = false;
    setLED(ui.Led_isEnabled, 0, 16);//ʹ��ָʾ�ƻָ���ɫ
}




/// <summary>
/// �ú�����label�ؼ����һ��Բ��ָʾ�ƣ���Ҫָ����ɫcolor�Լ�ֱ��size
/// </summary>
/// <param name="label"></param>
/// <param name="color">0:grey 1:red 2:green 3:yellow</param>
/// <param name="size">��λ������</param>
void qt_samp_01::setLED(QLabel* label, int color, int size)
{
    // ��label�е��������
    label->setText("");
    // �����þ��δ�С
    // ���ui�������õ�label��С����С��Ⱥ͸߶�С�����ν�������Ϊ��С��Ⱥ���С�߶ȣ�
    // ���ui�������õ�label��С����С��Ⱥ͸߶ȴ󣬾��ν�������Ϊ����Ⱥ����߶ȣ�
    QString min_width = QString("min-width: %1px;").arg(size);              // ��С��ȣ�size
    QString min_height = QString("min-height: %1px;").arg(size);            // ��С�߶ȣ�size
    QString max_width = QString("max-width: %1px;").arg(size);              // ��С��ȣ�size
    QString max_height = QString("max-height: %1px;").arg(size);            // ��С�߶ȣ�size
    // �����ñ߽���״���߿�
    QString border_radius = QString("border-radius: %1px;").arg(size / 2);    // �߿���Բ�ǣ��뾶Ϊsize/2
    QString border = QString("border:1px solid black;");                    // �߿�Ϊ1px��ɫ
    // ������ñ�����ɫ
    QString background = "background-color:";
    switch (color) {
    case 0:
        // ��ɫ
        background += "rgb(190,190,190)";
        break;
    case 1:
        // ��ɫ
        background += "rgb(255,0,0)";
        break;
    case 2:
        // ��ɫ
        background += "rgb(0,255,0)";
        break;
    case 3:
        // ��ɫ
        background += "rgb(255,255,0)";
        break;
    default:
        break;
    }

    const QString SheetStyle = min_width + min_height + max_width + max_height + border_radius + border + background;
    label->setStyleSheet(SheetStyle);
    
}

