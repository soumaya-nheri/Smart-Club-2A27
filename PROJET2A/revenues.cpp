#include "revenues.h"
#include"QSqlQuery"
#include"QSqlQueryModel"
#include"QDebug"
#include"QObject"
#include<QDate>
revenues::revenues()
{
ID_REV=0;CONSOMATION=0;REV_SPONSOR=0;REV_ABON=0;DATE_REV=QDate::currentDate();
}
revenues::revenues(int ID_REV,int CONSOMATION,int REV_SPONSOR,int REV_ABON,QDate DATE_REV)
{
    this->ID_REV=ID_REV;
    this->CONSOMATION=CONSOMATION;
    this->REV_SPONSOR=REV_SPONSOR;
    this->REV_ABON=REV_ABON;
    this->DATE_REV=DATE_REV;
}
int revenues::getID_REV(){return ID_REV;}
int revenues::getCONSOMATION(){return CONSOMATION;}
int revenues::getREV_SPONSOR(){return REV_SPONSOR;}
int revenues::getREV_ABON(){return REV_ABON;}
QDate revenues::getDATE_REV(){return DATE_REV;}
void revenues::setID_REV(int ID_REV){this->ID_REV=ID_REV;}
void revenues::setCONSOMATION(int CONSOMATION){this->CONSOMATION=CONSOMATION;}
void revenues::setREV_SPONSOR(int REV_SPONSOR){this->REV_SPONSOR=REV_SPONSOR;}
void revenues::setREV_ABON(int REV_ABON){this->REV_ABON=REV_ABON;}
void revenues::setDATE_REV(QDate DATE_REV){this->DATE_REV=DATE_REV;}
bool revenues::ajout_rev(){
    bool test=false;
    QSqlQuery query;
     QString ID_String=QString::number(ID_REV);
     QString CONSOMATION_String=QString::number(CONSOMATION);
     QString REV_SPONSOR_String=QString::number(REV_SPONSOR);
     QString REV_ABON_String=QString::number(REV_ABON);
    query.prepare("INSERT INTO revenues (ID_REV,CONSOMATION,REV_SPONSOR,REV_ABON,DATE_REV)"
                  "VALUES (:ID_REV,:CONSOMATION,:REV_SPONSOR,:REV_ABON,:DATE_REV)");
    query.bindValue(":ID_REV", ID_String);
    query.bindValue(":CONSOMATION",CONSOMATION_String);
    query.bindValue(":REV_SPONSOR",REV_SPONSOR_String);
    query.bindValue(":REV_ABON",REV_ABON_String);
    query.bindValue(":DATE_REV",DATE_REV);
    query.exec();

return test;
}
QSqlQueryModel* revenues::afficher(){
    QSqlQueryModel* model=new QSqlQueryModel();
    model->setQuery("SELECT* FROM revenues");
    model->setHeaderData(0, Qt::Horizontal,QObject::tr("ID_REV"));
    model->setHeaderData(1, Qt::Horizontal,QObject::tr("CONSOMATION"));
    model->setHeaderData(2, Qt::Horizontal,QObject::tr("REV_SPONSOR"));
    model->setHeaderData(3, Qt::Horizontal,QObject::tr("REV_ABON"));
    model->setHeaderData(4, Qt::Horizontal,QObject::tr("DATE_REV"));


    return model;
}
bool revenues::supprimer(int){

    QSqlQuery query;
          query.prepare("Delete from revenues where ID_REV=:ID_REV");
          query.bindValue(0, ID_REV);

         return query.exec();

}
bool revenues::modifier(int ID_REV)
{
    QSqlQuery query;
    QString CONSOMATION_String=QString::number(CONSOMATION);
    QString REV_SPONSOR_String=QString::number(REV_SPONSOR);
    QString REV_ABON_String=QString::number(REV_ABON);
    query.prepare("UPDATE revenues set CONSOMATION=:CONSOMATION,REV_SPONSOR=:REV_SPONSOR,REV_ABON=:REV_ABON,DATE_REV=:DATE_REV where ID_REV=:ID_REV ");
    query.bindValue(":ID_REV",ID_REV);
    query.bindValue(":CONSOMATION",CONSOMATION_String);
    query.bindValue(":REV_SPONSOR",REV_SPONSOR_String);
    query.bindValue(":REV_ABON",REV_ABON_String);
    query.bindValue(":DATE_REV",DATE_REV);
    return query.exec();

}

