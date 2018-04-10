#include "dialog_nuovo_film_inserimento.h"
#include "ui_dialog_nuovo_film_inserimento.h"
#include <iostream>
using namespace std;

Dialog_nuovo_film_inserimento::Dialog_nuovo_film_inserimento(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog_nuovo_film_inserimento)
{
    ui->setupUi(this);
    setWindowTitle("Inserimento nuovo film");
    ui->back->setText("Back");
    ui->elenco_registi->setColumnCount(1);
    ui->elenco_registi->setColumnWidth(0,400);
    ui->elenco_generi->setColumnCount(1);
    ui->elenco_generi->setColumnWidth(0,400);
    connect(ui->back,SIGNAL(clicked()),this,SLOT(close()));
    connect(ui->toolBox,SIGNAL(currentChanged(int)),this,SLOT(aggiorna(int)));
    connect(ui->aggiungi_genere,SIGNAL(clicked()),this,SLOT(aggiungi_genere()));
    connect(ui->aggiungi_regista,SIGNAL(clicked()),this,SLOT(aggiungi_regista()));
    connect(ui->reset_generi,SIGNAL(clicked()),this,SLOT(reset_genere()));
    connect(ui->reset_registi,SIGNAL(clicked()),this,SLOT(reset_regista()));
    connect(ui->salva,SIGNAL(clicked()),this,SLOT(salvatutto()));
}

Dialog_nuovo_film_inserimento::~Dialog_nuovo_film_inserimento()
{
    delete ui;
}

void Dialog_nuovo_film_inserimento::aggiorna(int pag){
    QSqlQuery q;
    q.exec("select max(id) from film");
    q.next();
    int nid=q.value(0).toInt()+1;
    QString riepilogo("");
    QString txq1=QString("insert into film values(")+QString::number(nid)+QString(",\"");
    txq1+=ui->titolo->text()+QString("\",0,");
    txq1+=(ui->disponibile->isChecked())? QString("1,") : QString("0,");
    txq1+=ui->anno->text()+QString(",")+ui->aspettativa->text()+QString(",\"");
    txq1+=ui->descrizione->toPlainText()+QString("\",\"");
    txq1+=ui->consigliatoda->text()+QString("\");");
    riepilogo+=txq1+QString("\n");
    //...
    for(int i=0;i<ui->elenco_registi->rowCount();i++){
        QString txq2=QString("insert into direzione values(")+QString::number(nid)+QString(",\"");
        txq2+=ui->elenco_registi->item(i,0)->text()+QString("\");");
        riepilogo+=txq2+QString("\n");
    }
    for(int i=0;i<ui->elenco_generi->rowCount();i++){
        QString txq2=QString("insert into gen values(")+QString::number(nid)+QString(",\"");
        txq2+=ui->elenco_generi->item(i,0)->text()+QString("\");");
        riepilogo+=txq2+QString("\n");
    }

    ui->riepilogo->setText(riepilogo);

}

void Dialog_nuovo_film_inserimento::aggiungi_regista(){
    ui->elenco_registi->insertRow(ui->elenco_registi->rowCount());
    QTableWidgetItem *ogg=new QTableWidgetItem(ui->nuovo_regista->text());
    ui->elenco_registi->setItem(ui->elenco_registi->rowCount()-1,0,ogg);
    ui->nuovo_regista->clear();
}

void Dialog_nuovo_film_inserimento::aggiungi_genere(){
    ui->elenco_generi->insertRow(ui->elenco_generi->rowCount());
    QTableWidgetItem *ogg=new QTableWidgetItem(ui->nuovo_genere->text());
    ui->elenco_generi->setItem(ui->elenco_generi->rowCount()-1,0,ogg);
    ui->nuovo_genere->clear();
}

void Dialog_nuovo_film_inserimento::reset_regista(){
    while(ui->elenco_registi->rowCount()>0){
            ui->elenco_registi->removeRow(ui->elenco_registi->rowCount()-1);
        }
}

void Dialog_nuovo_film_inserimento::reset_genere(){
    while(ui->elenco_generi->rowCount()>0){
            ui->elenco_generi->removeRow(ui->elenco_generi->rowCount()-1);
        }
}

void Dialog_nuovo_film_inserimento::salvatutto(){
    QSqlQuery q;
    q.exec("select max(id) from film");
    q.next();
    int nid=q.value(0).toInt()+1;
    QString txq1=QString("insert into film values(")+QString::number(nid)+QString(",\"");
    txq1+=ui->titolo->text()+QString("\",0,");
    txq1+=(ui->disponibile->isChecked())? QString("1,") : QString("0,");
    txq1+=ui->anno->text()+QString(",")+ui->aspettativa->text()+QString(",\"");
    txq1+=ui->descrizione->toPlainText()+QString("\",\"");
    txq1+=ui->consigliatoda->text()+QString("\");");
    q.exec(txq1);
    //...
    for(int i=0;i<ui->elenco_registi->rowCount();i++){
        QString txq2=QString("insert into direzione values(")+QString::number(nid)+QString(",\"");
        txq2+=ui->elenco_registi->item(i,0)->text()+QString("\");");
        q.exec(txq2);
    }
    for(int i=0;i<ui->elenco_generi->rowCount();i++){
        QString txq2=QString("insert into gen values(")+QString::number(nid)+QString(",\"");
        txq2+=ui->elenco_generi->item(i,0)->text()+QString("\");");
        q.exec(txq2);
    }
    close();
}















