#include "abonnes.h"
#include"QSqlQuery"
#include"QSqlQueryModel"
#include"QDebug"
#include"QObject"
#include<QDate>
#include<iostream>
using namespace std;
abonnes::abonnes()
{
ID_AB=0;NOM="";PRENOM="";AGE=0;
}
abonnes::abonnes(int ID_AB,QString NOM,QString PRENOM,int AGE)
{
    this->ID_AB=ID_AB;
    this->NOM=NOM;
    this->PRENOM=PRENOM;
    this->AGE=AGE;
}
int abonnes::getID_AB(){return ID_AB;}
QString abonnes::getNOM(){return NOM;}
QString abonnes::getPRENOM(){return PRENOM;}
int abonnes::getAGE(){return AGE;}

void abonnes::setID_AB(int ID_AB){this->ID_AB=ID_AB;}
void abonnes::setNOM(QString NOM){this->NOM=NOM;}
void abonnes::setPRENOM(QString PRENOM){this->PRENOM=PRENOM;}
void abonnes::setAGE(int AGE){this->AGE=AGE;}
bool abonnes::ajout_ab(){
    bool test=false;
    QSqlQuery query;
     QString IDd_String=QString::number(ID_AB);
    query.prepare("INSERT INTO abonnes (ID_AB,NOM,PRENOM,AGE)"
                  "VALUES (:ID_AB,:NOM,:PRENOM,:AGE)");
    query.bindValue(":ID_AB", IDd_String);
    query.bindValue(":NOM",NOM);
    query.bindValue(":PRENOM",PRENOM);
    query.bindValue(":AGE",AGE);
    query.exec();

return test;
}
QSqlQueryModel* abonnes::afficher(){
    QSqlQueryModel* model=new QSqlQueryModel();
    model->setQuery("SELECT * FROM abonnes");
    model->setHeaderData(0, Qt::Horizontal,QObject::tr("ID_AB"));
    model->setHeaderData(1, Qt::Horizontal,QObject::tr("NOM"));
    model->setHeaderData(2, Qt::Horizontal,QObject::tr("PRENOM"));
    model->setHeaderData(3, Qt::Horizontal,QObject::tr("AGE"));
    return model;
}
bool abonnes::supprimer(int){

    QSqlQuery query;
          query.prepare("Delete from abonnes where ID_AB=:ID_AB");
          query.bindValue(0, ID_AB);

         return query.exec();

}
bool abonnes::modifier(int ID_AB)
{
    QSqlQuery query;
    query.prepare("UPDATE abonnes set NOM=:NOM,PRENOM=:PRENOM,AGE=:AGE where ID_AB=:ID_AB ");
    query.bindValue(":ID_AB",ID_AB);
    query.bindValue(":NOM",NOM);
    query.bindValue(":PRENOM",PRENOM);
    query.bindValue(":AGE",AGE);

    return query.exec();

}
