#include "dialog_modifica_serie.h"
#include "ui_dialog_modifica_serie.h"
#include <iostream>
using namespace std;

Dialog_modifica_serie::Dialog_modifica_serie(int id,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog_modifica_serie)
{
    ui->setupUi(this);
    _id=id;
    QSqlQuery q;
    q.exec(QString("select * from serie where id=")+QString::number(id));
    q.next();
    ui->nome->setText(q.value(1).toString());
    ui->descrizione->setText(q.value(2).toString());
    if(q.value(3).toBool())ui->iniziata->setChecked(1);
    if(q.value(4).toBool())ui->terminata->setChecked(1);
    ui->stagioniUscite->setText(q.value(5).toString());
    ui->voto->setText(q.value(6).toString());
    ui->consiglio->setText(q.value(7).toString());
    connect(ui->annulla,SIGNAL(clicked()),this,SLOT(deleteLater()));
    connect(ui->salva,SIGNAL(clicked()),this,SLOT(salva()));
    setWindowTitle("- Modifica Serie -");
}

Dialog_modifica_serie::~Dialog_modifica_serie()
{
    delete ui;
}

void Dialog_modifica_serie::salva(){
    QSqlQuery q;
    QString tq=QString("update serie set nome=\"")+ui->nome->text()+QString("\" where id=")+QString::number(_id);
    //cout<<tq.toStdString()<<endl;
    q.exec(tq);
    tq=QString("update serie set descrizione=\"")+ui->descrizione->toPlainText()+QString("\" where id=")+QString::number(_id);
    //cout<<tq.toStdString()<<endl;
    q.exec(tq);
    tq=QString("update serie set iniziata=");
    tq+=(ui->iniziata->isChecked())? QString("1") : QString("0");
    tq+=QString(" where id=")+QString::number(_id);
    //cout<<tq.toStdString()<<endl;
    q.exec(tq);
    tq=QString("update serie set terminata=");
    tq+=(ui->terminata->isChecked())? QString("1") : QString("0");
    tq+=QString(" where id=")+QString::number(_id);
    //cout<<tq.toStdString()<<endl;
    q.exec(tq);
    tq=QString("update serie set stagioniuscite=")+ui->stagioniUscite->text()+QString(" where id=")+QString::number(_id);
    //cout<<tq.toStdString()<<endl;
    q.exec(tq);
    tq=QString("update serie set voto=")+ui->voto->text()+QString(" where id=")+QString::number(_id);
    //cout<<tq.toStdString()<<endl;
    q.exec(tq);
    tq=QString("update serie set consigliatoda=\"")+ui->consiglio->text()+QString("\" where id=")+QString::number(_id);
    //cout<<tq.toStdString()<<endl;
    q.exec(tq);

    deleteLater();
}
