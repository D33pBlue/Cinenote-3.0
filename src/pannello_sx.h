#ifndef PANNELLO_SX_H
#define PANNELLO_SX_H

#include <QWidget>
#include <QtGui>
#include "tipi_usati.h"
#include <QGridLayout>

class Pannello_sx : public QWidget
{
    Q_OBJECT
public:
    explicit Pannello_sx(sezione sez=film,specifica spec=home,QWidget *parent = 0);
    ~Pannello_sx();
    void settaLayout(sezione sez,specifica spec);
private:
    QGridLayout *lay;
    QWidget *oggetto;
    void cancellaLayout();
signals:

public slots:

};

#endif // PANNELLO_SX_H
