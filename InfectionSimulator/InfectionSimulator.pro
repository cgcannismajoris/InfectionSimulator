#-------------------------------------------------
#
# Project created by QtCreator 2015-05-04T18:39:36
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets printsupport

TARGET = InfectionSimulator
TEMPLATE = app


SOURCES += main.cpp\
    model/orderedPair.cpp \
    model/virusspread.cpp \
    control/maincontrol.cpp \
    vision/mainwindow.cpp \
    vision/qcustomplot.cpp \
    model/graphdata.cpp \
    model/virusresistance.cpp

HEADERS  += \
    model/orderedPair.h \
    model/virusspread.h \
    vision/qcustomplot.h \
    control/maincontrol.h \
    vision/mainwindow.h \
    vision/qcustomplot.h \
    model/graphdata.h \
    model/virusresistance.h

FORMS    += \
    vision/mainwindow.ui

OTHER_FILES +=


# Inclui a biblioteca do QWT e a regra de linkagem
INCLUDEPATH += /usr/local/qwt-6.1.3-svn/include
LIBS += -L/usr/local/qwt-6.1.3-svn/lib -lqwt
