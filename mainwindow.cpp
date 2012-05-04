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

QFile pfile("e:\\log.txt");
QTextStream out;


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    CAknAppUi* appUi = dynamic_cast<CAknAppUi*>(CEikonEnv::Static()->AppUi());
    iPayApi = CPayApi::NewL(*this,appUi);//创建

    pfile.open(QIODevice::WriteOnly);
    out.setDevice(&pfile);

    QTextCodec *codec=QTextCodec::codecForName("utf-16");
    out.setCodec(codec);
}

MainWindow::~MainWindow()
{
    out.flush();
    pfile.close();
    delete ui;
    delete iPayApi; //销毁
}

void MainWindow::on_pushButton_clicked()
{
     out<<"B"<<endl;
    _LIT8(KPoint,"1");
    _LIT8(KAttachment,"1");
    _LIT8(KFee,"100");
    _LIT8(KAppId,"83");
    _LIT8(KDeveloperId,"86");
    iPayApi->IssuePayL(KPoint,KAttachment,KFee,KAppId,KDeveloperId);
    //out<<"C"<<endl;
    iPayApi->GetPayResult(KAttachment);
    //out<<"D"<<endl;
    //out.flush();
    out.flush();
}

//实现MStateHandler的两个函数
void MainWindow::ClientEvent(const TDesC& aEventDescription)
{

}

void MainWindow::PayResult(PAY_RESULT& aResult)
{
    out<<(char *)aResult.aOrderId.Ptr()<<endl;
    out<<aResult.aPayResult<<endl;
    out<<aResult.aErrorCode<<endl;
    out<<(char *)aResult.aMDesc.Ptr()<<endl;
    out.flush();

    ui->label_orderidvalue->setText((char *)aResult.aOrderId.Ptr());
    ui->label_resultvalue->setText(QString(QChar(aResult.aPayResult)));
    ui->label_errorcodevalue->setText(QString(QChar(aResult.aErrorCode)));
    ui->label_desvalue->setText((char *)aResult.aMDesc.Ptr());
}
