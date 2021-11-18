#include "mycalendar.h"
#include "ui_mycalendar.h"
#include"mypushbutton.h"
#include<QDateTime>
#include<QLabel>
#include"buttongroup.h"
#include"parameter.h"
#include<QPropertyAnimation>
#include<QParallelAnimationGroup>
#include<QTimer>
#include<lunar.h>
#include<QFile>
#include<QDir>
MyCalendar::MyCalendar(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MyCalendar)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::CustomizeWindowHint);
    resize(WIDTH,HEIGHT-UPLINE);
    //初始化 设置动画的位置
    this->initValue();
    //设置动画
    this->setAnimation();
    //设置日程按钮
    button3 = new QPushButton("显示日程",this);
    button3->setGeometry(this->width()-button3->width(),
                         this->height()-button3->height()*1.5,button3->width(),button3->height());
    //button3->setStyleSheet("background:transparent; font: 11pt \"黑体\";color:rgb(15, 51, 255);");
    QString style ="QPushButton{"
         "   background:transparent;"
         "   font: 14pt \"楷体\";"
        "    text-align:left;"

        "    color: rgb(0, 0, 168);"
       " }"
       " QPushButton:hover{"

       "     color: rgb(180, 180, 180);"
       " }"
       " QPushButton:pressed{"
        "    color: rgb(160, 160, 160);"
       " }";
    button3->setStyleSheet(style);
    button3->setCursor(Qt::PointingHandCursor);
    //设置展开按钮
    this->setScheduleButton();
    //设置日期点击连接
    this->setDateClickedConnect();
    //设置记事
    setThing();
    //设置设置下线的日期
    Lunar lunar;
    QString arr[7] ={"一","二","三","四","五","六","日"};
    int week = lunar.weekOfDate(year,month,day);
    QString res="";
    res="星期"+arr[week-1]+" "+day+" "+lunar.getLunar(year,month,day);
    ui->label_9->setText(res);
    this->showThing();
}
void nextMonth(QString &year,QString &month)
{
    if(month=="12"){
        year = QString::number(year.toInt()+1);
        month = "1";
    }else month = QString::number(month.toInt()+1);
}
void lastMonth(QString &year,QString &month)
{
    if(month=="1"){
        year = QString::number(year.toInt()-1);
        month = "12";
    }else month = QString::number(month.toInt()-1);
}

