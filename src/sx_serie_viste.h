#ifndef SX_SERIE_VISTE_H
#define SX_SERIE_VISTE_H

#include <QWidget>
#include <QtGui>
#include <QVBoxLayout>
#include <QLabel>
#include <QScrollArea>
#include <QGridLayout>
#include "form_serie_viste.h"
#include <vector>
using namespace std;

class sx_serie_viste : public QWidget
{
    Q_OBJECT
public:
    explicit sx_serie_viste(bool attesi=0,QWidget *parent = 0);
    ~sx_serie_viste();
private:
    QVBoxLayout *lay;
    QLabel *l;
    QScrollArea *displayVisti;
    QWidget *bg;
    QGridLayout *griglia;
    vector<Form_serie_viste*> elca;
signals:

public slots:

};

#endif // SX_SERIE_VISTE_H
