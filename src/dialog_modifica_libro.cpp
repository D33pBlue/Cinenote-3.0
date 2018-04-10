#include "dialog_modifica_libro.h"
#include "ui_dialog_modifica_libro.h"
#include <iostream>
using namespace std;

Dialog_modifica_libro::Dialog_modifica_libro(int id,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog_modifica_libro)
{
    ui->setupUi(this);
    _id=id;
    QSqlQuery q;
    q.exec(QString("select * from libro where id=")+QString::number(id));
    q.next();
    ui->titolo->setText(q.value(1).toString());
    ui->autore->setText(q.value(2).toString());
    ui->anno->setText(q.value(3).toString());
    if(q.value(4).toBool())ui->letto->setChecked(1);
    ui->voto->setText(q.value(5).toString());
    ui->descrizione->setText(q.value(6).toString());
    ui->consigliatoda->setText(q.value(7).toString());
    connect(ui->annulla,SIGNAL(clicked()),this,SLOT(deleteLater()));
    connect(ui->ok,SIGNAL(clicked()),this,SLOT(salva()));
}

Dialog_modifica_libro::~Dialog_modifica_libro()
{
    delete ui;
}

void Dialog_modifica_libro::salva(){
    QSqlQuery q;
    QString tq;
    tq=QString("update libro set titolo=\"")+ui->titolo->text()+QString("\" where id=")+QString::number(_id);
    //cout<<tq.toStdString()<<endl;
    q.exec(tq);
    tq=QString("update libro set autore=\"")+ui->autore->text()+QString("\" where id=")+QString::number(_id);
    //cout<<tq.toStdString()<<endl;
    q.exec(tq);
    tq=QString("update libro set anno=")+ui->anno->text()+QString(" where id=")+QString::number(_id);
    //cout<<tq.toStdString()<<endl;
    q.exec(tq);
    tq=QString("update libro set letto=");
    tq+=(ui->letto->isChecked()) ? QString("1") : QString("0");
    tq+=QString(" where id=")+QString::number(_id);
    //cout<<tq.toStdString()<<endl;
    q.exec(tq);
    tq=QString("update libro set voto=")+ui->voto->text()+QString(" where id=")+QString::number(_id);
    //cout<<tq.toStdString()<<endl;
    q.exec(tq);
    tq=QString("update libro set descrizione=\"")+ui->descrizione->toPlainText()+QString("\" where id=")+QString::number(_id);
    //cout<<tq.toStdString()<<endl;
    q.exec(tq);
    tq=QString("update libro set consigliatoda=\"")+ui->consigliatoda->text()+QString("\" where id=")+QString::number(_id);
    //cout<<tq.toStdString()<<endl;
    q.exec(tq);
    deleteLater();
}
