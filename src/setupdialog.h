#ifndef SETUPDIALOG_H
#define SETUPDIALOG_H

#include <QDialog>

namespace Ui {
class setupDialog;
}

class setupDialog : public QDialog
{
    Q_OBJECT

public:
    explicit setupDialog(QWidget *parent = 0);
    ~setupDialog();
	QString getPortName() const;
    int getBaudRate();
    int getParity();
	int getFlowControl();
	int getDataBits();
	int getStopBits();
	int getQueryMode();
	int getTimeout();

private slots:
    void onPortAddedOrRemoved();

private:
    Ui::setupDialog *ui;
};

#endif // SETUPDIALOG_H
