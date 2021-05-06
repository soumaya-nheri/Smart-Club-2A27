#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include<QMediaPlayer>
#include<QVideoWidget>

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = nullptr);
    ~Dialog();

private:
    Ui::Dialog *ui;
    QMediaPlayer* video = new QMediaPlayer;
    QVideoWidget* vw =new QVideoWidget;

};

#endif // DIALOG_H
