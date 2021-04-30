#ifndef MODIFIER_DEP_H
#define MODIFIER_DEP_H

#include <QDialog>
#include<QDate>
#include<depenses.h>
#include<comptabilite.h>
namespace Ui {
class modifier_dep;
}

class modifier_dep : public QDialog
{
    Q_OBJECT

public:
    explicit modifier_dep(QWidget *parent = nullptr);
    ~modifier_dep();
    void setID_DEP(int);
    void setACHAT(float);
    void setSALAIRE(float);
    void setEVENT(float);
    void setDATE_DEP(QDate);

private slots:
    void on_mod_dep_clicked();


private:
    Ui::modifier_dep *ui;
    int ID_DEP;
    float ACHAT,SALAIRE,EVENT;
    QDate DATE_DEP;


};

#endif // MODIFIER_DEP_H
