#include "modifiercoach.h"
#include "ui_modifiercoach.h"
#include "coach.h"
#include<QMessageBox>
#include <QDate>
#include <QDateTimeEdit>

modifierCoach::modifierCoach(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::modifierCoach)
{
    ui->setupUi(this);
}

modifierCoach::~modifierCoach()
{
    delete ui;
}
void modifierCoach::setID_Coach(int ID_Coach){
QString IDd_String=QString::number(ID_Coach);

   ui->ID_Coach_2->setText(IDd_String);
}
void modifierCoach::setNom(QString Nom){


   ui->Nom_2->setText(Nom);
}
void modifierCoach::setPrenom(QString Prenom){

   ui->Prenom_2->setText(Prenom);
}
void modifierCoach::setSpecialite(QString Specialite){


   ui->Specialite_2->setText(Specialite);
}
void modifierCoach::setDate_Naiss(QDate){


   ui->Date_Naiss_2->setDate(Date_Naiss);
}

void modifierCoach::setEmail(QString Email){


   ui->Email_2->setText(Email);
}

void modifierCoach::setAB_PR(int AB_PR){
QString AB_PR_String=QString::number(AB_PR);

   ui->AB_PR_2->setText(AB_PR_String);
}


void modifierCoach::on_ModifierCoach_clicked()
{
    int ID_Coach=ui->ID_Coach_2->text().toInt();
    QString Nom=ui->Nom_2->text();
    QString Prenom=ui->Prenom_2->text();
    QString Specialite=ui->Specialite_2->text();
    QDate Date_Naiss =ui->Date_Naiss_2->date();
    QString Email=ui->Email_2->text();
    int AB_PR=ui->AB_PR_2->text().toInt();
    coach d(ID_Coach,Nom,Prenom,Specialite,Date_Naiss,Email,AB_PR);
    bool test=d.Modifier1(ID_Coach);
    QMessageBox msgbox;

    if(test)
        msgbox.setText("Modification avec succes");
    else
        msgbox.setText("Echec de modification");
    msgbox.exec();

}
