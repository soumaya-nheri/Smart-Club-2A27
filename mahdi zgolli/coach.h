#ifndef COACH_H
#define COACH_H
#include<QString>
#include<QSqlQuery>
#include<QSqlQueryModel>
#include<QDate>
#include<QTime>


class coach
{
public:
    coach();
    coach (int,QString,QString,QString,QDate,QString,int);
    //getters
    int getID_Coach();
    QString getNom();
    QString getPrenom();
    QString getSpecialite();
    QDate getDate_Naiss();
    QString getEmail();
    int getAB_PR();
    //setters
    void setID_Coach(int);
    void setNom(QString);
    void setPrenom(QString);
    void setSpecialite(QString);
    void setDate_Naiss(QDate);
    void setEmail(QString);
    void setAB_PR(int);

    //functions
    bool Ajouter1();
    QSqlQueryModel* Afficher1();
    bool Supprimer1(int);
    bool Modifier1(int);
    QSqlQueryModel* chercher(QString);

private:
int ID_Coach,AB_PR;
QDate Date_Naiss;
QString Nom,Prenom,Specialite,Email;


};

#endif // COACH_H
