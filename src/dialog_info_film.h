#ifndef DIALOG_INFO_FILM_H
#define DIALOG_INFO_FILM_H

#include <QDialog>
#include <QtWidgets>
#include <vector>
#include "visione.h"
#include "etichettacliccabile.h"
#include <QTextBrowser>
#include <QScrollArea>
#include <QGridLayout>

using std::vector;

namespace Ui {
class Dialog_info_film;
}

class Dialog_info_film : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog_info_film(int id=0,QWidget *parent = 0);
    ~Dialog_info_film();

private:
    int _id;
    Ui::Dialog_info_film *ui;
    QLabel *titolo;
    QString _titolo;
    QLabel *pic;
    EtichettaCliccabile *anre;
    QLabel *generi;
    QLabel *votoconsiglio;
    QTextBrowser *descri;
    QPushButton *modifica;
    QPushButton *visionato;
    QPushButton *back;
    QPushButton *classifica;
    bool visto;
    vector<Visione*> visioni;
    QScrollArea *areavisioni;
    QWidget *widvisioni;
    QGridLayout *layvisio;
    QLabel *descrivisio;
public slots:
    void visionatore();
    void modificatore();
    void metti_classifica();
};

#endif // DIALOG_INFO_FILM_H
