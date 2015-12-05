#-------------------------------------------------
#
# Project created by QtCreator 2014-04-12T12:07:52
#
#-------------------------------------------------

QT       += core gui svg network
QT       += widget
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
    videoclient.cpp \
    monitorwidget.cpp \
#    uavtalk/telemetry.cpp \
#    uavtalk/telemetrymanager.cpp \
#    uavtalk/telemetrymonitor.cpp \
#    uavtalk/uavtalk.cpp \
#    uavtalk/uavobject.cpp \
#    uavobjects/uavdataobject.cpp \
#    uavobjects/uavmetaobject.cpp \
#    uavobjects/uavobject.cpp \
#    uavobjects/uavobjectfield.cpp \
#    uavobjects/uavobjectmanager.cpp

HEADERS  += mainwindow.h \
    qled.h \
    setupdialog.h \
    execdialog.h \
    embeddedsvgviewer.h \
    serialportmanager.h \
    modelviewgadgetwidget.h \
    videoclient.h \
    config.h \
    monitorwidget.h \
#    uavtalk/telemetry.h \
#    uavtalk/telemetrymanager.h \
#    uavtalk/telemetrymonitor.h \
#    uavtalk/uavtalk.h \
#    uavtalk/uavtalk_global.h \
#    uavtalk/uavobject.h \
#    uavobjects/uavdataobject.h \
#    uavobjects/uavmetaobject.h \
#    uavobjects/uavobject.h \
#    uavobjects/uavobjectfield.h \
#    uavobjects/uavobjectmanager.h \
#    uavobjects/uavobjects_global.h \
#    uavobjects/uavobjectsinit.h

FORMS    += mainwindow.ui \
    setupdialog.ui \
    execdialog.ui

RESOURCES += \
    mainwindow.qrc \
    embeddedsvgviewer.qrc \
    ModelViewGadgetWidget.qrc

