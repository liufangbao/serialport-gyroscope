#include "qextserialport/qextserialport.h"
#include "qextserialport/qextserialenumerator.h"

#include "setupdialog.h"
#include "ui_setupdialog.h"

setupDialog::setupDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::setupDialog)
{
    ui->setupUi(this);
    foreach (QextPortInfo info, QextSerialEnumerator::getPorts())
        ui->portBox->addItem(info.portName);
    //make sure user can input their own port name!
    ui->portBox->setEditable(true);

    ui->baudRateBox->addItem("1200", BAUD1200);
    ui->baudRateBox->addItem("2400", BAUD2400);
    ui->baudRateBox->addItem("4800", BAUD4800);
    ui->baudRateBox->addItem("9600", BAUD9600);
    ui->baudRateBox->addItem("19200", BAUD19200);
    ui->baudRateBox->addItem("38400", BAUD38400);
    ui->baudRateBox->addItem("57600", BAUD57600);
    ui->baudRateBox->addItem("115200", BAUD115200);
    ui->baudRateBox->setCurrentIndex(7);

    ui->parityBox->addItem("NONE", PAR_NONE);
    ui->parityBox->addItem("ODD", PAR_ODD);
    ui->parityBox->addItem("EVEN", PAR_EVEN);
    ui->parityBox->addItem("SPACE", PAR_SPACE);

    ui->flowControlBox->addItem("OFF", FLOW_OFF);
    ui->flowControlBox->addItem("HARDWARE", FLOW_HARDWARE);
    ui->flowControlBox->addItem("XONXOFF", FLOW_XONXOFF);

    ui->dataBitsBox->addItem("5", DATA_5);
    ui->dataBitsBox->addItem("6", DATA_6);
    ui->dataBitsBox->addItem("7", DATA_7);
    ui->dataBitsBox->addItem("8", DATA_8);
    ui->dataBitsBox->setCurrentIndex(3);

    ui->stopBitsBox->addItem("1", STOP_1);
    ui->stopBitsBox->addItem("2", STOP_2);

    ui->queryModeBox->addItem("Polling", QextSerialPort::Polling);
    ui->queryModeBox->addItem("EventDriven", QextSerialPort::EventDriven);


}

setupDialog::~setupDialog()
{
    delete ui;
}

QString setupDialog::getPortName() const
{
    return ui->portBox->currentText();
}

int setupDialog::getBaudRate()
{
    return ui->baudRateBox->itemData(ui->baudRateBox->currentIndex()).toInt();
}

int setupDialog::getParity()
{
    return ui->parityBox->itemData(ui->parityBox->currentIndex()).toInt();
}

int setupDialog::getFlowControl()
{
    return ui->flowControlBox->itemData(ui->flowControlBox->currentIndex()).toInt();
}

int setupDialog::getDataBits()
{
    return ui->dataBitsBox->itemData(ui->dataBitsBox->currentIndex()).toInt();
}

int setupDialog::getStopBits()
{
    return ui->stopBitsBox->itemData(ui->stopBitsBox->currentIndex()).toInt();
}

int setupDialog::getQueryMode()
{
    return ui->queryModeBox->itemData(ui->queryModeBox->currentIndex()).toInt();
    return ui->queryModeBox->currentIndex();
}

int setupDialog::getTimeout()
{
    //return ui->stopBitsBox->itemData(ui->stopBitsBox->currentIndex()).toInt();
    return ui->timeoutBox->value();
}

void setupDialog::onPortAddedOrRemoved()
{
    QString current = ui->portBox->currentText();

    ui->portBox->blockSignals(true);
    ui->portBox->clear();
    foreach (QextPortInfo info, QextSerialEnumerator::getPorts())
        ui->portBox->addItem(info.portName);

    ui->portBox->setCurrentIndex(ui->portBox->findText(current));

    ui->portBox->blockSignals(false);
}
