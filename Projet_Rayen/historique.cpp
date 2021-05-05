#include "historique.h"
#include"QSqlQuery"
#include"QSqlQueryModel"
#include"QDebug"
#include"QObject"
#include<QDate>
historique::historique(){

}
historique::historique(int,QDate,QDate)
{
ID_HIS=0;CREATED=QDate::currentDate();MODIFIED=QDate::currentDate();
}
int historique::getID_HIS(){return ID_HIS;}
QDate historique::getCREATED(){return CREATED;}
QDate historique::getModified(){return MODIFIED;}
void historique::setID_HIS(int ID_HIS){this->ID_HIS=ID_HIS;}
void historique::setCREATED(QDate CREATED){this->CREATED=CREATED;}
void historique::setMODIFIED(QDate MODIFIED){this->MODIFIED=MODIFIED;}
bool historique::ajout_his(){
    bool test=false;
    QSqlQuery query;
     QString ID_Stringgg=QString::number(ID_HIS);
    query.prepare("INSERT INTO HISTORIQUE (ID_HIS,CREATED,MODIFIED)"
                  "VALUES (:ID_HIS,:CREATED,:MODIFIED)");
    query.bindValue(":ID_HIS", ID_Stringgg);
    query.bindValue(":CREATED",CREATED);
    query.bindValue(":MODIFIED",MODIFIED);
    query.exec();

return test;
}
QSqlQueryModel* historique::afficher(){
    QSqlQueryModel* model=new QSqlQueryModel();
    model->setQuery("SELECT* FROM HISTORIQUE");
    model->setHeaderData(0, Qt::Horizontal,QObject::tr("ID_HIS"));
    model->setHeaderData(1, Qt::Horizontal,QObject::tr("CREATED"));
    model->setHeaderData(2, Qt::Horizontal,QObject::tr("MODIFIED"));


    return model;
}
bool historique::modifier_his(int ID_HIS)
{
    QSqlQuery query;
    query.prepare("UPDATE HISTORIQUE set MODIFIED=:MODIFIED where ID_HIS=:ID_HIS ");
    query.bindValue(":ID_HIS",ID_HIS);
    query.bindValue(":MODIFIED",QDate::currentDate());
    return query.exec();

}
