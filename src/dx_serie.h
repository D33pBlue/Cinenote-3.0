#ifndef DX_SERIE_H
#define DX_SERIE_H

#include <QWidget>
#include <QtGui>
#include <QLabel>
#include <QPushButton>
#include <QLineEdit>

class dx_serie : public QWidget
{
    Q_OBJECT
public:
    explicit dx_serie(QWidget *parent = 0);
private:
    QLabel *t;
    QPushButton *nuova;
    QPushButton *viste;
    QPushButton *attese;
    QLineEdit *cer;
    QPushButton *crono;
signals:

public slots:
    void inseriscinuova();
    void cercaserie();
};

#endif // DX_SERIE_H
