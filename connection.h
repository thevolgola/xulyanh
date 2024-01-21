#ifndef CONNECTDIALOG_H
#define CONNECTDIALOG_H

#include <QDialog>
#include <QSerialPort>
#include <QSerialPortInfo>
#include <QtWidgets>
#include <QMessageBox>
#include <QString>
#include <QDebug>

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = nullptr);
    ~Dialog();

private slots:
    void on_buttonBox_clicked(QAbstractButton *buttonbox);


private:
    Ui::Dialog *ui;
    QSerialPort* COMPORT;


};

#endif // CONNECTDIALOG_H
