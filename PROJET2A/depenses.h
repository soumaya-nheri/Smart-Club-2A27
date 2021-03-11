#ifndef DEPENSES_H
#define DEPENSES_H
#include<QString>
#include<QSqlQuery>
#include<QSqlQueryModel>
#include<QDate>

class depenses
{
public:
    depenses();

    depenses (int,int,int,int,QDate);
    //getters
    int getID_DEP();
    int getACHAT();
    int getSALAIRE();
    int getSOMME();
    QDate getDATE_DEP();
    //setters
    void setID_DEP(int);
    void setACHAT(int);
    void setSALAIRE(int);
    void setSOMME(int);
    void setDATE_DEP(QDate);
    //functions
    bool ajout_dep();
    QSqlQueryModel* afficher();
    bool supprimer(int);
    bool modifier (int);

private:
int ID_DEP,ACHAT,SALAIRE,SOMME;
QDate DATE_DEP;


};

#endif // DEPENSES_H


