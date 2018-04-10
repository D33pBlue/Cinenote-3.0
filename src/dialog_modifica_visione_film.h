#ifndef DIALOG_MODIFICA_VISIONE_FILM_H
#define DIALOG_MODIFICA_VISIONE_FILM_H

#include <QDialog>
#include <QtWidgets>
#include <QtSql>
#include <QLabel>
#include <QTextEdit>
#include <QGridLayout>

namespace Ui {
class Dialog_modifica_visione_film;
}

class Dialog_modifica_visione_film : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog_modifica_visione_film(int id=-1,QString dat=QString(""),QWidget *parent = 0);
    ~Dialog_modifica_visione_film();

private:
    Ui::Dialog_modifica_visione_film *ui;
    QLabel *tit;
    int _id;
    QString _dat;
    QLabel *data;
    QLineEdit *dove;
    QLineEdit *voto;
    QTextEdit *note;
    QLineEdit *attore;
    QGridLayout* lay;
    QPushButton *vai;
    QPushButton *annulla;
    QLabel *_data;
    QLabel *_dove;
    QLabel *_voto;
    QLabel *_note;
    QLabel *_attore;
public slots:
    void salva();
};

#endif // DIALOG_MODIFICA_VISIONE_FILM_H
