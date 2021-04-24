#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include"revenues.h"
#include <QMainWindow>
#include "depenses.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_ajout_rev_clicked();

    void on_ref_rev_clicked();

    void on_supp_rev_clicked();


    void on_modifier_clicked();

    void on_ajout_dep_clicked();

    void on_ref_dep_clicked();

    void on_mod_dep_clicked();

    void on_supp_dep_clicked();


private:
    Ui::MainWindow *ui;
    revenues re;
    depenses de;
};

#endif // MAINWINDOW_H
