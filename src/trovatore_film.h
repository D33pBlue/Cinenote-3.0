#ifndef TROVATORE_FILM_H
#define TROVATORE_FILM_H

#include <QDialog>
#include <QtGui>
#include "tipi_usati.h"
#include <QLineEdit>
#include <QLabel>

class trovatore_film : public QDialog
{
    Q_OBJECT
public:
    explicit trovatore_film(datitrovatore cosa=cercafilm,QWidget *parent = 0);
    ~trovatore_film();
private:
    QWidget *padre;
    void settaLayout(datitrovatore tipo);
    QPushButton *ok;
    QPushButton *annulla;
    QLineEdit *cer;
    QLabel *tit;
    void cancella();
signals:

public slots:
    void cerca_Film();
    void cerca_Regista();
    void cerca_Genere();
    void cerca_serie();
    void cerca_Libro();
    void cerca_Autore();

};

#endif // TROVATORE_FILM_H
