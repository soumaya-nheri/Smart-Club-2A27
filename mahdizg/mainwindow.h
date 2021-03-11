#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <coach.h>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_Ajouter1_clicked();

    void on_Supprimer1_clicked();

    void on_Afficher1_clicked();

private:
    Ui::MainWindow *ui;
    coach re1;
};
#endif // MAINWINDOW_H
