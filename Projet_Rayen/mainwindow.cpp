#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QSqlQuery>
#include <QSqlError>
#include<QDebug>
#include<QMessageBox>
#include<QMediaPlayer>
#include<QSoundEffect>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    player->setMedia(QUrl("qrc:/images/music.mp3"));
    player->setVolume(100);
    player->play();
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::on_iden_clicked()
{
    QMediaPlayer *son;
        son=new QMediaPlayer();
        son->setMedia(QUrl("qrc:/images/click.mp3"));
        son->setVolume(50);
        son->play();

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
            comptabilite e;
            e.exec();
        }

        else if(ui->login->text().isEmpty() or ui->pass->text().isEmpty()){
            QMessageBox::critical(nullptr, QObject::tr("EMPTY!"),
                        QObject::tr("Champ Obligatoire.\n"), QMessageBox::Cancel);
        }
        else
        {
            QMessageBox::critical(nullptr, QObject::tr("Invalid Informations"),
                        QObject::tr("Please check login or password"), QMessageBox::Cancel);
         }
    }
}

void MainWindow::on_pushButton_clicked()
{
player->stop();
}


void MainWindow::on_pushButton_2_clicked()
{
    player->stop();
    player->setMedia(QUrl("qrc:/images/music.mp3"));
    player->setVolume(100);
    player->play();
}


