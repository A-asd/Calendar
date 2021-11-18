#ifndef MYCALENDAR_H
#define MYCALENDAR_H
#include<QMap>
#include <QMainWindow>
#include"buttongroup.h"
#include<QPropertyAnimation>
#include"mycheckbox.h"
#include<QPair>
#include<QList>
namespace Ui {
class MyCalendar;
}

class MyCalendar : public QMainWindow
{
    Q_OBJECT

public:
    explicit MyCalendar(QWidget *parent = nullptr);
    ~MyCalendar();
    bool schedule = true;
    void saveThing();
private:
    void initValue();
    void setAnimation();
    void setScheduleButton();
    void setDateClickedConnect();
    QPropertyAnimation *animation,*animation2;
    void setThing();
    void addThing(const QString &text = "",bool f = false);
    void showThing();
    void update(QString year,QString month,QString day);

signals:
    void scheduleButtonClicked(bool flag);
    void acceptHook(int num);
    void acceptClose(int num);
    void acceptUnHook(int num);
    void returnNowThing();

private:
    ButtonGroup *groupLast,*groupMid,*groupNext;
    QPushButton *button3;
    bool flag=true;
    QString year,month,day;
    QString selectedYear,selectedMonth,selectedDay;
    QVector<MyCheckBox*>vBox;
    int boxNum;
private:
    Ui::MyCalendar *ui;
};

#endif // MYCALENDAR_H
