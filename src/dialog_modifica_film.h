#ifndef DIALOG_MODIFICA_FILM_H
#define DIALOG_MODIFICA_FILM_H

#include <QDialog>
#include <QtWidgets>
#include <QtSql>
#include <QCheckBox>
#include <QGridLayout>
#include <QLabel>
#include <QTextEdit>

namespace Ui {
class Dialog_modifica_film;
}

class Dialog_modifica_film : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog_modifica_film(int id=-1,QWidget *parent = 0);
    ~Dialog_modifica_film();

private:
    Ui::Dialog_modifica_film *ui;
    int _id;
    QGridLayout *lay;
    QLineEdit *tit;
    QLabel *ltit;
    QLineEdit *anno;
    QLabel *lanno;
    QLineEdit *voto;
    QLabel *lvoto;
    QLineEdit *consigli;
    QLabel *lconsigli;
    QTextEdit *descri;
    QLabel *ldescri;
    QCheckBox *dispo;
    QLabel *ldispo;
    QPushButton *annulla;
    QPushButton *salva;
public slots:
    void salva_modifiche();
};

#endif // DIALOG_MODIFICA_FILM_H
