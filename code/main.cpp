#include "mainwindow.h"
#include <QApplication>
#include"lunar.h"
#include"mycheckbox.h"
#include<QLabel>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

        MainWindow w;
        w.show();

//    QWidget w;
//    QLabel label(&w);
//    Lunar l;
//    int s = l.weekOfDate(2022,1,1);
//    label.setText(QString::number(s));
//    //label.setText(l.getLunar(2022,1,1));
//    w.show();
    return a.exec();
}
