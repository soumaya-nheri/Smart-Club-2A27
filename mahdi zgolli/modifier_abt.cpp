#include "modifier_abt.h"
#include "ui_modifier_abt.h"
#include<QMessageBox>
modifier_abt::modifier_abt(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::modifier_abt)
{
    ui->setupUi(this);
}

modifier_abt::~modifier_abt()
{
    delete ui;
}
void modifier_abt::setID_ABT(int ID_ABT){
QString IDd_String=QString::number(ID_ABT);



   ui->ID_ABTMOD->setText(IDd_String);
}
void modifier_abt::setTYPE(QString TYPE){

   ui->TYPE_MOD->setText(TYPE);
}
void modifier_abt::setDATE_INS(QDate DATE_INS){

   ui->DATE_INS_MOD->setDate(DATE_INS);
}


void modifier_abt::on_MOD_clicked()
{
    int ID_ABT=ui->ID_ABTMOD->text().toInt();
    QString TYPE=ui->TYPE_MOD->text();

    QDate DATE_INS=ui->DATE_INS_MOD->date();
    abonnement a(ID_ABT,DATE_INS,TYPE);
    bool test=a.modifier(ID_ABT);
    QMessageBox msgbox;

    if(test)
        msgbox.setText("Modification avec succes");
    else
        msgbox.setText("Echec de modification");
    msgbox.exec();
}
