#include "gamesw.h"
#include "ui_gamesw.h"
#include<QPixmap>
GamesW::GamesW(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::GamesW)
{
    ui->setupUi(this);
    QPixmap pix(":/imagini/login_icon.jpeg");
    int w =ui->label_mwuser->width();
    int h=ui->label_mwuser->height();
    ui->label_mwuser->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));
    //aici ar trebui sa pun username-ul utilizatorului logat
    ui->label_mwusername->setText("niasns");
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

