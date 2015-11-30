#ifndef ATTITUDELABEL_H
#define ATTITUDELABEL_H
#include<QLabel>
#include<QMovie>
class AttitudeLabel : public QLabel
{
public:
    AttitudeLabel();
    AttitudeLabel(QString defaultText,
                                 QWidget *parent,
                                 QRect geometry,
                                QString styleSheet,
                                 QPalette pe,
                                 bool isAutoFillBackground,
                                 QString moviePath,QSize movieSize,bool isStartMovie);
signals:

public slots:

};

#endif // ATTITUDELABEL_H
