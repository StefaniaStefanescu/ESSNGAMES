#include "mainwindow.h"

#include <QApplication>
#include"tcpclient.h"

int main(int argc, char *argv[])
{


    QApplication a(argc, argv);

    //muzica de fundal

    //app

    tcpclient::getInstance().start("172.16.7.30",2001);

    MainWindow w;
    w.show();
    w.setFixedSize(500,500);
    //if(a.exec()==0){
    //    RequestLogout logout;
    //    if(logout._request()){
    //        qDebug()<<"Logout succeded!";
    //    }
    //}

    return a.exec();
}
