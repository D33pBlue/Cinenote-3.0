#include "dialog_nuova_serie.h"
#include "ui_dialog_nuova_serie.h"
#include <iostream>
using namespace std;


Dialog_nuova_serie::Dialog_nuova_serie(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog_nuova_serie)
{
    ui->setupUi(this);
    connect(ui->annulla,SIGNAL(clicked()),this,SLOT(close()));
    connect(ui->ok,SIGNAL(clicked()),this,SLOT(salva()));
    setWindowTitle("Inserimento nuova serie");
}

Dialog_nuova_serie::~Dialog_nuova_serie()
{
    delete ui;
}



void Dialog_nuova_serie::salva(){
    QSqlQuery q;
    q.exec("select max(id)+1 from serie;");
    q.next();
    QString txq("insert into serie values(");
    txq+=q.value(0).toString()+QString(",\"")+ui->nome->text();
    txq+=QString("\",\"")+ui->descrizione->toPlainText()+QString("\",0,0,");
    txq+=ui->stagioniUscite->text()+QString(",")+ui->voto->text();
    txq+=QString(",\"")+ui->consigliatoda->text()+QString("\");");
    //cout<<txq.toStdString()<<endl;
    q.exec(txq);
    close();
}
