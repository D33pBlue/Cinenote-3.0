#ifndef SX_FILM_CLASSIFICA_H
#define SX_FILM_CLASSIFICA_H

#include <QWidget>
#include <QtGui>
#include <QtSql>
#include <vector>
#include <QLabel>
#include <QTableWidget>
#include <QVBoxLayout>
#include <QTableWidgetItem>

using std::vector;

class sx_film_classifica : public QWidget
{
    Q_OBJECT
public:
    explicit sx_film_classifica(QWidget *parent = 0);
    ~sx_film_classifica();
private:
    QLabel *tit;
    QTableWidget *tab;
    QVBoxLayout *lay;
    vector<QTableWidgetItem*>eltab;
signals:

public slots:
    void vediFilm(int r,int c);
};

#endif // SX_FILM_CLASSIFICA_H
