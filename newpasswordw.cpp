#include "newpasswordw.h"
#include "ui_newpasswordw.h"
#include"requestchangepassword.h"
NewPasswordw::NewPasswordw(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NewPasswordw)
{
    ui->setupUi(this);
    ui->lineEdit_username->setPlaceholderText("Enter your username");
    ui->lineEdit_email->setPlaceholderText("Enter email");
    ui->lineEdit_newpassword->setPlaceholderText("Set password");
}

NewPasswordw::~NewPasswordw()
{
    delete ui;
}

void NewPasswordw::on_pushButton_clicked()
{
    QString user=ui->lineEdit_username->text();
    QString email=ui->lineEdit_email->text();
    QString password=ui->lineEdit_newpassword->text();
    RequestChangePassword req(user,email,password);
    if(req._request()){

        QMessageBox::information(0,"Great","The password was updated!");
    }else{
        QMessageBox::information(0,"OOOPS","Couldn't update your password! Try again!");
    }

}

