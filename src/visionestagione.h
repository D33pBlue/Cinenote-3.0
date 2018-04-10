#ifndef VISIONESTAGIONE_H
#define VISIONESTAGIONE_H

#include <QWidget>
#include <QtGui>
#include <QTextBrowser>
#include <QLabel>
#include <QPushButton>
class VisioneStagione : public QWidget
{
    Q_OBJECT
public:
    explicit VisioneStagione(int id=-1,int stagione=0,QString data=QString(""),QString modo=QString(""),double voto=0.0,QString datafine=QString(""),QString no=QString(""),QWidget *parent = 0);
    ~VisioneStagione();
private:
    QString _data;
    int filmid;
    int _stagione;
    QLabel *ldata;
    QLabel *lmodo;
    QLabel *lvoto;
    QLabel *ldatafine;
    QTextBrowser *note;
    QPushButton *modifica;
    QLabel *pic;
    QLabel *ifstag;
signals:

public slots:
    void modificaora();
};

#endif // VISIONESTAGIONE_H
