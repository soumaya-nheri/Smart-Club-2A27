#include "modifierprogrammes.h"
#include "ui_modifierprogrammes.h"
#include "programs.h"
#include<QMessageBox>
#include<QTime>
#include <QDate>


modifierProgrammes::modifierProgrammes(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::modifierProgrammes)
{
    ui->setupUi(this);
}

modifierProgrammes::~modifierProgrammes()
{
    delete ui;
}
void modifierProgrammes::setID_Planning(int ID_Planning){
QString IDd_String=QString::number(ID_Planning);

   ui->ID_Planning2->setText(IDd_String);
}
void modifierProgrammes::setDate_Planning(QDate Date_Planning){


   ui->Date_Planning2->setDate(Date_Planning);
}
void modifierProgrammes::setHeure(QTime Heure){

   ui->Heure2->setTime(Heure);
}
void modifierProgrammes::setNumero_Sem(int Numero_Sem){

QString NUMd_String=QString::number(Numero_Sem);
   ui->Numero_Sem2->setText(NUMd_String);
}
void modifierProgrammes::setNB_reservation(int NB_reservation){

QString REVd_String=QString::number(NB_reservation);
   ui->NB_reservation2->setText(REVd_String);
}
void modifierProgrammes::setNom_Coach(QString Nom_Coach){

   ui->Nom_Coach2->setText(Nom_Coach);
}


void modifierProgrammes::on_modifierProgrammes_2_clicked()
{
    int ID_Planning=ui->ID_Planning2->text().toInt();
    QDate Date_Planning =ui->Date_Planning2->date();
    QTime Heure =ui->Heure2->time();
    int Numero_Sem =ui->Numero_Sem2->text().toInt();
    int NB_reservation =ui->NB_reservation2->text().toInt();
    QString Nom_Coach=ui->Nom_Coach2->text();
    programs d(ID_Planning,Date_Planning,Heure,Numero_Sem,NB_reservation,Nom_Coach);
    bool test=d.Modifier2(ID_Planning);
    QMessageBox msgbox;

    if(test)
        msgbox.setText("Modification avec succes");
    else
        msgbox.setText("Echec de modification");
    msgbox.exec();
}
