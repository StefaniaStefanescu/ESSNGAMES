#ifndef CONTACTINFO_H
#define CONTACTINFO_H

#include <QDialog>

namespace Ui {
class ContactInfo;
}

class ContactInfo : public QDialog
{
    Q_OBJECT

public:
    explicit ContactInfo(QWidget *parent = nullptr);
    ~ContactInfo();

private:
    Ui::ContactInfo *ui;
};

#endif // CONTACTINFO_H
