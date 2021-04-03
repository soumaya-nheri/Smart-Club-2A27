#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "equipements.h"
#include <QMessageBox>
#include "services.h"
#include "modifier.h"
#include "modifiers.h"
#include "dialog.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
   /* QRegExp rx("[A-Za-z_ ]+");//[A-Za-z0-9_]
            QRegExp rx1("[0-9_]+");

            QValidator *validator = new QRegExpValidator(rx, this);

            ui->marque->setValidator(validator);
                ui->model->setValidator(validator);
                ui->prix->setValidator(validator);
                ui->etat->setValidator(validator);
                ui->disponibilite->setValidator(validator);
    ui->id_equipement->setValidator( new QIntValidator(0, 999999, this));
    ui->tab_equipements->setModel(Etmp.afficher()); */
}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_pushButton_2_clicked()
{
    Dialog d;
    d.exec();
}
