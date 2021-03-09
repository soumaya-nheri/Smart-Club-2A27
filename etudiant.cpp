#include "etudiant.h"
#include"QSqlQuery"
#include"QSqlQueryModel"
#include"QDebug"
#include"QObject"
etudiant::etudiant()
{
id=0;nom="";prenom="";
}
etudiant::etudiant(int id,QString nom,QString prenom)
{this->id=id;this->nom=nom;this->prenom=prenom;}
int etudiant::getid(){return id;}
QString etudiant::getnom(){return nom;}
QString etudiant::getprenom(){return prenom;}
void etudiant::setid(int id){this->id=id;}
void etudiant::setnom(QString nom){this->nom=nom;}
void etudiant::setprenom(QString prenom){this->prenom=prenom;}
bool etudiant::ajouter(){
    bool test=false;
    QSqlQuery query;
    QString id_string=QString::number(id);
          query.prepare("INSERT INTO etudiant (id, nom, prenom) "
                        "VALUES (:id, :nom, :prenom)");
          query.bindValue(":id", id_string);
          query.bindValue(":nom",nom);
          query.bindValue(":prenom",prenom);
          query.exec();

    return test;
}
QSqlQueryModel* etudiant::afficher(){
    QSqlQueryModel* model=new QSqlQueryModel();
    model->setQuery("SELECT* FROM etudiant");
    model->setHeaderData(0, Qt::Horizontal,QObject::tr("prenom"));
    model->setHeaderData(1, Qt::Horizontal,QObject::tr("nom"));
    model->setHeaderData(2, Qt::Horizontal,QObject::tr("Identifiant"));


    return model;
}
bool etudiant::supprimer(int){

    QSqlQuery query;
          query.prepare("Delete from etudiant where id=:id");
          query.bindValue(0, id);

          query.exec();

}
