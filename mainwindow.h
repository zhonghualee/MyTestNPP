#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "PayApi.h"


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow,public MStateHandler
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    
public:
        void ClientEvent(const TDesC& aEventDescription);
        void PayResult(PAY_RESULT& aResult);

private:
    bool isPaid(QString appId);
    int curAppId;

private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::MainWindow *ui;
    CPayApi* iPayApi;
};

#endif // MAINWINDOW_H
