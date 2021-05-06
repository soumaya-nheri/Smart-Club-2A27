#include "abonnement.h"
#include"QSqlQuery"
#include"QSqlQueryModel"
#include"QDebug"
#include"QObject"
#include<QDate>
#include<iostream>
using namespace std;
abonnement::abonnement()
{
ID_ABT=0;TYPE="";DATE_INS=QDate::currentDate();
}
abonnement::abonnement(int ID_ABT,QDate DATE_INS,QString TYPE)
{
    this->ID_ABT=ID_ABT;
    this->DATE_INS=DATE_INS;
    this->TYPE=TYPE;
}
int abonnement::getID_ABT(){return ID_ABT;}
QDate abonnement::getDATE_INS(){return DATE_INS;}
QString abonnement::getTYPE(){return TYPE;}
void abonnement::setID_ABT(int ID_ABT){this->ID_ABT=ID_ABT;}
void abonnement::setDATE_INS(QDate DATE_INS){this->DATE_INS=DATE_INS;}
void abonnement::setTYPE(QString TYPE){this->TYPE=TYPE;}
bool abonnement::ajout_abt(){
    bool test=false;
    QSqlQuery query;
     QString IDd_String=QString::number(ID_ABT);

    query.prepare("INSERT INTO ABONNEMENT (ID_ABT,DATE_INS,TYPE)"
                  "VALUES (:ID_ABT,:DATE_INS,:TYPE)");
    query.bindValue(":ID_ABT", IDd_String);
    qDebug()<<IDd_String;
    query.bindValue(":DATE_INS",DATE_INS);
    qDebug()<<DATE_INS;

    query.bindValue(":TYPE",TYPE);
    qDebug()<<TYPE;

    query.exec();

return test;
}
QSqlQueryModel* abonnement::afficher(){
    QSqlQueryModel* model=new QSqlQueryModel();
    model->setQuery("SELECT * FROM abonnement");
    model->setHeaderData(0, Qt::Horizontal,QObject::tr("ID_ABT"));
    model->setHeaderData(1, Qt::Horizontal,QObject::tr("DATE_INS"));
    model->setHeaderData(2, Qt::Horizontal,QObject::tr("TYPE"));
    return model;
}
bool abonnement::supprimer(int){

    QSqlQuery query;
          query.prepare("Delete from abonnement where ID_ABT=:ID_ABT");
          query.bindValue(0, ID_ABT);

         return query.exec();

}
bool abonnement::modifier(int ID_ABT)
{
    QSqlQuery query;
    query.prepare("UPDATE abonnement set DATE_INS=:DATE_INS,TYPE=:TYPE where ID_ABT=:ID_ABT ");
    query.bindValue(":ID_ABT",ID_ABT);
    query.bindValue(":DATE_INS",DATE_INS);
    query.bindValue(":TYPE",TYPE);
    return query.exec();

}
QSqlQueryModel* abonnement::tri_IDDESC(){
    QSqlQueryModel* model=new QSqlQueryModel();
    model->setQuery("SELECT* FROM abonnement Order By ID_ABT DESC");
    model->setHeaderData(0, Qt::Horizontal,QObject::tr("ID_ABT"));
    model->setHeaderData(1, Qt::Horizontal,QObject::tr("DATE_INS"));
    model->setHeaderData(2, Qt::Horizontal,QObject::tr("TYPE"));


    return model;
}
QSqlQueryModel* abonnement::tri_IDASC(){
    QSqlQueryModel* model=new QSqlQueryModel();
    model->setQuery("SELECT* FROM abonnement Order By ID_ABT ASC");
    model->setHeaderData(0, Qt::Horizontal,QObject::tr("ID_ABT"));
    model->setHeaderData(1, Qt::Horizontal,QObject::tr("DATE_INS"));
    model->setHeaderData(2, Qt::Horizontal,QObject::tr("TYPE"));


    return model;
}

QSqlQueryModel * abonnement ::chercher_ABT(QString word)
{
    QSqlQueryModel * model= new QSqlQueryModel();
    QString w= "select * from abonnement where ID_ABT like '%"+word+"%' or TYPE like '%"+word+"%' ";
    model->setQuery(w);
    return model;
}

