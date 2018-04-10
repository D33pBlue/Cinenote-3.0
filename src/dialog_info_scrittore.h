#ifndef DIALOG_INFO_SCRITTORE_H
#define DIALOG_INFO_SCRITTORE_H

#include <QDialog>
#include <QtSql>
#include <QVector>
#include <QtWidgets>

namespace Ui {
class Dialog_info_scrittore;
}

class Dialog_info_scrittore : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog_info_scrittore(QString nome=QString(""),QWidget *parent = 0);
    ~Dialog_info_scrittore();

private:
    Ui::Dialog_info_scrittore *ui;
    QString _nome;
    QVector<QTableWidgetItem*>ele;
private slots:
    void vedilibro(int r,int c);
};

#endif // DIALOG_INFO_SCRITTORE_H
