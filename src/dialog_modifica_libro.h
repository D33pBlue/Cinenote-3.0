#ifndef DIALOG_MODIFICA_LIBRO_H
#define DIALOG_MODIFICA_LIBRO_H

#include <QDialog>
#include <QtSql>

namespace Ui {
class Dialog_modifica_libro;
}

class Dialog_modifica_libro : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog_modifica_libro(int id=0,QWidget *parent = 0);
    ~Dialog_modifica_libro();

private:
    Ui::Dialog_modifica_libro *ui;
    int _id;
private slots:
    void salva();
};

#endif // DIALOG_MODIFICA_LIBRO_H
