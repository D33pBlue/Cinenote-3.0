#ifndef DIALOG_INFO_REGISTA_H
#define DIALOG_INFO_REGISTA_H

#include <QDialog>
#include <QtGui>
#include <QtSql>
#include <vector>
#include <QTextBrowser>
#include <QTableWidget>
#include <QTableWidgetItem>
#include <QLabel>

using std::vector;

namespace Ui {
class Dialog_info_regista;
}

class Dialog_info_regista : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog_info_regista(QString reg=QString(""),QWidget *parent = 0);
    ~Dialog_info_regista();

private:
    Ui::Dialog_info_regista *ui;
    QString _nomeregi;
    QLabel *nome;
    QLabel *pic;
    QLabel *datenm;
    QTextBrowser *descri;
    QLabel *numeri;
    QTableWidget *filmi;
    vector<QTableWidgetItem*> itemtab;
    QPushButton *modifica;
    QPushButton *back;
signals:
    void chiusore();
public slots:
    void mostrafilm(int r,int c);
    void fai_modifiche();
};

#endif // DIALOG_INFO_REGISTA_H
