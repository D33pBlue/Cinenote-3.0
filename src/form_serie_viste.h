#ifndef FORM_SERIE_VISTE_H
#define FORM_SERIE_VISTE_H

#include <QWidget>
#include "etichettacliccabile.h"
#include <QtSql>

namespace Ui {
class Form_serie_viste;
}

class Form_serie_viste : public EtichettaCliccabile
{
    Q_OBJECT

public:
    explicit Form_serie_viste(int id=0,QWidget *parent = 0);
    ~Form_serie_viste();

private:
    Ui::Form_serie_viste *ui;
    int _id;
private slots:
    void vedi();
};

#endif // FORM_SERIE_VISTE_H
