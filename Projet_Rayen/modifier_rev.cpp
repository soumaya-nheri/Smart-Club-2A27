#include "modifier_rev.h"
#include "ui_modifier_rev.h"
#include "revenues.h"
#include"QMessageBox"

modifier_rev::modifier_rev(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::modifier_rev)
{
    ui->setupUi(this);
     ui->ID_REV3->setValidator( new QIntValidator(0, 9999, this));
     auto dv = new QDoubleValidator(0.0, 5.0, 2);
     ui->CONSOMATION2->setValidator(dv);
      ui->REV_ABON2->setValidator(dv);
       ui->REV_SPONSOR2->setValidator(dv);

}

modifier_rev::~modifier_rev()
{
    delete ui;
}
void modifier_rev::setID_REV(int ID_REV){
QString ID_String=QString::number(ID_REV);

   ui->ID_REV3->setText(ID_String);
}
void modifier_rev::setCONSOMATION(float CONSOMATION){
QString CONSOMATION_String=QString::number(CONSOMATION);

   ui->CONSOMATION2->setText(CONSOMATION_String);
}
void modifier_rev::setREV_SPONSOR(float REV_SPONSOR){
QString REV_SPONSOR_String=QString::number(REV_SPONSOR);

   ui->REV_SPONSOR2->setText(REV_SPONSOR_String);
}
void modifier_rev::setREV_ABON(float REV_ABON){
QString REV_ABON_String=QString::number(REV_ABON);

   ui->REV_ABON2->setText(REV_ABON_String);
}
void modifier_rev::setDATE_REV(QDate){


   ui->DATE_REV2->setDate(DATE_REV);
}



void modifier_rev::on_pushButton_clicked()
{
    int ID_REV=ui->ID_REV3->text().toInt();
    float CONSOMATION=ui->CONSOMATION2->text().toFloat();
    float REV_SPONSOR=ui->REV_SPONSOR2->text().toFloat();
    float REV_ABON=ui->REV_ABON2->text().toFloat();
    QDate DATE_REV =ui->DATE_REV2->date();
    revenues r(ID_REV,CONSOMATION,REV_SPONSOR,REV_ABON,DATE_REV);
    bool test=r.modifier(ID_REV);
    QMessageBox msgbox;

    if(test)
        msgbox.setText("Modification avec succes");
    else
        msgbox.setText("Echec de modification");
    msgbox.exec();
}
