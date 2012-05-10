#include "mainwindow.h"
#include "ui_mainwindow.h"

#ifdef Q_OS_SYMBIAN
#include <eikenv.h>
#include <eikappui.h>
#include <aknenv.h>
#include <aknappui.h>
#include <e32base.h>
#endif

#include <QFile>
#include <QTextCodec>
#include <QByteArray>
#include <QtGui>

const int appId = 89;

QFile fRecord(QApplication::applicationDirPath() + "/paidSuccessRecord.txt");

MainWindow::MainWindow(QWidget *parent) :    
    pictureShow(false),
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    CAknAppUi* appUi = dynamic_cast<CAknAppUi*>(CEikonEnv::Static()->AppUi());
    iPayApi = CPayApi::NewL(*this,appUi);

    fRecord.open(QIODevice::ReadOnly);
    outRecord.setDevice(&fRecord);
    QTextCodec *codec=QTextCodec::codecForName("utf-8");
    outRecord.setCodec(codec);

    //Load results which have been paid
    QString key;
    QString value;
    QString line = outRecord.readLine();
    while (not line.isEmpty())
    {
        QStringList list;
        list = line.split((" "));
        bool ok;
        paidResult.insert(list.at(0), list.at(1).toInt(&ok));
        line = outRecord.readLine();
    }
    outRecord.flush();
    fRecord.close();

    pixmap.load(":/images/paid.png");

    if(isPaid(QString::number(appId)))
    {
        pictureShow = true;
    }
}

MainWindow::~MainWindow()
{   
    outRecord.flush();

    delete ui;
    delete iPayApi;
}

bool MainWindow::isPaid(QString appId)
{
    return paidResult.contains(appId);
}

void MainWindow::ClientEvent(const TDesC& aEventDescription)
{
}

void MainWindow::PayResult(PAY_RESULT& aResult)
{
    //save successful paid status to file
    if(aResult.aPayResult == 1 || aResult.aPayResult == 2)
    {
        paidResult[QString::number(appId)]= int(aResult.aPayResult);

        fRecord.open(QIODevice::ReadWrite|QIODevice::Append|QIODevice::Text);
        outRecord.setDevice(&fRecord);
        QTextCodec *codec=QTextCodec::codecForName("utf-8");
        outRecord.setCodec(codec);

        outRecord<<QString::number(appId)<<" "<<int(aResult.aPayResult)<<endl;
        outRecord.flush();
        fRecord.close();
    }
}

void MainWindow::on_pushButton_clicked()
{    
    _LIT8(KPoint,"1");
    _LIT8(KAttachment,"1");
    _LIT8(KFee,"100");
    _LIT8(KAppId, "89");
    _LIT8(KDeveloperId,"86");

    if(isPaid(QString::number(appId)))
    {
        pictureShow = true;
        update();
    }
    else
    {
        pictureShow = false;
        iPayApi->IssuePayL(KPoint,KAttachment,KFee,KAppId,KDeveloperId);
        iPayApi->GetPayResult(KAttachment);
    }
}

void MainWindow::paintEvent(QPaintEvent *event)
{
    if(pictureShow)
    {
        QPainter painter(this);
        painter.setRenderHint(QPainter::Antialiasing, false);
        painter.drawPixmap(60, 130, pixmap);
    }
}
