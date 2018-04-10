#include "visione.h"
#include "dialog_modifica_visione_film.h"

Visione::Visione(int id,QString data,QString dove,double voto,QString att,QString no,QWidget *parent) :
    QWidget(parent)
{
    _data=data;
    filmid=id;
    setMaximumWidth(650);
    setMaximumHeight(200);
    setMinimumHeight(200);
    setMinimumWidth(650);
    QDate daat=QDate::fromString(data,"yyyy-MM-dd");
    data=(daat.isValid())? daat.toString("dddd dd MMMM yyyy") : QString("Non si sa quando");
    ldata=new QLabel(QString("Visione di ")+data,this);
    ldove=new QLabel(QString("Luogo: ")+dove,this);
    lvoto=new QLabel(this);
    lvoto->setText(QString("Voto: ")+QString::number(voto));
    lvoto->setFont(QFont("Times",15));
    lattore=new QLabel(QString("Attore apprezzato: ")+att,this);
    note=new QTextBrowser(this);
    note->setText(no);
    ldata->setGeometry(10,10,310,20);
    ldove->setGeometry(320,10,310,20);
    lvoto->setGeometry(10,40,310,25);
    lattore->setGeometry(320,40,310,20);
    note->setGeometry(10,70,600,120);
    modifica=new QPushButton(this);
    modifica->setText("Modifica");
    modifica->setGeometry(580,0,70,15);
    connect(modifica,SIGNAL(clicked()),this,SLOT(modificazione()));
}


void Visione::modificazione(){
    Dialog_modifica_visione_film *mo=new Dialog_modifica_visione_film(filmid,_data,this);
    mo->show();
}


Visione::~Visione(){
    delete ldata;
    delete ldove;
    delete lvoto;
    delete lattore;
    delete note;
}