void MyCalendar::initValue()
{
    //设置当前日期时间
    this->year = QDate::currentDate().toString("yyyy");
    this->month = QDate::currentDate().toString("M");
    this->day = QDate::currentDate().toString("d");
    //设置被选中
    this->selectedYear = this->year;
    this->selectedMonth = this->month;
    this->selectedDay = this->day;
    //上个月
    QString year = QDate::currentDate().toString("yyyy");
    QString month = QDate::currentDate().toString("M");
    lastMonth(year,month);
    groupLast = new ButtonGroup(year,month,this);
    //这个月
    year = QDate::currentDate().toString("yyyy");
    month = QDate::currentDate().toString("M");
    groupMid = new ButtonGroup(year,month,this);
    //下个月
    year = QDate::currentDate().toString("yyyy");
    month = QDate::currentDate().toString("M");
    nextMonth(year,month);
    groupNext = new ButtonGroup(year,month,this);

    groupLast->setParent(this);
    groupLast->setGeometry(-WIDTH,ATTHEIGTH,WIDTH-14*2,HEIGHT-24-UPLINE-ATTHEIGTH);

    groupMid->setParent(this);
    groupMid->setGeometry(19,ATTHEIGTH,WIDTH-14*2,HEIGHT-24-UPLINE-ATTHEIGTH);

    groupNext->setParent(this);
    groupNext->setGeometry(WIDTH,ATTHEIGTH,WIDTH-14*2,HEIGHT-24-UPLINE-ATTHEIGTH);
    //设置待办的个数
    this->boxNum = 0;

    //设置左右按钮的图片
    ui->pushButton->setIcon(QIcon(":/Image/left.png"));
    ui->pushButton_2->setIcon(QIcon(":/Image/right.png"));
}
void MyCalendar::setAnimation()//设置日历动画
{
    animation = new QPropertyAnimation(this->groupLast,"geometry");
    animation2 = new QPropertyAnimation(this->groupMid,"geometry");
    connect(ui->pushButton,&QPushButton::clicked,[&](){//上一个
        if(flag)
        {
            QParallelAnimationGroup *group = new QParallelAnimationGroup(this);
            animation->setTargetObject(this->groupLast);
            animation->setDuration(1500);
            animation->setStartValue(QRect(this->groupLast->geometry()));
            animation->setEndValue(QRect(this->groupMid->geometry()));
            animation2->setTargetObject(this->groupMid);
            animation2->setDuration(1500);
            animation2->setStartValue(QRect(this->groupMid->geometry()));
            animation2->setEndValue(QRect(this->groupNext->geometry()));

//            animation->start();
//            animation2->start();
            group->addAnimation(animation);
            group->addAnimation(animation2);
            group->start();

            groupNext->setGeometry(-WIDTH,ATTHEIGTH,WIDTH-14*2,HEIGHT-24-UPLINE-ATTHEIGTH);
            QString year = groupLast->year;
            QString month = groupLast->month;
            lastMonth(year,month);
            groupNext->set(year,month);

            ButtonGroup *temp = groupNext;
            groupNext = groupLast;
            groupLast = temp;

            temp = groupNext;
            groupNext = groupMid;
            groupMid = temp;

            QString a = groupMid->year+"年"+groupMid->month+"月";
            ui->label->setText(a);
            flag = false;
            //QTimer::singleShot(1510, [&]() { flag = true; });
            connect(animation,&QPropertyAnimation::finished,[&](){flag = true; });
            connect(animation2,&QPropertyAnimation::finished,[&](){flag = true; });
        }
    });
    connect(ui->pushButton_2,&QPushButton::clicked,[&](){//下一个
        if(flag)
        {
            animation->setTargetObject(this->groupMid);
            animation->setDuration(1500);
            animation->setStartValue(QRect(this->groupMid->geometry()));
            animation->setEndValue(QRect(this->groupLast->geometry()));

            animation2->setTargetObject(this->groupNext);
            animation2->setDuration(1500);
            animation2->setStartValue(QRect(this->groupNext->geometry()));
            animation2->setEndValue(QRect(this->groupMid->geometry()));

            animation->start();
            animation2->start();

            groupLast->setGeometry(WIDTH,ATTHEIGTH,WIDTH-14*2,HEIGHT-24-UPLINE-ATTHEIGTH);
            QString year = groupNext->year;
            QString month = groupNext->month;
            nextMonth(year,month);
            groupLast->set(year,month);

            ButtonGroup *temp = groupNext;
            groupNext = groupLast;
            groupLast = temp;

            temp = groupLast;
            groupLast = groupMid;
            groupMid = temp;

            QString a = groupMid->year+"年"+groupMid->month+"月";
            ui->label->setText(a);
            flag = false;
            connect(animation,&QPropertyAnimation::finished,[&](){flag = true; });
            connect(animation2,&QPropertyAnimation::finished,[&](){flag = true; });
            //QTimer::singleShot(1510, [&]() { flag = true; });
        }
    });
}
void MyCalendar::setScheduleButton()
{
    connect(button3,&QPushButton::clicked,[=](){
        if(this->schedule)
        {
            this->setFixedSize(WIDTH,ALLSHOWHEIGHT-UPLINE);
            emit scheduleButtonClicked(this->schedule);
            button3->setGeometry(this->width()-button3->width(),
                                 this->height()-button3->height()*1.5,button3->width(),button3->height());
            this->schedule=!this->schedule;
            button3->setText("隐藏日程");
        }
        else
        {
            this->setFixedSize(WIDTH,HEIGHT-UPLINE);
            emit scheduleButtonClicked(this->schedule);
            button3->setGeometry(this->width()-button3->width(),
                                 this->height()-button3->height()*1.5,button3->width(),button3->height());
            this->schedule=!this->schedule;
            button3->setText("显示日程");
        }
    });
}
void MyCalendar::update(QString year,QString month,QString day)
{
    this->saveThing();
    Lunar lunar;
    QString arr[7] ={"一","二","三","四","五","六","日"};
    int week = lunar.weekOfDate(year,month,day);
    QString res="";
    res="星期"+arr[week-1]+" "+day+" "+lunar.getLunar(year,month,day);
    ui->label_9->setText(res);
    this->selectedYear = year;
    this->selectedMonth = month;
    this->selectedDay = day;
    showThing();
}
void MyCalendar::setDateClickedConnect()
{
    connect(this->groupLast,&ButtonGroup::myClickSignal,[&](QString year,QString month,QString day){
        update(year,month,day);
    });
    connect(this->groupMid,&ButtonGroup::myClickSignal,[&](QString year,QString month,QString day){
        update(year,month,day);
    });
    connect(this->groupNext,&ButtonGroup::myClickSignal,[&](QString year,QString month,QString day){
        update(year,month,day);
    });
    //上层时间显示按钮接受信号
    connect(this,&MyCalendar::returnNowThing,this,[&](){update(this->year,this->month,this->day);});
}

