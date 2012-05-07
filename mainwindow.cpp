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
#include <QTextStream>

QFile fResult("e:\\log.txt");
QFile fRecord("e:\\paidSuccessRecord.txt");
QTextStream outResult;
QTextStream outRecord;


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    CAknAppUi* appUi = dynamic_cast<CAknAppUi*>(CEikonEnv::Static()->AppUi());
    iPayApi = CPayApi::NewL(*this,appUi);//创建

    fResult.open(QIODevice::WriteOnly|QIODevice::Append);
    fRecord.open(QIODevice::WriteOnly|QIODevice::Append);

    outResult.setDevice(&fResult);
    outRecord.setDevice(&fRecord);


    QTextCodec *codec=QTextCodec::codecForName("utf-16");
    outResult.setCodec(codec);
    outRecord.setCodec(codec);
}

MainWindow::~MainWindow()
{
    outResult.flush();
    outRecord.flush();
    fResult.close();
    fRecord.close();
    delete ui;
    delete iPayApi; //销毁
}

void MainWindow::on_pushButton_clicked()
{
     outResult<<"A"<<endl;
    _LIT8(KPoint,"1");
    _LIT8(KAttachment,"1");
    _LIT8(KFee,"100");
    _LIT8(KAppId,"87");
    _LIT8(KDeveloperId,"86");

    iPayApi->IssuePayL(KPoint,KAttachment,KFee,KAppId,KDeveloperId);
    iPayApi->GetPayResult(KAttachment);

    //查询结果结果
    //_LIT8(KOrderID,"190");
    //iPayApi->GetPayResult(KOrderID);

    outResult<<"E"<<endl;
    outResult.flush();
}

//实现MStateHandler的两个函数
void MainWindow::ClientEvent(const TDesC& aEventDescription)
{

}

void MainWindow::PayResult(PAY_RESULT& aResult)
{
    outResult<<"B"<<endl;
    outResult<<(char *)aResult.aOrderId.Ptr()<<endl;
    outResult<<"B"<<endl;
    outResult<<aResult.aPayResult<<endl;
    outResult<<"B"<<endl;
    outResult<<aResult.aErrorCode<<endl;
    outResult<<"B"<<endl;
    outResult<<(char *)aResult.aMDesc.Ptr()<<endl;
    outResult<<"BBBBB"<<endl;
    outResult.flush();

    ui->label_orderidvalue->setText((char *)aResult.aOrderId.Ptr());
    ui->label_resultvalue->setText(QString::number(aResult.aPayResult));
    ui->label_errorcodevalue->setText(QString::number(aResult.aErrorCode));
    ui->label_desvalue->setText(QString((char *)aResult.aMDesc.Ptr()).toUtf8());
}
