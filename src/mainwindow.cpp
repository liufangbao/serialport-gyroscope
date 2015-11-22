#include "qextserialport/qextserialport.h"
#include "qextserialport/qextserialenumerator.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "setupdialog.h"
#include <QtCore>
#include <QMessageBox>
#include <QDebug>

#if defined(Q_OS_WIN)
    #define WORD_WRAP "\r\n"
#else
    #define WORD_WRAP "\n"
#endif

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->mainToolBar->hide();
#if 0
    //! [0]
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
    //! [0]
#endif
    ui->led->turnOff();

    timer = new QTimer(this);
    timer->setInterval(40);

    infoLabel = new QLabel(this);
    txLabel = new QLabel(this);
    rxLabel = new QLabel(this);

    ui->statusBar->addPermanentWidget(infoLabel);
    ui->statusBar->addPermanentWidget(txLabel);
    ui->statusBar->addPermanentWidget(rxLabel);

    //! [1]
    PortSettings settings = {BAUD115200, DATA_8, PAR_NONE, STOP_1, FLOW_OFF, 10};
    //port = new QextSerialPort(ui->portBox->currentText(), settings, QextSerialPort::Polling);
    //! [1]
    port = new QextSerialPort(settings, QextSerialPort::Polling);
    enumerator = new QextSerialEnumerator(this);
    enumerator->setUpNotifications();
#if 0
    connect(ui->baudRateBox, SIGNAL(currentIndexChanged(int)), SLOT(onBaudRateBox_currentIndexChanged(int)));
    connect(ui->parityBox, SIGNAL(currentIndexChanged(int)), SLOT(onParityBox_currentIndexChanged(int)));
    connect(ui->flowControlBox, SIGNAL(currentIndexChanged(int)), SLOT(onFlowControlBox_currentIndexChanged(int)));
    connect(ui->dataBitsBox, SIGNAL(currentIndexChanged(int)), SLOT(onDataBitsBox_currentIndexChanged(int)));
    connect(ui->stopBitsBox, SIGNAL(currentIndexChanged(int)), SLOT(onStopBitsBox_currentIndexChanged(int)));
    connect(ui->queryModeBox, SIGNAL(currentIndexChanged(int)), SLOT(onQueryModeBox_currentIndexChanged(int)));
    connect(ui->timeoutBox, SIGNAL(valueChanged(int)), SLOT(onTimeoutBox_valueChanged(int)));
    connect(ui->portBox, SIGNAL(editTextChanged(QString)), SLOT(onPortBox_editTextChanged(QString)));
#endif
    connect(ui->openCloseButton, SIGNAL(clicked()), SLOT(onOpenCloseButton_clicked()));
    connect(ui->sendButton, SIGNAL(clicked()), SLOT(onSendButton_clicked()));
    connect(ui->wordWrapBox, SIGNAL(stateChanged(int)), SLOT(onWordWrapBox_stateChanged(int)));

    connect(timer, SIGNAL(timeout()), SLOT(onReadyRead()));
    connect(port, SIGNAL(readyRead()), SLOT(onReadyRead()));

    //connect(enumerator, SIGNAL(deviceDiscovered(QextPortInfo)), SLOT(onPortAddedOrRemoved()));
    //connect(enumerator, SIGNAL(deviceRemoved(QextPortInfo)), SLOT(onPortAddedOrRemoved()));

    connect(ui->action_Setup, SIGNAL(triggered()), SLOT(onSetUp_triggered()));

}

MainWindow::~MainWindow()
{
    delete ui;
    delete port;
}
#if 0
void MainWindow::onPortBox_editTextChanged(const QString &arg1)
{
    qDebug()<<"port name is "<<arg1;
    if (port->isOpen()) {
        port->close();
        ui->led->turnOff();
    }
}

void MainWindow::onBaudRateBox_currentIndexChanged(int index)
{
    port->setBaudRate((BaudRateType)ui->baudRateBox->itemData(index).toInt());
}

void MainWindow::onDataBitsBox_currentIndexChanged(int index)
{
    port->setDataBits((DataBitsType)ui->dataBitsBox->itemData(index).toInt());

}

void MainWindow::onStopBitsBox_currentIndexChanged(int index)
{
    port->setStopBits((StopBitsType)ui->stopBitsBox->itemData(index).toInt());

}

void MainWindow::onParityBox_currentIndexChanged(int index)
{
    port->setParity((ParityType)ui->parityBox->itemData(index).toInt());

}

void MainWindow::onFlowControlBox_currentIndexChanged(int index)
{
    port->setFlowControl((FlowType)ui->flowControlBox->itemData(index).toInt());

}

void MainWindow::onQueryModeBox_currentIndexChanged(int index)
{
    port->setQueryMode((QextSerialPort::QueryMode)ui->queryModeBox->itemData(index).toInt());

}

void MainWindow::onTimeoutBox_valueChanged(int arg1)
{
    port->setTimeout(arg1);
}
#endif

void MainWindow::onOpenCloseButton_clicked()
{
    if (!port->isOpen()) {
        port->setPortName(this->portName);
        port->open(QIODevice::ReadWrite);

        this->infoLabel->setText(this->portName);
        this->txLabel->setText("TX: ");
        this->rxLabel->setText("RX: ");
    }
    else {
        port->close();
    }

    //If using polling mode, we need a QTimer
    if (port->isOpen() && port->queryMode() == QextSerialPort::Polling)
        timer->start();
    else
        timer->stop();

    ui->led->turnOn(port->isOpen());
}

