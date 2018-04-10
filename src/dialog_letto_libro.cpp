#include "dialog_letto_libro.h"
#include "ui_dialog_letto_libro.h"
#include <iostream>
using namespace std;

Dialog_letto_libro::Dialog_letto_libro(int id,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog_letto_libro)
{
    ui->setupUi(this);
    _id=id;
    QSqlQuery q;
    q.exec(QString("select case when numero isnull then 1 else max(numero)+1 end from lettura where libro=")+QString::number(id));
    q.next();
    ui->numero->setText(q.value(0).toString());
    connect(ui->annulla,SIGNAL(clicked()),this,SLOT(deleteLater()));
    connect(ui->ok,SIGNAL(clicked()),this,SLOT(salva()));
}

Dialog_letto_libro::~Dialog_letto_libro()
{
    delete ui;
}

void Dialog_letto_libro::salva(){
    QSqlQuery q;
    QString tq;
    tq=QString("insert into lettura values(")+QString::number(_id)+QString(",");
    tq+=ui->numero->text()+QString(",\"")+ui->inizio->text()+QString("\",\"");
    tq+=ui->fine->text()+QString("\",")+ui->voto->text()+QString(",\"");
    tq+=ui->note->toPlainText()+QString("\");");
    //cout<<tq.toStdString()<<endl;
    q.exec(tq);
    deleteLater();
}
