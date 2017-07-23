#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <QObject>
#include <QByteArray>
#include <qbytearray.h>
#include "posix_qextserialport.h"

const QByteArray motor_front("\x40\x06\x01\x06\x0a\x57", 6);
const QByteArray motor_back("\x40\x06\x01\x06\x0b\x58", 6);
const QByteArray motor_stop("\x40\x06\x01\x06\x0c\x59", 6);
const QByteArray pwm_range("\x00\x01\x02\x03\x04\x05\x06\x07\x08\x09", 10);
static QByteArray pwm_msg("\x40\x06\x01\x09\x00\x50", 6);

const QByteArray    THL_exist("\x40\x10\x01\x02\xaa\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\xfd", 16);
const QByteArray  smoke_exist("\x40\x10\x01\x04\xaa\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\xff", 16);
const QByteArray infray_exist("\x40\x10\x01\x05\xaa\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\xaa", 16);
const QByteArray  motor_exist("\x40\x10\x01\x06\xaa\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x01", 16);
const QByteArray    pwm_exist("\x40\x10\x01\x09\xaa\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x04", 16);



namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    int is_auto_pwm;

    int is_THL_exist;
    int is_smoke_exist;
    int is_infray_exist;
    int is_motor_exist;
    int is_pwm_exist;
    void addlog(QString);

signals:

private:
    Ui::MainWindow *ui;
    Posix_QextSerialPort * myCom;
    QTimer * myTimer;
    QTimer * existTimer;
    QTimer * updateTimer;
    int temperature, humidity;
    float light;
    QFile logfile;

private slots:
    void readMyCom();
    void check_exist();

    void update_temp();

    void on_pushButton_motor_back_clicked();
    void on_pushButton_motor_front_clicked();
    void on_pushButton_motor_stop_clicked();
    void on_horizontalSlider_valueChanged(int value);
    void on_checkBox_light_stateChanged(int arg1);
    void on_radioButton_up_clicked();
    void on_radioButton_down_clicked();

};

#endif // MAINWINDOW_H
