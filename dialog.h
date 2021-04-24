#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include"abonnement.h"
#include"abonnes.h"

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

    void on_Recherche_clicked();

private:
    Ui::Dialog *ui;
    abonnes ab;
        abonnement abt;
        int High;
        int Low;
};

#endif // DIALOG_H
