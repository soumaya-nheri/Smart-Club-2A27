#include "modifier.h"
#include "ui_modifier.h"
#include "equipements.h"
#include"QMessageBox"

modifier::modifier(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::modifier)
{
    ui->setupUi(this);

}

modifier::~modifier()
{
    delete ui;
}
void modifier::setid_equipement(int id_equipement){
QString ID_String=QString::number(id_equipement);

   ui->id_equipement2->setText(ID_String);
}
void modifier::setmarque(QString marque){


   ui->marque2->setText(marque);
}
void modifier::setmodel(QString model){


   ui->model2->setText(model);
}
void modifier::setprix(QString prix){


   ui->prix2->setText(prix);
}
void modifier::setetat(QString etat){


   ui->etat2->setText(etat);
}
void modifier::setdisponibilite(QString disponibilite){


   ui->disponibilite2->setText(disponibilite);
}





void modifier::on_modifier1_clicked()
{
    int id_equipement=ui->id_equipement2->text().toInt();
    QString marque=ui->marque2->text();
    QString model=ui->model2->text();
    QString prix=ui->prix2->text();
    QString etat=ui->etat2->text();
    QString disponibilite=ui->disponibilite2->text();
    equipements r(id_equipement,marque,model,prix,etat,disponibilite);
    bool test=r.modifier(id_equipement);
    QMessageBox msgbox;

    if(test)
       return msgbox.setText("Modification avec succes");
    else
       return msgbox.setText("Echec de modification");
    msgbox.exec();
}
