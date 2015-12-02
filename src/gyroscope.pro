#-------------------------------------------------
#
# Project created by QtCreator 2014-04-12T12:07:52
#
#-------------------------------------------------

QT       += core gui
QT += svg
QT           += network widget
#QT += opengl
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = gyroscope
TEMPLATE = app

include(./qextserialport/qextserialport.pri)

SOURCES += main.cpp\
        mainwindow.cpp \
    qled.cpp \
    setupdialog.cpp \
    execdialog.cpp \
    embeddedsvgviewer.cpp \
    serialportmanager.cpp \
    modelviewgadgetwidget.cpp \
    attitudelabel.cpp \
    videoclient.cpp \
    gcstelemetrystatslabel.cpp \
    UAVObjGyroscopeHandler.cpp

HEADERS  += mainwindow.h \
    qled.h \
    setupdialog.h \
    execdialog.h \
    embeddedsvgviewer.h \
    serialportmanager.h \
    modelviewgadgetwidget.h \
    attitudelabel.h \
    videoclient.h \
    config.h \
    gcstelemetrystatslabel.h \
    UAVObjGyroscopeHandler.h

FORMS    += mainwindow.ui \
    setupdialog.ui \
    execdialog.ui

RESOURCES += \
    mainwindow.qrc \
    embeddedsvgviewer.qrc \
    ModelViewGadgetWidget.qrc


#unix:!macx: LIBS += -L$$PWD/glc_lib/ -lGLC_lib

#INCLUDEPATH += $$PWD/glc_lib
#DEPENDPATH += $$PWD/glc_lib
