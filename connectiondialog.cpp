#include "connectiondialog.h"
#include "ui_connectiondialog.h"
#include <QMessageBox>

connectionDialog::connectionDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::connectionDialog)
{
    ui->setupUi(this);
    COMPORT = new QSerialPort;
    COMPORT -> setPortName("COM4");
    COMPORT -> setBaudRate(QSerialPort::BaudRate::Baud9600);
    COMPORT -> setParity(QSerialPort::Parity::NoParity);
    COMPORT -> setDataBits(QSerialPort::DataBits::Data8);
    COMPORT -> setStopBits(QSerialPort::StopBits::OneStop);
    COMPORT -> setFlowControl(QSerialPort::FlowControl::NoFlowControl);
    COMPORT -> open(QIODevice::ReadWrite);

}

connectionDialog::~connectionDialog()
{
    delete ui;
    COMPORT->close();

}

void connectionDialog::on_buttonBox_clicked(QAbstractButton *buttonbox)
{
    if (COMPORT->isOpen()){
        ui->portname->setText("No device");
        QMessageBox::about(this, "Connection", "No device connected");
    }
    else{
        ui->portname->setText("Arduino Uno \n Com4");
        QMessageBox::about(this, "Connection", "Arduino Uno \n Com4");
    }
}
