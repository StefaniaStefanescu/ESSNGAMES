#ifndef CHATW_H
#define CHATW_H

#include <QDialog>

namespace Ui {
class chatw;
}

class chatw : public QDialog
{
    Q_OBJECT

public:
    explicit chatw(QWidget *parent = nullptr);
    ~chatw();

private slots:
    void on_sendpb_clicked();
    void addlivemessage(QString message);

private:
    Ui::chatw *ui;
};

#endif // CHATW_H
