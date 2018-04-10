#ifndef DIALOG_LETTO_LIBRO_H
#define DIALOG_LETTO_LIBRO_H

#include <QDialog>
#include <QtSql>

namespace Ui {
class Dialog_letto_libro;
}

class Dialog_letto_libro : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog_letto_libro(int id=0,QWidget *parent = 0);
    ~Dialog_letto_libro();

private:
    Ui::Dialog_letto_libro *ui;
    int _id;
private slots:
    void salva();
};

#endif // DIALOG_LETTO_LIBRO_H
