#include "programs.h"
#include"QSqlQuery"
#include"QSqlQueryModel"
#include"QDebug"
#include"QObject"
#include<QDate>
#include<QString>

programs::programs()
{
    ID_Planning=0;Date_Planning=QDate::currentDate(); Numero_Sem=0 ;NB_reservation=0 ;Nom_Coach=QString();
    }
   programs::programs(int ID_Planning,QDate Date_Planning,QTime Heure,int Numero_Sem,int NB_reservation,QString Nom_Coach)
    {
        this->ID_Planning=ID_Planning;
        this->Date_Planning=Date_Planning;
        this->Heure=Heure;
        this->Numero_Sem=Numero_Sem;
        this->NB_reservation=NB_reservation;
        this->Nom_Coach=Nom_Coach;
    }
    int programs::getID_Planning(){return ID_Planning;}
    QDate programs::getDate_Planning(){return Date_Planning;}
    QTime programs::getHeure(){return Heure;}
    int programs::getNumero_Sem(){return Numero_Sem;}
    int programs::getNB_reservation(){return NB_reservation;}
    QString programs::getNom_Coach(){return Nom_Coach;}
    void programs::setID_Planning(int ID_Planning){this->ID_Planning=ID_Planning;}
    void programs::setDate_Planning(QDate Date_Planning){this->Date_Planning=Date_Planning;}
    void programs::setHeure(QTime Heure){this->Heure=Heure;}
    void programs::setNumero_Sem(int Numero_Sem){this->Numero_Sem=Numero_Sem;}
    void programs::setNB_reservation(int NB_reservation){this->NB_reservation=NB_reservation;}
    void programs::setNom_Coach(QString Nom_Coach){this->Nom_Coach=Nom_Coach;}
    bool programs::Ajouter2(){
        bool test=false;
        QSqlQuery query;
         QString ID_Planning_String=QString::number(ID_Planning);
         QString Numero_Sem_String=QString::number(Numero_Sem);
         QString NB_reservation_String=QString::number(NB_reservation);
        query.prepare("INSERT INTO programs (ID_Planning,Date_Planning,Heure,Numero_Sem,NB_reservation,Nom_Coach)"
                      "VALUES (:ID_Planning,:Date_Planning,:Heure,:Numero_Sem,:NB_reservation,:Nom_Coach)");
        query.bindValue(":ID_Planning", ID_Planning_String);
        query.bindValue(":Date_Planning",Date_Planning);
        query.bindValue(":Heure",Heure);
        query.bindValue(":Numero_Sem",Numero_Sem_String);
        query.bindValue(":NB_reservation",NB_reservation_String);
        query.bindValue(":Nom_Coach",Nom_Coach);
        query.exec();

    return test;
    }
    QSqlQueryModel* programs::Afficher2(){
        QSqlQueryModel* model=new QSqlQueryModel();
        model->setQuery("SELECT* FROM programs");
        model->setHeaderData(0, Qt::Horizontal,QObject::tr("ID_Planning"));
        model->setHeaderData(1, Qt::Horizontal,QObject::tr("Date_Planning"));
        model->setHeaderData(2, Qt::Horizontal,QObject::tr("Heure"));
        model->setHeaderData(3, Qt::Horizontal,QObject::tr("Numero_Sem"));
        model->setHeaderData(4, Qt::Horizontal,QObject::tr("NB_reservation"));
        model->setHeaderData(5, Qt::Horizontal,QObject::tr("Nom_Coach"));


        return model;
    }
    bool programs::Supprimer2(int){

        QSqlQuery query;
              query.prepare("Delete from programs where ID_Planning=:ID_Planning");
              query.bindValue(0, ID_Planning);

             return query.exec();

    }
    bool programs::Modifier2(int ID_Planning)
    {
        QSqlQuery query;
        QString ID_Planning_String=QString::number(ID_Planning);
        QString Numero_Sem_String=QString::number(Numero_Sem);
        QString NB_Reservation_String=QString::number(NB_reservation);
        query.prepare("UPDATE programs set Date_Planning=:Date_Planning,Heure=:Heure,Numero_Sem=:Numero_Sem,NB_reservation=:NB_reservation,Nom_Coach=:Nom_Coach where ID_Planning=:ID_Planning ");
        query.bindValue(":ID_Planning",ID_Planning_String);
        query.bindValue(":Date_Planning",Date_Planning);
        query.bindValue(":Heure",Heure);
        query.bindValue(":Numero_Sem",Numero_Sem_String);
        query.bindValue(":NB_reservation",NB_Reservation_String);
        query.bindValue(":Nom_Coach",Nom_Coach);


        return query.exec();

}
    QSqlQueryModel * programs ::chercher(QString word)
    {
        QSqlQueryModel * model= new QSqlQueryModel();
        QString w= "select * from programs where ID_Planning like '%"+word+"%' or Numero_Sem like '%"+word+"%' or NB_reservation like '%"+word+"%' or Nom_Coach like '%"+word+"%'";
        model->setQuery(w);
        return model;


    }
