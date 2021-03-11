#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "equipements.h"
#include <QMessageBox>
#include "services.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QRegExp rx("[A-Za-z_ ]+");//[A-Za-z0-9_]
            QRegExp rx1("[0-9_]+");

            QValidator *validator = new QRegExpValidator(rx, this);

            ui->marque->setValidator(validator);
                ui->model->setValidator(validator);
                ui->prix->setValidator(validator);
                ui->etat->setValidator(validator);
                ui->disponibilite->setValidator(validator);
    ui->id_equipement->setValidator( new QIntValidator(0, 999999, this));
    ui->tab_equipements->setModel(Etmp.afficher());
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    int id_equipement=ui->id_equipement->text().toInt();
        QString marque=ui->marque->text();
         QString model=ui->model->text();
         QString prix=ui->prix->text();
         QString etat=ui->etat->text();
         QString disponibilite=ui->disponibilite->text();
        equipements e(id_equipement,marque,model,prix,etat,disponibilite);
        bool test=e.ajouter();

        QMessageBox msgbox;

        if(!test)
          return  msgbox.setText("Ajout avec succes");
        else
           return msgbox.setText("Echec d ajout");
        msgbox.exec();
}

void MainWindow::on_pushButton_3_clicked()
{
    equipements e1;
       e1.setid_equipement(ui->id_equipement_2->text().toInt());
       bool test=e1.supprimer(e1.getid_equipement());
       QMessageBox msgbox;
       if(!test)
          return msgbox.setText("Suppression avec succes");
       else
          return msgbox.setText("Echec de suppression");
       msgbox.exec();
}





void MainWindow::on_pushButton_2_clicked()
{
    ui->tab_equipements->setModel(Etmp.afficher());
}


void MainWindow::on_pushButton_4_clicked()
{
    int id_service=ui->id_service->text().toInt();
        QString nom_service=ui->nom_service->text();
         int nbre_materiel=ui->nbre_materiel->text().toInt();
         QString type=ui->type->text();

        services e(id_service,nom_service,nbre_materiel,type);
        bool test=e.ajouter();

        QMessageBox msgbox;

        if(!test)
          return  msgbox.setText("Ajout avec succes");
        else
           return msgbox.setText("Echec d ajout");
        msgbox.exec();
}

void MainWindow::on_pushButton_5_clicked()
{
    services e1;
       e1.setid_service(ui->id_service_2->text().toInt());
       bool test=e1.supprimer(e1.getid_service());
       QMessageBox msgbox;
       if(!test)
          return msgbox.setText("Suppression avec succes");
       else
          return msgbox.setText("Echec de suppression");
       msgbox.exec();
}

void MainWindow::on_pushButton_6_clicked()
{
    ui->tab_service->setModel(Etmp1.afficher());
}
