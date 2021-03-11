#include "depenses.h"
#include"QSqlQuery"
#include"QSqlQueryModel"
#include"QDebug"
#include"QObject"
#include<QDate>
#include<iostream>
using namespace std;
depenses::depenses()
{
ID_DEP=0;ACHAT=0;SALAIRE=0;SOMME=0;DATE_DEP=QDate::currentDate();
}
depenses::depenses(int ID_DEP,int ACHAT,int SALAIRE,int SOMME,QDate DATE_DEP)
{
    this->ID_DEP=ID_DEP;
    this->ACHAT=ACHAT;
    this->SALAIRE=SALAIRE;
    this->SOMME=SOMME;
    this->DATE_DEP=DATE_DEP;
}
int depenses::getID_DEP(){return ID_DEP;}
int depenses::getACHAT(){return ACHAT;}
int depenses::getSALAIRE(){return SALAIRE;}
int depenses::getSOMME(){return SOMME;}
QDate depenses::getDATE_DEP(){return DATE_DEP;}
void depenses::setID_DEP(int ID_DEP){this->ID_DEP=ID_DEP;}
void depenses::setACHAT(int ACHAT){this->ACHAT=ACHAT;}
void depenses::setSALAIRE(int SALAIRE){this->SALAIRE=SALAIRE;}
void depenses::setSOMME(int SOMME){this->SOMME=SOMME;}
void depenses::setDATE_DEP(QDate DATE_DEP){this->DATE_DEP=DATE_DEP;}
bool depenses::ajout_dep(){
    bool test=false;
    QSqlQuery query;
     QString IDd_String=QString::number(ID_DEP);
     QString ACHAT_String=QString::number(ACHAT);
     QString SALAIRE_String=QString::number(SALAIRE);
     QString SOMME_String=QString::number(SOMME);
    query.prepare("INSERT INTO depenses (ID_DEP,ACHAT,SALAIRE,SOMME,DATE_DEP)"
                  "VALUES (:ID_DEP,:ACHAT,:SALAIRE,:SOMME,:DATE_DEP)");
    query.bindValue(":ID_DEP", IDd_String);
    query.bindValue(":ACHAT",ACHAT_String);
    query.bindValue(":SALAIRE",SALAIRE_String);
    query.bindValue(":SOMME",SOMME_String);
    query.bindValue(":DATE_DEP",DATE_DEP);
    query.exec();

return test;
}
QSqlQueryModel* depenses::afficher(){
    QSqlQueryModel* model=new QSqlQueryModel();
    model->setQuery("SELECT* FROM depenses");
    model->setHeaderData(0, Qt::Horizontal,QObject::tr("ID_DEP"));
    model->setHeaderData(1, Qt::Horizontal,QObject::tr("ACHAT"));
    model->setHeaderData(2, Qt::Horizontal,QObject::tr("SALAIRE"));
    model->setHeaderData(3, Qt::Horizontal,QObject::tr("SOMME"));
    model->setHeaderData(4, Qt::Horizontal,QObject::tr("DATE_DEP"));


    return model;
}
bool depenses::supprimer(int){

    QSqlQuery query;
          query.prepare("Delete from depenses where ID_DEP=:ID_DEP");
          query.bindValue(0, ID_DEP);

         return query.exec();

}
bool depenses::modifier(int ID_DEP)
{
    QSqlQuery query;
    QString ACHAT_String=QString::number(ACHAT);
    QString SALAIRE_String=QString::number(SALAIRE);
    QString SOMME_String=QString::number(SOMME);
    query.prepare("UPDATE depenses set ACHAT=:ACHAT,SALAIRE=:SALAIRE,SOMME=:SOMME,DATE_DEP=:DATE_DEP where ID_DEP=:ID_DEP ");
    query.bindValue(":ID_DEP",ID_DEP);
    query.bindValue(":ACHAT",ACHAT_String);
    query.bindValue(":SALAIRE",SALAIRE_String);
    query.bindValue(":SOMME",SOMME_String);
    query.bindValue(":DATE_DEP",DATE_DEP);
    return query.exec();

}



