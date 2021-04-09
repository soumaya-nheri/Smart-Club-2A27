#include "dialogtest.h"
#include "ui_dialogtest.h"

dialogtest::dialogtest(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::dialogtest)
{
    ui->setupUi(this);
}

dialogtest::~dialogtest()
{
    delete ui;
}
