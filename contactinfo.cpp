#include "contactinfo.h"
#include "ui_contactinfo.h"

ContactInfo::ContactInfo(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ContactInfo)
{
    ui->setupUi(this);
    ui->textEdit->setReadOnly(true);
}

ContactInfo::~ContactInfo()
{
    delete ui;
}
