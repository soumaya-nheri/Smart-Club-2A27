#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "coach.h"
#include "modifiercoach.h"
#include <QMessageBox>
#include "programs.h"
#include "modifierprogrammes.h"
#include "coachprogram.h"
#include"QDebug"
#include"QObject"
#include<QDate>
#include<QString>

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

void MainWindow::on_pushButton_clicked()
{
    CoachProgram e;
    e.exec();
}
