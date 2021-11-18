#include "buttongroup.h"
#include"parameter.h"
#include<QDate>
#include"lunar.h"
ButtonGroup::ButtonGroup(QWidget *parent) : QMainWindow(parent)
{

}
int monthDay(QString year, QString month)
{
    int arr[13]={-1,31,28,31,30,31,30,31,31,30,31,30,31};
    if(year.toInt()%400==0||(year.toInt()%4==0&&year.toInt()%100!=0)){
        arr[2]=29;
    }
    return arr[month.toInt()];
}

ButtonGroup::ButtonGroup(QString year, QString month,QWidget *parent): QMainWindow(parent)
{
    for(int i=0;i<31;i++)
    {
        MyPushButton *button = new MyPushButton("1","1","1");
        button->setParent(this);
        v.push_back(button);
    }
    //this->setStyleSheet("background-color:red");
    this->year="";
    this->month="";
    set(year,month);
    //创建点击连接
    this->createConnect();
}

void ButtonGroup::set(QString year, QString month)//设置月份
{
    if(year!=""&&month!=""){
        for(int i=0;i<31;i++){
            this->v[i]->hide();
        }
    }
    this->year = year;
    this->month = month;
    this->setWindowFlags(Qt::CustomizeWindowHint);
    int dayNum = monthDay(year,month);
    int interval = 1.0*M;
    Lunar lunar;
    int weekday = lunar.weekOfDate(year,month,"1");

    int row=0;
    for(int i=weekday-1;i<dayNum+weekday-1;i++){
        if(i!=weekday-1&&i%7==0)row++;
        //MyPushButton *button = new MyPushButton(year,month,QString::number(i-weekday+2));
        MyPushButton *button = this->v[i-weekday+1];
        button->set(year,month,QString::number(i-weekday+2));
        button->setGeometry(i%7*interval,row*interval,button->width(),button->height());
        button->show();
    }
}

void ButtonGroup::createConnect()
{
    for(QVector<MyPushButton*>::iterator it = this->v.begin();it!=v.end();it++){
        void (MyPushButton:: *signal)(QString,QString,QString) = &MyPushButton::myClickSignal;
        void (ButtonGroup::*slot)(QString,QString,QString) = &ButtonGroup::connectSlot;
        connect(*it,signal,this,slot);
    }
}

void ButtonGroup::connectSlot(QString year, QString month, QString day)
{
    emit this->myClickSignal(year,month,day);
}
