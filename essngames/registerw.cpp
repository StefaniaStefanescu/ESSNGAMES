#include "registerw.h"
#include "ui_registerw.h"
#include<QMessageBox>
#include"gamesw.h"
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
        QString bara{"/"};
        QString doi{"2"};
        //"2/user/pass/country/region/email/birthdate"
        QString sv_info;
        sv_info.reserve(user.length()+doi.length()+bara.length()+bara.length()+bara.length()+bara.length()+bara.length()+bara.length()+pass.length()+Country.length()+Region.length()+Email.length()+Birth.length());
        sv_info.append(doi);
        sv_info.append(bara);
        sv_info.append(bara);
        sv_info.append(user);
        sv_info.append(pass);
        sv_info.append(Country);
        sv_info.append(pass);
        sv_info.append(Region);
        sv_info.append(pass);
        sv_info.append(Email);
        sv_info.append(pass);
        sv_info.append(Birth);
        //primesc un raspuns ..o sa-i dau o perioada sa raspunda wait(2000) 2s...
        int raspuns=0;
        if(raspuns){
            this->hide();
            GamesW gameswindow;
            gameswindow.setModal(true);
            gameswindow.exec();
        }else{
            QMessageBox::warning(this,"Register","Depends on the sittuation");
        }
    }

}

