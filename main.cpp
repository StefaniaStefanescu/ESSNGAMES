#include "mainwindow.h"

#include <QApplication>
#include"tcpclient.h"
int main(int argc, char *argv[])
{


    QApplication a(argc, argv);

    //muzica de fundal

    //app

    tcpclient::getInstance().start("172.16.7.30",2001);
   // QString rasp=tcpclient::getInstance().getData("1/niasns/niasns/");
    MainWindow w;
    w.show();
    w.setFixedSize(500,500);


    return a.exec();
}