void MyCalendar::setThing()//事项的设置
{
    connect(ui->pushButton_3,&QPushButton::clicked,[=](){//添加按钮
        this->addThing();
    });
    connect(this,&MyCalendar::acceptHook,[&](int n){//打勾按钮
        //设置动画
        QParallelAnimationGroup *group = new QParallelAnimationGroup;
        for(int i=n+1;i<boxNum;i++){
            QPropertyAnimation *a=new QPropertyAnimation(vBox[i],"pos");
            a->setDuration(800);
            a->setStartValue(vBox[i]->pos());
            a->setEndValue(vBox[i-1]->pos());
            group->addAnimation(a);
            vBox[i]->Num--;
        }
        QPropertyAnimation *b=new QPropertyAnimation(vBox[n],"pos");
        b->setDuration(500);
        b->setStartValue(vBox[n]->pos());
        b->setEndValue(QPoint(0,vBox[n]->height()*(boxNum-1)));
        group->addAnimation((b));

        //修改参数
        vBox[n]->Num = this->boxNum - 1;
        group->start();

        MyCheckBox *temp = vBox[n];
        for(int i = n;i<vBox.size()-1;i++){
            vBox[i] = vBox[i+1];
        }
        vBox[vBox.size()-1] = temp;
    });
    connect(this,&MyCalendar::acceptUnHook,[&](int n){//取消打勾
        //设置动画
        QParallelAnimationGroup *group = new QParallelAnimationGroup;
        for(int i=0;i<n;i++){
            QPropertyAnimation *a=new QPropertyAnimation(vBox[i],"pos");
            a->setDuration(800);
            a->setStartValue(vBox[i]->pos());
            a->setEndValue(vBox[i+1]->pos());
            group->addAnimation(a);
            vBox[i]->Num++;
        }
        QPropertyAnimation *b=new QPropertyAnimation(vBox[n],"pos");
        b->setDuration(500);
        b->setStartValue(vBox[n]->pos());
        b->setEndValue(QPoint(0,0));
        group->addAnimation((b));
        group->start();
        //修改参数
        vBox[n]->Num = 0;
        MyCheckBox *temp = vBox[n];
        for(int i = n;i>0;i--){
            vBox[i] = vBox[i-1];
        }
        vBox[0] = temp;
    });
    connect(this,&MyCalendar::acceptClose,[&](int n){//关闭按钮
        //设置动画
        QParallelAnimationGroup *group = new QParallelAnimationGroup;
        for(int i=n+1;i<boxNum;i++){
            QPropertyAnimation *a=new QPropertyAnimation(vBox[i],"pos");
            a->setDuration(800);
            a->setStartValue(vBox[i]->pos());
            a->setEndValue(vBox[i-1]->pos());
            group->addAnimation(a);
            vBox[i]->Num--;
        }
        group->start();
        //修改参数
        for(int i = n;i<vBox.size()-1;i++){
            vBox[i] = vBox[i+1];
        }
        vBox.pop_back();
        boxNum--;

    });

}
void MyCalendar::addThing(const QString &text,bool f)
{
    //
    QWidget *wid = ui->scrollAreaWidgetContents;
    MyCheckBox *box = new MyCheckBox(boxNum,f,wid);
    connect(box,&MyCheckBox::makeHook,[=](int n){
        emit this->acceptHook(n);
    });
    connect(box,&MyCheckBox::checkBoxClose,[=](int n){
        emit this->acceptClose(n);
    });
    connect(box,&MyCheckBox::cancelHook,[=](int n){
        emit this->acceptUnHook(n);
    });
    box->setGeometry(0,box->height()*boxNum,box->width(),box->height());
    box->show();
    int a = boxNum - 5>0?boxNum - 5:0;
    wid->setGeometry(0,0,ui->scrollArea->width()-20,ui->scrollArea->height()+a*box->height()+15);
    box->setText(text);
    vBox.push_back(box);
    boxNum++;
}

void MyCalendar::showThing()
{
    QString dirName=DIRNAME;
    QDir dir;
    if(!dir.exists(dirName)){
        dir.mkdir(dirName);
    }
    QFile file(dirName+"/"+this->selectedYear+"-"+this->selectedMonth+"-"+this->selectedDay+".txt");
    if(file.open(QFile::ReadOnly)){
        QTextStream in(&file);
        QString temp;
        bool s=false;
        while(!in.atEnd()){
            temp = in.readLine();
            if(temp[0]=='`'){
                temp = temp.remove(0,1);//temp.erase(temp.begin(),temp.begin()+1);
                s=true;
            }
            this->addThing(temp,s);
        }
        file.close();
    }
}

void MyCalendar::saveThing()
{
    if(vBox.empty())return;
    QString dirName = DIRNAME;
    QDir dir;
    if(!dir.exists(dirName)){
        dir.mkdir(dirName);
    }
    QString fileName=dirName+"/"+this->selectedYear+"-"+this->selectedMonth+"-"+this->selectedDay+".txt";
    QFile file(fileName);
    if(file.open(QFile::WriteOnly|QFile::Truncate)){
        for(int i=0;i<this->vBox.size();i++){
            QString temp = vBox[i]->getText();
            if(temp.isEmpty())continue;
            if(vBox[i]->getCheck())temp="`"+temp;
            file.write(temp.toStdString().data());//
            if(i<this->vBox.size()-1)file.write("\n");
        }
        file.close();
    }
    for(int i=0;i<vBox.size();i++){
        vBox[i]->close();
    }
    vBox.clear();
    this->boxNum = 0;
}
MyCalendar::~MyCalendar()
{
    delete ui;
}









