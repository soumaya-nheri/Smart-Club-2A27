#ifndef COACHPROGRAM_H
#define COACHPROGRAM_H

#include <QDialog>
#include "coach.h"


namespace Ui {
class CoachProgram;
}

class CoachProgram : public QDialog
{
    Q_OBJECT

public:
    explicit CoachProgram(QWidget *parent = nullptr);
    ~CoachProgram();

private slots:

    void on_Ajouter1_clicked();

    void on_Afficher1_clicked();

    void on_Modifier1_clicked();

    void on_Supprimer1_clicked();


    void on_Ajouter2_clicked();

    void on_Afficher2_clicked();

    void on_Modifier2_clicked();

    void on_Supprimer2_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_3_clicked();


    void on_button_5_clicked();

    void on_button_6_clicked();

private:
    Ui::CoachProgram *ui;
    coach re1;
    int High=9999,Low=0;
};

#endif // COACHPROGRAM_H
