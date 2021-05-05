#include "sponsor.h"
#include <QSqlQuery>
#include <QApplication>
#include <QtDebug>
#include <qsqlerror.h>

Sponsor::Sponsor()
{
    id_spons=0;prix_spons=0; pub_spons="";

}
Sponsor::Sponsor(int id_spons,double prix_spons,QString pub_spons)
{this->id_spons=id_spons;this->prix_spons=prix_spons;this->pub_spons=pub_spons;

}
        int Sponsor::getid_spons() {return id_spons;}
       double Sponsor::getprix_spons() {return prix_spons;}



        QString Sponsor::getpub_spons(){return pub_spons;}
        void Sponsor:: setid_spons(int id_spons){this->id_spons=id_spons;}
          void Sponsor:: setprix_spons(double prix_spons){this->prix_spons=prix_spons;}
            void Sponsor:: setpub_spons(QString pub_spons){this->pub_spons=pub_spons;}
            bool Sponsor::ajouter()
            {



               QSqlQuery query;
                     query.prepare("INSERT INTO sponsor (id_spons, prix_spons, pub_spons) "
                                   "VALUES (:id_spons, :prix_spons, :pub_spons)");
                     query.bindValue(":id_spons", id_spons);
                     query.bindValue(":prix_spons", prix_spons);
                     query.bindValue(":pub_spons", pub_spons);



                    return query.exec();

                //    qDebug()<<query.lastError().text();


            }
            bool Sponsor::supprimer(int id_spons)
            {
qDebug()<<"****"<<id_spons;
                QSqlQuery query;
                      query.prepare("delete from sponsor where id_spons=:id_spons");
                      query.bindValue(":id_spons", id_spons);



                     return query.exec();





            }
            QSqlQueryModel *Sponsor::afficher()
            {


                QSqlQueryModel *model = new QSqlQueryModel();
                    model->setQuery("SELECT * FROM sponsor");


                    return model;




            }
 Sponsor* Sponsor::recherche_by_id(int id)
 {   QSqlQuery query;
     qDebug() <<"hello";
 Sponsor* S=new Sponsor();
        query.prepare("SELECT * FROM sponsor where id_spons=:id");
  query.bindValue(":id", id);
query.exec();
  while (query.next())
       {
       QString prix_string= query.value(1).toString();
        QString pub_string= query.value(2).toString();

        S->setid_spons(id);
      S->setprix_spons( prix_string.toDouble());
       S->setpub_spons( pub_string);

  }

  return S;
 }

 bool Sponsor::update (Sponsor S)
 {



     QSqlQuery query;
           query.prepare("update sponsor set   prix_spons=:prix, pub_spons=:pub where id_spons=:id") ;
           query.bindValue(":id", S.getid_spons());
           query.bindValue(":prix", S.getprix_spons());
           query.bindValue(":pub", S.getpub_spons());



          return query.exec();







 }
  QSqlQueryModel* Sponsor::afficher_by_recherche(QString arg)
  {




      QSqlQueryModel *model = new QSqlQueryModel();

      QSqlQuery query;
      model->setQuery("SELECT * FROM sponsor where id_spons like '%" +arg + "%' OR prix_spons like '%" +arg + "%'  OR pub_spons like '%" +arg + "%'  ");

          return model;


  }
  QSqlQueryModel* Sponsor::afficher_id_sponsors()
  {


      QSqlQueryModel *model = new QSqlQueryModel();
          model->setQuery("SELECT id_spons FROM sponsor");


          return model;


  }
