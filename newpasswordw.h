#ifndef NEWPASSWORDW_H
#define NEWPASSWORDW_H

#include <QDialog>

namespace Ui {
class NewPasswordw;
}

class NewPasswordw : public QDialog
{
    Q_OBJECT

public:
    explicit NewPasswordw(QWidget *parent = nullptr);
    ~NewPasswordw();

private slots:
    void on_pushButton_clicked();

private:
    Ui::NewPasswordw *ui;
};

#endif // NEWPASSWORDW_H
