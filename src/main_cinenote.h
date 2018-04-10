#ifndef MAIN_CINENOTE_H
#define MAIN_CINENOTE_H

#include <QMainWindow>
#include <QtSql>
#include <QtGui>
#include "tipi_usati.h"
#include "pannello_dx.h"
#include "pannello_sx.h"

namespace Ui {
class main_cinenote;
}

class main_cinenote : public QMainWindow
{
    Q_OBJECT

public:
    static QString radice;
    static QSqlDatabase db;
    static sezione io_sezione;
    static specifica io_specifica;
    explicit main_cinenote(QWidget *parent = 0);
    ~main_cinenote();
    void settaLayout(sezione sez,specifica spec);
    QString percorsoCover;

private:
    Ui::main_cinenote *ui;
    QWidget *bg;
    QHBoxLayout* lay;
    Pannello_sx *pansx;
    Pannello_dx *pandx;
    QLabel *logo;
    QShortcut *trovatoreFilm;
    QShortcut *nuovoshofilm;
    QShortcut *nuovashoserie;
    QShortcut *registashofilm;
    void cancellaLayout();
public slots:
    void cambiaSezione();
private slots:
    void on_actionVisti_triggered();
    void on_actionHome_triggered();
    void on_actionAttesi_triggered();
    void on_actionNuovo_2_triggered();
    void on_actionRoot_triggered();
    void on_actionCronologia_triggered();
    void on_actionRegisti_triggered();
    void on_actionGeneri_triggered();
    void on_actionCover_triggered();
    void on_actionFilm_2_triggered();
    void on_actionRegista_triggered();
    void on_actionFilm_triggered();
    void on_actionGenere_triggered();
    void on_actionNuovaSerie_triggered();
    void on_actionHomeSerie_triggered();
    void on_actionHome_Libri_triggered();
    void on_actionViste_triggered();
    void on_actionAttese_serie_triggered();
    void on_actionTrova_serie_triggered();
    void on_actionCronologia_Serie_triggered();
    void on_actionNuovo_Libro_triggered();
    void on_actionLetti_Libri_triggered();
    void on_actionAttesi_Libri_triggered();
    void on_actionLibro_triggered();
    void on_actionAutore_triggered();
    void on_actionCronologia_Libri_triggered();
    //void on_actionFile_serie_txt_triggered();
    void on_actionTestuale_Serie_triggered();
    void on_actionTestuale_Libri_triggered();
};

#endif // MAIN_CINENOTE_H













