#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <connectiondialog.h>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    timer =new QTimer(this);
    COMPORT = new QSerialPort;
    COMPORT -> setPortName("COM4");
    COMPORT -> setBaudRate(QSerialPort::BaudRate::Baud9600);
    COMPORT -> setParity(QSerialPort::Parity::NoParity);
    COMPORT -> setDataBits(QSerialPort::DataBits::Data8);
    COMPORT -> setStopBits(QSerialPort::StopBits::OneStop);
    COMPORT -> setFlowControl(QSerialPort::FlowControl::NoFlowControl);
    COMPORT -> open(QIODevice::ReadWrite);


    ui->comboBox->addItem("Red");
    ui->comboBox->addItem("Blue");
    ui->comboBox->addItem("Green");
    ui->comboBox->addItem("Yellow");
    ui->comboBox_2->addItem("Red");
    ui->comboBox_2->addItem("Blue");
    ui->comboBox_2->addItem("Green");
    ui->comboBox_2->addItem("Yellow");


    connect(timer, SIGNAL(timeout()), this, SLOT(timerfunc()));
    timer->setInterval(1000);
    timer->start();
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_actionConnection_triggered()
{
    connectionDialog connectiondialog;
    connectiondialog.setModal(true);
    connectiondialog.exec();
}



void MainWindow::on_actionStart_triggered()
{
    QString ip = ui->ip->text();
    string ip2 = ip.toStdString();
    cv::VideoCapture cap(ip2);
    cap.set(cv::CAP_PROP_FRAME_WIDTH, 1280);
    cap.set(cv::CAP_PROP_FRAME_HEIGHT, 720);

    while (true){
        cv::Mat frame;
        cap.read(frame);

        cv::Mat hsv_frame;
        cv::cvtColor(frame, hsv_frame, cv::COLOR_BGR2HSV);

        int height = frame.rows;
        int width = frame.cols;

        int cx = width / 2;
        int cy = height / 2;

        cv::Vec3b pixel_center = hsv_frame.at<cv::Vec3b>(cy, cx);
        int hue_value = pixel_center[0];
        int hue_value2 = pixel_center[1];
        int hue_value3 = pixel_center[2];

        std::string color = "";

//        if ((0 < hue_value && hue_value < 180) && (0 < hue_value2 && hue_value2 < 255) && (200 < hue_value3 && hue_value3 < 255)) {
//            color = "White";
//            code = 0;
//        }

        if ((20 < hue_value && hue_value < 30) && (100 < hue_value2 && hue_value2 < 255) && (100 < hue_value3 && hue_value3 < 255)) {
            color = "Yellow";
            code = 3;
        }

        if ((25 < hue_value && hue_value < 102) && (52 < hue_value2 && hue_value2 < 255) && (72 < hue_value3 && hue_value3 < 255)) {
            color = "Green";
            code = 2;
        }

        if ((78 < hue_value && hue_value < 138) && (158 < hue_value2 && hue_value2 < 255) && (124 < hue_value3 && hue_value3 < 255)) {
            color = "Blue";
            code = 1;
        }

        if (((0 < hue_value && hue_value < 10) || (136 < hue_value && hue_value < 180)) && (120 < hue_value2 && hue_value2 < 255) && (70 < hue_value3 && hue_value3 < 255)) {
            color = "Red";
            code = 0;
        }

        if(code == ui->comboBox->currentIndex() && ui->comboBox->currentIndex() != ui->comboBox_2->currentIndex())
        {
            servo="60";
            updateServo(servo);
            qDebug()<<code;
            qDebug()<<ui->comboBox->currentIndex();
        }
        if(code == ui->comboBox_2->currentIndex() && ui->comboBox->currentIndex() != ui->comboBox_2->currentIndex())
        {
            servo="40";
            updateServo(servo);
            qDebug()<<code;
            qDebug()<<ui->comboBox_2->currentIndex();
        }


        std::cout << pixel_center << std::endl;

        cv::putText(frame, color, cv::Point(18, 58), cv::FONT_HERSHEY_SIMPLEX, 1, cv::Scalar(255, 0, 0), 2);
        cv::circle(frame, cv::Point(cx, cy), 5, cv::Scalar(255, 0, 0), 3);
        cv::imshow("frame", frame);

        char key = cv::waitKey(1);
        if (key == 27) {
            break;
        }
    }

    cap.release();
    destroyAllWindows();

}




void MainWindow::on_pushButton_clicked()
{
    QFile file("G:/20207761/opencvtest/xulyanh/ip address.txt");
    if(file.open(QIODevice::WriteOnly| QIODevice::Append| QIODevice::Text)) {
        QTextStream out(&file);
        QString ip = ui->ip->text();
        out << ip << " " << "\n";
        file.flush();
        file.close();
    }


    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QMessageBox::warning(this, tr("Error"), tr("Could not open file"));
        return;
    }
    QTextStream in(&file);

    while (!in.atEnd()) {
        QString line = in.readLine();
        QStringList fields = line.split(" ");

        for (int i = 0; i < fields.size(); ++i) {

            ui->comboBox_3->addItem(line);
        }
    }
    file.close();


}

void MainWindow::timerfunc()
{
    ui->label_timer->setText(QDateTime::currentDateTime().toString("dd/MM/yyyy   HH:mm:ss"));
}

void MainWindow::on_comboBox_3_currentTextChanged(const QString &arg1)
{
    QString ip1 = arg1;
    ui->ip->setText(ip1);
}

void MainWindow::updateServo(QString cmd)
{
    if(COMPORT->isWritable())
    {
        qDebug() << cmd.toStdString().c_str();
        COMPORT->write(cmd.toStdString().c_str());
    }
    else
    {
        qDebug()<<"coundn't write to serial";
    }
}





void MainWindow::on_pushButton_2_clicked()
{

}


void MainWindow::on_comboBox_2_currentTextChanged(const QString &arg1)
{
//    ui->comboBox->currentTextChanged(arg1);
//    qDebug()<<arg1;
}

