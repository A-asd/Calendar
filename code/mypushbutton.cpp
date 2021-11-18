#include "mypushbutton.h"
#include"lunar.h"
#include<QDate>
#include"parameter.h"
MyPushButton::MyPushButton(QWidget *parent) : QPushButton(parent)
{

}

MyPushButton::MyPushButton(QString year, QString month, QString day)
{
    set(year,month,day);
    connect(this,&MyPushButton::clicked,this,[=](){
        emit myClickSignal(this->year,this->month,this->day);
    });
}

void MyPushButton::set(QString year, QString month, QString day)
{
    this->year = year;
    this->month = month;
    this->day = day;
    this->setStyleSheet("QPushButton{background:transparent;text-align:left;border-style: outset;}"
                        "QPushButton:hover{border: 2px solid white;text-align:left;color:white;border-style: outset;}"
                        "QPushButton:pressed{border: 2px solid blue;border-style: inset; }");
    //
    Lunar lunar;
    QString s=lunar.getLunar(year,month,day);
    int dex = s.indexOf("月");
    QString res=s.mid(dex+1,s.size()-dex-1);
    if(this->day.size()==1){
        this->setText("   "+this->day+"\n"+res);
    }else{
        this->setText(" "+this->day+"\n"+res);
    }
    //this->adjustSize();
    this->resize(LATTICEWIDTH,LATTICEHEIGTH);

}
