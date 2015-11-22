#ifndef QLED_H
#define QLED_H

#include <QWidget>

class QColor;

class QLed : public QWidget
{
    Q_OBJECT
public:
    QLed(QWidget *parent = 0);
    ~QLed();

    QColor color() const;
    QSize sizeHint() const;
    QSize minimumSizeHint() const;

public slots:
    void setColor(const QColor &color);
    void toggle();
    void turnOn(bool on=true);
    void turnOff(bool off=true);

protected:
    void paintEvent(QPaintEvent *);
    int ledWidth() const;

private:
    struct Private;
    Private * const m_d;
};

#endif // QLED_H
