#ifndef COMPTABILITE_H
#define COMPTABILITE_H
#include"revenues.h"
#include"depenses.h"
#include <QDialog>
#include<QMediaPlayer>
#include<QPropertyAnimation>

namespace Ui {
class comptabilite;
}

class comptabilite : public QDialog
{
    Q_OBJECT

public:
    explicit comptabilite(QWidget *parent = nullptr);
    ~comptabilite();
private slots:


    void on_pushButton_2_clicked();

    void on_refresh_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_clicked();

    void on_refresh_dep_clicked();

    void on_supp_dep_clicked();

    void on_mod_dep_clicked();



    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();



    void on_print_clicked();




    void on_somme_consomation2_clicked();

    void on_pushButton_7_clicked();

    void on_somme_rev_abon2_clicked();

    void on_somme_rev_sponsor2_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_11_clicked();

    void on_pushButton_10_clicked();

    void on_pushButton_12_clicked();

    void on_somme_dep_clicked();

    void on_pushButton_15_clicked();

    void on_pushButton_13_clicked();

private:

    void on_tabWidget_currentChanged(int index);

    Ui::comptabilite *ui;
    revenues re;
    depenses de;
    int High;
    int Low;
    QPropertyAnimation *Animation;


};

#endif // COMPTABILITE_H
