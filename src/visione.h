#ifndef VISIONE_H
#define VISIONE_H

#include <QWidget>
#include <QtGui>
#include <QTextBrowser>
#include <QLabel>
#include <QPushButton>

class Visione : public QWidget
{
    Q_OBJECT
public:
    explicit Visione(int id=-1,QString data=QString(""),QString dove=QString(""),double voto=0.0,QString att=QString(""),QString no=QString(""),QWidget *parent = 0);
    ~Visione();
private:
    QString _data;
    int filmid;
    QLabel *ldata;
    QLabel *ldove;
    QLabel *lvoto;
    QLabel *lattore;
    QTextBrowser *note;
    QPushButton *modifica;
signals:

public slots:
    void modificazione();
};

#endif // VISIONE_H
