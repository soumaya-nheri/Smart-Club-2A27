#ifndef ABONNES_H
#define ABONNES_H

#include<QString>
#include<QSqlQuery>
#include<QSqlQueryModel>
#include<QDate>
class abonnes
{
public:
    abonnes();
    abonnes(int ID_AB ,QString NOM,QString PRENOM ,int AGE );

    int getID_AB() ;
    QString getNOM() ;
    QString getPRENOM() ;
    int getAGE() ;

    void setID_AB(int);
    void setNOM( QString);
    void setPRENOM( QString);
    void setAGE(int);
    bool ajout_ab();
    QSqlQueryModel* afficher();
    bool supprimer(int);
    bool modifier (int);
    QSqlQueryModel* chercher(QString);
private:
    QString NOM,PRENOM;
    int ID_AB,AGE;
};

#endif // ABONNES_H
