#ifndef MODIFIER_AB_H
#define MODIFIER_AB_H

#include <QDialog>
#include<dialog.h>
#include<abonnes.h>

namespace Ui {
class modifier_ab;
}

class modifier_ab : public QDialog
{
    Q_OBJECT

public:
    explicit modifier_ab(QWidget *parent = nullptr);
    ~modifier_ab();
    void setID_AB(int);
    void setNOM( QString);
    void setPRENOM( QString);
    void setAGE(int);

private slots:
    void on_MOD_clicked();

private:
    Ui::modifier_ab *ui;
    QString NOM,PRENOM;
    int ID_AB,AGE;
};

#endif // MODIFIER_AB_H
