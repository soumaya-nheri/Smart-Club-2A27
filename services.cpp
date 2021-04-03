#include "services.h"
#include"QSqlQuery"
#include"QSqlQueryModel"
#include"QDebug"
#include"QObject"


services::services()
{
    id_service=0;nom_service="";nbre_materiel=0;type="";

}
services::services(int id_service,QString nom_service,int nbre_materiel,QString type)
{this->id_service=id_service;this->nom_service=nom_service;this->nbre_materiel=nbre_materiel;this->type=type;}
int services::getid_service(){return id_service;}
QString services::getnom_service(){return nom_service;}
int services::getnbre_materiel(){return nbre_materiel;}
QString services::gettype(){return type;}

void services::setid_service(int id_service){this->id_service=id_service;}
void services::setnom_service(QString nom_service){this->nom_service=nom_service;}
void services::setnbre_materiel(int nbre_materiel){this->nbre_materiel=nbre_materiel;}
void services::settype(QString type){this->type=type;}

bool services::ajouter(){
    bool test=false;
    QSqlQuery query;
    QString id_string=QString::number(id_service);
          query.prepare("INSERT INTO services (id_service, nom_service, nbre_materiel, type) "
                        "VALUES (:id_service, :nom_service, :nbre_materiel, :type)");
          query.bindValue(":id_service", id_string);
          query.bindValue(":nom_service",nom_service);
          query.bindValue(":nbre_materiel",nbre_materiel);
          query.bindValue(":type",type);

          query.exec();

    return test;
}
QSqlQueryModel* services::afficher(){
    QSqlQueryModel* model=new QSqlQueryModel();
    model->setQuery("SELECT* FROM services");
    model->setHeaderData(0, Qt::Horizontal,QObject::tr("Identifiant"));
    model->setHeaderData(1, Qt::Horizontal,QObject::tr("nom_service"));
    model->setHeaderData(2, Qt::Horizontal,QObject::tr("nbre_materiel"));
    model->setHeaderData(3, Qt::Horizontal,QObject::tr("type"));




    return model;
}

bool services::supprimer(int){

    QSqlQuery query;
          query.prepare("Delete from services where id_service=:id_service");
          query.bindValue(0, id_service);

        return  query.exec();


}

bool services::modifier(int id_service)
{
    QSqlQuery query;


    query.prepare("UPDATE services set nom_service=:nom_service,nbre_materiel=:nbre_materiel,type=:type where id_service=:id_service ");
    query.bindValue(":id_service",id_service);
    query.bindValue(":nom_service",nom_service);
    query.bindValue(":nbre_materiel",nbre_materiel);
    query.bindValue(":type",type);

    return query.exec();

}

