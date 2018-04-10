#include "dialog_vista_serie.h"
#include "ui_dialog_vista_serie.h"

Dialog_vista_serie::Dialog_vista_serie(int id,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog_vista_serie)
{
    ui->setupUi(this);
    _id=id;
    QSqlQuery q;
    q.exec(QString("select nome from serie where id=")+QString::number(id));
    q.next();
    connect(ui->annulla,SIGNAL(clicked()),this,SLOT(deleteLater()));
    connect(ui->salva,SIGNAL(clicked()),this,SLOT(salva()));
    ui->inizio->setDate(QDate::currentDate());
    ui->label->setText(QString("Visione Stagione di ")+q.value(0).toString());
    setWindowTitle("- Visione -");
}

Dialog_vista_serie::~Dialog_vista_serie()
{
    delete ui;
}

void Dialog_vista_serie::salva(){
    QSqlQuery q;
    QString tq=QString("insert into visionestagione values(");
    tq+=QString::number(_id)+QString(",");
    tq+=ui->stagione->text()+QString(",\"");
    tq+=ui->inizio->date().toString("yyyy-MM-dd")+QString("\",\"");
    tq+=ui->fine->text()+QString("\",\"");
    tq+=ui->modo->text()+QString("\",");
    tq+=ui->voto->text()+QString(",\"");
    tq+=ui->note->toPlainText()+QString("\");");
    //cout<<tq.toStdString()<<endl;
    q.exec(tq);
    deleteLater();
}
