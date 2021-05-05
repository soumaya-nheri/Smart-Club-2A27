#ifndef HISTORIQUE_H
#define HISTORIQUE_H
#include<QDate>
#include<QSqlQueryModel>

class historique
{
public:
    historique();
    historique(int,QDate,QDate);

    int getID_HIS();
    QDate getCREATED();
    QDate getModified();

    //setters
    void setID_HIS(int);
    void setCREATED(QDate);
    void setMODIFIED(QDate);
    //functions
    bool ajout_his();
    QSqlQueryModel* afficher();
    bool modifier_his (int);
private:
    int ID_HIS;
    QDate CREATED,MODIFIED;


};

#endif // HISTORIQUE_H
