#ifndef DIALOG_NUOVO_LIBRO_H
#define DIALOG_NUOVO_LIBRO_H

#include <QDialog>
#include <QtSql>

namespace Ui {
class Dialog_nuovo_libro;
}

class Dialog_nuovo_libro : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog_nuovo_libro(QWidget *parent = 0);
    ~Dialog_nuovo_libro();

private:
    Ui::Dialog_nuovo_libro *ui;
private slots:
    void salva();
};

#endif // DIALOG_NUOVO_LIBRO_H
