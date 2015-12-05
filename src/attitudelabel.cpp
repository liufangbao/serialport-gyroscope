#include "attitudelabel.h"
 #include <QColor>

AttitudeLabel::AttitudeLabel()
{

}

//AttitudeLabel::AttitudeLabel("pitchlabel",this,labelSize,ft,pe1,true,pitchRect)
AttitudeLabel::AttitudeLabel(QString defaultText,
                             QWidget *parent,
                             QRect geometry,
                            QString styleSheet,
                             QPalette pe,
                             bool isAutoFillBackground,
                             QString moviePath,QSize movieSize,bool isStartMovie)
{
    this->setParent(parent);
    this->setText(defaultText);
    setAutoFillBackground(isAutoFillBackground);
    setGeometry(geometry);
    setPalette(pe);
   setStyleSheet(styleSheet);
    if(NULL!=moviePath)
    {
        QMovie *mMovie=new QMovie(moviePath);
        mMovie->setScaledSize(movieSize);
        if(isStartMovie)
        {
            setMovie(mMovie);
             mMovie->start();
        }
    }
}

