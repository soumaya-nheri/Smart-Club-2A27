#ifndef SPONSOR_H
#define SPONSOR_H
#include <QString>
#include <QSqlQueryModel>

class Sponsor
{
public:
    Sponsor();

    Sponsor(int,double,QString);
    int getid_spons();
    double getprix_spons();
    QString getpub_spons();
    void setid_spons(int);
    void setprix_spons(double);
    void setpub_spons(QString);
    bool ajouter();
    QSqlQueryModel* afficher();
bool supprimer(int);
 QSqlQueryModel* afficher_by_recherche(QString);
Sponsor* recherche_by_id(int);
bool update (Sponsor);
  QSqlQueryModel* afficher_id_sponsors();
private:
    int id_spons;
   double prix_spons ;
     QString pub_spons;
};

#endif // SPONSOR_H
