#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include"abonnement.h"
#include"abonnes.h"
#include"programs.h"
#include"coach.h"
#include<equipements.h>
#include <QMediaPlayer>


namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = nullptr);
    ~Dialog();

private slots:
    void on_Ajouter_clicked();

    void on_Supprimer_clicked();

    void on_pushButton_clicked();

    void on_Modifier_clicked();

    void on_Ajouter_2_clicked();

    void on_Modifier_2_clicked();

    void on_Supprimer_2_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();


    void on_Ajouter2_clicked();

    void on_pushButton_5_clicked();

    void on_Supprimerprog_clicked();

    void on_pushButton_15_clicked();

    void on_pushButton_6_clicked();

    void on_button_6_clicked();

    void on_pushButton_7_clicked();

    void on_Modifierprog_clicked();

    void on_Ajouter1_clicked();

    void on_Supprimer1_clicked();

    void on_pushButton_9_clicked();

    void on_Modifier1_clicked();

    void on_button_5_clicked();

    void on_Afficher1_clicked();

    void on_pushButton_8_clicked();

    void on_presence_selectionChanged();

    void on_nomcombo_currentIndexChanged(const QString &arg1);

    void on_pushButton_18_clicked();

    void on_pushButton_17_clicked();

    void on_pushButton_16_clicked();

    void on_pushButton_12_clicked();

    void on_pushButton_13_clicked();

    void on_pushButton_14_clicked();

    void on_pushButton_11_clicked();

    void on_modifiereq_clicked();

private:
    Ui::Dialog *ui;
    abonnes ab;
        abonnement abt;
        programs prog;
        coach c;
        int High=9999;
        int Low=1;
        equipements Etmp;
          QMediaPlayer *player = new QMediaPlayer;
};

#endif // DIALOG_H
