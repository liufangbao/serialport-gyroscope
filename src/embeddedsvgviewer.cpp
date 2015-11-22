#include "embeddedsvgviewer.h"
#include <qmath.h>
#include<QTimer>
#include <QKeyEvent>
#include <QTextFormat>
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

#include <QPainter>
#include <QApplication>
#include <QDebug>
#include "embeddedsvgviewer.h"
#include <QDesktopWidget>
#include <QPoint>
#include <QDir>
#include<QLabel>
#include<QMovie>
EmbeddedSvgViewer::EmbeddedSvgViewer(const QString &filePath):AH_Painter(this),Dial_Painter(this),FixedHorizonTrans_Painter(this)
{
    qApp->setStyleSheet(" QSlider:vertical { width: 50px; } \
                          QSlider::groove:vertical { border: 1px solid black; border-radius: 3px; width: 6px; } \
                          QSlider::handle:vertical { height: 25px; margin: 0 -22px; image: url('://res/v-slider-handle.svg'); } \
                       ");
      QDesktopWidget *dwsktopwidget = QApplication::desktop();
     QRect deskrect = dwsktopwidget->availableGeometry();    //desktop size
     QRect screenrect = dwsktopwidget->screenGeometry();   //screen size
    mScreencenter.setX(screenrect.width()/2);
    mScreencenter.setY(screenrect.height()/2);

    m_renderer = new QSvgRenderer(filePath);
    m_imageSize = m_renderer->viewBox().size();

    m_viewBoxCenter = (QPointF(m_imageSize.width() / qreal(2.0), m_imageSize.height() / qreal(2.0)));

    m_zoomSlider = new QSlider(Qt::Vertical, this);
    m_zoomSlider->setMaximum(150);
    m_zoomSlider->setMinimum(1);

    connect(m_zoomSlider, SIGNAL(valueChanged(int)), this, SLOT(setZoom(int)));
    m_zoomSlider->setValue(100);

    if (m_renderer->animated())
        connect(m_renderer, SIGNAL(repaintNeeded()), this, SLOT(update()));

    QDir dir;
    QString pathname;
    pathname = dir.currentPath();
   qDebug()<<"CurrentPath:"<<pathname;

    QString AH_PATH = ":/Gyroscope/res/AH1.png";
   qDebug()<<"laoding AH.png from "<<AH_PATH;
      AH.load(AH_PATH);

      QString FixedHorizonTrans_PATH = ":/Gyroscope/res/FixedHorizonTrans.png";
      qDebug()<<"laoding FixedHorizonTrans.png from "<<FixedHorizonTrans_PATH;
      FixedHorizonTrans .load(FixedHorizonTrans_PATH);

      QString Dial_PATH = ":/Gyroscope/res/Dial.png";
        qDebug()<<"laoding Dial.png from "<<Dial_PATH;
        Dial.load(Dial_PATH);

        QSize gyroscopeAreaSize(screenrect.width()/2,screenrect.width()/2);
        QMatrix rotateMatrix;
         rotateMatrix.rotate(-90);
        AH=AH.transformed(rotateMatrix);
        AH=AH.scaledToWidth(gyroscopeAreaSize.width());
        qDebug()<<"AH size:"<<AH.width()<<AH.height();

      //  FixedHorizonTrans=FixedHorizonTrans.scaledToWidth(screenrect.height()).scaledToHeight(screenrect.height());
        FixedHorizonTrans=FixedHorizonTrans.scaled(gyroscopeAreaSize);
        qDebug()<<"FixedHorizonTrans size:"<<FixedHorizonTrans.width()<<FixedHorizonTrans.height();

        //Dial=Dial.scaledToWidth(screenrect.height()).scaledToHeight(screenrect.height());
        Dial=Dial.scaled(gyroscopeAreaSize);
        qDebug()<<"Dial size:"<<Dial.width()<<Dial.height();

        mTimer = new QTimer();
        mTimer->setInterval(40);
        connect(mTimer, SIGNAL(timeout()),SLOT(update()));
        mTimer->start();

        QSize labelSize(    screenrect.width()/12,screenrect.width()/12);
        QRect pitchRect(0,screenrect.width()/2,
                        screenrect.width()/12,screenrect.height()-screenrect.width()/2);
         mPitchLabel = new QLabel("pitchlabel",this);
         mPitchLabel->setAutoFillBackground(true);
         mPitchLabel->setGeometry(pitchRect);
         mPitchLabel->setPixmap(AH);
         QPalette pe1;
         pe1.setColor(QPalette::WindowText,Qt::green);
         mPitchLabel->setPalette(pe1);
         mPitchLabel->setText("Pitch");

         mPitchMovie=new QMovie(":/Gyroscope/res/pitch.gif");
         mPitchMovie->setScaledSize(labelSize);
         mPitchLabel->setMovie(mPitchMovie);
         mPitchMovie->start();

         QRect pitchValueRect(screenrect.width()/12,screenrect.width()/2,
                         screenrect.width()/12,screenrect.height()-screenrect.width()/2);
         mPitchLabelValue = new QLabel("pitchlabelvalue",this);
         mPitchLabelValue->setGeometry(pitchValueRect);
         mPitchLabelValue->setStyleSheet(QString::fromUtf8("font: 15pt \"Sans Serif\";"));

        QRect rollRect(screenrect.width()/6,screenrect.width()/2,
                     screenrect.width()/12,screenrect.height()-screenrect.width()/2);
        QRect rollValueRect(screenrect.width()/6+screenrect.width()/12,screenrect.width()/2,
                     screenrect.width()/12,screenrect.height()-screenrect.width()/2);
         mRollLabel = new QLabel("rolllabel",this);
         mRollLabelValue = new QLabel("rolllabelvalue",this);
         mRollLabel->setAutoFillBackground(true);
         mRollLabel->setGeometry(rollRect);
         mRollLabelValue->setGeometry(rollValueRect);
         mRollLabelValue->setStyleSheet(QString::fromUtf8("font: 15pt \"Sans Serif\";"));
         mRollLabel->setPixmap(FixedHorizonTrans);
         QPalette pe2;
         pe2.setColor(QPalette::WindowText,Qt::green);
         mRollLabel->setPalette(pe2);
         mRollLabel->setText("Roll");
         mRollMovie=new QMovie(":/Gyroscope/res/roll.gif");
         mRollLabel->setMovie(mRollMovie);
         mRollMovie->setScaledSize(labelSize);
         mRollMovie->start();

        QRect yawRect(screenrect.width()/3,screenrect.width()/2,
                      screenrect.width()/12,screenrect.height()-screenrect.width()/2);
        QRect yawRectValue(screenrect.width()/3+screenrect.width()/12,screenrect.width()/2,
                      screenrect.width()/12,screenrect.height()-screenrect.width()/2);
         mYawLabel = new QLabel("yawlabel",this);
         mYawLabelValue = new QLabel("yawlabelvalue",this);
        mYawLabel->setAutoFillBackground(true);
        mYawLabel->setGeometry(yawRect);
         mYawLabelValue->setStyleSheet(QString::fromUtf8("font: 15pt \"Sans Serif\";"));
        mYawLabelValue->setGeometry(yawRectValue);
        mYawLabel->setPixmap(Dial);
        QPalette pe3;
        pe3.setColor(QPalette::WindowText,Qt::blue);
        mYawLabel->setPalette(pe3);
        mYawLabel->setText("Yaw");
        mYawMovie=new QMovie(":/Gyroscope/res/yaw.gif");
        mYawLabel->setMovie(mYawMovie);
        mYawMovie->setScaledSize(labelSize);
        mYawMovie->start();

       m_quitButton = new QPushButton("Quit", this);
        QRect quitButtonRect(mScreencenter.x()+FixedHorizonTrans.width()/2,
                                                  3*mScreencenter.y()/2,
                                                  mScreencenter.x()-FixedHorizonTrans.width()/2,
                                                  mScreencenter.y()/2);
      // m_quitButton->setGeometry(quitButtonRect);
       connect(m_quitButton, SIGNAL(pressed()), QApplication::instance(), SLOT(quit()));

       mModelViewGadgetWidget = new ModelViewGadgetWidget(this);
       QRect ModelViewRect(screenrect.width()/2,0,
                                                screenrect.width()/2,screenrect.width()/2);
       mModelViewGadgetWidget->setGeometry(ModelViewRect);

   //    mModelViewGadgetWidget->reloadScene();
       connect(this, SIGNAL(updateModelView(QByteArray)), mModelViewGadgetWidget, SLOT(serialPortHandler(QByteArray)));
}

