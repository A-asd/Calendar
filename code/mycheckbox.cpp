#include "mycheckbox.h"
#include "ui_mycheckbox.h"

MyCheckBox::MyCheckBox(int num, bool isCheck, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MyCheckBox)
{
    ui->setupUi(this);
    Num=num;
    //设置图片
    ui->pushButton->setIcon(QIcon(":/Image/hook.jpeg"));
    ui->pushButton_2->setIcon(QIcon(":/Image/min.png"));
    if(isCheck){
        ui->lineEdit->setStyleSheet("text-decoration:line-through;color:gray");
    }else
    {
        ui->pushButton->setIconSize(QSize(0,0));
        //ui->lineEdit->setStyleSheet("text-decoration:normal;");
    }
    flag = isCheck;
    connect(ui->pushButton,&QPushButton::clicked,[=](){
       if(flag){
           ui->pushButton->setIconSize(QSize(0,0));
           flag = false;
           ui->lineEdit->setStyleSheet("text-decoration:normal;");
           emit this->cancelHook(this->Num);
       }
       else{
           ui->pushButton->setIconSize(QSize(ui->pushButton->width(),ui->pushButton->height()));
           flag = true;
           ui->lineEdit->setStyleSheet("text-decoration:line-through;color:gray");
           emit this->makeHook(this->Num);
       }
    });
    connect(ui->pushButton_2,&QPushButton::clicked,[=](){
        emit this->checkBoxClose(this->Num);
        this->close();
    });
}

QString MyCheckBox::getText()
{
    return ui->lineEdit->text();
}

void MyCheckBox::setText(QString text)
{
    ui->lineEdit->setText(text);
}

void MyCheckBox::closeBox()
{
    this->close();
}

bool MyCheckBox::getCheck()
{
    return flag;
}


MyCheckBox::~MyCheckBox()
{
    delete ui;
}
