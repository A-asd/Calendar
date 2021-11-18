#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include<QTimer>
#include<QPaintEvent>
#include<QPainter>
#include"mycalendar.h"
#include <QMouseEvent>
#include<QNetworkAccessManager>
#include<QNetworkReply>
#include<QNetworkRequest>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    void timerEvent(QTimerEvent *event);
    //void paintEvent(QPaintEvent*event);
    ~MainWindow();
public:
    MyCalendar *mycalendar;
    bool enlargeFlag;
private:
    Ui::MainWindow *ui;
    void setMovie(QString weather);
    void getWeatherInfo();
    QNetworkAccessManager *manager;
    QString city;
    QString weatherInfo;
    QString weather;
private slots:
    void weatherSlot(QNetworkReply*reply);

//others
protected:
    void mouseMoveEvent(QMouseEvent *event);
    void mousePressEvent(QMouseEvent *event);
void mouseReleaseEvent(QMouseEvent *event);
private:
    QPoint mousePoint;
    bool mouse_press;
};
#endif // MAINWINDOW_H
