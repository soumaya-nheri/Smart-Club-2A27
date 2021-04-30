#include "coach.h"
#include"QSqlQuery"
#include"QSqlQueryModel"
#include"QDebug"
#include"QObject"
#include<QDate>
#include<QString>
coach::coach()
{
    ID_Coach=0; Nom=QString() ;Prenom=QString() ;Specialite=QString();Date_Naiss=QDate::currentDate();Email=QString();AB_PR= 0;
    }
    coach::coach(int ID_Coach,QString Nom,QString Prenom,QString Specialite,QDate Date_Naiss,QString Email,int AB_PR)
    {
        this->ID_Coach=ID_Coach;
        this->Nom=Nom;
        this->Prenom=Prenom;
        this->Specialite=Specialite;
        this->Date_Naiss=Date_Naiss;
        this->Email=Email;
        this->AB_PR=AB_PR;
    }
    int coach::getID_Coach(){return ID_Coach;}
    QString coach::getNom(){return Nom;}
    QString coach::getPrenom(){return Prenom;}
    QString coach::getSpecialite(){return Specialite;}
    QDate coach::getDate_Naiss(){return Date_Naiss;}
    QString coach::getEmail(){return Email;}
    int coach::getAB_PR(){return AB_PR;}
    void coach::setID_Coach(int ID_Coach){this->ID_Coach=ID_Coach;}
    void coach::setNom(QString Nom){this->Nom=Nom;}
    void coach::setPrenom(QString Prenom){this->Prenom=Prenom;}
    void coach::setSpecialite(QString Specialite){this->Specialite=Specialite;}
    void coach::setDate_Naiss(QDate Date_Naiss){this->Date_Naiss=Date_Naiss;}
    void coach::setEmail(QString Email){this->Email=Email;}
    void coach::setAB_PR(int AB_PR){this->AB_PR=AB_PR;}
    bool coach::Ajouter1(){
        bool test=false;
        QSqlQuery query;
         QString ID_Coach_String=QString::number(ID_Coach);
         QString AB_PR_String=QString::number(AB_PR);

        query.prepare("INSERT INTO coach (ID_Coach,Nom,Prenom,Specialite,Date_Naiss,Email,AB_PR)"
                      "VALUES (:ID_Coach,:Nom,:Prenom,:Specialite,:Date_Naiss,:Email,:AB_PR)");
        query.bindValue(":ID_Coach", ID_Coach_String);
        query.bindValue(":Nom",Nom);
        query.bindValue(":Prenom",Prenom);
        query.bindValue(":Specialite",Specialite);
        query.bindValue(":Date_Naiss",Date_Naiss);
        query.bindValue(":Email",Email);
        query.bindValue(":AB_PR", AB_PR_String);


        query.exec();

    return test;
    }
    QSqlQueryModel* coach::Afficher1(){
        QSqlQueryModel*  model=new QSqlQueryModel();
        model->setQuery("SELECT* FROM coach");
        model->setHeaderData(0, Qt::Horizontal,QObject::tr("ID_Coach"));
        model->setHeaderData(1, Qt::Horizontal,QObject::tr("Nom"));
        model->setHeaderData(2, Qt::Horizontal,QObject::tr("Prenom"));
        model->setHeaderData(3, Qt::Horizontal,QObject::tr("Specialite"));
        model->setHeaderData(4, Qt::Horizontal,QObject::tr("Date_Naiss"));
        model->setHeaderData(5, Qt::Horizontal,QObject::tr("Email"));
        model->setHeaderData(6, Qt::Horizontal,QObject::tr("AB_PR"));



        return model;
    }
    bool coach::Supprimer1(int){

        QSqlQuery query;
              query.prepare("Delete from coach where ID_Coach=:ID_Coach");
              query.bindValue(0, ID_Coach);

             return query.exec();

    }
    bool coach::Modifier1(int ID_Coach)
    {
        QSqlQuery query;
        query.prepare("UPDATE coach set Nom=:Nom,Prenom=:Prenom,Specialite=:Specialite,Date_Naiss=:Date_Naiss,Email=:Email,AB_PR=:AB_PR where ID_Coach=:ID_Coach ");
        query.bindValue(":ID_Coach",ID_Coach);
        query.bindValue(":Nom",Nom);
        query.bindValue(":Prenom",Prenom);
        query.bindValue(":Specialite",Specialite);
        query.bindValue(":Date_Naiss",Date_Naiss);
        query.bindValue(":Email",Email);
        query.bindValue(":AB_PR",AB_PR);
        return query.exec();

}
    QSqlQueryModel * coach ::chercher(QString word)
    {

        QSqlQueryModel * model= new QSqlQueryModel();
        QString p= "select * from coach where ID_Coach like '%"+word+"%' or Nom like '%"+word+"%' or Prenom like '%"+word+"%' or Specialite like '%"+word+"%'";
        model->setQuery(p);
        return model;


    }
