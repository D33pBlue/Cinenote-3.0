#ifndef LETTURA_H
#define LETTURA_H

#include <QWidget>
#include <QtWidgets>
#include <QTextBrowser>

class Lettura : public QWidget
{
    Q_OBJECT
public:
    explicit Lettura(int id=0,int num=0,QString inizio=QString(""),QString fine=QString(""),QString voto=QString(""),QString notef=QString(""),QWidget *parent = 0);
    ~Lettura();
private:
    int _num;
    int _id;
    QLabel *ldata;
    QLabel *ldove;
    QLabel *lvoto;
    QLabel *lattore;
    QTextBrowser *note;
    QPushButton *modifica;

signals:

public slots:
    void modificalettu();

};

#endif // LETTURA_H
