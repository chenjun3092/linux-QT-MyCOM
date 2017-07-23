/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Fri Jul 21 10:19:53 2017
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QFormLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLCDNumber>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QMainWindow>
#include <QtGui/QPushButton>
#include <QtGui/QRadioButton>
#include <QtGui/QSlider>
#include <QtGui/QTextBrowser>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QLabel *label;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *label_2;
    QVBoxLayout *verticalLayout;
    QPushButton *pushButton_motor_back;
    QPushButton *pushButton_motor_stop;
    QPushButton *pushButton_motor_front;
    QWidget *layoutWidget1;
    QFormLayout *formLayout;
    QLabel *label_3;
    QLCDNumber *tempNumber;
    QLabel *label_4;
    QLCDNumber *humiNumber;
    QLabel *label_5;
    QLCDNumber *lightNumber;
    QCheckBox *checkBox_light;
    QSlider *horizontalSlider;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_8;
    QLineEdit *lineEditSmoke;
    QLineEdit *lineEditSteal;
    QLabel *label_9;
    QRadioButton *radioButton_up;
    QRadioButton *radioButton_down;
    QTextBrowser *textBrowser_log;
    QLabel *label_10;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->setEnabled(true);
        MainWindow->resize(530, 610);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(190, 10, 201, 41));
        QFont font;
        font.setPointSize(21);
        label->setFont(font);
        layoutWidget = new QWidget(centralWidget);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(89, 240, 147, 101));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout->addWidget(label_2);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        pushButton_motor_back = new QPushButton(layoutWidget);
        pushButton_motor_back->setObjectName(QString::fromUtf8("pushButton_motor_back"));

        verticalLayout->addWidget(pushButton_motor_back);

        pushButton_motor_stop = new QPushButton(layoutWidget);
        pushButton_motor_stop->setObjectName(QString::fromUtf8("pushButton_motor_stop"));

        verticalLayout->addWidget(pushButton_motor_stop);

        pushButton_motor_front = new QPushButton(layoutWidget);
        pushButton_motor_front->setObjectName(QString::fromUtf8("pushButton_motor_front"));

        verticalLayout->addWidget(pushButton_motor_front);


        horizontalLayout->addLayout(verticalLayout);

        layoutWidget1 = new QWidget(centralWidget);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(259, 240, 181, 101));
        formLayout = new QFormLayout(layoutWidget1);
        formLayout->setSpacing(6);
        formLayout->setContentsMargins(11, 11, 11, 11);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        formLayout->setFormAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        formLayout->setContentsMargins(0, 0, 0, 0);
        label_3 = new QLabel(layoutWidget1);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy);
        QFont font1;
        font1.setPointSize(10);
        label_3->setFont(font1);

        formLayout->setWidget(0, QFormLayout::LabelRole, label_3);

        tempNumber = new QLCDNumber(layoutWidget1);
        tempNumber->setObjectName(QString::fromUtf8("tempNumber"));
        sizePolicy.setHeightForWidth(tempNumber->sizePolicy().hasHeightForWidth());
        tempNumber->setSizePolicy(sizePolicy);
        QFont font2;
        font2.setPointSize(12);
        font2.setBold(false);
        font2.setWeight(50);
        tempNumber->setFont(font2);

        formLayout->setWidget(0, QFormLayout::FieldRole, tempNumber);

        label_4 = new QLabel(layoutWidget1);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        sizePolicy.setHeightForWidth(label_4->sizePolicy().hasHeightForWidth());
        label_4->setSizePolicy(sizePolicy);
        label_4->setFont(font1);

        formLayout->setWidget(1, QFormLayout::LabelRole, label_4);

        humiNumber = new QLCDNumber(layoutWidget1);
        humiNumber->setObjectName(QString::fromUtf8("humiNumber"));
        sizePolicy.setHeightForWidth(humiNumber->sizePolicy().hasHeightForWidth());
        humiNumber->setSizePolicy(sizePolicy);
        humiNumber->setFont(font2);

        formLayout->setWidget(1, QFormLayout::FieldRole, humiNumber);

        label_5 = new QLabel(layoutWidget1);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        sizePolicy.setHeightForWidth(label_5->sizePolicy().hasHeightForWidth());
        label_5->setSizePolicy(sizePolicy);
        label_5->setFont(font1);

        formLayout->setWidget(2, QFormLayout::LabelRole, label_5);

        lightNumber = new QLCDNumber(layoutWidget1);
        lightNumber->setObjectName(QString::fromUtf8("lightNumber"));
        sizePolicy.setHeightForWidth(lightNumber->sizePolicy().hasHeightForWidth());
        lightNumber->setSizePolicy(sizePolicy);
        lightNumber->setFont(font2);

        formLayout->setWidget(2, QFormLayout::FieldRole, lightNumber);

        checkBox_light = new QCheckBox(centralWidget);
        checkBox_light->setObjectName(QString::fromUtf8("checkBox_light"));
        checkBox_light->setGeometry(QRect(89, 200, 93, 22));
        horizontalSlider = new QSlider(centralWidget);
        horizontalSlider->setObjectName(QString::fromUtf8("horizontalSlider"));
        horizontalSlider->setGeometry(QRect(179, 200, 160, 19));
        horizontalSlider->setFont(font1);
        horizontalSlider->setMaximum(9);
        horizontalSlider->setPageStep(1);
        horizontalSlider->setOrientation(Qt::Horizontal);
        label_6 = new QLabel(centralWidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(350, 200, 91, 20));
        label_7 = new QLabel(centralWidget);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(90, 140, 62, 17));
        label_8 = new QLabel(centralWidget);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(280, 140, 60, 17));
        lineEditSmoke = new QLineEdit(centralWidget);
        lineEditSmoke->setObjectName(QString::fromUtf8("lineEditSmoke"));
        lineEditSmoke->setEnabled(false);
        lineEditSmoke->setGeometry(QRect(160, 140, 100, 27));
        lineEditSteal = new QLineEdit(centralWidget);
        lineEditSteal->setObjectName(QString::fromUtf8("lineEditSteal"));
        lineEditSteal->setEnabled(false);
        lineEditSteal->setGeometry(QRect(340, 140, 100, 27));
        label_9 = new QLabel(centralWidget);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(101, 91, 39, 17));
        radioButton_up = new QRadioButton(centralWidget);
        radioButton_up->setObjectName(QString::fromUtf8("radioButton_up"));
        radioButton_up->setGeometry(QRect(216, 91, 41, 22));
        radioButton_down = new QRadioButton(centralWidget);
        radioButton_down->setObjectName(QString::fromUtf8("radioButton_down"));
        radioButton_down->setGeometry(QRect(331, 91, 41, 22));
        textBrowser_log = new QTextBrowser(centralWidget);
        textBrowser_log->setObjectName(QString::fromUtf8("textBrowser_log"));
        textBrowser_log->setGeometry(QRect(90, 390, 360, 190));
        label_10 = new QLabel(centralWidget);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setGeometry(QRect(90, 370, 500, 17));
        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("MainWindow", "\346\231\272\350\203\275\345\256\266\345\272\255\346\216\247\344\273\266", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("MainWindow", "\347\252\227\345\270\230\346\216\247\345\210\266", 0, QApplication::UnicodeUTF8));
        pushButton_motor_back->setText(QApplication::translate("MainWindow", "\344\270\212\345\215\207", 0, QApplication::UnicodeUTF8));
        pushButton_motor_stop->setText(QApplication::translate("MainWindow", "\345\201\234\346\255\242", 0, QApplication::UnicodeUTF8));
        pushButton_motor_front->setText(QApplication::translate("MainWindow", "\344\270\213\351\231\215", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("MainWindow", "\346\270\251\345\272\246", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("MainWindow", "\346\271\277\345\272\246", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("MainWindow", "\345\205\211\345\274\272\345\272\246", 0, QApplication::UnicodeUTF8));
        checkBox_light->setText(QApplication::translate("MainWindow", "\350\207\252\345\212\250\350\260\203\345\205\211", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("MainWindow", "\347\201\257\345\205\211\344\272\256\345\272\246\350\260\203\350\212\202", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("MainWindow", "\347\203\237\351\233\276\346\212\245\350\255\246", 0, QApplication::UnicodeUTF8));
        label_8->setText(QApplication::translate("MainWindow", "\347\233\227\347\252\203\346\212\245\350\255\246", 0, QApplication::UnicodeUTF8));
        label_9->setText(QApplication::translate("MainWindow", "\346\200\273\345\274\200\345\205\263", 0, QApplication::UnicodeUTF8));
        radioButton_up->setText(QApplication::translate("MainWindow", "\345\274\200", 0, QApplication::UnicodeUTF8));
        radioButton_down->setText(QApplication::translate("MainWindow", "\345\205\263", 0, QApplication::UnicodeUTF8));
        label_10->setText(QApplication::translate("MainWindow", "\346\227\245\345\277\227\347\252\227\345\217\243      \346\233\264\345\244\232\346\227\245\345\277\227\350\257\267\346\237\245\347\234\213\342\200\230log.txt\342\200\231", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
