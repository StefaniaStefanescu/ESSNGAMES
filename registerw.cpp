#include "registerw.h"
#include "ui_registerw.h"
#include<QMessageBox>
#include"gamesw.h"
#include"refistereduser.h"
#include<tcpclient.h>
#include"requestregister.h"
RegisterW::RegisterW(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::RegisterW)
{
    ui->setupUi(this);
    ui->username->setPlaceholderText("Enter your username");
    ui->password->setPlaceholderText("Enter password");
    ui->confirm->setPlaceholderText("Confirm password");
    ui->country->setPlaceholderText("Enter your country name");
    ui->date->setPlaceholderText("Enter your birth date zz-ll-aaaa");
    ui->email->setPlaceholderText("Enter your email address");
    ui->region->setPlaceholderText("Enter your region");
}

RegisterW::~RegisterW()
{
    delete ui;
}

void RegisterW::on_pushButton_submitReg_clicked()
{
    //aici trbuie sa fac legaturile cu serverul
    QString user=ui->username->text();
    QString pass=ui->password->text();
    QString Confirm=ui->confirm->text();
    if(pass!=Confirm){
        QMessageBox::warning(this,"Register","You need to confirm again.");
    }else{
        QString Country=ui->country->text();
        QString Region=ui->region->text();
        QString Email=ui->email->text();
        QString Birth=ui->date->text();
        if(user==""||pass==""||Confirm==""||Country==""||Region==""||Email==""||Birth==""){
            CExceptie exc;
            exc.RegisterError();
        }


//username,password,country,region,email,birthdate
        RequestRegister req(user,pass,Country,Region,Email,Birth);

        if(req._request()){
            tcpclient::setUsername(user);
            this->hide();
            GamesW gameswindow;
            gameswindow.setModal(true);
            //gameswindow.showMaximized();
            gameswindow.setWindowState(Qt::WindowFullScreen);
            gameswindow.showFullScreen();
            gameswindow.exec();
        }else{
            CExceptie exc;
            exc.RegisterError();
        }
    }

}

