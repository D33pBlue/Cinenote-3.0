#ifndef SX_FILM_CLASSIFICA_REGISTI_H
#define SX_FILM_CLASSIFICA_REGISTI_H

#include <QWidget>
#include <QtGui>
#include <vector>
#include <QtSql>
#include <QTableWidget>
#include <QVBoxLayout>
#include <QLabel>
#include <QTableWidgetItem>

using std::vector;

class sx_film_classifica_registi : public QWidget
{
    Q_OBJECT
public:
    explicit sx_film_classifica_registi(QWidget *parent = 0);
    ~sx_film_classifica_registi();
private:
    QTableWidget *tab;
    QVBoxLayout *lay;
    QLabel *tit;
    vector<QTableWidgetItem*>eltab;
signals:

public slots:
    void mostraAutore(int r,int c);
};

#endif // SX_FILM_CLASSIFICA_REGISTI_H
