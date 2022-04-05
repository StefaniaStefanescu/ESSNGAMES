#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "iexceptie.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_log_clicked()
{

    this->hide();
    LoginW loginwindow;
    loginwindow.setModal(true);
    loginwindow.exec();
}


void MainWindow::on_pushButton_reg_clicked()
{
    this->hide();
    RegisterW registerwindow;
    registerwindow.setModal(true);
    registerwindow.exec();
}

