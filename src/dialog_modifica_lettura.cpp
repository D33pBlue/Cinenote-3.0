#include "dialog_modifica_lettura.h"
#include "ui_dialog_modifica_lettura.h"
#include <iostream>
using namespace std;

Dialog_modifica_lettura::Dialog_modifica_lettura(int id,int num,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog_modifica_lettura)
{
    ui->setupUi(this);
    _id=id;
    _num=num;
    connect(ui->annulla,SIGNAL(clicked()),this,SLOT(deleteLater()));
    connect(ui->ok,SIGNAL(clicked()),this,SLOT(salva()));
    QSqlQuery q;
    q.exec(QString("select titolo from libro where id=")+QString::number(id));
    q.next();
    ui->libro->setText(q.value(0).toString()+QString(" (")+QString::number(num)+QString(")"));
    q.exec(QString("select * from lettura where libro=")+QString::number(id)+QString(" and numero=")+QString::number(num));
    q.next();
    ui->datainizio->setText(q.value(2).toString());
    ui->datafine->setText(q.value(3).toString());
    ui->voto->setText(q.value(4).toString());
    ui->note->setText(q.value(5).toString());
    setWindowTitle("Modifica lettura");
}

Dialog_modifica_lettura::~Dialog_modifica_lettura()
{
    delete ui;
}

void Dialog_modifica_lettura::salva(){
    QSqlQuery q;
    QString tq;
    tq=QString("update lettura set datafine=\"")+ui->datafine->text()+QString("\"");
    tq+=QString(" where libro=")+QString::number(_id)+QString(" and numero=")+QString::number(_num)+QString(";");
    //cout<<tq.toStdString()<<endl;
    q.exec(tq);
    tq=QString("update lettura set datainizio=\"")+ui->datainizio->text()+QString("\"");
    tq+=QString(" where libro=")+QString::number(_id)+QString(" and numero=")+QString::number(_num)+QString(";");
    //cout<<tq.toStdString()<<endl;
    q.exec(tq);
    tq=QString("update lettura set note=\"")+ui->note->toPlainText()+QString("\"");
    tq+=QString(" where libro=")+QString::number(_id)+QString(" and numero=")+QString::number(_num)+QString(";");
    //cout<<tq.toStdString()<<endl;
    q.exec(tq);
    tq=QString("update lettura set voto=")+ui->voto->text();
    tq+=QString(" where libro=")+QString::number(_id)+QString(" and numero=")+QString::number(_num)+QString(";");
    //cout<<tq.toStdString()<<endl;
    q.exec(tq);
    deleteLater();
}
