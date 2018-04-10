#ifndef DIALOG_MODIFICA_REGISTA_H
#define DIALOG_MODIFICA_REGISTA_H

#include <QDialog>
#include <QtWidgets>
#include <QtSql>
#include <QLabel>
#include <QTextEdit>
#include <QGridLayout>

namespace Ui {
class Dialog_modifica_regista;
}

class Dialog_modifica_regista : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog_modifica_regista(QString nome=QString(""),QWidget *parent = 0);
    ~Dialog_modifica_regista();

private:
    Ui::Dialog_modifica_regista *ui;
    QString _nome;
    QLabel *tit;
    QLineEdit *nas;
    QLabel *lnas;
    QLineEdit *mor;
    QLabel *lmor;
    QTextEdit *descri;
    QLabel *ldescri;
    QGridLayout *lay;
    QPushButton *back;
    QPushButton *salva;
public slots:
    void modificatore();
};

#endif // DIALOG_MODIFICA_REGISTA_H
