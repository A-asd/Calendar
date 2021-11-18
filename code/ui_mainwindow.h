/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.1.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLabel *label;
    QPushButton *pushButton;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(398, 733);
        MainWindow->setStyleSheet(QString::fromUtf8(""));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(24, 26, 171, 41));
        label->setStyleSheet(QString::fromUtf8("QLabel{\n"
"	\n"
"	font: 25 36pt \"\347\255\211\347\272\277 Light\";\n"
"}"));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(24, 70, 241, 21));
        pushButton->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	background:transparent;\n"
"	font: 14pt \"\346\245\267\344\275\223\";\n"
"	text-align:left;\n"
"	\n"
"	\n"
"	color: rgb(0, 0, 168);\n"
"}\n"
"QPushButton:hover{\n"
"	\n"
"	\n"
"	\n"
"	color: rgb(0, 170, 255);\n"
"}\n"
"QPushButton:pressed{\n"
"	color: rgb(160, 160, 160);\n"
"}\n"
""));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(240, 20, 71, 31));
        label_2->setStyleSheet(QString::fromUtf8(""));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(23, 98, 41, 21));
        label_3->setStyleSheet(QString::fromUtf8("font: 16pt \"\345\256\213\344\275\223\";\n"
"\n"
"color: rgb(0, 0, 0);"));
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(70, 100, 321, 21));
        label_4->setStyleSheet(QString::fromUtf8("font: 11pt \"\345\256\213\344\275\223\";\n"
"color: rgb(0, 0, 0);"));
        MainWindow->setCentralWidget(centralwidget);
        label_2->raise();
        label->raise();
        pushButton->raise();
        label_3->raise();
        label_4->raise();
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 398, 21));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "19:25:38", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "2021\345\271\26410\346\234\21014\346\227\245 \344\271\235\346\234\210\345\210\235\344\271\235", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "test", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "\345\271\277\345\267\236", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "\345\244\232\344\272\221 19\342\204\203-28\342\204\203 \345\244\234\351\227\264\351\243\216\345\220\221:\346\227\240\346\214\201\347\273\255\351\243\216\345\220\221<3\347\272\247", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
