#include "equipements.h"
#include"QSqlQuery"
#include"QSqlQueryModel"
#include"QDebug"
#include"QObject"
equipements::equipements()
{
id_equipement=0;marque="";model="";prix="";etat="";disponibilite="";
}
equipements::equipements(int id_equipement,QString marque,QString model,QString prix,QString etat,QString disponibilite)
{this->id_equipement=id_equipement;this->marque=marque;this->model=model;this->prix=prix;this->etat=etat;this->disponibilite=disponibilite;}
int equipements::getid_equipement(){return id_equipement;}
QString equipements::getmarque(){return marque;}
QString equipements::getmodel(){return model;}
QString equipements::getprix(){return prix;}
QString equipements::getetat(){return etat;}
QString equipements::getdisponibilite(){return disponibilite;}
void equipements::setid_equipement(int id_equipement){this->id_equipement=id_equipement;}
void equipements::setmarque(QString marque){this->marque=marque;}
void equipements::setmodel(QString model){this->model=model;}
void equipements::setprix(QString prix){this->prix=prix;}
void equipements::setetat(QString etat){this->etat=etat;}
void equipements::setdisponibilite(QString disponibilite){this->disponibilite=disponibilite;}
bool equipements::ajouter(){
    bool test=false;
    QSqlQuery query;
    QString id_string=QString::number(id_equipement);
          query.prepare("INSERT INTO equipements (id_equipement, marque, model, prix, etat, disponibilite) "
                        "VALUES (:id_equipement, :marque, :model, :prix, :etat, :disponibilite)");
          query.bindValue(":id_equipement", id_string);
          query.bindValue(":marque",marque);
          query.bindValue(":model",model);
          query.bindValue(":prix",prix);
          query.bindValue(":etat",etat);
          query.bindValue(":disponibilite",disponibilite);
          query.exec();

    return test;
}
QSqlQueryModel* equipements::afficher(){
    QSqlQueryModel* model=new QSqlQueryModel();
    model->setQuery("SELECT* FROM equipements");
    model->setHeaderData(0, Qt::Horizontal,QObject::tr("Identifiant"));
    model->setHeaderData(1, Qt::Horizontal,QObject::tr("marque"));
    model->setHeaderData(2, Qt::Horizontal,QObject::tr("model"));
    model->setHeaderData(3, Qt::Horizontal,QObject::tr("prix"));
    model->setHeaderData(4, Qt::Horizontal,QObject::tr("etat"));
    model->setHeaderData(5, Qt::Horizontal,QObject::tr("disponibilite"));



    return model;
}

bool equipements::supprimer(int){

    QSqlQuery query;
          query.prepare("Delete from equipements where id_equipement=:id_equipement");
          query.bindValue(0, id_equipement);

        return  query.exec();


}

bool equipements::modifier(int id_equipement)
{
    QSqlQuery query;


    query.prepare("UPDATE equipements set marque=:marque,model=:model,prix=:prix,etat=:etat,disponibilite=:disponibilite where id_equipement=:id_equipement ");
    query.bindValue(":id_equipement",id_equipement);
    query.bindValue(":marque",marque);
    query.bindValue(":model",model);
    query.bindValue(":prix",prix);
    query.bindValue(":etat",etat);
    query.bindValue(":disponibilite",disponibilite);
    return query.exec();

}

QSqlQueryModel* equipements::affid_eq(){
    QSqlQueryModel* model=new QSqlQueryModel();
    model->setQuery("SELECT* FROM equipements");
    model->setHeaderData(0, Qt::Horizontal,QObject::tr("Identifiant"));




    return model;
}
