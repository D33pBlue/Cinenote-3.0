#ifndef DIALOG_INFO_SERIE_H
#define DIALOG_INFO_SERIE_H

#include <QDialog>
#include <QtGui>
#include <QTextBrowser>
#include <QScrollArea>
#include <vector>
#include <QLabel>
#include <QGridLayout>
#include "visionestagione.h"
using std::vector;

namespace Ui {
class Dialog_info_serie;
}

class Dialog_info_serie : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog_info_serie(int id=0,QWidget *parent = 0);
    ~Dialog_info_serie();

private:
    Ui::Dialog_info_serie *ui;
    int _id;
    QLabel *titolo;
    QString _titolo;
    QLabel *pic;
    QLabel *votoconsiglio;
    QLabel *stagionius;
    QTextBrowser *descri;
    QPushButton *modifica;
    QPushButton *visionato;
    QPushButton *back;
    QPushButton * terminata;
    bool visto;
    vector<VisioneStagione*> visioni;
    QScrollArea *areavisioni;
    QWidget *widvisioni;
    QGridLayout *layvisio;
    QLabel *descrivisio;
private slots:
    void modificaserie();
    void settaterminata();
    void visualizzaserie();
};

#endif // DIALOG_INFO_SERIE_H
