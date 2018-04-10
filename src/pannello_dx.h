#ifndef PANNELLO_DX_H
#define PANNELLO_DX_H

#include <QWidget>
#include <QtGui>
#include <QtSql>
#include "etichettacliccabile.h"
#include "tipi_usati.h"
#include <QTextEdit>
#include <QVBoxLayout>
#include <QGridLayout>
#include <QHBoxLayout>
#include <QShortcut>

class Pannello_dx;
class main_cinenote;

#include "main_cinenote.h"


class Pannello_dx : public QWidget
{
    Q_OBJECT
public:
    explicit Pannello_dx(sezione sez=film,QWidget *parent = 0);
    ~Pannello_dx();
    void settaLayout(sezione sez);
private:
    QTextEdit *ins;
    QWidget *pannello;
    main_cinenote *padre;
    QVBoxLayout *lv;
    EtichettaCliccabile *tastofilm;
    EtichettaCliccabile *tastoserie;
    EtichettaCliccabile *tastolibri;
    void cancellaLayout();

signals:

public slots:
    void RispondiQuery();
    void sezioneFilm();
    void sezioneSerie();
    void sezioneLibri();
    void sezioneFilmVisti();
    void sezioneFilmAttesi();
    void sezioneFilmCronologia();
    void selezioneSerieViste();
    void selezioneSerieAttese();
    void selezioneSerieCronologia();
    void libriletti();
    void libriattesi();
    void sezionelibricronologia();
};

#endif // PANNELLO_DX_H
