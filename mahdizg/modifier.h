#ifndef MODIFIER_H
#define MODIFIER_H

#include <QDialog>
#include<QDate>

namespace Ui {
class modifier;
}

class modifier :public QDialog
{
    Q_OBJECT
 public:
    explicit modifier(QDialog *parent = nullptr);
    ~modifier();
    void setID_COACH(int);
    void setNOM(QString);
    void setPRENOM(QString);
    void setSPECIALITE(QString);
    void setDATE_NAISS(QDate);

private slots:
    void on_modifier2_clicked();

private:
    Ui::modifier *ui;
    int ID_COACH;
    QString NOM,PRENOM,SPECIALITE;
    QDate DATE_NAISS;

};

#endif // MODIFIER_H
