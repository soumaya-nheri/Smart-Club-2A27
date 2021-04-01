#ifndef MODIFIEREQ_H
#define MODIFIEREQ_H

#include <QDialog>


namespace Ui {
class modifier;
}

class modifier : public QDialog
{
    Q_OBJECT

public:
    explicit modifier(QDialog *equipements = nullptr);
    ~modifier();
    void setid_equipement(int);
    void setmarque(QString);
    void setmodel(QString);
    void setprix(QString);
    void setetat(QString);
    void setdisponibilite(QString);

private slots:
    void on_modifier2_clicked();

private:
    Ui::modifier *ui;
    int id_equipement;
    QString marque,model,prix,etat,disponibilite;
};

#endif // MODIFIER_H
