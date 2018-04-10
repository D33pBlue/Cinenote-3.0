#ifndef SX_LIBRO_HOME_H
#define SX_LIBRO_HOME_H

#include <QWidget>
#include <QtGui>
#include <QVector>
#include <QVBoxLayout>
#include <QScrollArea>
#include "etichettacliccabile.h"

class sx_libro_home : public QWidget
{
    Q_OBJECT
public:
    explicit sx_libro_home(QWidget *parent = 0);
    ~sx_libro_home();
protected:
    QLabel *t;
    QVBoxLayout *lay;
    QScrollArea *disp;
    QScrollArea *atte;
    QLabel *des2;
    QVector<EtichettaCliccabile*> vettore_dispo;
    QWidget *bg_dispo;
    QVector<EtichettaCliccabile*> vettore_atte;
    QWidget *bg_atte;
signals:

public slots:

};

#endif // SX_LIBRO_HOME_H
