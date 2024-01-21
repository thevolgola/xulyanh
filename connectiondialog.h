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
class connectionDialog;
}

class connectionDialog : public QDialog
{
    Q_OBJECT

public:
    explicit connectionDialog(QWidget *parent = nullptr);
    ~connectionDialog();

private slots:
    void on_buttonBox_clicked(QAbstractButton *buttonbox);


private:
    Ui::connectionDialog *ui;
    QSerialPort* COMPORT;


};

#endif // CONNECTDIALOG_H
