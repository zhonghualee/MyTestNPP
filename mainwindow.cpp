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
#include <QMap>

QFile fResult("e:\\log.txt");
QFile fRecord("e:\\paidSuccessRecord.txt");
QTextStream outResult;
QTextStream outRecord;
QMap<QString,int> paidResult;



MainWindow::MainWindow(QWidget *parent) :
    curAppId(-1),
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    //QTextCodec::setCodecForTr(QTextCodec::codecForName("utf8"));

    ui->setupUi(this);
    CAknAppUi* appUi = dynamic_cast<CAknAppUi*>(CEikonEnv::Static()->AppUi());
    iPayApi = CPayApi::NewL(*this,appUi);//创建

    fResult.open(QIODevice::ReadWrite|QIODevice::Append|QIODevice::Text);
    fRecord.open(QIODevice::ReadOnly);
//  fRecord.open(QIODevice::ReadWrite|QIODevice::Append|QIODevice::Text);


    outResult.setDevice(&fResult);
    outRecord.setDevice(&fRecord);

    QTextCodec *codec=QTextCodec::codecForName("utf-8");
    outResult.setCodec(codec);
    outRecord.setCodec(codec);
#if 0
    //wirte paid data
    outRecord<<"87"<<" "<<"1"<<endl;
//  outRecord<<"83"<<" "<<"1"<<endl;
    outRecord.flush();
#else
    //Load results which have been paid
    QString key;
    QString value;

    outResult<<"Begin-"<<endl;

    QString line = outRecord.readLine();

    while (not line.isEmpty()) {
        QStringList list;
        list = line.split((" "));
        bool ok;
        paidResult.insert(list.at(0), list.at(1).toInt(&ok));
        outResult<<list.at(0)<<" "<<list.at(1)<<endl;
        line = outRecord.readLine();
    }
    outResult<<"-End"<<endl;

#endif
    outResult.flush();
    outRecord.flush();
    fRecord.close();
}

MainWindow::~MainWindow()
{
    outResult.flush();
    outRecord.flush();
    fResult.close();
    delete ui;
    delete iPayApi; //销毁
}

bool MainWindow::isPaid(QString appId)
{
    if(paidResult.contains(appId))
    {
        outResult<<"already paid!"<<endl;
        return true;
    }
    else
    {
        outResult<<"not paid yet!"<<endl;
        return false;
    }
}

void MainWindow::on_pushButton_clicked()
{
    outResult<<"Begin"<<endl;
    curAppId = 89;

    _LIT8(KPoint,"1");
    _LIT8(KAttachment,"1");
    _LIT8(KFee,"100");
    _LIT8(KAppId, "89");
    _LIT8(KDeveloperId,"86");


    if(isPaid(QString::number(curAppId)))
    {
        ui->label_desvalue->setText(QString("Paid already"));
    }
    else
    {
        iPayApi->IssuePayL(KPoint,KAttachment,KFee,KAppId,KDeveloperId);
        iPayApi->GetPayResult(KAttachment);
    }

    //查询结果
    //_LIT8(KOrderID,"190");
    //iPayApi->GetPayResult(KOrderID);

    outResult<<"End"<<endl;
    outResult.flush();
}

//实现MStateHandler的两个函数
void MainWindow::ClientEvent(const TDesC& aEventDescription)
{

}

void MainWindow::PayResult(PAY_RESULT& aResult)
{
    outResult<<(char *)aResult.aOrderId.Ptr()<<endl;
    outResult<<aResult.aPayResult<<endl;
    outResult<<aResult.aErrorCode<<endl;
    outResult<<(char *)aResult.aMDesc.Ptr()<<endl;
    outResult.flush();

    //save valid paid status to file
    if(aResult.aPayResult == 1 || aResult.aPayResult == 2)
    {
        paidResult[QString::number(curAppId)]= int(aResult.aPayResult);

        fRecord.open(QIODevice::ReadWrite|QIODevice::Append|QIODevice::Text);
        outRecord.setDevice(&fRecord);
        QTextCodec *codec=QTextCodec::codecForName("utf-8");
        outRecord.setCodec(codec);

        outRecord<<QString::number(curAppId)<<" "<<int(aResult.aPayResult)<<endl;
        fRecord.close();
    }

    outRecord.flush();

    ui->label_orderidvalue->setText((char *)aResult.aOrderId.Ptr());
    ui->label_resultvalue->setText(QString::number(aResult.aPayResult));
    ui->label_errorcodevalue->setText(QString::number(aResult.aErrorCode));
    ui->label_desvalue->setText(QString((char *)aResult.aMDesc.Ptr()).toUtf8());
}
