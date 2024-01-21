#include "connection.h"
#include "ui_connectdialog.h"
#include <QMessageBox>

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    COMPORT = new QSerialPort;
    COMPORT -> setPortName("COM2");
    COMPORT -> setBaudRate(QSerialPort::BaudRate::Baud9600);
    COMPORT -> setParity(QSerialPort::Parity::NoParity);
    COMPORT -> setDataBits(QSerialPort::DataBits::Data8);
    COMPORT -> setStopBits(QSerialPort::StopBits::OneStop);
    COMPORT -> setFlowControl(QSerialPort::FlowControl::NoFlowControl);
    COMPORT -> open(QIODevice::ReadWrite);

}

Dialog::~Dialog()
{
    delete ui;
    COMPORT->close();

}

void Dialog::on_buttonBox_clicked(QAbstractButton *buttonbox)
{
    if (COMPORT->isOpen()){
        ui->portname->setText("No device");
        QMessageBox::about(this, "Connection", "No device connected");
    }
    else{
        ui->portname->setText("Arduino Uno \n Com2");
        QMessageBox::about(this, "Connection", "Arduino Uno \n Com2");
    }
}

