/****************************************************************************
**
** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies).
** Contact: http://www.qt-project.org/legal
**
** This file is part of the demonstration applications of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:LGPL$
** Commercial License Usage
** Licensees holding valid commercial Qt licenses may use this file in
** accordance with the commercial license agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and Digia.  For licensing terms and
** conditions see http://qt.digia.com/licensing.  For further information
** use the contact form at http://qt.digia.com/contact-us.
**
** GNU Lesser General Public License Usage
** Alternatively, this file may be used under the terms of the GNU Lesser
** General Public License version 2.1 as published by the Free Software
** Foundation and appearing in the file LICENSE.LGPL included in the
** packaging of this file.  Please review the following information to
** ensure the GNU Lesser General Public License version 2.1 requirements
** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html.
**
** In addition, as a special exception, Digia gives you certain additional
** rights.  These rights are described in the Digia Qt LGPL Exception
** version 1.1, included in the file LGPL_EXCEPTION.txt in this package.
**
** GNU General Public License Usage
** Alternatively, this file may be used under the terms of the GNU
** General Public License version 3.0 as published by the Free Software
** Foundation and appearing in the file LICENSE.GPL included in the
** packaging of this file.  Please review the following information to
** ensure the GNU General Public License version 3.0 requirements will be
** met: http://www.gnu.org/copyleft/gpl.html.
**
**
** $QT_END_LICENSE$
**
****************************************************************************/

#ifndef EMBEDDED_SVG_VIEWER_H
#define EMBEDDED_SVG_VIEWER_H

#include <QWidget>
#include <QString>
#include <QSvgRenderer>
#include <QSize>
#include <QMouseEvent>
#include <QSlider>
#include <QPushButton>
#include <QPainter>
#include <QKeyEvent>
#include<QLabel>
#include "modelviewgadgetwidget.h"
#include"videoclient.h"
#include"config.h"
#include"monitorwidget.h"
class EmbeddedSvgViewer : public QWidget
{
    Q_OBJECT
public:
    EmbeddedSvgViewer(const QString& filePath);
    virtual void paintEvent(QPaintEvent *event);
    void mouseMoveEvent ( QMouseEvent * event );
    void mousePressEvent ( QMouseEvent * event );
    void resizeEvent ( QResizeEvent * event );
signals:
    void updateModelView(QByteArray);
    void telemetryConnected();
    void telemetryDisconnected();
    void telemetryUpdated(double txRate, double rxRate);
public slots:
    void setZoom(int); // 100 <= newZoom < 0
    void attitudeHandler(float,float,float);
    void showVideoView(QString);
private:
    QSvgRenderer* m_renderer;
    QSlider* m_zoomSlider;
    QPushButton* m_quitButton;
    QSize m_imageSize;
    qreal m_zoomLevel;
    qreal m_imageScale; // How many Image coords 1 widget pixel is worth

    QRectF m_viewBox;
    QRectF m_viewBoxBounds;
    QSizeF m_viewBoxSize;
    QPointF m_viewBoxCenter;
    QPointF m_viewBoxCenterOnMousePress;
    QPoint m_mousePress;
    typedef struct {
        float Pitch;
        float Roll;
        float Yaw;
    } AttitudeState;
    AttitudeState mAttitudeState;

    QPoint mScreencenter;
     QPixmap AH,Dial,FixedHorizonTrans;
     qreal AH_X,AH_Y,FixedHorizonTrans_X,FixedHorizonTrans_Y,Dial_X,Dial_Y;
     QPainter AH_Painter,Dial_Painter,FixedHorizonTrans_Painter;

      QTimer *mTimer,*quitButtonTimer;
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

      };
     AttitudeLabel *mPitchLabel,*mRollLabel,*mYawLabel;
     AttitudeLabel *mPitchLabelValue,*mRollLabelValue,*mYawLabelValue;
     QLabel *videoView;
     VideoClient *vc;
#if USE_GLC_LIB
     ModelViewGadgetWidget *mModelViewGadgetWidget;
#endif
    MonitorWidget *mMonitorWidget;

    void updateImageScale();
    QRectF getViewBox(QPointF viewBoxCenter);

    // QWidget interface
protected:
    virtual void keyPressEvent(QKeyEvent *);
};



#endif

