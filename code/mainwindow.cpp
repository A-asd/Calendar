#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDateTime>
#include<QPen>
#include"lunar.h"
#include"mypushbutton.h"
#include"parameter.h"
#include<QMovie>
#include<QRegularExpression>
#include<QRegularExpressionMatch>
#include<QFile>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    this->setFixedSize(WIDTH,HEIGHT);
    this->setGeometry(530,100,WIDTH,HEIGHT);
    QDateTime time;
    QString timeString = time.currentDateTime().toString("H:mm:ss");
    ui->label->setText(timeString);
    this->setWindowFlags(Qt::CustomizeWindowHint);

    //设置时间
    startTimer(1000);
    //设置日期
    timeString = time.currentDateTime().toString ("yyyy年MM月dd日");
    QString year = time.currentDateTime().toString ("yyyy");
    QString month = time.currentDateTime().toString ("MM");
    QString day = time.currentDateTime().toString ("dd");
    timeString+=" ";
    Lunar lunar;
    timeString+=lunar.getLunar(year,month,day);
    ui->pushButton->setText(timeString);
    //创建日历表
    this->mycalendar = new MyCalendar(this);
    this->mycalendar->setWindowFlags(Qt::CustomizeWindowHint);
    this->mycalendar->setGeometry(0,UPLINE,WIDTH,HEIGHT-UPLINE);
    this->mycalendar->show();
    //展开按钮
    connect(this->mycalendar,&MyCalendar::scheduleButtonClicked,[=](bool flag){
        enlargeFlag=flag;
        if(flag)
        {
            this->setFixedSize(WIDTH,ALLSHOWHEIGHT);
            //设置背景
            //this->setMovie(this->weather);
            this->setMovie(this->weather);
        }
        else
        {
            this->setFixedSize(WIDTH,HEIGHT);
            //设置背景
            //this->setMovie(this->weather);
            this->setMovie(this->weather);
        }
    });
    //获取天气信息
    this->getWeatherInfo();

    //设置按钮返回当前时间的事
    connect(ui->pushButton,&QPushButton::clicked,[=](){
        emit this->mycalendar->returnNowThing();
    });
}

void MainWindow::timerEvent(QTimerEvent *event)//时间显示
{
    Q_UNUSED(event);
    QDateTime time;
    QString timeString = time.currentDateTime().toString("H:mm:ss");
    ui->label->setText(timeString);
}

//void MainWindow::paintEvent(QPaintEvent *event)
//{
//    Q_UNUSED(event);
//    QPainter painter(this);
//    QPen pen(QColor(0,0,0));
//    painter.setPen(pen);
//    painter.drawLine(0,UPLINE,this->width(),UPLINE);
//    if(this->enlargeFlag==true){
//        painter.drawLine(0,HEIGHT-24,this->width(),HEIGHT-24);
//    }
//    //painter.drawLine(0,0.35*HEIGHT,this->width(),0.35*HEIGHT);
//}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setMovie(QString weather)//设置背景
{
    ui->label_2->setGeometry(0,0,this->width(),this->height());
    if(weather.indexOf("雨")!=-1){
        QMovie *movie = new QMovie(":/gif/Image/perfectrain.gif");
        ui->label_2->setMovie(movie);
        movie->setScaledSize(QSize(ui->label_2->width(),ui->label_2->height()));
        movie->start();

        return;
    }
    else{
        QPixmap *pixmap;
        if(weather=="多云")
            pixmap = new QPixmap(":/Image/cludy1.jpeg");
        else if(weather=="晴")
            pixmap = new QPixmap(":/Image/sun1.jpeg");
        else if(weather=="阴")
            pixmap = new QPixmap(":/Image/overcast3.jpeg");
        else
            pixmap = new QPixmap(":/Image/what1.jpeg");
        //pixmap->scaled(ui->label_2->size());
        pixmap->scaled(ui->label_2->size(),Qt::IgnoreAspectRatio);
        ui->label_2->setPixmap(*pixmap);
    }
}

void MainWindow::getWeatherInfo()//获取天气信息
{
    this->manager = new QNetworkAccessManager(this);
    QString path ="http://weathernew.pae.baidu.com/weathernew/pc?query=%E5%B9%BF%E4%B8%9C%E5%B9%BF%E5%B7%9E%E5%A4%A9%E6%B0%94&srcid=4982&city_name=%E5%B9%BF%E5%B7%9E&province_name=%E5%B9%BF%E4%B8%9C";
    QNetworkRequest *request=new QNetworkRequest((QUrl(path)));
    connect(this->manager,&QNetworkAccessManager::finished,this,&MainWindow::weatherSlot);
    this->manager->get(*request);

}
QString match(const QString &text,const QString &pa){
    QRegularExpression regular(pa);
    QRegularExpressionMatch match = regular.match(text);
    QString ci;
    if(match.hasMatch()){
        ci = match.captured(0);
        do {
            int idx = ci.indexOf("\\u");
            QString strHex = ci.mid(idx, 6);
            strHex = strHex.replace("\\u", QString());
            int nHex = strHex.toInt(0, 16);
            ci.replace(idx, 6, QChar(nHex));
        } while (ci.indexOf("\\u") != -1);
    }
    return ci;
}
void MainWindow::weatherSlot(QNetworkReply*reply)
{
    QString text = reply->readAll();
    if(text.isEmpty()){
        ui->label_3->setText("");
        ui->label_4->setText("");
        reply->deleteLater();
        this->setMovie("other");
        return;
    }
    QString pattern = "(?<=city\":\")(\\\\\\w{5}){2}";
    this->city=match(text,pattern);;

    //天气
    pattern = "(?<=weather\":\").*?(?=\")";
    QString w1 = match(text,pattern);
    this->weather = w1;

    //起始温度
    pattern = "(?<=temperature_night\":\")\\d{2}";
    QString w2 = match(text,pattern);

    //结束温度
    pattern = "(?<=temperature_day\":\")\\d{2}";
    QString w3 = match(text,pattern);

    //风向
    pattern = "(?<=\"wind_direction_night\":\").*?(?=\")";
    QString w4 = match(text,pattern);

    //风强
    pattern = "(?<=wind_power_night\":\").{8}";
    QString w5 = match(text,pattern);

    this->weatherInfo=QString("%1 %2℃~%3℃ %4%5").arg(w1,w2,w3,w4,w5);
    ui->label_3->setText(this->city);
    ui->label_4->setText(this->weatherInfo);

    //this->setMovie(this->weather);
    this->setMovie(this->weather);
    reply->deleteLater();
}

void MainWindow::mousePressEvent(QMouseEvent *event)
{

    if( (event->button() == Qt::LeftButton) ){
        mouse_press = true;
        mousePoint = event->globalPos() - this->pos();

    }
    else if(event->button() == Qt::RightButton){
        this->close();
        this->mycalendar->saveThing();
    }
}
void MainWindow::mouseMoveEvent(QMouseEvent *event)
{
    if(mouse_press){
        move(event->globalPos() - mousePoint);
    }
}
void MainWindow::mouseReleaseEvent(QMouseEvent *event)
{
    Q_UNUSED(event);
    mouse_press = false;
}


