#ifndef DIALOG_MODIFICA_LETTURA_H
#define DIALOG_MODIFICA_LETTURA_H

#include <QDialog>
#include <QtSql>

namespace Ui {
class Dialog_modifica_lettura;
}

class Dialog_modifica_lettura : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog_modifica_lettura(int id=0,int num=0,QWidget *parent = 0);
    ~Dialog_modifica_lettura();

private:
    Ui::Dialog_modifica_lettura *ui;
    int _id;
    int _num;
private slots:
    void salva();
};

#endif // DIALOG_MODIFICA_LETTURA_H
