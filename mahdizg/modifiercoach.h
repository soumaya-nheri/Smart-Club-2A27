#ifndef MODIFIERCOACH_H
#define MODIFIERCOACH_H

#include <QDialog>
#include<QString>
#include<QSqlQuery>
#include<QSqlQueryModel>
#include<QDate>
#include<QTime>

namespace Ui {
class modifierCoach;
}

class modifierCoach : public QDialog
{
    Q_OBJECT

public:
    explicit modifierCoach(QWidget *parent = nullptr);
    ~modifierCoach();
    void setID_Coach(int);
    void setNom(QString);
    void setPrenom(QString);
    void setSpecialite(QString);
    void setDate_Naiss(QDate);


private slots:

    void on_ModifierCoach_clicked();

private:
    Ui::modifierCoach *ui;
    int ID_Coach;
    QDate Date_Naiss;
    QString Nom,Prenom,Specialite;
};

#endif // MODIFIERCOACH_H
