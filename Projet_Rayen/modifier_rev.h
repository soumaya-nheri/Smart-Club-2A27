#ifndef MODIFIER_REV_H
#define MODIFIER_REV_H

#include <QDialog>
#include<QDate>
namespace Ui {
class modifier_rev;
}

class modifier_rev : public QDialog
{
    Q_OBJECT

public:
    explicit modifier_rev(QWidget *parent = nullptr);
    ~modifier_rev();
    void setID_REV(int);
    void setCONSOMATION(float);
    void setREV_SPONSOR(float);
    void setREV_ABON(float);
    void setDATE_REV(QDate);
private slots:
    void on_pushButton_clicked();

private:
    Ui::modifier_rev *ui;
    int ID_REV;
    float CONSOMATION,REV_SPONSOR,REV_ABON;
    QDate DATE_REV;
};

#endif // MODIFIER_REV_H
