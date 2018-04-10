#include "dialog_info_genere.h"
#include "ui_dialog_info_genere.h"
#include "dialog_info_film.h"

Dialog_info_genere::Dialog_info_genere(QString genere,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog_info_genere)
{
    ui->setupUi(this);
    QSqlQuery q;
    q.exec(QString("select * from genere where upper(nome) like upper(\"%")+genere+QString("%\") order by length(nome);"));
    q.next();
    ui->label_genere->setText(q.value(0).toString());
    ui->label_info->setText(QString("#film: ")+q.value(1).toString()+QString("    #visti: ")+q.value(2).toString()+QString("    media: ")+q.value(3).toString());
    q.exec(QString("select f.titolo,f.id from film as f join gen as g on f.id=g.film where g.genere=\"")+ui->label_genere->text()+QString("\" order by f.voto desc;"));
    ui->tabFilm->setColumnCount(2);
    ui->tabFilm->setHorizontalHeaderLabels(QStringList()<<"Film"<<"id");
    ui->tabFilm->setColumnWidth(0,411);
    while(q.next()){
        ui->tabFilm->insertRow(ui->tabFilm->rowCount());
        QTableWidgetItem *fi=new QTableWidgetItem(q.value(0).toString());
        eltab.push_back(fi);
        QTableWidgetItem *fid=new QTableWidgetItem(q.value(1).toString());
        eltab.push_back(fid);
        ui->tabFilm->setItem(ui->tabFilm->rowCount()-1,0,fi);
        ui->tabFilm->setItem(ui->tabFilm->rowCount()-1,1,fid);
    }
    connect(ui->tabFilm,SIGNAL(cellClicked(int,int)),this,SLOT(mostraFilm(int,int)));
}

Dialog_info_genere::~Dialog_info_genere()
{
    for(int i=0;i<eltab.size();i++)delete eltab[i];
    delete ui;
}


void Dialog_info_genere::mostraFilm(int r, int c){
    Dialog_info_film *info=new Dialog_info_film(ui->tabFilm->item(r,1)->text().toInt(),this);
    info->show();
}
