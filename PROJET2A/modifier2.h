#ifndef MODIFIER2_H
#define MODIFIER2_H

#include <QDialog>
#include<QDate>

namespace Ui {
class modifier2;
}

class modifier2 : public QDialog
{
    Q_OBJECT

public:
    explicit modifier2(QDialog *parent = nullptr);
    ~modifier2();
    void setID_DEP(int);
    void setACHAT(int);
    void setSALAIRE(int);
    void setSOMME(int);
    void setDATE_DEP(QDate);

private slots:


    void on_mod_dep2_clicked();

private:
    Ui::modifier2 *ui;
    int ID_DEP,ACHAT,SALAIRE,SOMME;
    QDate DATE_DEP;
};

#endif // MODIFIER2_H
