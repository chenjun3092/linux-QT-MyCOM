#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QObject>
#include <qdatastream.h>
#include <qmessagebox.h>
#include <QMessageBox>
#include <QDateTime>
#include <qtimer.h>
#include <qfile.h>
#include <QFile>
#include <qdebug.h>
#include <QTextStream>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    myCom = new Posix_QextSerialPort("/dev/ttyS0", QextSerialBase::Polling);

    ui->tempNumber->setNumDigits(6);
    ui->tempNumber->setPalette(Qt::black);
    ui->humiNumber->setNumDigits(6);
    ui->humiNumber->setPalette(Qt::black);
    ui->lightNumber->setNumDigits(6);
    ui->lightNumber->setPalette(Qt::black);
    ui->horizontalSlider->setRange(0, 9);
    ui->horizontalSlider->setTickPosition(QSlider::TicksRight);
    ui->horizontalSlider->setPageStep(1);
    is_auto_pwm = 0;

    ui->checkBox_light->setEnabled(false);
    ui->horizontalSlider->setEnabled(false);
    ui->pushButton_motor_back->setEnabled(false);
    ui->pushButton_motor_front->setEnabled(false);
    ui->pushButton_motor_stop->setEnabled(false);

//    is_THL_exist = 1;
//    is_smoke_exist = 1;
//    is_infray_exist = 1;
//    is_motor_exist = 1;
//    is_pwm_exist = 1;
}



MainWindow::~MainWindow()
{
    delete ui;

}

void MainWindow::addlog(QString s)
{
    QDateTime tim = QDateTime::currentDateTime();
    QString str = tim.toString() + " : " + s + "\n";

    ui->textBrowser_log->append(str);

    QFile logfile("log.txt");
    logfile.open(QIODevice::WriteOnly|QIODevice::Append);

    QTextStream out(&logfile);
    out << str << endl;
    logfile.close();
}


void MainWindow::readMyCom()
{

    QByteArray msg = myCom->readAll();

    if (msg.length() < 6)
        return;

    if (msg[3] == 0x02 && msg[4] == 0x01) {
        unsigned char adcValue[2];
        temperature = (msg[5] * 256) + msg[6];
        humidity = (msg[7] * 256) + msg[8];
        adcValue[0] = msg[10];
        adcValue[1] = msg[9];
        adcValue[0] = adcValue[0] >> 2;
        light = ((adcValue[1] << 8) + adcValue[0]) * 3.3 / 8192;
        light /= 4;
        light *= 913;

        if (is_auto_pwm && light < 500.0) {
            int rng = int((light-300.0)/20.0);
            unsigned char range = pwm_range[rng];
            pwm_msg[4] = range;
            pwm_msg[5] = 0x50 + rng;
            myCom->write(pwm_msg);
            addlog(QString::fromLocal8Bit("自动调节亮度为：") + QString::number(rng));
        }

//        qdebug("%d  %d  %f\n", temperature, humidity, light);
//        qDebug("%d\n", qPrintable(temperature));
//        qDebug("%d\n", qPrintable(msg.length()));
//        qDebug("%f\n", qPrintable(light));
        is_THL_exist = 1;
    }
    if (msg[3] == 0x04 && msg[4] == 0x01) {
//        if (msg[5] == 0x00 && msg[6] == 0x4D) {
        if (msg[5] == 0x00) {
            ui->lineEditSmoke->setText(QString::fromLocal8Bit("安全"));
                    addlog(QString::fromLocal8Bit("没有烟雾，安全"));
        }
//        else if (msg[5] == 0x01 && msg[6] == 0x4E) {
        else if (msg[5] == 0x01) {
            ui->lineEditSmoke->setText(QString::fromLocal8Bit("注意，有烟雾！"));
            addlog(QString::fromLocal8Bit("注意，有烟雾！"));
        }
        is_smoke_exist = 1;
    }
    if (msg[3] == 0x05 && msg[4] == 0x01) {
        if (msg[5] == 0x00 && msg[6] == 0x4E) {
            ui->lineEditSteal->setText(QString::fromLocal8Bit("红外：安全"));
            addlog(QString::fromLocal8Bit("红外：安全"));
        }
        else if (msg[5] == 0x00 && msg[6] == 0x4F) {
            ui->lineEditSteal->setText(QString::fromLocal8Bit("注意！有未知人出现"));
            addlog(QString::fromLocal8Bit("注意！有未知人出现"));
        }
        is_infray_exist = 1;
    }
    if (msg[3] == 0x02 && msg[4] == 0xaa) {
        is_THL_exist = 1;
    }
    if (msg[3] == 0x04 && msg[4] == 0xaa) {
        is_smoke_exist = 1;
    }
    if (msg[3] == 0x05 && msg[4] == 0xaa) {
        is_infray_exist = 1;
    }
    if (msg[3] == 0x09 && msg[4] == 0xaa) {
        is_pwm_exist = 1;
    }
    if (msg[3] == 0x06 && msg[4] == 0xaa) {
        is_motor_exist = 1;
    }
}

void MainWindow::on_pushButton_motor_back_clicked()
{
    myCom->write(motor_back);
    addlog(QString::fromLocal8Bit("卷起窗帘"));

    sleep(3);

    myCom->write(motor_stop);
    addlog(QString::fromLocal8Bit("停止转动窗帘"));
}

