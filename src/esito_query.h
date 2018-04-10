#ifndef ESITO_QUERY_H
#define ESITO_QUERY_H

#include <QDialog>
#include <QtSql>
#include <QtWidgets>
#include <QScrollArea>
#include <QLabel>
#include <QVBoxLayout>

namespace Ui {
class Esito_query;
}

class Esito_query : public QDialog
{
    Q_OBJECT

public:
    explicit Esito_query(QWidget *parent = 0,QSqlQuery *q=0);
    ~Esito_query();

private:
    Ui::Esito_query *ui;
    QLabel *l;
    QLineEdit *nuovaq;
    QScrollArea *tab;
public slots:
    void nuovaQuery();
};

#endif // ESITO_QUERY_H
