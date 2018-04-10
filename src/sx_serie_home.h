#ifndef SX_SERIE_HOME_H
#define SX_SERIE_HOME_H

#include <QWidget>
#include <QtGui>
#include <QVector>
#include <QVBoxLayout>
#include <QScrollArea>
#include "etichettacliccabile.h"

class sx_serie_home : public QWidget
{
    Q_OBJECT
public:
    explicit sx_serie_home(QWidget *parent = 0);
    ~sx_serie_home();
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

#endif // SX_SERIE_HOME_H
