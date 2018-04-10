#ifndef METTI_IN_CLASSIFICA_H
#define METTI_IN_CLASSIFICA_H

#include <QDialog>
#include <QtSql>

namespace Ui {
class Metti_in_classifica;
}

class Metti_in_classifica : public QDialog
{
    Q_OBJECT

public:
    explicit Metti_in_classifica(int id=-1,QWidget *parent = 0);
    ~Metti_in_classifica();

private:
    Ui::Metti_in_classifica *ui;
    int _id;
public slots:
    void salvaclass();
};

#endif // METTI_IN_CLASSIFICA_H
