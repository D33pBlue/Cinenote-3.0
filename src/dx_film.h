#ifndef DX_FILM_H
#define DX_FILM_H

#include <QWidget>
#include <QtGui>
#include <QLabel>
#include <QPushButton>
#include <QLineEdit>

class dx_film : public QWidget
{
    Q_OBJECT
public:
    explicit dx_film(QWidget *parent = 0);
    ~dx_film();
private:
    QLabel *t;
    QPushButton *bottone_visti;
    QPushButton *bottone_attesi;
    QPushButton *bottone_nuovo;
    QPushButton *bottone_crono;
    QLineEdit *cercafilm;
    QLineEdit *cercaregista;
signals:

public slots:
    void cercafilmslot();
    void cercaregistaslot();
    void cancellino();
    void cancellino2();
    void inseriscinuovo();

};

#endif // DX_FILM_H
