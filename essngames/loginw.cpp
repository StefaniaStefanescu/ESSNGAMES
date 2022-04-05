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
    QString bara{"/"};
    QString unu{"1"};
    //aici trbuie trimise datele catre server in format "1/user/pass"
    QString sv_info; //=unu+bara+user+bara+pass;
    //aici am o concatenare mai eficienta
    sv_info.reserve(user.length()+unu.length()+bara.length()+bara.length()+pass.length());
    sv_info.append(unu);
    sv_info.append(bara);
    sv_info.append(user);
    sv_info.append(bara);
    sv_info.append(pass);
    //int raspuns ====socket_requestverify(string,2000);
    //primesc un raspuns ..o sa-i dau o perioada sa raspunda wait(2000) 2s...
    int raspuns=1;
    if(raspuns){
        this->hide();
        GamesW gameswindow;
        gameswindow.setModal(true);
        gameswindow.exec();
    }else{
        QMessageBox::warning(this,"Login","Username or password is not coorrect. Try again.");
    }

}

