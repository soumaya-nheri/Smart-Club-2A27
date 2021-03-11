#include "modifier.h"
#include "revenues.h"
#include "ui_modifier.h"
#include"QMessageBox"




modifier::modifier(QDialog *parent) :
    QDialog(parent),
    ui(new Ui::modifier)
{
    ui->setupUi(this);
    QValidator *validator = new QIntValidator(0, 99999999, this);
    ui->REV_ABON2->setValidator(validator);
    ui->REV_SPONSOR2->setValidator(validator);
    ui->CONSOMATION2->setValidator(validator);
}

modifier::~modifier()
{
    delete ui;
}
void modifier::setID_REV(int ID_REV){
QString ID_String=QString::number(ID_REV);

   ui->ID_Rev4->setText(ID_String);
}
void modifier::setCONSOMATION(int CONSOMATION){
QString CONSOMATION_String=QString::number(CONSOMATION);

   ui->CONSOMATION2->setText(CONSOMATION_String);
}
void modifier::setREV_SPONSOR(int REV_SPONSOR){
QString REV_SPONSOR_String=QString::number(REV_SPONSOR);

   ui->REV_SPONSOR2->setText(REV_SPONSOR_String);
}
void modifier::setREV_ABON(int REV_ABON){
QString REV_ABON_String=QString::number(REV_ABON);

   ui->REV_ABON2->setText(REV_ABON_String);
}
void modifier::setDATE_REV(QDate){


   ui->DATE_REV2->setDate(DATE_REV);
}


void modifier::on_modifier2_clicked()
{
    int ID_REV=ui->ID_Rev4->text().toInt();
    int CONSOMATION=ui->CONSOMATION2->text().toInt();
    int REV_SPONSOR=ui->REV_SPONSOR2->text().toInt();
    int REV_ABON=ui->REV_ABON2->text().toInt();
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
