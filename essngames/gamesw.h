#ifndef GAMESW_H
#define GAMESW_H

#include <QDialog>

namespace Ui {
class GamesW;
}

class GamesW : public QDialog
{
    Q_OBJECT

public:
    explicit GamesW(QWidget *parent = nullptr);
    ~GamesW();

private slots:
    void on_add_button_clicked();

    void on_delete_button_clicked();

    void on_friendslist_currentRowChanged(int currentRow);

private:
    Ui::GamesW *ui;
    int mnSelected =-1;
};

#endif // GAMESW_H
