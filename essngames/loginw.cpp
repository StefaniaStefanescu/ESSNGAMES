#include "loginw.h"
#include "ui_loginw.h"
#include<QMessageBox>
#include<QPixmap>
#include"gamesw.h"
LoginW::LoginW(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LoginW)
{
    ui->setupUi(this);
    ui->username->setPlaceholderText("Enter your username");
    ui->password->setPlaceholderText("Enter password");
    QPixmap pix(":/imagini/login_icon.jpeg");
    int w =ui->label_logimg->width();
    int h=ui->label_logimg->height();
    ui->label_logimg->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));
}

LoginW::~LoginW()
{
    delete ui;
}

void LoginW::on_pushButton_submitlog_clicked()
{
    //aici trbuie sa fac legaturile cu serverul
    QString user=ui->username->text();
    QString pass=ui->password->text();
    //use User class for that
    int raspuns=1;
    if(raspuns){
        this->hide();
        GamesW gameswindow;
        gameswindow.setModal(true);
        gameswindow.showMaximized();
        gameswindow.exec();
    }else{
        QMessageBox::warning(this,"Login","Username or password is not coorrect. Try again.");
    }

}

