#include "modifiereq.h"
#include "ui_modifiereq.h"
#include "equipements.h"
#include"QMessageBox"




modifier::modifier(QDialog *equipements) :
    QDialog(equipements),
    ui(new Ui::modifier)
{
    ui->setupUi(this);
    QValidator *validator = new QIntValidator(0, 99999999, this);
    ui->id_equipement2->setValidator(validator);
    ui->marque2->setValidator(validator);
    ui->model2->setValidator(validator);
    ui->prix2->setValidator(validator);
    ui->etat2->setValidator(validator);
    ui->disponibilite2->setValidator(validator);
}

modifier::~modifier()
{
    delete ui;
}
void modifier::setid_equipement(int id_equipement){
QString ID_String=QString::number(marque);

   ui->id_equipement4->setText(ID_String);
}
void modifier::setmarque(int marque){
QString marque_String=QString::number(marque);

   ui->marque2->setText(marque_String);
}
void modifier::setmodel(int model){
QString model_String=QString::number(model);

   ui->model2->setText(model_String);
}
void modifier::setprix(int prix){
QString prix_String=QString::number(prix);

   ui->prix2->setText(prix_String);
}
void modifier::setetat(int etat){
QString etat_String=QString::number(etat);

   ui->etat2->setText(etat_String);
}
void modifier::setdisponibilite(int disponibilite){
QString disponibilite_String=QString::number(disponibilite);

   ui->disponibilite2->setText(disponibilite_String);
}



void modifier::on_modifier2_clicked()
{
    int id_equipement=ui->id_equipement4->text().toInt();
    QString marque=ui->marque2->text();
    QString model=ui->model2->text();
    QString prix=ui->prix2->text();
    QString etat=ui->etat2->text();
    QString disponibilite =ui->disponibilite2;
    equipements r(id_equipement,marque,prix,etat,disponibilite);
    bool test=r.modifier(id_equipement);
    QMessageBox msgbox;

    if(test)
       return msgbox.setText("Modification avec succes");
    else
       return msgbox.setText("Echec de modification");
    msgbox.exec();

}
