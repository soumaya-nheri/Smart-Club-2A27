#ifndef CALCULATRICE_H
#define CALCULATRICE_H

#include <QDialog>

namespace Ui {
class calculatrice;
}

class calculatrice : public QDialog
{
    Q_OBJECT

public:
    explicit calculatrice(QWidget *parent = nullptr);
    ~calculatrice();

private:
    Ui::calculatrice *ui;
    void NumPressed();

};

#endif // CALCULATRICE_H
