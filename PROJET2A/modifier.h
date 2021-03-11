#ifndef MODIFIER_H
#define MODIFIER_H

#include <QDialog>
#include<QDate>

namespace Ui {
class modifier;
}

class modifier : public QDialog
{
    Q_OBJECT

public:
    explicit modifier(QDialog *parent = nullptr);
    ~modifier();
    void setID_REV(int);
    void setCONSOMATION(int);
    void setREV_SPONSOR(int);
    void setREV_ABON(int);
    void setDATE_REV(QDate);

private slots:
    void on_modifier2_clicked();

private:
    Ui::modifier *ui;
    int ID_REV,CONSOMATION,REV_SPONSOR,REV_ABON;
    QDate DATE_REV;
};

#endif // MODIFIER_H
