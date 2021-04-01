#ifndef COMPTABILITE_H
#define COMPTABILITE_H
#include"revenues.h"
#include"depenses.h"
#include <QDialog>
#include<QMediaPlayer>

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

    void on_comboBox_currentIndexChanged(int index);

    void on_comboBox_2_currentIndexChanged(int index);



    void on_somme_consomation_clicked();

    void on_pushButton_7_clicked();

    void on_somme_rev_abon_clicked();

    void on_somme_rev_sponsor_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_9_clicked();

private:

    Ui::comptabilite *ui;
    revenues re;
    depenses de;
    int High;
    int Low;


};

#endif // COMPTABILITE_H