void EmbeddedSvgViewer::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event)
    QPainter painter(this);
    m_renderer->setViewBox(m_viewBox);
    m_renderer->render(&painter);

    qreal pitch,roll,yaw;
     pitch = mAttitudeState.Pitch;
     roll = mAttitudeState.Roll;
     yaw = mAttitudeState.Yaw;

     mPitchLabelValue->setText(QString("%1").arg(mAttitudeState.Pitch));
     mRollLabelValue->setText(QString("%1").arg(mAttitudeState.Roll));
     mYawLabelValue->setText(QString("%1").arg(mAttitudeState.Yaw));

  //  painter.translate(mScreencenter);
    painter.translate(FixedHorizonTrans.width()/2,FixedHorizonTrans.height()/2);

     painter.rotate(-roll);
     QRect AHTargetArea(-AH.width()/2,
                        -FixedHorizonTrans.height()/2,
                        AH.width(),
                        FixedHorizonTrans.height());
     QRect AH_SourceSection(0,
                          (AH.height()-FixedHorizonTrans.height())/2-pitch*AH.height()/180,
                          AH.width(),
                          FixedHorizonTrans.height());
     painter.drawPixmap(AHTargetArea,
                        AH,
                        AH_SourceSection);

    painter.rotate(roll);
    painter.drawPixmap(-FixedHorizonTrans.width()/2,-FixedHorizonTrans.height()/2,FixedHorizonTrans.width(),FixedHorizonTrans.height(),FixedHorizonTrans);

    painter.rotate(yaw);
    painter.drawPixmap(-Dial.width()/2,-Dial.height()/2,Dial.width(),Dial.height(),Dial);


}


