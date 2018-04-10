#include "dialog_modifica_visione_serie.h"
#include "ui_dialog_modifica_visione_serie.h"
#include <iostream>
using namespace std;

Dialog_modifica_visione_serie::Dialog_modifica_visione_serie(int id,int stagione,QString data,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog_modifica_visione_serie)
{
    ui->setupUi(this);
    _id=id;
    _stagione=stagione;
    _data=data;
    connect(ui->annulla,SIGNAL(clicked()),this,SLOT(deleteLater()));
    QSqlQuery q;
    q.exec(QString("select * from visionestagione where serie=")+QString::number(id)+QString(" and stagione=")+QString::number(stagione)+QString(" and datainizio=\"")+data+QString("\";"));
    q.next();
    ui->stagione->setText(QString("Stagione ")+QString::number(stagione));
    ui->inizio->setText(QString("Iniziata il ")+q.value(2).toString());
    ui->fine->setText(q.value(3).toString());
    ui->modo->setText(q.value(4).toString());
    ui->voto->setText(q.value(5).toString());
    ui->note->setText(q.value(6).toString());
    setWindowTitle("Modifica visione serie");
    connect(ui->modifica,SIGNAL(clicked()),this,SLOT(salva()));
}

Dialog_modifica_visione_serie::~Dialog_modifica_visione_serie()
{
    delete ui;
}

void Dialog_modifica_visione_serie::salva(){
    QSqlQuery q;
    QString tq;
    tq=QString("update visionestagione set datafine=\"")+ui->fine->text()+QString("\"");
    tq+=QString(" where serie=")+QString::number(_id)+QString(" and stagione=")+QString::number(_stagione);
    tq+=QString(" and datainizio=\"")+_data+QString("\";");
    //cout<<tq.toStdString()<<endl;
    q.exec(tq);
    tq=QString("update visionestagione set modo=\"")+ui->modo->text()+QString("\"");
    tq+=QString(" where serie=")+QString::number(_id)+QString(" and stagione=")+QString::number(_stagione);
    tq+=QString(" and datainizio=\"")+_data+QString("\";");
    //cout<<tq.toStdString()<<endl;
    q.exec(tq);
    tq=QString("update visionestagione set voto=")+ui->voto->text();
    tq+=QString(" where serie=")+QString::number(_id)+QString(" and stagione=")+QString::number(_stagione);
    tq+=QString(" and datainizio=\"")+_data+QString("\";");
    //cout<<tq.toStdString()<<endl;
    q.exec(tq);
    tq=QString("update visionestagione set note=\"")+ui->note->toPlainText()+QString("\"");
    tq+=QString(" where serie=")+QString::number(_id)+QString(" and stagione=")+QString::number(_stagione);
    tq+=QString(" and datainizio=\"")+_data+QString("\";");
    //cout<<tq.toStdString()<<endl;
    q.exec(tq);
    deleteLater();
}
