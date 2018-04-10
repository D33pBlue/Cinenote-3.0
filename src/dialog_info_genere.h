#ifndef DIALOG_INFO_GENERE_H
#define DIALOG_INFO_GENERE_H

#include <QDialog>
#include <QtSql>
#include <QtGui>
#include <vector>
#include <QTableWidgetItem>
using std::vector;

namespace Ui {
class Dialog_info_genere;
}

class Dialog_info_genere : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog_info_genere(QString genere=QString(""),QWidget *parent = 0);
    ~Dialog_info_genere();

private:
    Ui::Dialog_info_genere *ui;
    vector<QTableWidgetItem*>eltab;
public slots:
    void mostraFilm(int r,int c);
};

#endif // DIALOG_INFO_GENERE_H
