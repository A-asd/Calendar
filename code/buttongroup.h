#ifndef BUTTONGROUP_H
#define BUTTONGROUP_H
#include"mypushbutton.h"
#include <QMainWindow>
#include <vector>
class ButtonGroup : public QMainWindow
{
    Q_OBJECT
public:
    explicit ButtonGroup(QWidget *parent = nullptr);
    ButtonGroup(QString year, QString month,QWidget *parent);
    void set(QString year,QString month);
    QString year,month;
    QVector<MyPushButton*>v;
private:
    void createConnect();
public:
signals:
    void myClickSignal(QString year,QString month,QString day);
public slots:
    void connectSlot(QString year,QString month,QString day);

};

#endif // BUTTONGROUP_H