void EmbeddedSvgViewer::mouseMoveEvent ( QMouseEvent * event )
{
    int incX = int((event->globalX() - m_mousePress.x()) * m_imageScale);
    int incY = int((event->globalY() - m_mousePress.y()) * m_imageScale);

    QPointF newCenter;
    newCenter.setX(m_viewBoxCenterOnMousePress.x() - incX);
    newCenter.setY(m_viewBoxCenterOnMousePress.y() - incY);

    QRectF newViewBox = getViewBox(newCenter);


    // Do a bounded move on the horizontal:
    if ( (newViewBox.left() >= m_viewBoxBounds.left()) &&
         (newViewBox.right() <= m_viewBoxBounds.right()) )
    {
        m_viewBoxCenter.setX(newCenter.x());
        m_viewBox.setLeft(newViewBox.left());
        m_viewBox.setRight(newViewBox.right());
    }

    // do a bounded move on the vertical:
    if (  (newViewBox.top() >= m_viewBoxBounds.top()) &&
          (newViewBox.bottom() <= m_viewBoxBounds.bottom()) )
    {
        m_viewBoxCenter.setY(newCenter.y());
        m_viewBox.setTop(newViewBox.top());
        m_viewBox.setBottom(newViewBox.bottom());
    }

    update();
}

void EmbeddedSvgViewer::mousePressEvent ( QMouseEvent * event )
{
    m_viewBoxCenterOnMousePress = m_viewBoxCenter;
    m_mousePress = event->globalPos();
}


QRectF EmbeddedSvgViewer::getViewBox(QPointF viewBoxCenter)
{
    QRectF result;
    result.setLeft(viewBoxCenter.x() - (m_viewBoxSize.width() / 2));
    result.setTop(viewBoxCenter.y() - (m_viewBoxSize.height() / 2));
    result.setRight(viewBoxCenter.x() + (m_viewBoxSize.width() / 2));
    result.setBottom(viewBoxCenter.y() + (m_viewBoxSize.height() / 2));
    return result;
}

