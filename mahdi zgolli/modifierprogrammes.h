#ifndef MODIFIERPROGRAMMES_H
#define MODIFIERPROGRAMMES_H

#include <QDialog>
#include<QDate>
#include<QTime>

namespace Ui {
class modifierprogrammes;
}

class modifierprogrammes : public QDialog
{
    Q_OBJECT

public:
    void setID_Planning(int);
    void setDate_Planning(QDate);
    void setHeure(QTime);
    void setNumero_Sem(int);
    void setNB_reservation(int);
    void setNom_Coach(QString);

    explicit modifierprogrammes(QWidget *parent = nullptr);
    ~modifierprogrammes();

private slots:
    void on_modifierProgrammes_2_clicked();

private:
    Ui::modifierprogrammes *ui;
    int ID_Planning,Numero_Sem,NB_reservation;
    QDate Date_Planning;
    QTime Heure;
    QString Nom_Coach;

};

#endif // MODIFIERPROGRAMMES_H
