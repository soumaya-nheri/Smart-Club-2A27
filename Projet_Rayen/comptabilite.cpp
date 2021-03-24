#include "comptabilite.h"
#include "ui_comptabilite.h"
#include"revenues.h"
#include<QMessageBox>
#include<modifier_rev.h>
#include<depenses.h>
#include<modifier_dep.h>
#include<QMediaPlayer>

comptabilite::comptabilite(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::comptabilite)
{
    ui->setupUi(this);
    ui->tab_rev->setModel(re.afficher());
 ui->tab_dep->setModel(de.afficher());
 auto dv = new QDoubleValidator(0.0, 5.0, 2);
 ui->CONSOMATION->setValidator(dv);
  ui->REV_ABON->setValidator(dv);
   ui->REV_SPONSOR->setValidator(dv);
   ui->ACHAT->setValidator(dv);
    ui->salaire->setValidator(dv);
    ui->event->setValidator(dv);
  ui->ID_DEP->setValidator( new QIntValidator(0, 9999, this));
  ui->ID_DEP2->setValidator( new QIntValidator(0, 9999, this));
  ui->ID_REV2->setValidator( new QIntValidator(0, 9999, this));
  ui->ID_REV->setValidator( new QIntValidator(0, 9999, this));
  High = 9999;
  Low = 0;

}

comptabilite::~comptabilite()
{
    delete ui;
}

void comptabilite::on_pushButton_2_clicked()
{
    int ID_REV=ui->ID_REV->text().toInt();
    float CONSOMATION=ui->CONSOMATION->text().toFloat();
    float REV_SPONSOR=ui->REV_SPONSOR->text().toFloat();
    float REV_ABON=ui->REV_ABON->text().toFloat();
    QDate DATE_REV =ui->DATE_REV->date();
    revenues r(ID_REV,CONSOMATION,REV_SPONSOR,REV_ABON,DATE_REV);
    QMessageBox msg;
    bool test=r.ajout_rev();


    if(test)
    {
        QMessageBox::critical(nullptr, QObject::tr("Statut d'ajout"),
                    QObject::tr("id deja exist.\n"), QMessageBox::Cancel);

}
    else if(ui->ID_REV->text().isEmpty()){

        QMessageBox::critical(nullptr, QObject::tr("EMPTY!"),
                    QObject::tr("ID Obligatoire.\n"), QMessageBox::Cancel);

    }
    else
        QMessageBox::information(nullptr, QObject::tr("Statut d'ajout"),
                    QObject::tr("Ajout avec succes.\n"), QMessageBox::Cancel);



}

void comptabilite::on_refresh_clicked()
{
    ui->tab_rev->setModel(re.afficher());
}


void comptabilite::on_pushButton_3_clicked()
{
    revenues re1;
    re1.setID_REV(ui->ID_REV2->text().toInt());
    bool test=re1.supprimer(re1.getID_REV());
    if(!test)
    {
        QMessageBox::critical(nullptr, QObject::tr("Statut de suppression"),
                    QObject::tr("Erreur de suppression.\n"), QMessageBox::Cancel);

}
    else if(ui->ID_REV2->text().isEmpty()){

        QMessageBox::critical(nullptr, QObject::tr("EMPTY!"),
                    QObject::tr("ID Obligatoire.\n"), QMessageBox::Cancel);

    }
    else
        QMessageBox::information(nullptr, QObject::tr("Statut de suppression"),
                    QObject::tr("suppression avec succes.\n"), QMessageBox::Cancel);

}

void comptabilite::on_pushButton_4_clicked()
{
    modifier_rev m;

   m.setID_REV(ui->ID_REV2->text().toInt());
   if(ui->ID_REV2->text().isEmpty())
       QMessageBox::critical(nullptr, QObject::tr("EMPTY!"),
                   QObject::tr("ID Obligatoire.\n"), QMessageBox::Cancel);

    else
    m.exec();
}

void comptabilite::on_pushButton_clicked()
{
    int ID_DEP=ui->ID_DEP->text().toInt();
    float ACHAT=ui->ACHAT->text().toFloat();
    float SALAIRE=ui->salaire->text().toFloat();
    float EVENT=ui->event->text().toFloat();
    QDate DATE_DEP =ui->date_dep->date();
    depenses d(ID_DEP,ACHAT,SALAIRE,EVENT,DATE_DEP);
  bool test=d.ajout_dep();
  if(test)
  {
      QMessageBox::critical(nullptr, QObject::tr("Statut d'ajout"),
                  QObject::tr("Erreur d'ajout.\n"), QMessageBox::Cancel);

}
  else if(ui->ID_DEP->text().isEmpty()){

      QMessageBox::critical(nullptr, QObject::tr("EMPTY!"),
                  QObject::tr("ID Obligatoire.\n"), QMessageBox::Cancel);

  }

  else
      QMessageBox::information(nullptr, QObject::tr("Statut d'ajout"),
                  QObject::tr("Ajout avec succes.\n"), QMessageBox::Cancel);





}

void comptabilite::on_refresh_dep_clicked()
{
    ui->tab_dep->setModel(de.afficher());
}

void comptabilite::on_supp_dep_clicked()
{
    depenses de1;
   de1.setID_DEP(ui->ID_DEP2->text().toInt());
   bool test=de1.supprimer(de1.getID_DEP());
   if(!test)
   {
       QMessageBox::critical(nullptr, QObject::tr("Statut de suppression"),
                   QObject::tr("Erreur de suppression.\n"), QMessageBox::Cancel);

}
   else if(ui->ID_DEP2->text().isEmpty()){

       QMessageBox::critical(nullptr, QObject::tr("EMPTY!"),
                   QObject::tr("ID Obligatoire.\n"), QMessageBox::Cancel);

   }
   else
       QMessageBox::information(nullptr, QObject::tr("Statut de suppression"),
                   QObject::tr("suppression avec succes.\n"), QMessageBox::Cancel);
}

void comptabilite::on_mod_dep_clicked()
{
    modifier_dep dm;
    QMessageBox msg;
   dm.setID_DEP(ui->ID_DEP2->text().toInt());
   if(ui->ID_DEP2->text().isEmpty())
       QMessageBox::critical(nullptr, QObject::tr("EMPTY!"),
                   QObject::tr("ID Obligatoire.\n"), QMessageBox::Cancel);

    else
    dm.exec();
}



void comptabilite::on_pushButton_5_clicked()
{
    qsrand(qrand());
    ui->ID_DEP->setText(QString::number(qrand() % ((High + 1) - Low) + Low));
}

void comptabilite::on_pushButton_6_clicked()
{ qsrand(qrand());
            ui->ID_REV->setText(QString::number(qrand() % ((High + 1) - Low) + Low));
            bool alreadyExist = false;
            {

               int ID_REV=ui->ID_REV->text().toInt();
            QSqlQuery query; QString ID_String=QString::number(ID_REV);
            query.prepare("select ID_REV from revenues where ID_REV=:ID_REV");
            query.bindValue(":ID_REV",ID_REV);
            if(!query.exec()){
            // select failed
            }
            alreadyExist = query.next();
            }
            if(alreadyExist){
            // update
                qDebug()<<"already exist" ;
            }
            else{
            //insert
                qDebug()<<"n'existe pas";
            }
}
