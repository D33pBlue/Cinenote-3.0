#ifndef DIALOG_MODIFICA_VISIONE_SERIE_H
#define DIALOG_MODIFICA_VISIONE_SERIE_H

#include <QDialog>
#include <QtSql>

namespace Ui {
class Dialog_modifica_visione_serie;
}

class Dialog_modifica_visione_serie : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog_modifica_visione_serie(int id=0,int stagione=0,QString data=QString(""),QWidget *parent = 0);
    ~Dialog_modifica_visione_serie();

private:
    Ui::Dialog_modifica_visione_serie *ui;
    int _id;
    int _stagione;
    QString _data;
private slots:
    void salva();
};

#endif // DIALOG_MODIFICA_VISIONE_SERIE_H
