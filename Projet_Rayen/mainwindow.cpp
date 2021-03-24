#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QSqlQuery>
#include <QSqlError>
#include<QDebug>
#include<QMessageBox>

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


void MainWindow::on_iden_clicked()
{

    QString login = ui->login->text();
    QString pass = ui->pass->text();

    QSqlQuery query;
    query.prepare("SELECT * from admin WHERE login ='" + login + "' AND pass ='" + pass + "'");
    if (query.exec())
    {

        if (query.next())
        {

            // You login a user here

            QString login = query.value(0).toString();
            qDebug() << login << "is logged in";
            comptabilite e;
            e.exec();
        }
        else if(ui->login->text().isEmpty() or ui->pass->text().isEmpty()){
            QMessageBox::critical(nullptr, QObject::tr("EMPTY!"),
                        QObject::tr("Champ Obligatoire.\n"), QMessageBox::Cancel);
        }
        else
        {
            qDebug() << "Login failed. Invalid username or password.";
        }
    }

}
