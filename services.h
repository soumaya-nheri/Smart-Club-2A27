#ifndef SERVICES_H
#define SERVICES_H
#include"QString"
#include "QSqlQueryModel"

class services
{
public:
    services();


    services(int,QString,int,QString);
    int getid_service();
    QString getnom_service();
    int getnbre_materiel();
    QString gettype();

    void setid_service(int);
    void setnom_service(QString);
    void setnbre_materiel(int);
    void settype(QString);

    bool ajouter();
    QSqlQueryModel* afficher();
    bool supprimer(int);
    bool modifier(int);

private:
    int id_service,nbre_materiel;
    QString nom_service,type;
};

#endif // SERVICES_H
