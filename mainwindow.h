#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include"etudiant.h"
#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_ajouter_clicked();

    void on_pushButton_clicked();

    void on_refresh_clicked();

private:
    Ui::MainWindow *ui;
    etudiant Etmp;
};

#endif // MAINWINDOW_H
