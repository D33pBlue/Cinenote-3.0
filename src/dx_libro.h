#ifndef DX_LIBRO_H
#define DX_LIBRO_H

#include <QWidget>
#include <QtGui>
#include <QLabel>
#include <QPushButton>
#include <QLineEdit>

class dx_libro : public QWidget
{
    Q_OBJECT
public:
    explicit dx_libro(QWidget *parent = 0);
private:
    QLabel *t;
    QPushButton *nuova;
    QPushButton *viste;
    QPushButton *attese;
    QLineEdit *cer;
    QPushButton *crono;
signals:

public slots:
    void nuovolibro();
    void cercalibro();


};

#endif // DX_LIBRO_H
