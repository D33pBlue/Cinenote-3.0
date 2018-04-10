#ifndef SX_LIBRO_LETTI_H
#define SX_LIBRO_LETTI_H

#include <QWidget>
#include <QtWidgets>
#include "cartolina.h"
#include <vector>
using namespace std;

class sx_libro_letti : public QWidget
{
    Q_OBJECT
public:
    explicit sx_libro_letti(QWidget *parent = 0,bool attesi=0);
    ~sx_libro_letti();
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

#endif // SX_LIBRO_LETTI_H
