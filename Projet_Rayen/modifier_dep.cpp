#include "modifier_dep.h"
#include "ui_modifier_dep.h"
#include"depenses.h"
#include<QMessageBox>

modifier_dep::modifier_dep(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::modifier_dep)
{
    ui->setupUi(this);
     ui->ID_DEP3->setValidator( new QIntValidator(0, 9999, this));
     auto dv = new QDoubleValidator(0.0, 5.0, 2);
     ui->ACHAT2->setValidator(dv);
      ui->SALAIRE2->setValidator(dv);
      ui->EVENT2->setValidator(dv);

}

modifier_dep::~modifier_dep()
{
    delete ui;
}
void modifier_dep::setID_DEP(int ID_DEP){
QString IDd_String=QString::number(ID_DEP);

   ui->ID_DEP3->setText(IDd_String);
}
void modifier_dep::setACHAT(float ACHAT){
QString ACHAT_String=QString::number(ACHAT);

   ui->ACHAT2->setText(ACHAT_String);
}
void modifier_dep::setSALAIRE(float SALAIRE){
QString SALAIRE_String=QString::number(SALAIRE);

   ui->SALAIRE2->setText(SALAIRE_String);
}
void modifier_dep::setEVENT(float EVENT){
QString EVENT_String=QString::number(EVENT);

   ui->EVENT2->setText(EVENT_String);
}
void modifier_dep::setDATE_DEP(QDate){


   ui->DATE_DEP2->setDate(DATE_DEP);
}

void modifier_dep::on_mod_dep_clicked()
{
    int ID_DEP=ui->ID_DEP3->text().toInt();
    float ACHAT=ui->ACHAT2->text().toFloat();
    float SALAIRE=ui->SALAIRE2->text().toFloat();
    float EVENT=ui->EVENT2->text().toFloat();
    QDate DATE_DEP =ui->DATE_DEP2->date();
    depenses d(ID_DEP,ACHAT,SALAIRE,EVENT,DATE_DEP);
    bool test=d.modifier(ID_DEP);
    QMessageBox msgbox;

    if(test)
        msgbox.setText("Modification avec succes");
    else
        msgbox.setText("Echec de modification");
    msgbox.exec();
}
