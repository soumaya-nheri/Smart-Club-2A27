#ifndef MODIFIERS_H
#define MODIFIERS_H

#include <QDialog>

namespace Ui {
class modifiers;
}

class modifiers : public QDialog
{
    Q_OBJECT

public:
    explicit modifiers(QWidget *parent = nullptr);
    ~modifiers();
    void setid_service(int);
    void setnom_service(QString);
    void setnbre_materiel(int);
    void settype(QString);

private slots:


        void on_modifierservices_clicked();



private:
    Ui::modifiers *ui;
    int id_service,nbre_materiel;
    QString nom_service,type;
};

#endif // MODIFIERS_H
