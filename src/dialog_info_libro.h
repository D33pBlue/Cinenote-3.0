#ifndef DIALOG_INFO_LIBRO_H
#define DIALOG_INFO_LIBRO_H

#include <QDialog>
#include <QtGui>
#include <vector>
#include "lettura.h"
#include "etichettacliccabile.h"
#include <QGridLayout>
#include <QTextBrowser>
#include <QScrollArea>
using std::vector;

namespace Ui {
class Dialog_info_libro;
}

class Dialog_info_libro : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog_info_libro(int id=0,QWidget *parent = 0);
    ~Dialog_info_libro();

private:
    Ui::Dialog_info_libro *ui;
    int _id;
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
    bool visto;
    vector<Lettura*> visioni;
    QScrollArea *areavisioni;
    QWidget *widvisioni;
    QGridLayout *layvisio;
    QLabel *descrivisio;
public slots:
    void modificadialog();
    void letturasalva();
};

#endif // DIALOG_INFO_LIBRO_H
