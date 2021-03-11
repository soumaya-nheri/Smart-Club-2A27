#ifndef REVENUES_H
#define REVENUES_H
#include<QString>
#include<QSqlQuery>
#include<QSqlQueryModel>
#include<QDate>

class revenues
{
public:
    revenues();

    revenues (int,int,int,int,QDate);
    //getters
    int getID_REV();
    int getCONSOMATION();
    int getREV_SPONSOR();
    int getREV_ABON();
    QDate getDATE_REV();
    //setters
    void setID_REV(int);
    void setCONSOMATION(int);
    void setREV_SPONSOR(int);
    void setREV_ABON(int);
    void setDATE_REV(QDate);
    //functions
    bool ajout_rev();
    QSqlQueryModel* afficher();
    bool supprimer(int);
    bool modifier (int);

private:
int ID_REV,CONSOMATION,REV_SPONSOR,REV_ABON;
QDate DATE_REV;


};

#endif // REVENUES_H
