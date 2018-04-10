#ifndef SX_SERIE_CRONOLOGIA_H
#define SX_SERIE_CRONOLOGIA_H

#include <QWidget>
#include <QtWidgets>

class sx_serie_cronologia : public QWidget
{
    Q_OBJECT
public:
    explicit sx_serie_cronologia(QWidget *parent = 0);

private:
    QLabel *tit;
    QScrollArea *area;
    QVBoxLayout *lay;
signals:

public slots:

};

#endif // SX_SERIE_CRONOLOGIA_H
