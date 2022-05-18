#include "gamesw.h"
#include "ui_gamesw.h"
#include<QPixmap>
#include<QProcess>
#include<QFile>
#include<QTextStream>
#include"QStringList"
#include"chatw.h"




GamesW::GamesW(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::GamesW),caz(0)
{
    ui->setupUi(this);
    QPixmap pix(":/imagini/login_icon.jpeg");
    int w =ui->label_mwuser->width();
    int h=ui->label_mwuser->height();
    ui->label_mwuser->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));
    //aici ar trebui sa pun username-ul utilizatorului logat
    ui->label_mwusername->setText(tcpclient::getInstance().getUsername());
    QPixmap pix2(":/imagini/choose.png");
    w =ui->label_currentgame->width();
    h=ui->label_currentgame->height();
    ui->label_currentgame->setPixmap(pix2.scaled(w,h,Qt::KeepAspectRatio));
    ui->label_descriere->setText("Choose a game, then select 'INFO'\nif you want to see "
                                 "\ninformation about the game.\n");

    RequestMyFriends requestt;
    QString frlist=requestt._req();
    QStringList list;
    list=frlist.split("/");
    foreach(QString item, list)
       { if(item!=" ")
        ui->friendslist->addItem(item);

    }
    RequestAllTops request;
    QString str=request._req();
    QStringList lista=str.split("/");
    foreach(QString item,lista){
        if(item!=0)
        {
            ui->TopList->addItem(item);
        }
    }
}

GamesW::~GamesW()
{

    RequestLogout logout;
       if(logout._request()){
          qDebug()<<"Logout succeded!";
          tcpclient::getInstance().stop();
          tcpclient::destroyInstance();
        }
    delete ui;
}

void GamesW::on_add_button_clicked()
{
    ui->lineEdit_search->setPlaceholderText("search username");
    QString tosearch=ui->lineEdit_search->text();
    RequestAddFriend requestt(tcpclient::getInstance().getUsername(),tosearch);

    if(tosearch==""){
        return;         //nu trimit catre server nimic daca nu a fost introdusa o valoare
    }
    //cerere catre server sa verifice daca username-ul este existent -->daca este existent il adaug in lista de prieteni
    //totodata trebuie sa verifice daca user-ul este deja prieten cu mine
    if(requestt._request())
    {
        ui->friendslist->addItem(tosearch);
    }
    else{
        CExceptie exc;
        exc.AddFriendError();


    }
}


void GamesW::on_delete_button_clicked()
{
    //la butonul delete se apasa pe itemul din lista
    QListWidgetItem *it=ui->friendslist->takeItem(mnSelected);
    QString item=it->text();
    RequestDeleteFriend requestt(tcpclient::getInstance().getUsername(),item);
    if(requestt._request())
    {    delete it;
    }else{
        CExceptie exc;
        exc.DeleteFriendError();
    }
}


void GamesW::on_friendslist_currentRowChanged(int currentRow)
{
    mnSelected=currentRow;
}


void GamesW::on_pb_joc1_clicked()
{
    caz=1;
    //print game photo
    //get the right game
    RequestGameImage imagine("spaceinvaders");
    QPixmap pix2(imagine.req());
    //QPixmap pix2(":/imagini/spaceinv2.png");
    int w =ui->label_currentgame->width();
    int h=ui->label_currentgame->height();
    ui->label_currentgame->setPixmap(pix2.scaled(w,h,Qt::KeepAspectRatio));

}


void GamesW::on_pb_joc2_clicked()
{
    caz=2;
    RequestGameImage imagine("flappybird");
    QPixmap pix2(imagine.req());
    //QPixmap pix2(":/imagini/flappybird.jpg");
    int w =ui->label_currentgame->width();
    int h=ui->label_currentgame->height();
    ui->label_currentgame->setPixmap(pix2.scaled(w,h,Qt::KeepAspectRatio));

}


void GamesW::on_pb_joc3_clicked()
{
    caz=3;
    RequestGameImage imagine("snake");
    QPixmap pix2(imagine.req());
    //QPixmap pix2(":/imagini/snake.jpg");
    int w =ui->label_currentgame->width();
    int h=ui->label_currentgame->height();
    ui->label_currentgame->setPixmap(pix2.scaled(w,h,Qt::KeepAspectRatio));
}