void MainWindow::on_pushButton_motor_front_clicked()
{
    myCom->write(motor_front);
    addlog(QString::fromLocal8Bit("放下窗帘"));

    sleep(3);

    myCom->write(motor_stop);
    addlog(QString::fromLocal8Bit("停止转动窗帘"));
}

void MainWindow::on_pushButton_motor_stop_clicked()
{
    myCom->write(motor_stop);
    addlog(QString::fromLocal8Bit("停止转动窗帘"));
}

void MainWindow::on_horizontalSlider_valueChanged(int value)
{
    qDebug("%d\n", qPrintable(value));
    if (is_auto_pwm)
        return;
    unsigned char range = pwm_range[value];
    pwm_msg[4] = range;
    pwm_msg[5] = 0x50 + range;
    myCom->write(pwm_msg);
    addlog(QString::fromLocal8Bit("更改LED亮度为：") + QString::number(value));
}

void MainWindow::on_checkBox_light_stateChanged(int arg1)
{
    is_auto_pwm = arg1;
    if (is_auto_pwm == 2) {
        addlog(QString::fromLocal8Bit("自动调光"));
    }
    else
        addlog(QString::fromLocal8Bit("手动调光"));
}

void MainWindow::on_radioButton_up_clicked()
{
    myCom->open(QIODevice::ReadWrite);
    myCom->setBaudRate(BAUD115200);
    myCom->setDataBits(DATA_8);
    myCom->setParity(PAR_NONE);
    myCom->setStopBits(STOP_1);
    myCom->setFlowControl(FLOW_OFF);
    myCom->setTimeout(50);

    myTimer = new QTimer(this);
    myTimer->start(50);
    connect(myTimer , SIGNAL(timeout()), this, SLOT(readMyCom()));

    existTimer = new QTimer(this);
    existTimer->start(20000);
    connect(existTimer, SIGNAL(timeout()), this, SLOT(check_exist()));

    updateTimer = new QTimer(this);
    updateTimer->start(5000);
    connect(updateTimer, SIGNAL(timeout()), this, SLOT(update_temp()));

    addlog(QString::fromLocal8Bit("开启所有控件"));
    ui->checkBox_light->setEnabled(true);
    ui->horizontalSlider->setEnabled(true);
    ui->pushButton_motor_back->setEnabled(true);
    ui->pushButton_motor_front->setEnabled(true);
    ui->pushButton_motor_stop->setEnabled(true);
    ui->lineEditSmoke->setText(QString::fromLocal8Bit("安全"));
    ui->lineEditSteal->setText(QString::fromLocal8Bit("红外:安全"));

}

void MainWindow::on_radioButton_down_clicked()
{
    myCom->close();
    addlog(QString::fromLocal8Bit("关闭所有控件"));

    myTimer->stop();
    delete myTimer;
    existTimer->stop();
    delete existTimer;

    updateTimer->stop();
    delete updateTimer;


    ui->checkBox_light->setEnabled(false);
    ui->horizontalSlider->setEnabled(false);
    ui->pushButton_motor_back->setEnabled(false);
    ui->pushButton_motor_front->setEnabled(false);
    ui->pushButton_motor_stop->setEnabled(false);

    ui->humiNumber->display(0);
    ui->lightNumber->display(0);
    ui->tempNumber->display(0);
    ui->lineEditSmoke->clear();
    ui->lineEditSteal->clear();
}

void MainWindow::check_exist()
{
    if (!is_THL_exist) {
        addlog(QString::fromLocal8Bit("温湿度及光照传感器出现问题，请验证～"));
        QMessageBox::information(this, QString::fromLocal8Bit("提示"), QString::fromLocal8Bit("温湿度及光照传感器出现问题，请验证～"));
    }
    if (!is_smoke_exist) {
        addlog(QString::fromLocal8Bit("烟雾传感器出现问题，请验证～"));
        QMessageBox::information(this, QString::fromLocal8Bit("提示"), QString::fromLocal8Bit("烟雾传感器出现问题，请验证～"));
    }
    if (!is_infray_exist) {
        addlog(QString::fromLocal8Bit("热视电红外传感器出现问题，请验证～"));
        QMessageBox::information(this, QString::fromLocal8Bit("提示"), QString::fromLocal8Bit("热视电红外传感器出现问题，请验证～"));
    }
    if (!is_pwm_exist) {
        addlog(QString::fromLocal8Bit("PWM灯光出现问题，请验证～"));
        QMessageBox::information(this, QString::fromLocal8Bit("提示"), QString::fromLocal8Bit("PWM灯光出现问题，请验证～"));
    }
    if (!is_motor_exist) {
        addlog(QString::fromLocal8Bit("电机模块出现问题，请验证～"));
        QMessageBox::information(this, QString::fromLocal8Bit("提示"), QString::fromLocal8Bit("电机模块出现问题，请验证～"));
    }
    is_THL_exist = 0;
    is_smoke_exist = 0;
    is_infray_exist = 0;
    is_pwm_exist = 0;
    is_motor_exist = 0;
}

void MainWindow::update_temp()
{
    ui->tempNumber->display(temperature);
    ui->humiNumber->display(humidity);
    ui->lightNumber->display(light);

    addlog(QString::fromLocal8Bit("温度：") + QString::number(temperature));
    addlog(QString::fromLocal8Bit("湿度：") + QString::number(humidity));
    addlog(QString::fromLocal8Bit("亮度：") + QString::number(light));

}
