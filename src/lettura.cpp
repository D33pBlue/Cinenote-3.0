#include "lettura.h"
#include "dialog_modifica_lettura.h"

Lettura::Lettura(int id,int num,QString inizio,QString fine,QString voto,QString notef,QWidget *parent) :
    QWidget(parent)
{
    _id=id;
    _num=num;
    setMaximumWidth(650);
    setMaximumHeight(200);
    setMinimumHeight(200);
    setMinimumWidth(650);
    QDate daat=QDate::fromString(inizio,"yyyy-MM-dd");
    inizio=(daat.isValid())? daat.toString("dddd dd MMMM yyyy") : QString("Non si sa quando");
    ldata=new QLabel(QString("Iniziato ")+inizio,this);
    daat=QDate::fromString(fine,"yyyy-MM-dd");
    fine=(daat.isValid())? daat.toString("dddd dd MMMM yyyy") : QString("Non si sa quando");
    ldove=new QLabel(QString("Finito ")+fine,this);
    lvoto=new QLabel(this);
    lvoto->setText(QString("Voto: ")+voto);
    lvoto->setFont(QFont("Times",15));
    lattore=new QLabel(QString("Visione numero ")+QString::number(num),this);
    note=new QTextBrowser(this);
    note->setText(notef);
    ldata->setGeometry(10,10,310,20);
    ldove->setGeometry(320,10,310,20);
    lvoto->setGeometry(10,40,310,25);
    lattore->setGeometry(320,40,310,20);
    note->setGeometry(10,70,600,120);
    modifica=new QPushButton(this);
    modifica->setText("Modifica");
    modifica->setGeometry(580,0,70,15);
    connect(modifica,SIGNAL(clicked()),this,SLOT(modificalettu()));
}

Lettura::~Lettura(){
    delete ldata;
    delete ldove;
    delete lvoto;
    delete lattore;
    delete note;
}

void Lettura::modificalettu(){
    Dialog_modifica_lettura* mod=new Dialog_modifica_lettura(_id,_num,this);
    mod->show();
}
