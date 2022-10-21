#include "qt_samp_01.h"
#include<atlstr.h>
qt_samp_01::qt_samp_01(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);

    //将UI上控件按钮与响应函数相关联
    //connect(ui.btnConnect, SIGNAL(clicked), this, SLOT(on_btnConnectClicked()));
    connect(ui.btnConnect, SIGNAL(clicked()), this, SLOT(btnConnectClicked()));
    connect(ui.btnDisconnect, SIGNAL(clicked()), this, SLOT(btnDisconnectClicked()));
    connect(ui.btnEnable, SIGNAL(clicked()), this, SLOT(btnEnableClicked()));
    connect(ui.btnDisable, SIGNAL(clicked()), this, SLOT(btnDisableClicked()));

   
    //将指示灯初始化为灰色
    setLED(ui.Led_IsConnected, 0, 16);
    setLED(ui.Led_isEnabled, 0, 16);

    //初始状态下禁用使能按钮
    ui.btnEnable->setEnabled(false);
    ui.btnDisable->setEnabled(false);
}

/// <summary>
/// 连接控制器
/// </summary>
/// <returns></returns>
bool qt_samp_01::btnConnectClicked()
{
    if (m_hComm == ACSC_INVALID)//初次建立连接
    {
        try
        {

            CString strAddress = ("10.0.0.100");
            //连接控制器
            m_hComm = acsc_OpenCommEthernetTCP((char*)LPCTSTR(strAddress), 701);
            //连接成功
            if (m_hComm == 0)
            {
                isConnected = true;//连接成功标志位
                setLED(ui.Led_IsConnected, 2, 16);//指示灯设置为绿色
                ui.btnEnable->setEnabled(true);//解禁使能按钮
                ui.btnDisable->setEnabled(true);//解禁断使能按钮
                return true;
            }
            //连接失败
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
    else //前面已经有一次连接
    {
        try
        {
            btnDisconnectClicked();//先关掉之前的连接
            CString strAddress = ("10.0.0.100");
            //连接控制器
            m_hComm = acsc_OpenCommEthernetTCP((char*)LPCTSTR(strAddress), 701);
            if (m_hComm == 0)
            {
                isConnected = true;//连接成功标志位
                setLED(ui.Led_IsConnected, 2, 16);//指示灯设置为绿色
                ui.btnEnable->setEnabled(true);//解禁使能按钮
                ui.btnDisable->setEnabled(true);//解禁断使能按钮
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
/// 断开控制器
/// </summary>
/// <returns></returns>
bool qt_samp_01::btnDisconnectClicked()
{
    try
    {
        acsc_CloseComm(m_hComm);
        isConnected = false;
        setLED(ui.Led_IsConnected, 0, 16);//指示灯恢复灰色
        ui.btnEnable->setEnabled(false);//禁用按钮
        ui.btnDisable->setEnabled(false);//禁用按钮
        return true;
    }
    catch (const std::exception&)
    {
        return false;
    }
   
}

/// <summary>
/// 电机使能
/// </summary>
void qt_samp_01::btnEnableClicked()
{
    if (isConnected == true)
    {
        acsc_Enable(m_hComm, 0, NULL);
        isEnabled = true;
        setLED(ui.Led_isEnabled, 2, 16);//使能指示灯设置为绿色
    }
    else
    {
        QMessageBox msgBox;   // 生成对象
        msgBox.setText("Please Connect to Controller First!");    // 设置文本
        msgBox.exec();  // 执行
    }
}

/// <summary>
/// 断开使能
/// </summary>
void qt_samp_01::btnDisableClicked()
{
    acsc_Disable(m_hComm, 0, NULL);
    isEnabled = false;
    setLED(ui.Led_isEnabled, 0, 16);//使能指示灯恢复灰色
}




/// <summary>
/// 该函数将label控件变成一个圆形指示灯，需要指定颜色color以及直径size
/// </summary>
/// <param name="label"></param>
/// <param name="color">0:grey 1:red 2:green 3:yellow</param>
/// <param name="size">单位是像素</param>
void qt_samp_01::setLED(QLabel* label, int color, int size)
{
    // 将label中的文字清空
    label->setText("");
    // 先设置矩形大小
    // 如果ui界面设置的label大小比最小宽度和高度小，矩形将被设置为最小宽度和最小高度；
    // 如果ui界面设置的label大小比最小宽度和高度大，矩形将被设置为最大宽度和最大高度；
    QString min_width = QString("min-width: %1px;").arg(size);              // 最小宽度：size
    QString min_height = QString("min-height: %1px;").arg(size);            // 最小高度：size
    QString max_width = QString("max-width: %1px;").arg(size);              // 最小宽度：size
    QString max_height = QString("max-height: %1px;").arg(size);            // 最小高度：size
    // 再设置边界形状及边框
    QString border_radius = QString("border-radius: %1px;").arg(size / 2);    // 边框是圆角，半径为size/2
    QString border = QString("border:1px solid black;");                    // 边框为1px黑色
    // 最后设置背景颜色
    QString background = "background-color:";
    switch (color) {
    case 0:
        // 灰色
        background += "rgb(190,190,190)";
        break;
    case 1:
        // 红色
        background += "rgb(255,0,0)";
        break;
    case 2:
        // 绿色
        background += "rgb(0,255,0)";
        break;
    case 3:
        // 黄色
        background += "rgb(255,255,0)";
        break;
    default:
        break;
    }

    const QString SheetStyle = min_width + min_height + max_width + max_height + border_radius + border + background;
    label->setStyleSheet(SheetStyle);
    
}

