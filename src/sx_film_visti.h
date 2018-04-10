#ifndef SX_FILM_VISTI_H
#define SX_FILM_VISTI_H

#include <QWidget>
#include <QtGui>
#include "cartolina.h"
#include <vector>
#include <QVBoxLayout>
#include <QScrollArea>
#include <QGridLayout>

using namespace std;

class sx_film_visti : public QWidget
{
    Q_OBJECT
public:
    explicit sx_film_visti(QWidget *parent = 0,bool attesi=0);
    ~sx_film_visti();
private:
    QVBoxLayout *lay;
    QLabel *l;
    QScrollArea *displayVisti;
    QWidget *bg;
    QGridLayout *griglia;
    vector<Cartolina*> elca;

signals:

public slots:

};

#endif // SX_FILM_VISTI_H
