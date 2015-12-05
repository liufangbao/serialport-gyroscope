#include "gcstelemetrystatslabel.h"

GCSTelemetryStatsLabel::GCSTelemetryStatsLabel()
{

}

GCSTelemetryStatsLabel::GCSTelemetryStatsLabel(QString defaultText,
                                               QWidget *parent,
                                               QRect geometry,
                                              QString styleSheet,
                                               QPalette pe)
{
    this->setParent(parent);
    this->setText(defaultText);
    setGeometry(geometry);
    setPalette(pe);
   setStyleSheet(styleSheet);
}

