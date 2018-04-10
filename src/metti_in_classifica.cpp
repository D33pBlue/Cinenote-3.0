#include "metti_in_classifica.h"
#include "ui_metti_in_classifica.h"

Metti_in_classifica::Metti_in_classifica(int id,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Metti_in_classifica)
{
    ui->setupUi(this);
    _id=id;
    ui->elenco_classifica->setColumnCount(2);
    ui->elenco_classifica->setColumnWidth(0,300);
    ui->elenco_classifica->setColumnWidth(1,30);
    QSqlQuery q;
    q.exec("select p.posizione,f.titolo from classifica as p join film as f on p.film=f.id order by p.posizione;");
    while(q.next()){
        ui->elenco_classifica->insertRow(ui->elenco_classifica->rowCount());
        QTableWidgetItem *pos=new QTableWidgetItem(q.value(0).toString());
        QTableWidgetItem *fil=new QTableWidgetItem(q.value(1).toString());
        ui->elenco_classifica->setItem(ui->elenco_classifica->rowCount()-1,1,pos);
        ui->elenco_classifica->setItem(ui->elenco_classifica->rowCount()-1,0,fil);
    }
    connect(ui->annulla,SIGNAL(clicked()),this,SLOT(close()));
    connect(ui->salva,SIGNAL(clicked()),this,SLOT(salvaclass()));
}

Metti_in_classifica::~Metti_in_classifica()
{
    delete ui;
}

void Metti_in_classifica::salvaclass(){
    QSqlQuery q;
    q.exec("select max(posizione) from classifica;");
    q.next();
    if(ui->posizione->text().toInt()>0 && ui->posizione->text().toInt()<=q.value(0).toInt()+1){
        q.exec(QString("insert into classifica values(")+ui->posizione->text()+QString(",")+QString::number(_id)+QString(");"));
        close();
    }
    else ui->posizione->setText(QString::number(q.value(0).toInt()+1));
}
