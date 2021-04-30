#include "modifier_ab.h"
#include "ui_modifier_ab.h"
#include<QMessageBox>
modifier_ab::modifier_ab(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::modifier_ab)
{
    ui->setupUi(this);
}

modifier_ab::~modifier_ab()
{
    delete ui;
}
void modifier_ab::setID_AB(int ID_AB){
QString IDd_String=QString::number(ID_AB);

   ui->ID_ABMOD->setText(IDd_String);
}
void modifier_ab::setNOM(QString NOM){

   ui->NOM_MOD->setText(NOM);
}
void modifier_ab::setPRENOM(QString PRENOM){

   ui->PRENOM_MOD->setText(PRENOM);
}
void modifier_ab::setAGE(int AGE){
QString AGE_String=QString::number(AGE);

   ui->AGE_MOD->setText(AGE_String);
}

void modifier_ab::on_MOD_clicked()
{
    int ID_AB=ui->ID_ABMOD->text().toInt();
    QString NOM=ui->NOM_MOD->text();
    QString PRENOM=ui->PRENOM_MOD->text();
    int AGE=ui->AGE_MOD->text().toInt();
    abonnes a(ID_AB,NOM,PRENOM,AGE);
    bool test=a.modifier(ID_AB);
    QMessageBox msgbox;

    if(test)
        msgbox.setText("Modification avec succes");
    else
        msgbox.setText("Echec de modification");
    msgbox.exec();
}
