#include "modifiers.h"
#include "ui_modifiers.h"
#include"QMessageBox"
#include"services.h"

modifiers::modifiers(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::modifiers)
{
    ui->setupUi(this);
    ui->nbre_materiel2->setValidator( new QIntValidator(0, 9999, this));
    ui->nom_service2->setValidator(new QRegExpValidator( QRegExp("([A-Za-z_][A-Za-z]+)"), this ));
    ui->type2->setValidator(new QRegExpValidator( QRegExp("([A-Za-z_][A-Za-z]+)"), this ));
}

modifiers::~modifiers()
{
    delete ui;
}

void modifiers::setid_service(int id_service){
QString ID_String=QString::number(id_service);

   ui->id_service2->setText(ID_String);
}
void modifiers::setnbre_materiel(int nbre_materiel){
QString nbre_materiel_String=QString::number(nbre_materiel);

   ui->nbre_materiel2->setText(nbre_materiel_String);
}
void modifiers::setnom_service(QString nom_service){


   ui->nom_service2->setText(nom_service);
}
void modifiers::settype(QString type){


   ui->type2->setText(type);
}



void modifiers::on_modifierservices_clicked()
{
    int id_service=ui->id_service2->text().toInt();
    int nbre_materiel=ui->nbre_materiel2->text().toInt();
    QString nom_service=ui->nom_service2->text();
    QString type=ui->type2->text();


    services r(id_service,nom_service,nbre_materiel,type);
    bool test=r.modifier(id_service);
    QMessageBox msgbox;

    if(test)
       return msgbox.setText("Modification avec succes");
    else
       return msgbox.setText("Echec de modification");
    msgbox.exec();
}


