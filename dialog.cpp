#include "dialog.h"
#include "ui_dialog.h"
#include<QMessageBox>
#include<QTableView>
#include<QSqlRecord>
#include<abonnes.h>
#include"modifier_ab.h"
#include"modifier_abt.h"
#include<QDate>
#include<QDebug>
Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
 ui->tableab->setModel(ab.afficher());
 ui->tableabt->setModel(abt.afficher());
 ui->comboBoxab->clear();
     QSqlQuery qry;
         qry.prepare("SELECT ID_AB FROM ABONNES");
         qry.exec();
         qry.first();
         int groupID_AB = qry.record().indexOf("ID_AB");
          ui->comboBoxab->addItem(qry.value(0).toString());
         while (qry.next()) {
               ui->comboBoxab->addItem(qry.value(groupID_AB).toString());
}
}
Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_Ajouter_clicked()
{
    int ID_AB=ui->ID_AB->text().toInt();
     QString NOM=ui->NOM->text();
     QString PRENOM=ui->PRENOM->text();
     int AGE=ui->AGE->text().toInt();
     abonnes ab(ID_AB,NOM,PRENOM,AGE);
     QMessageBox msg;
     bool test=ab.ajout_ab();



     if(test)
     {
         QMessageBox::critical(nullptr, QObject::tr("Statut d'ajout"),
                     QObject::tr("id deja exist.\n"), QMessageBox::Cancel);

 }
     else if(ui->ID_AB->text().isEmpty()){

         QMessageBox::critical(nullptr, QObject::tr("EMPTY!"),
                     QObject::tr("ID Obligatoire.\n"), QMessageBox::Cancel);

     }
     else
        { QMessageBox::information(nullptr, QObject::tr("Statut d'ajout"),
                     QObject::tr("Ajout avec succes.\n"), QMessageBox::Cancel);}

     ui->tableab->setModel(ab.afficher());
     ui->comboBoxab->clear();
         QSqlQuery qry;
             qry.prepare("SELECT ID_AB FROM ABONNES");
             qry.exec();
             qry.first();
             int groupID_AB = qry.record().indexOf("ID_AB");
              ui->comboBoxab->addItem(qry.value(0).toString());
             while (qry.next()) {
                   ui->comboBoxab->addItem(qry.value(groupID_AB).toString());


}}

void Dialog::on_Supprimer_clicked()
{
    ui->comboBoxab->clear();
        QSqlQuery qry;
            qry.prepare("SELECT ID_AB FROM ABONNES");
            qry.exec();
            qry.first();
            int groupID_AB = qry.record().indexOf("ID_AB");
             ui->comboBoxab->addItem(qry.value(0).toString());
            while (qry.next()) {
                  ui->comboBoxab->addItem(qry.value(groupID_AB).toString());


}
    abonnes ab1;
       ab1.setID_AB(ui->comboBoxab->currentText().toInt());
       bool test=ab1.supprimer(ab1.getID_AB());
       if(!test)
       {
           QMessageBox::critical(nullptr, QObject::tr("Statut de suppression"),
                       QObject::tr("Erreur de suppression.\n"), QMessageBox::Cancel);

   }
       else if(ui->comboBoxab->currentText().isEmpty()){

           QMessageBox::critical(nullptr, QObject::tr("EMPTY!"),
                       QObject::tr("ID Obligatoire.\n"), QMessageBox::Cancel);

       }
       else
           QMessageBox::information(nullptr, QObject::tr("Statut de suppression"),
                       QObject::tr("suppression avec succes.\n"), QMessageBox::Cancel);


}

void Dialog::on_pushButton_clicked()
{
      ui->tableab->setModel(ab.afficher());
      ui->comboBoxab->clear();
          QSqlQuery qry;
              qry.prepare("SELECT ID_AB FROM ABONNES");
              qry.exec();
              qry.first();
              int groupID_AB = qry.record().indexOf("ID_AB");
               ui->comboBoxab->addItem(qry.value(0).toString());
              while (qry.next()) {
                    ui->comboBoxab->addItem(qry.value(groupID_AB).toString());


  }
}

void Dialog::on_Modifier_clicked()
{
    modifier_ab a;

      a.setID_AB(ui->comboBoxab->currentText().toInt());
      QSqlQuery qry;
      int ID_AB=ui->comboBoxab->currentText().toInt();
        QString ID_AB_STRING= QString::number(ID_AB);
        qry.prepare("SELECT * from ABONNES where ID_AB='"+ID_AB_STRING+"'");
         if (qry.exec())
            {
             while (qry.next()) {
                QString nom=qry.value(1).toString();
              a.setNOM(nom);
              QString prenom=qry.value(2).toString();
            a.setPRENOM(prenom);
              int age=qry.value(3).toString().toInt();
              QString age_STRING= QString::number(age);
            a.setAGE(age);
              a.exec();
   }
   }
}

