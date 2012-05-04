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

private slots:
    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    CPayApi* iPayApi;
};

#endif // MAINWINDOW_H
