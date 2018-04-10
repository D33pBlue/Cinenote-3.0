#include "visionestagione.h"
#include "funzioni.h"
#include "dialog_modifica_visione_serie.h"

VisioneStagione::VisioneStagione(int id,int stagione,QString data,QString modo,double voto,QString datafine,QString no,QWidget *parent) :
    QWidget(parent)
{
    _data=data;
    filmid=id;
    _stagione=stagione;
    setMaximumWidth(650);
    setMaximumHeight(200);
    setMinimumHeight(200);
    setMinimumWidth(650);
    QDate iniz=QDate::fromString(data,"yyyy-MM-dd");
    QDate fiz=QDate::fromString(datafine,"yyyy-MM-dd");
    ldata=new QLabel(QString("Iniziata in ")+iniz.toString("MMMM yyyy"),this);
    lmodo=new QLabel(QString("Modo: ")+modo,this);
    lvoto=new QLabel(this);
    lvoto->setText(QString("Voto: ")+QString::number(voto));
    lvoto->setFont(QFont("Times",15));
    ldatafine=new QLabel(QString("Finita in ")+fiz.toString("MMMM yyyy"),this);
    note=new QTextBrowser(this);
    note->setText(no);
    ldata->setGeometry(226,25,310,20);
    lmodo->setGeometry(400,43,310,20);
    lvoto->setGeometry(226,43,310,25);
    ldatafine->setGeometry(400,25,310,20);
    note->setGeometry(226,70,380,120);
    ifstag=new QLabel(QString("Stagione ")+QString::number(stagione),this);
    ifstag->setGeometry(180,0,310,20);
    ifstag->setFont(QFont("Times",15));
    modifica=new QPushButton(this);
    modifica->setText("Modifica");
    modifica->setGeometry(580,0,70,15);
    connect(modifica,SIGNAL(clicked()),this,SLOT(modificaora()));
    pic=new QLabel(this);
    pic->setScaledContents(1);
    pic->setGeometry(0,0,150,216);
    pic->setPixmap(QPixmap(fun::imagserie(id,stagione)));
}

void VisioneStagione::modificaora(){
    Dialog_modifica_visione_serie *mod=new Dialog_modifica_visione_serie(filmid,_stagione,_data,this);
    mod->show();
}

VisioneStagione::~VisioneStagione(){
    delete ldata;
    delete lmodo;
    delete lvoto;
    delete ldatafine;
    delete note;
    delete pic;
    delete ifstag;
}
