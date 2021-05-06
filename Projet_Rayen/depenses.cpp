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
ID_DEP=0;ACHAT=0;SALAIRE=0;EVENT=0;DATE_DEP=QDate::currentDate();
}
depenses::depenses(int ID_DEP,float ACHAT,float SALAIRE,float EVENT,QDate DATE_DEP)
{
    this->ID_DEP=ID_DEP;
    this->ACHAT=ACHAT;
    this->SALAIRE=SALAIRE;
    this->EVENT=EVENT;
    this->DATE_DEP=DATE_DEP;
}
int depenses::getID_DEP(){return ID_DEP;}
float depenses::getACHAT(){return ACHAT;}
float depenses::getSALAIRE(){return SALAIRE;}
float depenses::getEVENT(){return EVENT;}
QDate depenses::getDATE_DEP(){return DATE_DEP;}
void depenses::setID_DEP(int ID_DEP){this->ID_DEP=ID_DEP;}
void depenses::setACHAT(float ACHAT){this->ACHAT=ACHAT;}
void depenses::setSALAIRE(float SALAIRE){this->SALAIRE=SALAIRE;}
void depenses::setEVENT(float EVENT){this->EVENT=EVENT;}
void depenses::setDATE_DEP(QDate DATE_DEP){this->DATE_DEP=DATE_DEP;}
bool depenses::ajout_dep(){
    bool test=false;
    QSqlQuery query;
     QString IDd_String=QString::number(ID_DEP);
     QString ACHAT_String=QString::number(ACHAT);
     QString SALAIRE_String=QString::number(SALAIRE);
     QString EVENT_String=QString::number(EVENT);
    query.prepare("INSERT INTO depenses (ID_DEP,ACHAT,SALAIRE,EVENT,DATE_DEP)"
                  "VALUES (:ID_DEP,:ACHAT,:SALAIRE,:EVENT,:DATE_DEP)");
    query.bindValue(":ID_DEP", IDd_String);
    query.bindValue(":ACHAT",ACHAT_String);
    query.bindValue(":SALAIRE",SALAIRE_String);
    query.bindValue(":EVENT",EVENT_String);
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
    model->setHeaderData(3, Qt::Horizontal,QObject::tr("EVENT"));
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
    QString EVENT_String=QString::number(EVENT);
    query.prepare("UPDATE depenses set ACHAT=:ACHAT,SALAIRE=:SALAIRE,EVENT=:EVENT,DATE_DEP=:DATE_DEP where ID_DEP=:ID_DEP ");
    query.bindValue(":ID_DEP",ID_DEP);
    query.bindValue(":ACHAT",ACHAT_String);
    query.bindValue(":SALAIRE",SALAIRE_String);
    query.bindValue(":EVENT",EVENT_String);
    query.bindValue(":DATE_DEP",DATE_DEP);
    return query.exec();

}

