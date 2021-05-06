#ifndef EVENEMENT_H
#define EVENEMENT_H
#include <QString>
#include <QSqlQueryModel>
#include<QDate>

class Evenement
{
public:
    Evenement();
    Evenement(int,QString,QString,QString,QDate,int,QString,QString);
    int getid();

    QString getlieu_event();
    QString getnom();
    QString getdescr();
    QDate getdate();
    void setid(int);
    QString getcat();
    void setcat(QString);
    QString gettype();
    void settype(QString);
    void setlieu_event(QString);
    void setnom(QString);
    void setdescr(QString);
    void setdate(QDate);
    bool ajouter();
int getcount(QString,QString);
int getTotal();
double pourcentage(QString,QString);

    QSqlQueryModel* afficher();

    QSqlQueryModel* afficher_id_events();
    bool supprimer(int);
     QSqlQueryModel* afficher_by_recherche(QString);
     Evenement* recherche_by_id(int);
     bool update (Evenement);

private:
    int id,id_spons ;

    QString  lieu_event,nom,descr,type,cat;
    QDate date;


};

#endif // EVENEMENT_H
