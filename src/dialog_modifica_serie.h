#ifndef DIALOG_MODIFICA_SERIE_H
#define DIALOG_MODIFICA_SERIE_H

#include <QDialog>
#include <QtSql>

namespace Ui {
class Dialog_modifica_serie;
}

class Dialog_modifica_serie : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog_modifica_serie(int id=0,QWidget *parent = 0);
    ~Dialog_modifica_serie();

private:
    Ui::Dialog_modifica_serie *ui;
    int _id;
private slots:
    void salva();
};

#endif // DIALOG_MODIFICA_SERIE_H
