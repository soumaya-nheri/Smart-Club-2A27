#ifndef DIALOGTEST_H
#define DIALOGTEST_H

#include <QDialog>

namespace Ui {
class dialogtest;
}

class dialogtest : public QDialog
{
    Q_OBJECT

public:
    explicit dialogtest(QWidget *parent = nullptr);
    ~dialogtest();

private:
    Ui::dialogtest *ui;
};

#endif // DIALOGTEST_H
