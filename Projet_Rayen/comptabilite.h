#ifndef COMPTABILITE_H
#define COMPTABILITE_H
#include"revenues.h"
#include"depenses.h"
#include <QDialog>
#include<QMediaPlayer>
#include<QPropertyAnimation>
#include"equipements.h"
#include"services.h"
#include"coach.h"
#include"programs.h"
#include"abonnement.h"
#include"abonnes.h"
#include"sponsor.h"
#include"evenement.h"
#include <QtWidgets/QStatusBar>
#include <QtCharts/QChartView>
#include "donutbreakdownchart.h"
#include"historique.h"
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

    void on_pushButton_17_clicked();

    void on_pushButton_16_clicked();

    void on_pushButton_14_clicked();

    void on_modifiereq_clicked();

    void on_pushButton_18_clicked();

    void on_pushButton_19_clicked();

    void on_pushButton_20_clicked();

    void on_pushButton_21_clicked();

    void on_pushButton_43_clicked();

    void on_pushButton_44_clicked();


    void on_pushButton_24_clicked();

    void on_pushButton_22_clicked();

    void on_modifierse_2_clicked();

    void on_pushButton_25_clicked();

    void on_pushButton_28_clicked();

    void on_pushButton_27_clicked();

    void on_pushButton_26_clicked();

    void on_Ajouter1_2_clicked();

    void on_Supprimer1_2_clicked();

    void on_Afficher1_2_clicked();

    void on_Modifier1_2_clicked();

    void on_button_7_clicked();

    void on_pushButton_57_clicked();

    void on_nomcombo_2_currentIndexChanged(const QString &arg1);

    void on_pushButton_29_clicked();

    void on_pushButton_56_clicked();

    void on_Ajouter2_2_clicked();

    void on_Supprimer2_clicked();

    void on_Modifier2_clicked();

    void on_Afficher2_clicked();

    void on_button_8_clicked();

    void on_pushButton_60_clicked();

    void on_pushButton_61_clicked();

    void on_pushButton_32_clicked();

    void on_Ajouter_2_clicked();

    void on_Supprimer_2_clicked();

    void on_pushButton_34_clicked();

    void on_Modifier_clicked();

    void on_Supprimer_clicked();

    void on_pushButton_33_clicked();

    void on_pushButton_23_clicked();

    void on_Modifier_2_clicked();

    void on_Ajouter_clicked();

    void on_pushButton_31_clicked();

    void on_pushButton_35_clicked();

    void on_pushButton_38_clicked();

    void on_pushButton_37_clicked();

    void on_pushButton_30_clicked();

    void on_pb_ajouter_2_clicked();

    void on_pb_supprimer_2_clicked();

    void on_pushButton_42_clicked();

    void on_pushButton_40_clicked();

    void on_pushButton_39_clicked();

     QChartView * affichestat();

     void on_pushButton_45_clicked();

     void on_pushButton_46_clicked();

     void on_cb_event_ids_2_currentIndexChanged(int index);

     void on_cb_sponsor_ids_2_currentIndexChanged(const QString &arg1);

     void on_le_recherche_sp_2_textChanged(const QString &arg1);

     void on_le_recherche_2_textChanged(const QString &arg1);

     void on_pushButton_47_clicked();

     void on_pushButton_48_clicked();

     void on_pushButton_49_clicked();

     void on_pushButton_50_clicked();

     void on_pushButton_51_clicked();

     void on_pushButton_52_clicked();

     void on_pushButton_53_clicked();

     void on_pushButton_54_clicked();

     void on_pushButton_55_clicked();

     void on_rech_depp_textChanged(const QString &arg1);

     void on_print_2_clicked();

     void on_pushButton_66_clicked();

     void on_pushButton_553_clicked();

     void on_pushButton_65_clicked();

     void on_pushButton_64_clicked();

     void on_pushButton_67_clicked();

     void on_pushButton_62_clicked();

     void on_pushButton_63_clicked();

     void on_pushButton_58_clicked();


     void on_rech_depp_2_textChanged(const QString &arg1);

     void on_pushButton_68_clicked();

private:

    void on_tabWidget_currentChanged(int index);

    Ui::comptabilite *ui;
    revenues re;
    depenses de;
    equipements Etmp;
    services Etmp1;
    coach re1;
    programs prog;
    abonnement abt;
    abonnes ab;
    Sponsor S;
    Evenement E;
    historique HI;
    int High=9999;
    int Low=0;
    QPropertyAnimation *Animation;
    QMediaPlayer *player = new QMediaPlayer;


};

#endif // COMPTABILITE_H
