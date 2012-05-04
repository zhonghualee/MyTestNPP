#-------------------------------------------------
#
# Project created by QtCreator 2012-05-02T17:50:29
#
#-------------------------------------------------

QT       += core gui

TARGET = MyTestNPP
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp

HEADERS  += mainwindow.h \
    PayApi.h \
    MStateHandler.h

FORMS    += mainwindow.ui

CONFIG += mobility
MOBILITY = 

LIBS += -lApiDll -lcone -lavkon


my_deployment.pkg_postrules.main = "IF NOT package(0x2005B89B)"\
                                     "; install ApiDll_Symbian^3_Production.sis only if not already installed"\
                                     "@\"ApiDll_Symbian^3_Production.sis\", (0x2005B89B)" \
                                     "endif" \
                                    "IF NOT package(0x2005B89E )"\
                                    "; install PayClient.sis only if not already installed"\
                                    "@\"PayClient_Symbian^3_Production.sis\", (0x2005B89E)"\
                                    "endif"
DEPLOYMENT += my_deployment
VERSION = 1.0.19
symbian {
    TARGET.UID3 = 0xe0436072
    TARGET.EPOCSTACKSIZE = 0x14000
    TARGET.EPOCHEAPSIZE = 0x020000 0x800000
}
