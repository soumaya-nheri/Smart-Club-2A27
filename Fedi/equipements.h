#ifndef EQUIPEMENTS_H
#define EQUIPEMENTS_H
#include"QString"
#include "QSqlQueryModel"
class equipements
{
public:
    equipements();

    equipements(int,QString,QString,QString,QString,QString);
    int getid_equipement();
    QString getmarque();
    QString getmodel();
    QString getprix();
    QString getetat();
    QString getdisponibilite();
    void setid_equipement(int);
    void setmarque(QString);
    void setmodel(QString);
    void setprix(QString);
    void setetat(QString);
    void setdisponibilite(QString);
    bool ajouter();
    QSqlQueryModel* afficher();
    bool supprimer(int);
    bool modifier(int);
    QSqlQueryModel* affid_eq();

private:
    int id_equipement;
    QString marque,model,prix,etat,disponibilite;

};
#endif // EQUIPEMENTS_H
