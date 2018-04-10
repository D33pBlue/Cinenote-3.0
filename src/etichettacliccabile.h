#ifndef ETICHETTACLICCABILE_H
#define ETICHETTACLICCABILE_H

#include <QLabel>
#include <QWidget>

class EtichettaCliccabile : public QLabel
{
    Q_OBJECT
public:
    explicit EtichettaCliccabile(QWidget *parent = 0);
    int id;
    QString reg;

private:
    void mousePressEvent(QMouseEvent*e);

signals:
    void clicked();

public slots:
    void selezionefilm();
    void selezioneregista();
    void selezionelibro();
    void selezioneserie();
    void selezionescrittore();
};

#endif // ETICHETTACLICCABILE_H
