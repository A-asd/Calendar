/********************************************************************************
** Form generated from reading UI file 'mycheckbox.ui'
**
** Created by: Qt User Interface Compiler version 6.1.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MYCHECKBOX_H
#define UI_MYCHECKBOX_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MyCheckBox
{
public:
    QPushButton *pushButton;
    QLineEdit *lineEdit;
    QPushButton *pushButton_2;

    void setupUi(QWidget *MyCheckBox)
    {
        if (MyCheckBox->objectName().isEmpty())
            MyCheckBox->setObjectName(QString::fromUtf8("MyCheckBox"));
        MyCheckBox->resize(300, 22);
        pushButton = new QPushButton(MyCheckBox);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(0, 0, 21, 21));
        lineEdit = new QLineEdit(MyCheckBox);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(20, 0, 258, 21));
        lineEdit->setStyleSheet(QString::fromUtf8("font-style:itelic;"));
        lineEdit->setMaxLength(24);
        pushButton_2 = new QPushButton(MyCheckBox);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(278, 0, 21, 22));
        pushButton_2->setStyleSheet(QString::fromUtf8("border:0px;"));

        retranslateUi(MyCheckBox);

        QMetaObject::connectSlotsByName(MyCheckBox);
    } // setupUi

    void retranslateUi(QWidget *MyCheckBox)
    {
        MyCheckBox->setWindowTitle(QCoreApplication::translate("MyCheckBox", "Form", nullptr));
        pushButton->setText(QString());
        lineEdit->setText(QCoreApplication::translate("MyCheckBox", "\344\273\212\345\244\251\346\230\2572021\345\271\26410\346\234\21021\346\227\245\357\274\214\345\244\251\346\260\224\345\244\232\344\272\221\343\200\202\345\206\231\344\275\234", nullptr));
        pushButton_2->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MyCheckBox: public Ui_MyCheckBox {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MYCHECKBOX_H
