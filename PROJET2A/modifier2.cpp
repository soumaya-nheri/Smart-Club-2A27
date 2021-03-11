#include "modifier2.h"
#include "ui_modifier2.h"
#include"depenses.h"
#include<qmessagebox.h>
#include<iostream>
using namespace std;


modifier2::modifier2(QDialog *parent) :
    QDialog(parent),
    ui(new Ui::modifier2)
{

    ui->setupUi(this);
    QValidator *validator = new QIntValidator(0, 99999999, this);
    ui->ACHAT2->setValidator(validator);
    ui->SALAIRE2->setValidator(validator);
    ui->SOMME2->setValidator(validator);
}

modifier2::~modifier2()
{
    delete ui;
}
void modifier2::setID_DEP(int ID_DEP){
QString IDd_String=QString::number(ID_DEP);

   ui->ID_DEP4->setText(IDd_String);
}
void modifier2::setACHAT(int ACHAT){
QString ACHAT_String=QString::number(ACHAT);

   ui->ACHAT2->setText(ACHAT_String);
}
void modifier2::setSALAIRE(int SALAIRE){
QString SALAIRE_String=QString::number(SALAIRE);

   ui->SALAIRE2->setText(SALAIRE_String);
}
void modifier2::setSOMME(int SOMME){
QString SOMME_String=QString::number(SOMME);

   ui->SOMME2->setText(SOMME_String);
}
void modifier2::setDATE_DEP(QDate){


   ui->DATE_DEP2->setDate(DATE_DEP);
}

void modifier2::on_mod_dep2_clicked()
{
    int ID_DEP=ui->ID_DEP4->text().toInt();
    int ACHAT=ui->ACHAT2->text().toInt();
    int SALAIRE=ui->SALAIRE2->text().toInt();
    int SOMME=ui->SOMME2->text().toInt();
    QDate DATE_DEP =ui->DATE_DEP2->date();
    depenses d(ID_DEP,ACHAT,SALAIRE,SOMME,DATE_DEP);
    bool test=d.modifier(ID_DEP);
    QMessageBox msgbox;

    if(test)
        msgbox.setText("Modification avec succes");
    else
        msgbox.setText("Echec de modification");
    msgbox.exec();
}
