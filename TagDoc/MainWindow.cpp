#include "MainWindow.h"
#include "ui_MainWindow.h"
#include <windowsx.h>
#include <windows.h>
#include <IconHelper.h>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->TitleLable->setAttribute(Qt::WA_TransparentForMouseEvents,true);
    IconHelper::Instance()->SetIcon(ui->CloseBtn,QChar(0xf00d),9);
    IconHelper::Instance()->SetIcon(ui->ResizeBtn,QChar(0xf079),9);
    IconHelper::Instance()->SetIcon(ui->MinBtn,QChar(0xf068),9);
    IconHelper::Instance()->SetIcon(ui->SetBtn,QChar(0xf0c9),9);
    QUrl url("http://www.baidu.com");
    ui->webView->load(url);
}
bool MainWindow::nativeEvent(const QByteArray &eventType, void *message, long *result)
{
    if(eventType=="windows_generic_MSG")
    {
        const MSG *msg=static_cast<MSG*>(message);
        if(msg->message == WM_NCLBUTTONDBLCLK)
        {
            on_ResizeBtn_released();
            return true;
        }
        else if(msg->message==WM_NCHITTEST)
        {
            int xPos = GET_X_LPARAM(msg->lParam) - this->frameGeometry().x();
            int yPos = GET_Y_LPARAM(msg->lParam) - this->frameGeometry().y();
            QWidget* pt = this->childAt(xPos,yPos);
            if(pt == ui->HeaderLeftContainer)
            {
                *result = HTCAPTION;
                return true;
            }
            else
            {
                if(xPos > 0 && xPos < 6)
                {
                    *result = HTLEFT;
                }
                if(xPos > (this->width() - 6) && xPos < (this->width() - 0))
                {
                    *result = HTRIGHT;
                }
                if(yPos > 0 && yPos < 6)
                {
                    *result = HTTOP;
                }

                if(yPos > (this->height() - 6) && yPos < (this->height() - 0))
                {
                    *result = HTBOTTOM;
                }
                if(xPos > 0 && xPos < 6 && yPos > 0 && yPos < 6)
                {
                    *result = HTTOPLEFT;
                }
                if(xPos > (this->width() - 6) && xPos < (this->width() - 0) && yPos > 0 && yPos < 6)
                {
                    *result = HTTOPRIGHT;
                }

                if(xPos > 0 && xPos < 6 && yPos > (this->height() - 6) && yPos < (this->height() - 0))
                {
                    *result = HTBOTTOMLEFT;
                }

                if(xPos > (this->width() - 6) && xPos < (this->width() - 0) && yPos > (this->height() - 6) && yPos < (this->height() - 0))
                {
                    *result = HTBOTTOMRIGHT;
                }
                if(*result)
                {
                    return true;
                }
            }
        }
    }
    return false;
}
MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_ResizeBtn_released()
{
    if(maxFlag)
    {
        this->showNormal();
        maxFlag = false;
    }
    else
    {
        this->showMaximized();
        maxFlag = true;
    }
}

void MainWindow::on_SetBtn_released()
{
    ui->webView->reload();
}

void MainWindow::on_MinBtn_released()
{
 this->showMinimized();
}

void MainWindow::on_CloseBtn_released()
{
    QApplication* app;
    app->quit();
}
