#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QPixmap>
#include <QMainWindow>
#include <QMap>
#include <QTextStream>

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
protected:
    void paintEvent(QPaintEvent *);

private:
    bool isPaid(QString appId);

private slots:
    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    CPayApi* iPayApi;

    QPixmap pixmap;
    int curAppId;
    bool pictureShow;
    QTextStream outRecord;
    QMap<QString,int> paidResult;
};

#endif // MAINWINDOW_H
