#ifndef DIALOG_NUOVO_FILM_INSERIMENTO_H
#define DIALOG_NUOVO_FILM_INSERIMENTO_H

#include <QDialog>
#include <QStringListModel>
#include <QStringList>
#include <QtSql>

namespace Ui {
class Dialog_nuovo_film_inserimento;
}

class Dialog_nuovo_film_inserimento : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog_nuovo_film_inserimento(QWidget *parent = 0);
    ~Dialog_nuovo_film_inserimento();

private:
    Ui::Dialog_nuovo_film_inserimento *ui;

public slots:
    void aggiorna(int pag);
    void aggiungi_regista();
    void aggiungi_genere();
    void reset_regista();
    void reset_genere();
    void salvatutto();
};

#endif // DIALOG_NUOVO_FILM_INSERIMENTO_H
