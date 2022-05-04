#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include"loginw.h"
#include"registerw.h"
#include "cexceptie.h"


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_log_clicked();

    void on_pushButton_reg_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
