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
    ui->label_descriere->setText("Choose a game, then select 'INFO' if you want to see "
                                 "information about the game.\n");

    RequestMyFriends requestt;
    QString frlist=requestt._req();
    QStringList list;
    list=frlist.split("/");
    foreach(QString item, list)
       { if(item!=" ")
        ui->friendslist->addItem(item);

    }
}

GamesW::~GamesW()
{
    RequestLogout logout;
        if(logout._request()){
          qDebug()<<"Logout succeded!";
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
    //print game photo
    //get the right game
    caz=1;
    QPixmap pix2(":/imagini/spaceinv2.png");
    int w =ui->label_currentgame->width();
    int h=ui->label_currentgame->height();
    ui->label_currentgame->setPixmap(pix2.scaled(w,h,Qt::KeepAspectRatio));

}


void GamesW::on_pb_joc2_clicked()
{
    caz=2;
    QPixmap pix2(":/imagini/flappybird.jpg");
    int w =ui->label_currentgame->width();
    int h=ui->label_currentgame->height();
    ui->label_currentgame->setPixmap(pix2.scaled(w,h,Qt::KeepAspectRatio));

}


void GamesW::on_pb_joc3_clicked()
{
    caz=3;
    QPixmap pix2(":/imagini/snake.jpg");
    int w =ui->label_currentgame->width();
    int h=ui->label_currentgame->height();
    ui->label_currentgame->setPixmap(pix2.scaled(w,h,Qt::KeepAspectRatio));
}


void GamesW::on_pb_joc4_clicked()
{
    caz=4;
    QPixmap pix2(":/imagini/mario.jpg");
    int w =ui->label_currentgame->width();
    int h=ui->label_currentgame->height();
    ui->label_currentgame->setPixmap(pix2.scaled(w,h,Qt::KeepAspectRatio));
}


void GamesW::on_pb_joc5_clicked()
{
     caz=5;
     QPixmap pix2(":/imagini/sudokuim.jpg");
     int w =ui->label_currentgame->width();
     int h=ui->label_currentgame->height();
     ui->label_currentgame->setPixmap(pix2.scaled(w,h,Qt::KeepAspectRatio));
}

void GamesW::on_pb_joc6_clicked()
{
    caz=6;
    QPixmap pix2(":/imagini/tetrisim.jpg");
    int w =ui->label_currentgame->width();
    int h=ui->label_currentgame->height();
    ui->label_currentgame->setPixmap(pix2.scaled(w,h,Qt::KeepAspectRatio));
}


void GamesW::on_pb_play_clicked()
{
    QProcess *process = new QProcess(this);

    if(caz==1)
    {
     process->start("qrc:/../../../../../exespaceinv2/SpaceInvaders.exe");
    }
    else if(caz==2){
      process->start(":/../../../../../exeflappybird2/FlappyBird.exe");
    }
    else if(caz==3)
    {
        process->start(":/../../../../../exesnake2/snake.exe");
    }
    else if(caz==4){
         process->start(":/../../../../../exemario2/gameMainWindow.exe");

    }else if(caz==5){
         process->start(":/../../../../../sudokuexe2/Sudoku.exe");
    }else if(caz==6){
        process->start(":/../../../../../tetrisexe2/QtTetris.exe");
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

