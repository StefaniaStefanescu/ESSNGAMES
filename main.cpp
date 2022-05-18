#include "mainwindow.h"

#include <QApplication>
#include"tcpclient.h"
#include<QDebug>

int main(int argc, char *argv[])
{


    QApplication a(argc, argv);

    //muzica de fundal

    //app
   //127.0.0.1
    //172.16.7.30
    tcpclient::getInstance().start("172.16.7.30",2001);

    MainWindow w;
    w.show();
    w.setFixedSize(500,500);



    return a.exec();
}