void GamesW::on_pb_joc4_clicked()
{
    caz=4;
    RequestGameImage imagine("mario");
    QPixmap pix2(imagine.req());
    //QPixmap pix2(":/imagini/mario.jpg");
    int w =ui->label_currentgame->width();
    int h=ui->label_currentgame->height();
    ui->label_currentgame->setPixmap(pix2.scaled(w,h,Qt::KeepAspectRatio));
}


void GamesW::on_pb_joc5_clicked()
{
     caz=5;
     RequestGameImage imagine("sudoku");
     QPixmap pix2(imagine.req());
     //QPixmap pix2(":/imagini/sudokuim.jpg");
     int w =ui->label_currentgame->width();
     int h=ui->label_currentgame->height();
     ui->label_currentgame->setPixmap(pix2.scaled(w,h,Qt::KeepAspectRatio));
}

void GamesW::on_pb_joc6_clicked()
{
    caz=6;
    RequestGameImage imagine("tetris");
    QPixmap pix2(imagine.req());
    //QPixmap pix2(":/imagini/tetrisim.jpg");
    int w =ui->label_currentgame->width();
    int h=ui->label_currentgame->height();
    ui->label_currentgame->setPixmap(pix2.scaled(w,h,Qt::KeepAspectRatio));
}


void GamesW::on_pb_play_clicked()
{
    QProcess *process = new QProcess(this);


    RequestGamePath path;
    if(caz==1)
    {
     QElapsedTimer timer;
     timer.start();
     // we want to measure the time of this slowOperation()
     process->start(path.req("spaceinvaders"));
     //process->start("qrc:/../../../../../exespaceinv2/SpaceInvaders.exe");
     int Milliseconds=timer.elapsed();
     RequestSendScore request("spaceinvaders",Milliseconds);
     bool ans=request._request();
     if(ans){
         RequestAllTops request;
         QString str=request._req();
         QStringList lista=str.split("/");
         ui->TopList->clear();
         foreach(QString item,lista){
             if(item!=0)
             {
                 ui->TopList->addItem(item);
             }
         }

     }
     //process->start("qrc:/../../../../../exespaceinv2/SpaceInvaders.exe");
    }
    else if(caz==2){
       QElapsedTimer timer;
       timer.start();
       process->start(path.req("flappybird"));
       int Milliseconds=timer.elapsed();
       RequestSendScore request("flappybird",Milliseconds);
       bool ans=request._request();
       if(ans){
           RequestAllTops request;
           QString str=request._req();
           QStringList lista=str.split("/");
           ui->TopList->clear();
           foreach(QString item,lista){
               if(item!=0)
               {
                   ui->TopList->addItem(item);
               }
           }
       }

      //process->start(":/../../../../../exeflappybird2/FlappyBird.exe");
    }
    else if(caz==3)
    {
        QElapsedTimer timer;
        timer.start();
        process->start(path.req("snake"));
        int Milliseconds=timer.elapsed();
        RequestSendScore request("snake",Milliseconds);
        bool ans=request._request();
        if(ans){
            RequestAllTops request;
            QString str=request._req();
            QStringList lista=str.split("/");
            ui->TopList->clear();
            foreach(QString item,lista){
                if(item!=0)
                {
                    ui->TopList->addItem(item);
                }
            }
        }

        //process->start(":/../../../../../exesnake2/snake.exe");
    }
    else if(caz==4){
        QElapsedTimer timer;
        timer.start();
        process->start(path.req("mario"));
        int Milliseconds=timer.elapsed();
        RequestSendScore request("mario",Milliseconds);
        bool ans=request._request();
        if(ans){
            RequestAllTops request;
            QString str=request._req();
            QStringList lista=str.split("/");
            ui->TopList->clear();
            foreach(QString item,lista){
                if(item!=0)
                {
                    ui->TopList->addItem(item);
                }
            }
        }

         //process->start(":/../../../../../exemario2/gameMainWindow.exe");

    }else if(caz==5){
        QElapsedTimer timer;
        timer.start();
        process->start(path.req("sudoku"));
        int Milliseconds=timer.elapsed();
        RequestSendScore request("sudoku",Milliseconds);
        bool ans=request._request();
        if(ans){
            RequestAllTops request;
            QString str=request._req();
            QStringList lista=str.split("/");
            ui->TopList->clear();
            foreach(QString item,lista){
                if(item!=0)
                {
                    ui->TopList->addItem(item);
                }
            }
        }

        //process->start(":/../../../../../sudokuexe2/Sudoku.exe");
    }else if(caz==6){
        QElapsedTimer timer;
        timer.start();
        process->start(path.req("tetris"));

        int Milliseconds=timer.elapsed();
        RequestSendScore request("tetris",Milliseconds);
        bool ans=request._request();
        if(ans){
            RequestAllTops request;
            QString str=request._req();
            QStringList lista=str.split("/");
            ui->TopList->clear();
            foreach(QString item,lista){
                if(item!=0)
                {
                    ui->TopList->addItem(item);
                }
            }
        }

        //process->start(":/../../../../../tetrisexe2/QtTetris.exe");
    }


}




