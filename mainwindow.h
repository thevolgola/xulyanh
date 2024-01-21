#ifndef MAINWINDOW_H
#define MAINWINDOW_H


#include <QMainWindow>
#include <QDialog>
#include <QSerialPort>
#include <QSerialPortInfo>
#include <QDebug>
#include <QWidget>
#include <QFile>
#include <connectiondialog.h>
#include <iostream>
#include <sstream>
#include <opencv2\imgcodecs.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/videoio.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/video.hpp>
using namespace cv;
using namespace std;
#include <opencv2/opencv.hpp>
#include <QTimer>
#include <QDateTime>
#include <QSerialPort>
#include <QSerialPortInfo>
#include <QDebug>
#include <QtWidgets>
#include <QString>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_actionConnection_triggered();

    void on_actionStart_triggered();

    void timerfunc();

    void on_pushButton_clicked();

    void updateServo(QString cmd);

    void on_comboBox_3_currentTextChanged(const QString &arg1);

    void on_pushButton_2_clicked();

    void on_comboBox_2_currentTextChanged(const QString &arg1);

private:
    Ui::MainWindow *ui;
    QSerialPort* COMPORT;
    QTimer *timer;
    QString ip;
    int code;
    int codel;
    int coder;
    QSerialPort *arduino;
    static const quint16 arduino_uno_vendorID = 6790;
    static const quint16 arduino_uno_productID = 29987;
    QString arduino_port_name;
    bool arduino_is_available;
    QString defaulteagle;
    QString Data_from_serialPort;
    bool IS_Data_Reveived=false;
    QString servo;
};
#endif // MAINWINDOW_H
