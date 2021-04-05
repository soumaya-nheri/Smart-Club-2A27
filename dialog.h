#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include "equipements.h"
#include "services.h"
#include "QMediaPlayer"
#include "QPropertyAnimation"
namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = nullptr);
    ~Dialog();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_3_clicked();








        void on_pushButton_4_clicked();

        void on_pushButton_5_clicked();

        void on_pushButton_6_clicked();

        void on_modifiereq_clicked();

        void on_modifierse_2_clicked();

        void on_pushButton_2_clicked();





        void on_pushButton_7_clicked();



        void on_pushButton_9_clicked();

        void on_pushButton_8_clicked();

        void on_pushButton_10_clicked();

        void on_pushButton_11_clicked();

        void on_pushButton_12_clicked();

private:
    Ui::Dialog *ui;
    equipements Etmp;
    services Etmp1;
    QMediaPlayer *player = new QMediaPlayer;
    QPropertyAnimation * Animation;
};

#endif // DIALOG_H