void GamesW::on_pb_info_clicked()
{
    if(caz==1)
    {
        //QFile file(":/../InfoJocuri/infospaceinvaders.txt");
        //file.open(QIODevice::ReadOnly);
        //QTextStream str(&file);
        //QString content = str.readAll();
        //file.close();

        //cereri catre server
        RequestGameDescription requestt("spaceinvaders");
        QString answer=requestt._req();
        ui->label_descriere->setText(answer);
    }
    else if(caz==2){
        RequestGameDescription requestt("flappybird");
        QString answer=requestt._req();
        ui->label_descriere->setText(answer);
    }
    else if(caz==3)
    {
        RequestGameDescription requestt("snake");
        QString answer=requestt._req();
        ui->label_descriere->setText(answer);
    }
    else if(caz==4){
        RequestGameDescription requestt("mario");
        QString answer=requestt._req();
        ui->label_descriere->setText(answer);

    }else if(caz==5){
        RequestGameDescription requestt("sudoku");
        QString answer=requestt._req();
        ui->label_descriere->setText(answer);

    }else if(caz==6){
        RequestGameDescription requestt("tetris");
        QString answer=requestt._req();
        ui->label_descriere->setText(answer);
    }
}


void GamesW::on_aboutpb_clicked()
{

    AboutUs ab;
    ab.setModal(true);
    ab.setFixedSize(527,420);
    ab.exec();

}


void GamesW::on_contactpb_clicked()
{
    ContactInfo ct;
    ct.setModal(true);
    ct.setFixedSize(527,420);
    ct.exec();
}


void GamesW::on_chat_pb_clicked()
{
    chatw ct;
    ct.setModal(true);
    ct.exec();
}


void GamesW::on_pb_top_clicked()
{
    if(caz==1)
    {
        ui->toplistwidget->clear();
        RequestGameTop request("spaceinvaders");
        QString str=request.req();

        QStringList toplist=str.split("/");
        foreach(QString item,toplist){
            if(item!=" ")
            {
                ui->toplistwidget->addItem(item);
            }
        }

    }else if(caz==2)
    {
        ui->toplistwidget->clear();
        RequestGameTop request("flappybird");
        QString str=request.req();

        QStringList toplist=str.split("/");
        foreach(QString item,toplist){
            if(item!=" ")
            {
                ui->toplistwidget->addItem(item);
            }
        }

    }
    else if(caz==3)
    {
        ui->toplistwidget->clear();
        RequestGameTop request("snake");
        QString str=request.req();
        QStringList toplist=str.split("/");
        foreach(QString item,toplist){
            if(item!=" ")
            {
                ui->toplistwidget->addItem(item);
            }
        }

    }
    else if(caz==4)
    {
            ui->toplistwidget->clear();
            RequestGameTop request("mario");
            QString str=request.req();

            QStringList toplist=str.split("/");
            foreach(QString item,toplist){
                if(item!=" ")
                {
                    ui->toplistwidget->addItem(item);
                }
            }

     }
    else if(caz==5)
    {
            ui->toplistwidget->clear();
            RequestGameTop request("sudoku");
            QString str=request.req();

            QStringList toplist=str.split("/");
            foreach(QString item,toplist){
                if(item!=" ")
                {
                    ui->toplistwidget->addItem(item);
                }
            }

     }else if(caz==6)
     {
            ui->toplistwidget->clear();
            RequestGameTop request("tetris");
            QString str=request.req();

            QStringList toplist=str.split("/");
            foreach(QString item,toplist){
                if(item!=" ")
                {
                    ui->toplistwidget->addItem(item);
                }
            }

     }


}

