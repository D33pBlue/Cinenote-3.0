#ifndef FORM_SERIE_MESE_H
#define FORM_SERIE_MESE_H

#include <QWidget>
#include <QtWidgets>
#include <QtSql>
#include <QVector>

namespace Ui {
class Form_serie_mese;
}

class Form_serie_mese : public QLabel
{
    Q_OBJECT

public:
    explicit Form_serie_mese(QWidget *parent = 0);
    ~Form_serie_mese();
    int settamese(QDate data);

private:
    Ui::Form_serie_mese *ui;
    QVector<QTableWidgetItem*>el;
private slots:
    void vedi(int r,int c);
};

#endif // FORM_SERIE_MESE_H
