#ifndef PROGRAM_H
#define PROGRAM_H

#include<QString>
#include<QSqlQuery>
#include<QSqlQueryModel>
#include<QDate>
#include<QTime>

class programs
{
public:
    programs();

    programs (int,QDate,QTime,int,int,QString);
    //getters
    int getID_Planning();
    QDate getDate_Planning();
    QTime getHeure();
    int getNumero_Sem();
    int getNB_reservation();
    QString getNom_Coach();
    //setters
    void setID_Planning(int);
    void setDate_Planning(QDate);
    void setHeure(QTime);
    void setNumero_Sem(int);
    void setNB_reservation(int);
    void setNom_Coach(QString);
    //functions
    bool Ajouter2();
    QSqlQueryModel* Afficher2();
    bool Supprimer2(int);
    bool Modifier2(int);
    QSqlQueryModel* chercher(QString);

private:
int ID_Planning,Numero_Sem,NB_reservation;
QDate Date_Planning;
QTime Heure;
QString Nom_Coach;


};

#endif // PROGRAM_H
