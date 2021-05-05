#include "evenement.h"
#include <QSqlQuery>
#include <QApplication>
#include <QtDebug>
#include <qsqlerror.h>
Evenement::Evenement()
{
    id=0;lieu_event=""; nom="";descr="";date=QDate::currentDate();

}
Evenement::Evenement(int id,QString lieu_event,QString nom,QString descr,QDate date,int id_spons,QString cat,QString type)
{this->id=id;this->lieu_event=lieu_event;this->nom=nom;this->descr=descr;this->id_spons=id_spons;
    this->type=type;this->cat=cat;
this->date=date;
}
        int Evenement::getid() {return id;}

        QString Evenement:: getlieu_event() {return lieu_event;}
        QString Evenement::getnom(){return nom;}
        QString Evenement::getdescr(){return descr;}
        QDate Evenement::getdate(){return date;}
        void Evenement:: setid(int id){this->id=id;}

void  Evenement::setlieu_event(QString lieu_event){this->lieu_event=lieu_event;}
void Evenement:: setnom(QString nom){this->nom=nom;}
void Evenement:: setdescr(QString descr){this->descr=descr;}
void Evenement:: setdate(QDate date){this->date=date;}
QString Evenement::getcat(){return  cat;}
void Evenement::setcat(QString cat){this->cat=cat;}
QString Evenement::gettype(){return  type;}
void Evenement::settype(QString type){this->type=type;}
bool Evenement::ajouter()
{



   QSqlQuery query;
         query.prepare("INSERT INTO evenement (id, nom, lieu,date_event,description,fk_sponsor,categorie,type) "
                       "VALUES (:id, :nom, :lieu,:date,:des,:fk,:cat,:type)");
         query.bindValue(":id", id);
         query.bindValue(":nom", nom);
         query.bindValue(":lieu", lieu_event);
         query.bindValue(":date", date);
         query.bindValue(":des", descr);
          query.bindValue(":fk", id_spons);
 query.bindValue(":cat", cat);
  query.bindValue(":type", type);
        return query.exec();

    //    qDebug()<<query.lastError().text();


}
bool Evenement::supprimer(int id)
{

    QSqlQuery query;
          query.prepare("delete from evenement where id=:id");
          query.bindValue(0, id);



         return query.exec();





}
QSqlQueryModel * Evenement::afficher()
{


    QSqlQueryModel *model = new QSqlQueryModel();
        model->setQuery("SELECT * FROM evenement");


        return model;




}

QSqlQueryModel * Evenement::afficher_id_events()
{


    QSqlQueryModel *model = new QSqlQueryModel();
        model->setQuery("SELECT id FROM evenement");


        return model;




}
Evenement* Evenement::recherche_by_id(int id)
{   QSqlQuery query;
    qDebug() <<"hello";
Evenement* E=new Evenement();
       query.prepare("SELECT * FROM evenement where id=:id");
 query.bindValue(":id", id);
query.exec();
 while (query.next())
      {
      QString nom_string= query.value(1).toString();
       QString lieu_string= query.value(2).toString();
        QDate date_string= query.value(3).toDate();
       QString descr_string= query.value(4).toString();
 QString cat= query.value(6).toString();
  QString type= query.value(7).toString();

       E->setid(id);
       E->setnom( nom_string);
       E->setlieu_event(lieu_string);
      E->setdescr( descr_string);

      E->setdate(date_string);
      E->setcat(cat);

      E->settype(type);


 }

 return E;

}
bool Evenement::update (Evenement E)
{



    QSqlQuery query;
          query.prepare("update evenement set   nom=:nom, lieu=:lieu,date_event=:date,description=:description,categorie=:cat,type=:type where id=:id") ;
          query.bindValue(":id", E.getid());
          query.bindValue(":nom", E.getnom());
           query.bindValue(":description", E.getdescr());
          query.bindValue(":lieu", E.getlieu_event());

           query.bindValue(":date", E.getdate());

            query.bindValue(":cat", E.getcat());
             query.bindValue(":type", E.gettype());

         return query.exec();







}
QSqlQueryModel* Evenement::afficher_by_recherche(QString arg)
{




    QSqlQueryModel *model = new QSqlQueryModel();

    QSqlQuery query;
    model->setQuery("SELECT * FROM evenement where id like '%" +arg + "%' OR nom  like '%" +arg + "%' OR lieu  like '%" +arg + "%' OR description like  '%" +arg + "%' OR date_event like  '%" +arg + "%' OR categorie  like '%" +arg + "%' OR type  like '%" +arg + "%'  ");
return model;

}
int  Evenement::getcount(QString cat, QString type)
{

    double count=0;


    QSqlQuery query;
      qDebug() <<"hello";

         query.prepare("SELECT count(*) FROM evenement where categorie=:cat and type=:type");
   query.bindValue(":cat", cat);
   query.bindValue(":type", type);
  query.exec();
   while (query.next())
        {
        count= query.value(0).toInt();



   }


  return count ;

}
int Evenement::getTotal()
{

    double count=0;


    QSqlQuery query;
      qDebug() <<"hello";

         query.prepare("SELECT count(*) FROM evenement ");

  query.exec();
   while (query.next())
        {
        count= query.value(0).toInt();



   }


  return count ;

}
double Evenement::pourcentage(QString cat,QString type)
{
qDebug()<<"catttt "<<cat<<" "<<"type "<<type<<" nb tiotal "<<getTotal()<<" getcount "<<getcount(cat,type)<<" pourcentage "<<((getcount(cat,type)*100)/getTotal());
 return ((getcount(cat,type)*100)/getTotal());


}
