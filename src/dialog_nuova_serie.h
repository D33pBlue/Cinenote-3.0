#ifndef DIALOG_NUOVA_SERIE_H
#define DIALOG_NUOVA_SERIE_H

#include <QDialog>
#include <QtSql>

namespace Ui {
class Dialog_nuova_serie;
}

class Dialog_nuova_serie : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog_nuova_serie(QWidget *parent = 0);
    ~Dialog_nuova_serie();

private:
    Ui::Dialog_nuova_serie *ui;
public slots:
    void salva();
};

#endif // DIALOG_NUOVA_SERIE_H
