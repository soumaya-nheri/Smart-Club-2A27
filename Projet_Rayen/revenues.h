#ifndef REVENUES_H
#define REVENUES_H
#include"QDate"
#include<QSqlQuery>
#include<QSqlQueryModel>
#include<QString>

class revenues
{
public:
    revenues();

    revenues (int,float,float,float,QDate);
    //getters
    int getID_REV();
    float getCONSOMATION();
    float getREV_SPONSOR();
    float getREV_ABON();
    QDate getDATE_REV();
    //setters
    void setID_REV(int);
    void setCONSOMATION(float);
    void setREV_SPONSOR(float);
    void setREV_ABON(float);
    void setDATE_REV(QDate);
    //functions
    bool ajout_rev();
    QSqlQueryModel* afficher();
    bool supprimer(int);
    bool modifier (int);
    bool rechercher(int);
private:
    int ID_REV;
    float CONSOMATION,REV_SPONSOR,REV_ABON;
    QDate DATE_REV;

};

#endif // REVENUES_H
