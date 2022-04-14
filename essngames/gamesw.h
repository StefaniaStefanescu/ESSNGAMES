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

    void on_pb_joc1_clicked();

    void on_pb_joc2_clicked();

    void on_pb_joc3_clicked();

    void on_pb_joc4_clicked();

    void on_pb_joc5_clicked();

    void on_pb_play_clicked();

    void on_pb_joc6_clicked();

    void on_pb_info_clicked();

private:
    Ui::GamesW *ui;
    int mnSelected =-1;
    int caz;
};

#endif // GAMESW_H
