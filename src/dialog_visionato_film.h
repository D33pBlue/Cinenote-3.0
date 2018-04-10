#ifndef DIALOG_VISIONATO_FILM_H
#define DIALOG_VISIONATO_FILM_H

#include <QDialog>
#include <QtWidgets>
#include <QtSql>
#include <QDateEdit>
#include <QLabel>
#include <QTextEdit>
#include <QGridLayout>

namespace Ui {
class Dialog_visionato_film;
}

class Dialog_visionato_film : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog_visionato_film(int id=-1,QWidget *parent = 0);
    ~Dialog_visionato_film();

private:
    Ui::Dialog_visionato_film *ui;
    QLabel *tit;
    int _id;
    QDateEdit *data;
    QLineEdit *dove;
    QLineEdit *voto;
    QTextEdit *note;
    QLineEdit *attore;
    QGridLayout* lay;
    QPushButton *vai;
    QPushButton *annulla;
    QLabel *_data;
    QLabel *_dove;
    QLabel *_voto;
    QLabel *_note;
    QLabel *_attore;
public slots:
    void salva();
};

#endif // DIALOG_VISIONATO_FILM_H
