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

    depenses (int,float,float,float,QDate);
    //getters
    int getID_DEP();
    float getACHAT();
    float getSALAIRE();
    float getEVENT();
    QDate getDATE_DEP();
    //setters
    void setID_DEP(int);
    void setACHAT(float);
    void setSALAIRE(float);
    void setEVENT(float);
    void setDATE_DEP(QDate);
    //functions
    bool ajout_dep();
    QSqlQueryModel* afficher();
    bool supprimer(int);
    bool modifier (int);

private:
int ID_DEP;
float ACHAT,SALAIRE,EVENT;
QDate DATE_DEP;


};

#endif // DEPENSES_H
