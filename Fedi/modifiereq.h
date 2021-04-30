#ifndef MODIFIEREQ_H
#define MODIFIEREQ_H

#include <QDialog>

#include <QDialog>

namespace Ui {
class modifiereq;
}

class modifiereq : public QDialog
{
    Q_OBJECT

public:
    explicit modifiereq(QWidget *parent = nullptr);
    ~modifiereq();
    void setid_equipement(int);
        void setmarque(QString);
        void setmodel(QString);
        void setprix(QString);
        void setetat(QString);
        void setdisponibilite(QString);

private slots:
        void on_modifier1_clicked();

private:
    Ui::modifiereq *ui;
    int id_equipement;
        QString marque,model,prix,etat,disponibilite;
};

#endif // MODIFIEREQ_H
