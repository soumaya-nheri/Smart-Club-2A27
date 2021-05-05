#ifndef MODIFIERCOACH_H
#define MODIFIERCOACH_H

#include <QDialog>
#include<QString>
#include<QSqlQuery>
#include<QSqlQueryModel>
#include<QDate>
#include<QTime>
namespace Ui {
class modifiercoach;
}

class modifiercoach : public QDialog
{
    Q_OBJECT

public:
    explicit modifiercoach(QWidget *parent = nullptr);
    ~modifiercoach();
    void setID_Coach(int);
    void setNom(QString);
    void setPrenom(QString);
    void setSpecialite(QString);
    void setDate_Naiss(QDate);
    void setEmail(QString);
    void setAB_PR(int);



private slots:
    void on_ModifierCoach_clicked();

private:
    Ui::modifiercoach *ui;
    int ID_Coach,AB_PR;
    QDate Date_Naiss;
    QString Nom,Prenom,Specialite,Email;
};

#endif // MODIFIERCOACH_H