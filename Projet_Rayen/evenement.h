
#ifndef EVENEMENT_H
#define EVENEMENT_H
#include <QString>
#include <QSqlQueryModel>

class Evenement
{
public:
    Evenement();
    Evenement(int,QString,QString,QString,QString,int,QString,QString);
    int getid();

    QString getlieu_event();
    QString getnom();
    QString getdescr();
    QString getdate();
    void setid(int);
    QString getcat();
    void setcat(QString);
    QString gettype();
    void settype(QString);
    void setlieu_event(QString);
    void setnom(QString);
    void setdescr(QString);
    void setdate(QString);
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

    QString  lieu_event,nom,descr,date,type,cat;


};

#endif // EVENEMENT_H
