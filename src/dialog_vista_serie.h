#ifndef DIALOG_VISTA_SERIE_H
#define DIALOG_VISTA_SERIE_H

#include <QDialog>
#include <QtSql>
#include <iostream>
using namespace std;

namespace Ui {
class Dialog_vista_serie;
}

class Dialog_vista_serie : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog_vista_serie(int id=0,QWidget *parent = 0);
    ~Dialog_vista_serie();

private:
    Ui::Dialog_vista_serie *ui;
    int _id;
private slots:
    void salva();
};

#endif // DIALOG_VISTA_SERIE_H
