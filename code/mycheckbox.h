#ifndef MYCHECKBOX_H
#define MYCHECKBOX_H

#include <QWidget>

namespace Ui {
class MyCheckBox;
}

class MyCheckBox : public QWidget
{
    Q_OBJECT

public:
    explicit MyCheckBox(int num, bool isCheck = false,QWidget *parent = nullptr);
    QString getText();
    void setText(QString text);
    void closeBox();
    bool getCheck();
    //void setCheck(bool f);
    int Num;
    ~MyCheckBox();
private:
    bool flag;
private:
    Ui::MyCheckBox *ui;
signals:
    void checkBoxClose(int num);
    void makeHook(int num);
    void cancelHook(int num);
};

#endif // MYCHECKBOX_H