void MainWindow::onSendButton_clicked()
{
    if (port->isOpen() && !ui->sendEdit->toPlainText().isEmpty()){
        if(ui->hexSendBox->isChecked()){
            //port->write(stringToHex(g_array, ui->sendEdit->toPlainText().toLatin1()));
            bool ok;
            char data;
            QStringList list;
            g_array.clear();
            list = ui->sendEdit->toPlainText().split(" ");
            for(int i = 0; i < list.count(); i++){
                if(list.at(i) == " ") continue;
                if(list.at(i).isEmpty()) continue;
                data = (char)list.at(i).toInt(&ok, 16);
                if(!ok){
                    QMessageBox::information(this, tr("Warning: "), tr("data is bad "), QMessageBox::Ok);
                }
                g_array.append(data);
            }
            port->write(g_array);
        }
        else port->write(ui->sendEdit->toPlainText().toLatin1());
    }
    if(ui->clearBox->isChecked())
        ui->sendEdit->clear();
}

void MainWindow::onWordWrapBox_stateChanged(int state)
{
    //if(ui->wordWrapBox->checkState() == Qt::Checked) ui->recvEdit->insertPlainText(WORD_WRAP);
    if(state == Qt::Checked) ui->recvEdit->insertPlainText(WORD_WRAP);
}

void MainWindow::onReadyRead()
{
    if (port->bytesAvailable()) {
        ui->recvEdit->moveCursor(QTextCursor::End);
        if(ui->hexShowBox->isChecked()){
            g_string.clear();
            //ui->recvEdit->insertPlainText(showHex(g_string, port->readAll()));
            QByteArray array;
            array = port->readAll();
            for(int i = 0; i< array.count(); i++){
                QString s;
                s.sprintf("%02x ", (unsigned char)array.at(i));
                g_string.append(s);
            }
            ui->recvEdit->insertPlainText(g_string);
        }
        else ui->recvEdit->insertPlainText(QString::fromLatin1(port->readAll()));
        if(ui->wordWrapBox->isChecked()) ui->recvEdit->insertPlainText(WORD_WRAP);
    }
}

#if 0
void MainWindow::onPortAddedOrRemoved()
{
    QString current = ui->portBox->currentText();

    ui->portBox->blockSignals(true);
    ui->portBox->clear();
    foreach (QextPortInfo info, QextSerialEnumerator::getPorts())
        ui->portBox->addItem(info.portName);

    ui->portBox->setCurrentIndex(ui->portBox->findText(current));

    ui->portBox->blockSignals(false);
}
#endif
void MainWindow::onSetUp_triggered()
{
    setupDialog setup(this);
    setup.setWindowTitle(tr("serial port setup"));

    connect(enumerator, SIGNAL(deviceDiscovered(QextPortInfo)), &setup, SLOT(onPortAddedOrRemoved()));
    connect(enumerator, SIGNAL(deviceRemoved(QextPortInfo)), &setup, SLOT(onPortAddedOrRemoved()));

    if(setup.exec()){
        //qDebug()<<setup.getPortName();
        this->portName = setup.getPortName();
        this->port->setBaudRate((BaudRateType)setup.getBaudRate());
        this->port->setDataBits((DataBitsType)setup.getDataBits());
        this->port->setParity((ParityType)setup.getParity());
        this->port->setStopBits((StopBitsType)setup.getStopBits());
        this->port->setFlowControl((FlowType)setup.getFlowControl());
        this->port->setQueryMode((QextSerialPort::QueryMode)setup.getQueryMode());
    }
    disconnect(enumerator, SIGNAL(deviceDiscovered(QextPortInfo)), &setup, SLOT(onPortAddedOrRemoved()));
    disconnect(enumerator, SIGNAL(deviceRemoved(QextPortInfo)), &setup, SLOT(onPortAddedOrRemoved()));
}

#if 0
const QByteArray &MainWindow::stringToHex(QByteArray &array, const QString &string)
{
    char str_h, str_l, data;
    int i, len = string.length();
    array.clear();

    for(i = 0; i < len;){
        if((i + 1) >= len) return array;
        //str_h = string[i].toAscii();
        str_h = string[i].toAscii();
        if(str_h == ' '){
            i++;
            continue;
        }
        i++;
        str_l = string[i].toAscii();
        if(str_l == ' ') return array;

        data = charToHex(str_h) * 16 + charToHex(str_l);
        array.append(data);
        qDebug()<<"send: "<<((int)data & 0x00ff);
    }

    return array;
}

const QString &MainWindow::showHex(QString &string, const QByteArray &array)
{
    int i, len = array.length();
    char c;
    string.clear();

    for(i = 0; i < len; i++){
        c = array[i] / 16;
        if(c >= 0 && c <= 9)
            string.append(c + '0');
        else{
            if(c > 9)
                string.append(c + 'a');
        }
        qDebug()<<"recv: "<<c;

        c = array[i] - c;
        c = (c > 0)? c:(-c);
        if(c >= 0 && c <= 9)
            string.append(c + '0');
        else{
            if(c > 9)
                string.append(c + 'a');
        }
        qDebug()<<"""recv: "<<c;

        if((i +1) % 16) string.append(' ');
        else string.append('\n');
    }
    return string;
}

char MainWindow::charToHex(char c)
{
    if(c >= '0' && c <= '9')
        return c - '0';
    else{
        if(c >= 'a' && c <= 'f')
            return c - 'a' + 10;
        else{
            if(c >= 'A' && c <= 'F')
                return c - 'A' + 10;
            else return -1;
        }
    }

    return -1;
}
#endif
