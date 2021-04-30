#ifndef MODIFIER_ABT_H
#define MODIFIER_ABT_H

#include <QDialog>
#include<abonnement.h>
namespace Ui {
class modifier_abt;
}

class modifier_abt : public QDialog
{
    Q_OBJECT

public:
    explicit modifier_abt(QWidget *parent = nullptr);
    ~modifier_abt();
    void setID_ABT(int);
    void setDATE_INS( QDate);
    void setTYPE( QString);


private slots:
    void on_MOD_clicked();



private:
    Ui::modifier_abt *ui;
    QString TYPE;
    int ID_ABT;
    QDate DATE_INS;
};

#endif // MODIFIER_ABT_H
