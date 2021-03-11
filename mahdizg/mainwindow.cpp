#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "coach.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_Ajouter1_clicked()
{
        int ID_Coach=ui->ID_Coach->text().toInt();
        QString Nom=ui->Nom->text();
        QString Prenom=ui->Prenom->text();
        QString Specialite=ui->Specialite->text();
        QDate Date_Naiss =ui->Date_Naiss->date();
        coach r(ID_Coach,Nom,Prenom,Specialite,Date_Naiss);
        bool test=r.Ajouter1();
        QMessageBox msgbox;

            if(!test)
                 return msgbox.setText("Ajout avec succes");
            else
                return msgbox.setText("Echec d ajout");
            msgbox.exec();
}

void MainWindow::on_Supprimer1_clicked()
{
    coach re1;
       re1.setID_Coach(ui->ID_Coach_sup1->text().toInt());
       bool test=re1.Supprimer1(re1.getID_Coach());
       QMessageBox msgbox;

           if(!test)
                return msgbox.setText("Ajout avec succes");
           else
               return msgbox.setText("Echec d ajout");
           msgbox.exec();
}

void MainWindow::on_Afficher1_clicked()
{
    ui->tableView->setModel(re1.Afficher1());
}