QSqlQueryModel* depenses::tri_ACHAT(){
    QSqlQueryModel* model=new QSqlQueryModel();
    model->setQuery("SELECT* FROM depenses Order By ACHAT DESC");
    model->setHeaderData(0, Qt::Horizontal,QObject::tr("ID_DEP"));
    model->setHeaderData(1, Qt::Horizontal,QObject::tr("ACHAT"));
    model->setHeaderData(2, Qt::Horizontal,QObject::tr("SALAIRE"));
    model->setHeaderData(3, Qt::Horizontal,QObject::tr("EVENT"));
    model->setHeaderData(4, Qt::Horizontal,QObject::tr("DATE_DEP"));


    return model;
}
QSqlQueryModel* depenses::tri_ACHATASC(){
    QSqlQueryModel* model=new QSqlQueryModel();
    model->setQuery("SELECT* FROM depenses Order By ACHAT ASC");
    model->setHeaderData(0, Qt::Horizontal,QObject::tr("ID_DEP"));
    model->setHeaderData(1, Qt::Horizontal,QObject::tr("ACHAT"));
    model->setHeaderData(2, Qt::Horizontal,QObject::tr("SALAIRE"));
    model->setHeaderData(3, Qt::Horizontal,QObject::tr("EVENT"));
    model->setHeaderData(4, Qt::Horizontal,QObject::tr("DATE_DEP"));


    return model;
}
QSqlQueryModel* depenses::tri_SALAIREDESC(){
    QSqlQueryModel* model=new QSqlQueryModel();
    model->setQuery("SELECT* FROM depenses Order By SALAIRE DESC");
    model->setHeaderData(0, Qt::Horizontal,QObject::tr("ID_DEP"));
    model->setHeaderData(1, Qt::Horizontal,QObject::tr("ACHAT"));
    model->setHeaderData(2, Qt::Horizontal,QObject::tr("SALAIRE"));
    model->setHeaderData(3, Qt::Horizontal,QObject::tr("EVENT"));
    model->setHeaderData(4, Qt::Horizontal,QObject::tr("DATE_DEP"));


    return model;
}
QSqlQueryModel* depenses::tri_SALAIREASC(){
    QSqlQueryModel* model=new QSqlQueryModel();
    model->setQuery("SELECT* FROM depenses Order By SALAIRE ASC");
    model->setHeaderData(0, Qt::Horizontal,QObject::tr("ID_DEP"));
    model->setHeaderData(1, Qt::Horizontal,QObject::tr("ACHAT"));
    model->setHeaderData(2, Qt::Horizontal,QObject::tr("SALAIRE"));
    model->setHeaderData(3, Qt::Horizontal,QObject::tr("EVENT"));
    model->setHeaderData(4, Qt::Horizontal,QObject::tr("DATE_DEP"));


    return model;
}
QSqlQueryModel* depenses::tri_EVENTDESC(){
    QSqlQueryModel* model=new QSqlQueryModel();
    model->setQuery("SELECT* FROM depenses Order By EVENT DESC");
    model->setHeaderData(0, Qt::Horizontal,QObject::tr("ID_DEP"));
    model->setHeaderData(1, Qt::Horizontal,QObject::tr("ACHAT"));
    model->setHeaderData(2, Qt::Horizontal,QObject::tr("SALAIRE"));
    model->setHeaderData(3, Qt::Horizontal,QObject::tr("EVENT"));
    model->setHeaderData(4, Qt::Horizontal,QObject::tr("DATE_DEP"));


    return model;
}
QSqlQueryModel* depenses::tri_EVENTASC(){
    QSqlQueryModel* model=new QSqlQueryModel();
    model->setQuery("SELECT* FROM depenses Order By EVENT ASC");
    model->setHeaderData(0, Qt::Horizontal,QObject::tr("ID_DEP"));
    model->setHeaderData(1, Qt::Horizontal,QObject::tr("ACHAT"));
    model->setHeaderData(2, Qt::Horizontal,QObject::tr("SALAIRE"));
    model->setHeaderData(3, Qt::Horizontal,QObject::tr("EVENT"));
    model->setHeaderData(4, Qt::Horizontal,QObject::tr("DATE_DEP"));


    return model;
}
QSqlQueryModel* depenses::tri_datedepDESC(){
    QSqlQueryModel* model=new QSqlQueryModel();
    model->setQuery("SELECT* FROM depenses Order By DATE_DEP DESC");
    model->setHeaderData(0, Qt::Horizontal,QObject::tr("ID_DEP"));
    model->setHeaderData(1, Qt::Horizontal,QObject::tr("ACHAT"));
    model->setHeaderData(2, Qt::Horizontal,QObject::tr("SALAIRE"));
    model->setHeaderData(3, Qt::Horizontal,QObject::tr("EVENT"));
    model->setHeaderData(4, Qt::Horizontal,QObject::tr("DATE_DEP"));


    return model;
}
QSqlQueryModel* depenses::tri_datedepASC(){
    QSqlQueryModel* model=new QSqlQueryModel();
    model->setQuery("SELECT* FROM depenses Order By DATE_DEP ASC");
    model->setHeaderData(0, Qt::Horizontal,QObject::tr("ID_DEP"));
    model->setHeaderData(1, Qt::Horizontal,QObject::tr("ACHAT"));
    model->setHeaderData(2, Qt::Horizontal,QObject::tr("SALAIRE"));
    model->setHeaderData(3, Qt::Horizontal,QObject::tr("EVENT"));
    model->setHeaderData(4, Qt::Horizontal,QObject::tr("DATE_DEP"));


    return model;
}
QSqlQueryModel * depenses ::chercher_Dep(QString word)
{
    QSqlQueryModel * model= new QSqlQueryModel();
    QString w= "select * from depenses where ID_DEP like '%"+word+"%' or ACHAT like '%"+word+"%' or SALAIRE like '%"+word+"%' or EVENT like '%"+word+"%'";
    model->setQuery(w);
    return model;
}
