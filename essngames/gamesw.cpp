#include "gamesw.h"
#include "ui_gamesw.h"
#include<QPixmap>
#include<QProcess>
#include<QFile>
#include<QTextStream>
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
    ui->label_mwusername->setText("niasns");
    QPixmap pix2(":/imagini/choose.png");
    w =ui->label_currentgame->width();
    h=ui->label_currentgame->height();
    ui->label_currentgame->setPixmap(pix2.scaled(w,h,Qt::KeepAspectRatio));
    ui->label_descriere->setText("Choose a game, then select 'INFO' if you want to see "
                                 "information about the game.\n");

}

GamesW::~GamesW()
{
    delete ui;
}

void GamesW::on_add_button_clicked()
{
    ui->lineEdit_search->setPlaceholderText("search username");
    QString tosearch=ui->lineEdit_search->text();
    if(tosearch==""){
        return;         //nu trimit catre server nimic daca nu a fost introdusa o valoare
    }
    //cerere catre server sa verifice daca username-ul este existent -->daca este existent il adaug in lista de prieteni
    //totodata trebuie sa verifice daca user-ul este deja prieten cu mine
    ui->friendslist->addItem(tosearch);
}


void GamesW::on_delete_button_clicked()
{
    //la butonul delete se apasa pe itemul din lista
    QListWidgetItem *it=ui->friendslist->takeItem(mnSelected);

    delete it;
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
        ui->label_descriere->setText("Space invaders info");
    }
    else if(caz==2){
      ui->label_descriere->setText("FlappyBird info");
    }
    else if(caz==3)
    {
       ui->label_descriere->setText("Snake info");
    }
    else if(caz==4){
       ui->label_descriere->setText("Mario info");

    }else if(caz==5){
       ui->label_descriere->setText("Sudoku info");

    }else if(caz==6){
       ui->label_descriere->setText("Tetris info");
    }
}

