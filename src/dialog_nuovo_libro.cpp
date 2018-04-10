#include "dialog_nuovo_libro.h"
#include "ui_dialog_nuovo_libro.h"
#include <iostream>
using namespace std;

Dialog_nuovo_libro::Dialog_nuovo_libro(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog_nuovo_libro)
{
    ui->setupUi(this);
    connect(ui->annulla,SIGNAL(clicked()),this,SLOT(deleteLater()));
    connect(ui->ok,SIGNAL(clicked()),this,SLOT(salva()));
    setWindowTitle("Inserimento nuovo libro");
}

Dialog_nuovo_libro::~Dialog_nuovo_libro()
{
    delete ui;
}

void Dialog_nuovo_libro::salva(){
    QSqlQuery q;
    q.exec("select max(id)+1 from libro;");
    q.next();
    QString idnuovo=q.value(0).toString();
    QString tq;
    tq=QString("insert into libro values(")+idnuovo+QString(",\"")+ui->titolo->text()+QString("\",\"");
    tq+=ui->autore->text()+QString("\",")+ui->anno->text()+QString(",");
    tq+=QString("0");
    tq+=QString(",")+ui->voto->text()+QString(",\"");
    tq+=ui->descrizione->toPlainText()+QString("\",\"")+ui->consigliatoda->text()+QString("\");");
    //cout<<tq.toStdString()<<endl;
    q.exec(tq);
    tq=QString("insert into generelibro values(")+idnuovo+QString(",\"")+ui->genere->text()+QString("\");");
    //cout<<tq.toStdString()<<endl;
    q.exec(tq);
    deleteLater();
}
