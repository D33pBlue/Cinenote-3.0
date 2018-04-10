#ifndef SX_FILM_CRONOLOGIA_H
#define SX_FILM_CRONOLOGIA_H

#include <QWidget>
#include <QtGui>
#include <QtSql>
#include <vector>
#include <QVBoxLayout>
#include <QTableWidget>
#include <QLabel>

using std::vector;

class sx_film_cronologia : public QWidget
{
    Q_OBJECT
public:
    explicit sx_film_cronologia(QWidget *parent = 0);
    ~sx_film_cronologia();
private:
    QLabel *tit;
    QTableWidget *tab;
    QVBoxLayout *lay;
    vector<QTableWidgetItem*> elite;
signals:

public slots:
    void vediFilm(int r,int c);

};

#endif // SX_FILM_CRONOLOGIA_H