void Dialog::on_Ajouter_2_clicked()
{
    int ID_ABT=ui->ID_ABT->text().toInt();
     QDate DATE_INS=ui->dateEdit->date();
     qDebug()<<DATE_INS;
     QString TYPE=ui->TYPE->text();
     qDebug()<<TYPE+"dialog";
     qDebug()<<DATE_INS;
     qDebug()<<ID_ABT;

     abonnement abt(ID_ABT,DATE_INS,TYPE);
     QMessageBox msg;
     bool test=abt.ajout_abt();



     if(test)
     {
         QMessageBox::critical(nullptr, QObject::tr("Statut d'ajout"),
                     QObject::tr("id deja exist.\n"), QMessageBox::Cancel);

 }
     else if(ui->ID_ABT->text().isEmpty()){

         QMessageBox::critical(nullptr, QObject::tr("EMPTY!"),
                     QObject::tr("ID Obligatoire.\n"), QMessageBox::Cancel);

     }
     else
        { QMessageBox::information(nullptr, QObject::tr("Statut d'ajout"),
                     QObject::tr("Ajout avec succes.\n"), QMessageBox::Cancel);}

     ui->tableabt->setModel(abt.afficher());
     ui->comboBoxabt->clear();
         QSqlQuery qry;
             qry.prepare("SELECT ID_ABT FROM ABONNEMENT");
             qry.exec();
             qry.first();
             int groupID_ABT = qry.record().indexOf("ID_ABT");
              ui->comboBoxabt->addItem(qry.value(0).toString());
             while (qry.next()) {
                   ui->comboBoxabt->addItem(qry.value(groupID_ABT).toString());


}}


void Dialog::on_Modifier_2_clicked()
{
    modifier_abt a;

      a.setID_ABT(ui->comboBoxabt->currentText().toInt());
      QSqlQuery qry;
      int ID_ABT=ui->comboBoxabt->currentText().toInt();
        QString ID_ABT_STRING= QString::number(ID_ABT);
        qry.prepare("SELECT * from ABONNEMENT where ID_ABT='"+ID_ABT_STRING+"'");
         if (qry.exec())
            {
             while (qry.next()) {

              QDate DATE_INS=qry.value(1).toDate();
            a.setDATE_INS(DATE_INS);
            QString TYPE=qry.value(2).toString();
          a.setTYPE(TYPE);

              a.exec();
             }}

}

void Dialog::on_Supprimer_2_clicked()
{
    ui->comboBoxabt->clear();
        QSqlQuery qry;
            qry.prepare("SELECT ID_ABT FROM ABONNEMENT");
            qry.exec();
            qry.first();
            int groupID_ABT = qry.record().indexOf("ID_ABT");
             ui->comboBoxabt->addItem(qry.value(0).toString());
            while (qry.next()) {
                  ui->comboBoxabt->addItem(qry.value(groupID_ABT).toString());


}
    abonnement ab1;
       ab1.setID_ABT(ui->comboBoxabt->currentText().toInt());
       bool test=ab1.supprimer(ab1.getID_ABT());
       if(test)
       {
           QMessageBox::information(nullptr, QObject::tr("Statut de suppression"),
                       QObject::tr("suppression avec succes.\n"), QMessageBox::Cancel);

   }
       else if(ui->comboBoxabt->currentText().isEmpty()){

           QMessageBox::critical(nullptr, QObject::tr("EMPTY!"),
                       QObject::tr("ID Obligatoire.\n"), QMessageBox::Cancel);

       }
       else
           QMessageBox::critical(nullptr, QObject::tr("Statut de suppression"),
                       QObject::tr("Erreur de suppression.\n"), QMessageBox::Cancel);

}

void Dialog::on_pushButton_2_clicked()
{
   ui->tableabt->setModel(abt.afficher());
   ui->comboBoxabt->clear();
       QSqlQuery qry;
           qry.prepare("SELECT ID_ABT FROM ABONNEMENT");
           qry.exec();
           qry.first();
           int groupID_ABT = qry.record().indexOf("ID_ABT");
            ui->comboBoxabt->addItem(qry.value(0).toString());
           while (qry.next()) {
                 ui->comboBoxabt->addItem(qry.value(groupID_ABT).toString());
}
}
