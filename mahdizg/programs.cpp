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
         QString ID_PLANNING_String=QString::number(ID_Planning);
         QString NUMERO_SEM_String=QString::number(Numero_Sem);
         QString NB_RESERVATION_String=QString::number(NB_reservation);
        query.prepare("INSERT INTO programs (ID_Planning,Date_Planning,Heure,Numero_Sem,NB_reservation,Nom_Coach)"
                      "VALUES (:ID_Planning,:Date_Planning,:Heure,:Numero_Sem,:NB_reservation,Nom_Coach)");
        query.bindValue(":ID_Planning", ID_PLANNING_String);
        query.bindValue(":Nom",Date_Planning);
        query.bindValue(":Nom",Heure);
        query.bindValue(":Nom",NUMERO_SEM_String);
        query.bindValue(":Prenom",NB_RESERVATION_String);
        query.bindValue(":Specialite",Nom_Coach);
        query.exec();

    return test;
    }
    QSqlQueryModel* programs::Afficher2(){
        QSqlQueryModel* model=new QSqlQueryModel();
        model->setQuery("SELECT* FROM coach");
        model->setHeaderData(0, Qt::Horizontal,QObject::tr("ID_PLANNING"));
        model->setHeaderData(1, Qt::Horizontal,QObject::tr("DATE_PLANNING"));
        model->setHeaderData(2, Qt::Horizontal,QObject::tr("HEURE"));
        model->setHeaderData(3, Qt::Horizontal,QObject::tr("NUMERO_SEM"));
        model->setHeaderData(4, Qt::Horizontal,QObject::tr("NB_RESERVATION"));
        model->setHeaderData(5, Qt::Horizontal,QObject::tr("NOM_COACH"));


        return model;
    }
    bool programs::Supprimer2(int){

        QSqlQuery query;
              query.prepare("Delete from revenues where ID_COACH=:ID_COACH");
              query.bindValue(0, ID_Planning);

             return query.exec();

    }
    bool programs::Modifier2(int ID_Planning)
    {
        QSqlQuery query;
        QString ID_PLANNING_String=QString::number(ID_Planning);
        QString NUMERO_SEM_String=QString::number(Numero_Sem);
        QString NB_RESERVATION_String=QString(NB_reservation);
        query.prepare("UPDATE programs set DATE_PLANNING=:DATE_PLANNING,HEURE=:HEURE,NUMERO_SEM=:NUMERO_SEM,NB_RESERVATION=:NB_RESERVATION,NOM_COACH=:NOM_COACH where ID_PLANNING=:ID_PLANNING ");
        query.bindValue(":ID_Planning",ID_PLANNING_String);
        query.bindValue(":Date_Planning",Date_Planning);
        query.bindValue(":Heure",Heure);
        query.bindValue(":Numero_Sem",NUMERO_SEM_String);
        query.bindValue(":NB_reservation",NB_RESERVATION_String);
        query.bindValue(":Nom_Coach",Nom_Coach);


        return query.exec();

}