void EmbeddedSvgViewer::keyPressEvent(QKeyEvent *event)
{
//    qDebug()<<"key value:"<<hex<<event->key();
  if(event->key() == Qt::Key_Left)
  {
    if(event->modifiers() == Qt::ControlModifier)
      {;}
    else
      {;}
    event->accept();
    return;
  }

  if(event->key() == Qt::Key_Right)
  {
    if(event->modifiers() == Qt::ControlModifier)
      {;}
    else
     {;}
    event->accept();
    return;
  }

  if (event->key() == Qt::Key_Enter || event->key() == Qt::Key_Select ||event->key() == Qt::Key_Return) {
    qApp->quit();;
    event->accept();
    return;
  }

  event->ignore();
}

void EmbeddedSvgViewer::updateImageScale()
{
    m_imageScale = qMax( (qreal)m_imageSize.width() / (qreal)width(),
                               (qreal)m_imageSize.height() / (qreal)height())*m_zoomLevel;

    m_viewBoxSize.setWidth((qreal)width() * m_imageScale);
    m_viewBoxSize.setHeight((qreal)height() * m_imageScale);
}


void EmbeddedSvgViewer::resizeEvent ( QResizeEvent * /* event */ )
{
    qreal origZoom = m_zoomLevel;

    // Get the new bounds:
    m_zoomLevel = 1.0;
    updateImageScale();
    m_viewBoxBounds = getViewBox(QPointF(m_imageSize.width() / 2.0, m_imageSize.height() / 2.0));

    m_zoomLevel = origZoom;
    updateImageScale();
    m_viewBox = getViewBox(m_viewBoxCenter);

    QRect sliderRect;
    sliderRect.setLeft(width() - m_zoomSlider->sizeHint().width());
    sliderRect.setRight(width());
    sliderRect.setTop(height()/4);
    sliderRect.setBottom(height() - (height()/4));
    m_zoomSlider->setGeometry(sliderRect);
}


void EmbeddedSvgViewer::setZoom(int newZoom)
{
    m_zoomLevel = qreal(newZoom) / qreal(100);

    updateImageScale();
    m_viewBox = getViewBox(m_viewBoxCenter);

    update();
}

/*
recognise packet and fetch data from it
*/
void EmbeddedSvgViewer::serialPortHandler(QByteArray array)
{
    float q0,q1,q2,q3,Pitch,Roll,Yaw;
 //   mModelViewGadgetWidget->serialPortHandler(array);
    memcpy(&mAttitudeState,array,sizeof(AttitudeStateDataPacked));
    mPitchLabelValue->setText(QString("%1").arg(mAttitudeState.Pitch));
    mRollLabelValue->setText(QString("%1").arg(mAttitudeState.Roll));
    mYawLabelValue->setText(QString("%1").arg(mAttitudeState.Yaw));

    updateModelView(array);

     q0=mAttitudeState.q1;
     q1=mAttitudeState.q2;
     q2=mAttitudeState.q3;
     q3=mAttitudeState.q4;
     Pitch=mAttitudeState.Pitch;
     Roll=mAttitudeState.Roll;
     Yaw=mAttitudeState.Yaw;

    if((abs(Pitch - asin(-2 * q1 * q3 + 2 * q0* q2)* 57.3)<10e-3) // pitch
    &&(abs(Roll - atan2(2 * q2 * q3 + 2 * q0 * q1, -2 * q1 * q1 - 2 * q2* q2 + 1)* 57.3)<10e-3) // roll
    &&(abs(Yaw - atan2(2*(q1*q2 + q0*q3),q0*q0+q1*q1-q2*q2-q3*q3) * 57.3)<10e-3))		//yaw
    {
        update();
    }

 //   qDebug()<<"q1:"<<mAttitudeState.q1<<"q2:"<<mAttitudeState.q2<<"q3:"<<mAttitudeState.q3<<"q4:"<<mAttitudeState.q4<<endl;
  //  qDebug()<<"pitch:"<<mAttitudeState.Pitch<<"roll:"<<mAttitudeState.Roll<<"yaw:"<<mAttitudeState.Yaw<<endl;
}

