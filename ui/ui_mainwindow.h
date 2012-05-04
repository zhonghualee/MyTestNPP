/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Fri 4. May 16:20:44 2012
**      by: Qt User Interface Compiler version 4.7.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QMainWindow>
#include <QtGui/QPushButton>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QPushButton *pushButton;
    QLabel *label;
    QLabel *label_orderid;
    QLabel *label_errorcode;
    QLabel *label_orderidvalue;
    QLabel *label_errorcodevalue;
    QLabel *label_result;
    QLabel *label_resultvalue;
    QLabel *label_des;
    QLabel *label_desvalue;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(373, 640);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(40, 60, 281, 61));
        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(50, 170, 271, 31));
        label->setAlignment(Qt::AlignCenter);
        label_orderid = new QLabel(centralWidget);
        label_orderid->setObjectName(QString::fromUtf8("label_orderid"));
        label_orderid->setGeometry(QRect(40, 230, 111, 31));
        label_errorcode = new QLabel(centralWidget);
        label_errorcode->setObjectName(QString::fromUtf8("label_errorcode"));
        label_errorcode->setGeometry(QRect(40, 350, 111, 31));
        label_orderidvalue = new QLabel(centralWidget);
        label_orderidvalue->setObjectName(QString::fromUtf8("label_orderidvalue"));
        label_orderidvalue->setGeometry(QRect(220, 230, 53, 16));
        label_errorcodevalue = new QLabel(centralWidget);
        label_errorcodevalue->setObjectName(QString::fromUtf8("label_errorcodevalue"));
        label_errorcodevalue->setGeometry(QRect(220, 360, 53, 16));
        label_result = new QLabel(centralWidget);
        label_result->setObjectName(QString::fromUtf8("label_result"));
        label_result->setGeometry(QRect(40, 290, 101, 20));
        label_resultvalue = new QLabel(centralWidget);
        label_resultvalue->setObjectName(QString::fromUtf8("label_resultvalue"));
        label_resultvalue->setGeometry(QRect(220, 290, 53, 16));
        label_des = new QLabel(centralWidget);
        label_des->setObjectName(QString::fromUtf8("label_des"));
        label_des->setGeometry(QRect(40, 430, 71, 20));
        label_desvalue = new QLabel(centralWidget);
        label_desvalue->setObjectName(QString::fromUtf8("label_desvalue"));
        label_desvalue->setGeometry(QRect(220, 430, 53, 16));
        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("MainWindow", "\346\224\257\344\273\230", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("MainWindow", "\346\224\257\344\273\230\347\273\223\346\236\234", 0, QApplication::UnicodeUTF8));
        label_orderid->setText(QApplication::translate("MainWindow", "\350\256\242\345\215\225\345\217\267", 0, QApplication::UnicodeUTF8));
        label_errorcode->setText(QApplication::translate("MainWindow", "\351\224\231\350\257\257\347\240\201", 0, QApplication::UnicodeUTF8));
        label_orderidvalue->setText(QApplication::translate("MainWindow", "0", 0, QApplication::UnicodeUTF8));
        label_errorcodevalue->setText(QApplication::translate("MainWindow", "0", 0, QApplication::UnicodeUTF8));
        label_result->setText(QApplication::translate("MainWindow", "\346\224\257\344\273\230\347\273\223\346\236\234", 0, QApplication::UnicodeUTF8));
        label_resultvalue->setText(QApplication::translate("MainWindow", "0", 0, QApplication::UnicodeUTF8));
        label_des->setText(QApplication::translate("MainWindow", "\351\224\231\350\257\257\346\217\217\350\277\260", 0, QApplication::UnicodeUTF8));
        label_desvalue->setText(QApplication::translate("MainWindow", "0", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
