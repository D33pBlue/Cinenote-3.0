#ifndef CARTOLINA_H
#define CARTOLINA_H

#include <QWidget>
#include "etichettacliccabile.h"
#include <QtGui>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QTextBrowser>

class Cartolina : public EtichettaCliccabile
{
    Q_OBJECT
public:
    explicit Cartolina(int _id=-1,QString titolo=QString(""),int anno=0,QString voto=QString(""),QString regis=QString(""),QString gene=QString(""),QString desc=QString(""),QWidget *parent = 0,bool libro=0);
    ~Cartolina();
private:
    QHBoxLayout *lay;
    QVBoxLayout *dxlay;
    QLabel *tit;
    QLabel *reg;
    QLabel *ann;
    QLabel *vot;
    QLabel *ge;
    QWidget *dx;
    QLabel *pic;
    QTextBrowser *descri;
signals:

public slots:

};

#endif // CARTOLINA_H
