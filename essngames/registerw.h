#ifndef REGISTERW_H
#define REGISTERW_H

#include <QDialog>

namespace Ui {
class RegisterW;
}

class RegisterW : public QDialog
{
    Q_OBJECT

public:
    explicit RegisterW(QWidget *parent = nullptr);
    ~RegisterW();

private slots:
    void on_pushButton_submitReg_clicked();

private:
    Ui::RegisterW *ui;
};

#endif // REGISTERW_H
