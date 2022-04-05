#ifndef LOGINW_H
#define LOGINW_H

#include <QDialog>

namespace Ui {
class LoginW;
}

class LoginW : public QDialog
{
    Q_OBJECT

public:
    explicit LoginW(QWidget *parent = nullptr);
    ~LoginW();

private slots:
    void on_pushButton_submitlog_clicked();

private:
    Ui::LoginW *ui;
};

#endif // LOGINW_H
