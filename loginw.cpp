#include "loginw.h"
#include "ui_loginw.h"
#include<QMessageBox>
#include<QPixmap>
#include"gamesw.h"
#include"tcpclient.h"
#include"newpasswordw.h"
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
    if(user==""||pass==""){
        CExceptie exc;
        exc.LoginError();

    }

    currentuser=new NormalUser(user,pass);
    //use User class for that
    if(currentuser->sendCredentials()){
        tcpclient::setUsername(user);
        this->hide();
        GamesW gameswindow;
        gameswindow.setModal(true);
        //gameswindow.setWindowState(Qt::WindowFullScreen);
        //gameswindow.showFullScreen();

        //gameswindow.showMaximized();
        gameswindow.setFixedSize(1300,900);
        gameswindow.exec();


    }else{
        CExceptie exc;
        exc.LoginError();
    }

}


void LoginW::on_pb_change_pass_clicked()
{
    NewPasswordw ab;
    ab.setModal(true);
    ab.setFixedSize(527,420);
    ab.exec();
}

