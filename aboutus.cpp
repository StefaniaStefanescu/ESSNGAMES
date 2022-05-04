#include "aboutus.h"
#include "ui_aboutus.h"

AboutUs::AboutUs(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AboutUs)
{
    ui->setupUi(this);
    ui->textEdit->setReadOnly(true);
}

AboutUs::~AboutUs()
{
    delete ui;
}
