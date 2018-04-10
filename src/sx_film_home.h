#ifndef SX_FILM_HOME_H
#define SX_FILM_HOME_H

#include <QWidget>
#include <QtGui>
#include <QVector>
#include "etichettacliccabile.h"
#include <QScrollArea>
#include <QVBoxLayout>

class sx_film_home : public QWidget
{
    Q_OBJECT
public:
    explicit sx_film_home(QWidget *parent = 0);
    ~sx_film_home();
protected:
    QLabel *t;
    QScrollArea *disp;
    QScrollArea *atte;
    QLabel *des2;
    QVBoxLayout *lay;
    QVector<EtichettaCliccabile*> vettore_dispo;
    QWidget *bg_dispo;
    QVector<EtichettaCliccabile*> vettore_atte;
    QWidget *bg_atte;

signals:

public slots:

};

#endif // SX_FILM_HOME_H
