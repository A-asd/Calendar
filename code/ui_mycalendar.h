/********************************************************************************
** Form generated from reading UI file 'mycalendar.ui'
**
** Created by: Qt User Interface Compiler version 6.1.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MYCALENDAR_H
#define UI_MYCALENDAR_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MyCalendar
{
public:
    QWidget *centralwidget;
    QLabel *label;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *label_9;
    QLabel *label_10;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QPushButton *pushButton_3;
    QMenuBar *menubar;

    void setupUi(QMainWindow *MyCalendar)
    {
        if (MyCalendar->objectName().isEmpty())
            MyCalendar->setObjectName(QString::fromUtf8("MyCalendar"));
        MyCalendar->resize(358, 621);
        MyCalendar->setStyleSheet(QString::fromUtf8("QLabel{\n"
"	font: 12pt \"\347\255\211\347\272\277\";\n"
"}"));
        centralwidget = new QWidget(MyCalendar);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(24, 20, 111, 21));
        label->setStyleSheet(QString::fromUtf8("QLabel{\n"
"	text-align:left; \n"
"	\n"
"	font: 16pt \"\346\245\267\344\275\223\";\n"
"}"));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(290, 20, 14, 19));
        pushButton->setStyleSheet(QString::fromUtf8("background-color: rgb(217, 217, 217);"));
        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(310, 20, 14, 19));
        pushButton_2->setStyleSheet(QString::fromUtf8("background-color: rgb(217, 217, 217);"));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(24, 50, 31, 31));
        label_2->setStyleSheet(QString::fromUtf8(""));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(71, 50, 31, 31));
        label_3->setStyleSheet(QString::fromUtf8(""));
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(118, 50, 31, 31));
        label_4->setStyleSheet(QString::fromUtf8(""));
        label_5 = new QLabel(centralwidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(165, 50, 31, 31));
        label_5->setStyleSheet(QString::fromUtf8(""));
        label_6 = new QLabel(centralwidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(212, 50, 31, 31));
        label_6->setStyleSheet(QString::fromUtf8(""));
        label_7 = new QLabel(centralwidget);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(259, 50, 31, 31));
        label_7->setStyleSheet(QString::fromUtf8(""));
        label_8 = new QLabel(centralwidget);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(306, 50, 31, 31));
        label_8->setStyleSheet(QString::fromUtf8(""));
        label_9 = new QLabel(centralwidget);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(20, 383, 221, 21));
        label_9->setStyleSheet(QString::fromUtf8("font: 14pt \"\345\256\213\344\275\223\";\n"
"font-weight:bold;"));
        label_10 = new QLabel(centralwidget);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setGeometry(QRect(20, 412, 91, 20));
        scrollArea = new QScrollArea(centralwidget);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        scrollArea->setGeometry(QRect(20, 440, 321, 121));
        scrollArea->setWidgetResizable(false);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 319, 119));
        scrollArea->setWidget(scrollAreaWidgetContents);
        pushButton_3 = new QPushButton(centralwidget);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setGeometry(QRect(310, 420, 31, 21));
        pushButton_3->setCursor(QCursor(Qt::PointingHandCursor));
        MyCalendar->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MyCalendar);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 358, 21));
        MyCalendar->setMenuBar(menubar);

        retranslateUi(MyCalendar);

        QMetaObject::connectSlotsByName(MyCalendar);
    } // setupUi

    void retranslateUi(QMainWindow *MyCalendar)
    {
        MyCalendar->setWindowTitle(QCoreApplication::translate("MyCalendar", "MainWindow", nullptr));
        label->setText(QCoreApplication::translate("MyCalendar", "2021\345\271\26410\346\234\210", nullptr));
        pushButton->setText(QString());
        pushButton_2->setText(QString());
        label_2->setText(QCoreApplication::translate("MyCalendar", "\344\270\200", nullptr));
        label_3->setText(QCoreApplication::translate("MyCalendar", "\344\272\214", nullptr));
        label_4->setText(QCoreApplication::translate("MyCalendar", "\344\270\211", nullptr));
        label_5->setText(QCoreApplication::translate("MyCalendar", "\345\233\233", nullptr));
        label_6->setText(QCoreApplication::translate("MyCalendar", "\344\272\224", nullptr));
        label_7->setText(QCoreApplication::translate("MyCalendar", "\345\205\255", nullptr));
        label_8->setText(QCoreApplication::translate("MyCalendar", "\346\227\245", nullptr));
        label_9->setText(QCoreApplication::translate("MyCalendar", "\346\230\237\346\234\237\344\272\224 8 \344\271\235\346\234\210\345\210\235\344\270\211 \345\257\222\351\234\234", nullptr));
        label_10->setText(QCoreApplication::translate("MyCalendar", "\345\276\205\345\212\236\344\272\213\351\241\271", nullptr));
        pushButton_3->setText(QCoreApplication::translate("MyCalendar", "\346\267\273\345\212\240", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MyCalendar: public Ui_MyCalendar {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MYCALENDAR_H
