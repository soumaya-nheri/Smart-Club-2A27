#include "mainwindow.h"
#include "ui_mainwindow.h"

#include"revenues.h"
#include"modifier.h"
#include"QMessageBox"
#include"depenses.h"
#include"modifier2.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QValidator *validator = new QIntValidator(0, 99999999, this);
    ui->ID_REV->setValidator( new QIntValidator(0, 9999, this));
    ui->ID_REV2->setValidator( new QIntValidator(0, 9999, this));
    ui->tab_rev->setModel(re.afficher());
    ui->ID_REV3->setValidator( new QIntValidator(0, 9999, this));
    ui->ID_DEP->setValidator( new QIntValidator(0, 9999, this));
    ui->ID_DEP2->setValidator( new QIntValidator(0, 9999, this));
    ui->ID_DEP3->setValidator( new QIntValidator(0, 9999, this));
    ui->tab_dep->setModel(de.afficher());
    ui->ACHAT->setValidator(validator);
    ui->SALAIRE->setValidator(validator);
    ui->SOMME->setValidator(validator);


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_ajout_rev_clicked()
{
    int ID_REV=ui->ID_REV->text().toInt();
    int CONSOMATION=ui->CONSOMATION->text().toInt();
    int REV_SPONSOR=ui->REV_SPONSOR->text().toInt();
    int REV_ABON=ui->REV_ABON->text().toInt();
    QDate DATE_REV =ui->DATE_REV->date();
    revenues r(ID_REV,CONSOMATION,REV_SPONSOR,REV_ABON,DATE_REV);
    bool test=r.ajout_rev();
    QMessageBox msgbox;

     if(test)
       return msgbox.setText("Ajout avec succes");
    else
       return msgbox.setText("Echec d ajout");
    msgbox.exec();

}


void MainWindow::on_ref_rev_clicked()
{
    ui->tab_rev->setModel(re.afficher());
}

void MainWindow::on_supp_rev_clicked()
{
    revenues re1;
   re1.setID_REV(ui->ID_REV2->text().toInt());
   bool test=re1.supprimer(re1.getID_REV());
   QMessageBox msgbox;
   if(test)
     return  msgbox.setText("Suppression avec succes");
   else
      return msgbox.setText("Echec de suppression");
   msgbox.exec();
}



void MainWindow::on_modifier_clicked()
{
    modifier m;
    QMessageBox msg;
   m.setID_REV(ui->ID_REV3->text().toInt());
   if(ui->ID_REV3->text().isEmpty())
      msg.setText("empty");

    else
    m.exec();

}

void MainWindow::on_ajout_dep_clicked()
{
    int ID_DEP=ui->ID_DEP->text().toInt();
    int ACHAT=ui->ACHAT->text().toInt();
    int SALAIRE=ui->SALAIRE->text().toInt();
    int SOMME=ui->SOMME->text().toInt();
    QDate DATE_REV =ui->DATE_REV->date();
    depenses d(ID_DEP,ACHAT,SALAIRE,SOMME,DATE_REV);
  bool test=d.ajout_dep();
    QMessageBox msgbox;

    if(!test)
         return msgbox.setText("Ajout avec succes");
    else
        return msgbox.setText("Echec d ajout");
    msgbox.exec();
}

void MainWindow::on_ref_dep_clicked()
{
    ui->tab_dep->setModel(de.afficher());
}

void MainWindow::on_mod_dep_clicked()
{
    modifier2 dm;
    QMessageBox msg;
   dm.setID_DEP(ui->ID_DEP3->text().toInt());
   if(ui->ID_DEP3->text().isEmpty())
         msg.setText("empty");

    else
    dm.exec();
}

void MainWindow::on_supp_dep_clicked()
{
    depenses de1;
   de1.setID_DEP(ui->ID_DEP2->text().toInt());
   bool test=de1.supprimer(de1.getID_DEP());
   QMessageBox msgbox;
   if(test)
      return msgbox.setText("Suppression avec succes");
   else
       return msgbox.setText("Echec de suppression");
   msgbox.exec();
}
