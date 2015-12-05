#ifndef GCSTELEMETRYSTATSLABEL_H
#define GCSTELEMETRYSTATSLABEL_H

#include<QLabel>
class GCSTelemetryStatsLabel : public QLabel
{
public:
    GCSTelemetryStatsLabel();
    GCSTelemetryStatsLabel(QString defaultText,
                                                   QWidget *parent,
                                                   QRect geometry,
                                                  QString styleSheet,
                                                   QPalette pe);
signals:

public slots:
};

#endif // GCSTELEMETRYSTATSLABEL_H
