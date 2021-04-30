#include "modifiereq.h"
#include "ui_modifiereq.h"
#include "equipements.h"
#include"QMessageBox"

modifiereq::modifiereq(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::modifiereq)
{
    ui->setupUi(this);

}

modifiereq::~modifiereq()
{
    delete ui;
}
void modifiereq::setid_equipement(int id_equipement){
QString ID_String=QString::number(id_equipement);

   ui->id_equipement2->setText(ID_String);
}
void modifiereq::setmarque(QString marque){


   ui->marque2->setText(marque);
}
void modifiereq::setmodel(QString model){


   ui->model2->setText(model);
}
void modifiereq::setprix(QString prix){


   ui->prix2->setText(prix);
}
void modifiereq::setetat(QString etat){


   ui->etat2->setText(etat);
}
void modifiereq::setdisponibilite(QString disponibilite){


   ui->disponibilite2->setText(disponibilite);
}





void modifiereq::on_modifier1_clicked()
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
