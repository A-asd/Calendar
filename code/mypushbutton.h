#ifndef MYPUSHBUTTON_H
#define MYPUSHBUTTON_H
#include<QPushButton>
#include <QWidget>

class MyPushButton : public QPushButton
{
    Q_OBJECT
public:
    explicit MyPushButton(QWidget *parent = nullptr);
    MyPushButton(QString year,QString month,QString day);
    void set(QString year,QString month,QString day);
    QString year,month,day;

signals:
    void myClickSignal(QString year,QString month,QString day);
};

#endif // MYPUSHBUTTON_H
