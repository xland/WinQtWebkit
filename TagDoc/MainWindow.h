#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
protected:
    bool nativeEvent(const QByteArray &eventType, void *message, long *result);
private slots:
    void on_ResizeBtn_released();

    void on_SetBtn_released();

    void on_MinBtn_released();

    void on_CloseBtn_released();

private:
    Ui::MainWindow *ui;
        bool maxFlag;
};

#endif // MAINWINDOW_H
