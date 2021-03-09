#include "mainwindow.h"
#include "ui_mainwindow.h"
#include"etudiant.h"
#include"QMessageBox"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QRegExp rx("[A-Za-z_ ]+");//[A-Za-z0-9_]
        QRegExp rx1("[0-9_]+");

        QValidator *validator = new QRegExpValidator(rx, this);
        QValidator *validator2 = new QRegExpValidator(rx1, this);
        ui->nom->setValidator(validator);
            ui->prenom->setValidator(validator);
ui->id->setValidator( new QIntValidator(0, 999999, this));
ui->tab_etudiant->setModel(Etmp.afficher());
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_ajouter_clicked()
{
    int id=ui->id->text().toInt();
    QString nom=ui->nom->text();
     QString prenom=ui->prenom->text();
    etudiant e(id,nom,prenom);
    bool test=e.ajouter();

    QMessageBox msgbox;

    if(!test)
        msgbox.setText("Ajout avec succes");
    else
        msgbox.setText("Echec d ajout");
    msgbox.exec();
}

void MainWindow::on_pushButton_clicked()
{
    etudiant e1;
   e1.setid(ui->id_2->text().toInt());
   bool test=e1.supprimer(e1.getid());
   QMessageBox msgbox;
   if(test)
       msgbox.setText("Suppression avec succes");
   else
       msgbox.setText("Echec de suppression");
   msgbox.exec();

}

void MainWindow::on_refresh_clicked()
{
ui->tab_etudiant->setModel(Etmp.afficher());
}
