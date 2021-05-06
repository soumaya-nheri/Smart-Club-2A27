#ifndef ABONNEMENT_H
#define ABONNEMENT_H


#include<QString>
#include<QSqlQuery>
#include<QSqlQueryModel>
#include<QDate>

class abonnement
{
public:
    abonnement();
    abonnement(int,QDate,QString);
    //getters
    int getID_ABT();
    QDate getDATE_INS();
    QString getTYPE();
    //setters
    void setID_ABT(int);
    void setDATE_INS(QDate);
    void setTYPE(QString);
    //functions
    bool ajout_abt();
    QSqlQueryModel* afficher();
    bool supprimer(int);
    bool modifier (int);
    QSqlQueryModel* tri_IDDESC();
    QSqlQueryModel* tri_IDASC();
    QSqlQueryModel* chercher_ABT(QString);

private:
int ID_ABT;
QString TYPE;
QDate DATE_INS;


};
#endif // ABONNEMENT_H
