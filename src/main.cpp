#include <QApplication>
#include <QDebug>
#include <QDir>
#include "embeddedsvgviewer.h"
#include <QDesktopWidget>
#include <QRect>
#include "serialportmanager.h"
#include "config.h"
//#include "uavtalk/telemetrymanager.h"
void printscreeninfo()
{
    QDesktopWidget *dwsktopwidget = QApplication::desktop();
    QRect deskrect = dwsktopwidget->availableGeometry();
    QRect screenrect = dwsktopwidget->screenGeometry();
    int scrcount = dwsktopwidget->screenCount();
    qCritical("screenrect.w==%s screenrect.h==%s\n",qPrintable(QString::number(screenrect.width())),qPrintable(QString::number(screenrect.height())));
    qCritical("deskrect.w==%s deskrect.h==%s\n",qPrintable(QString::number(deskrect.width())),qPrintable(QString::number(deskrect.height())));
    qCritical("screen count==%s\n",qPrintable(QString::number(scrcount)));

}


int main(int argc, char** argv)
{

    QApplication::addLibraryPath("./plugins");
    QApplication app(argc, argv);
    Q_INIT_RESOURCE(embeddedsvgviewer);

    QString filePath;

    printscreeninfo();

    QDir dir;
    QString pathname;
    pathname = dir.currentPath();

    if (argc == 1)
      filePath = QLatin1String("/usr/local/arm/qt-4.8.5/gyroscope/src/res/default.svg");
    else if (argc == 2)
      filePath = argv[1];
    else {
        qDebug() << QLatin1String("Please specify an svg file!");
        return -1;
    }
     filePath = QLatin1String("/usr/local/arm/qt-4.8.5/gyroscope/src/res/default.svg");
    qDebug()<<"filePath:"<<filePath<<endl;
    SerialPortManager serialportManager(new QString("/dev/ttySAC2")); //for ok6410
   // SerialPortManager serialportManager(new QString("/dev/ttyUSB0")); //for PC-ubuntu

    //TelemetryManager *mTelemetryManager = new TelemetryManager;
    //mTelemetryManager->start(serialportManager.port());

    EmbeddedSvgViewer viewer(filePath);
    viewer.connect(&serialportManager,SIGNAL(attitudeReady(float,float,float)),&viewer,SLOT(attitudeHandler(float,float,float)));
    viewer.showFullScreen();
#ifdef QT_KEYPAD_NAVIGATION
    QApplication::setNavigationMode(Qt::NavigationModeCursorAuto);
#endif
    return app.exec();
}
