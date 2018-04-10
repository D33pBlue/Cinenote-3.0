#ifndef SX_FILM_CLASSIFICA_GENERI_H
#define SX_FILM_CLASSIFICA_GENERI_H

#include <QWidget>
#include <QtGui>
#include <QtSql>
#include <vector>
#include <QTableWidget>
#include <QVBoxLayout>
#include <QLabel>
#include <QTableWidgetItem>

using std::vector;

class sx_film_classifica_generi : public QWidget
{
    Q_OBJECT
public:
    explicit sx_film_classifica_generi(QWidget *parent = 0);
    ~sx_film_classifica_generi();
private:
    QTableWidget *tab;
    QVBoxLayout *lay;
    QLabel *tit;
    vector<QTableWidgetItem*>eltab;
signals:

public slots:
    void vediGenere(int r,int c);

};

#endif // SX_FILM_CLASSIFICA_GENERI_H
