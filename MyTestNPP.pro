QT       += core gui

TARGET = basicTestNPP
TEMPLATE = app

SOURCES += main.cpp\
        mainwindow.cpp

HEADERS  += mainwindow.h \
    PayApi.h \
    MStateHandler.h

FORMS    += mainwindow.ui

RESOURCES     = \
    MyTestNPP.qrc


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

VERSION = 1.0.22

symbian {
    TARGET.UID3 = 0xe0436072
    TARGET.EPOCSTACKSIZE = 0x14000
    TARGET.EPOCHEAPSIZE = 0x020000 0x800000
    TARGET.CAPABILITY += NetworkServices
}
