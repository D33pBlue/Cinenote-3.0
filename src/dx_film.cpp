#include "dx_film.h"
#include "main_cinenote.h"
#include "pannello_dx.h"
#include <QtSql>
#include "dialog_info_film.h"
#include "dialog_info_regista.h"
#include "dialog_nuovo_film_inserimento.h"

dx_film::dx_film(QWidget *parent) :
    QWidget(parent)
{
    Pannello_dx *padre=reinterpret_cast<Pannello_dx*>(parent);
    t=new QLabel(this);
    t->setGeometry(0,0,280,555);
    t->setPixmap(QPixmap(main_cinenote::radice+QString("risorse/wall1")));
    t->setScaledContents(1);
    this->setMinimumHeight(555);
    this->setMaximumHeight(555);
    bottone_visti=new QPushButton(this);
    bottone_visti->setText("Visti");
    bottone_visti->setGeometry(200,430,70,30);//setGeometry(0,340,70,30);
    bottone_attesi=new QPushButton(this);
    bottone_attesi->setText("Attesi");
    bottone_attesi->setGeometry(200,390,70,30);//setGeometry(0,300,70,30);
    bottone_nuovo=new QPushButton(this);
    bottone_nuovo->setText("Nuovo");
    bottone_nuovo->setGeometry(200,470,70,30);//setGeometry(0,220,70,30);
    bottone_crono=new QPushButton(this);
    bottone_crono->setText("Cronologia");
    bottone_crono->setGeometry(200,350,70,30);//setGeometry(0,260,70,30);
    connect(bottone_visti,SIGNAL(clicked()),padre,SLOT(sezioneFilmVisti()));
    connect(bottone_attesi,SIGNAL(clicked()),padre,SLOT(sezioneFilmAttesi()));
    connect(bottone_nuovo,SIGNAL(clicked()),this,SLOT(inseriscinuovo()));
    connect(bottone_crono,SIGNAL(clicked()),padre,SLOT(sezioneFilmCronologia()));
    cercafilm=new QLineEdit(this);
    cercafilm->setText("Cerca film");
    cercafilm->setGeometry(120,530,150,20);//setGeometry(0,30,120,20);
    connect(cercafilm,SIGNAL(returnPressed()),this,SLOT(cercafilmslot()));
    connect(cercafilm,SIGNAL(selectionChanged()),this,SLOT(cancellino()));
    cercaregista=new QLineEdit(this);
    cercaregista->setText("Cerca regista");
    cercaregista->setGeometry(120,510,150,20);//setGeometry(0,10,120,20);
    connect(cercaregista,SIGNAL(returnPressed()),this,SLOT(cercaregistaslot()));
    connect(cercaregista,SIGNAL(selectionChanged()),this,SLOT(cancellino2()));
}

dx_film::~dx_film(){
    delete t;
    delete bottone_visti;
    delete bottone_attesi;
    delete cercafilm;
    delete bottone_crono;
}

void dx_film::cercafilmslot(){
    QSqlQuery q;
    q.exec(QString("select id from film where upper(titolo) like upper(\"%")+cercafilm->text()+QString("%\") order by length(titolo);"));
    //select * from film where upper(titolo) like upper('%la casa%') order by length(titolo);
    if(q.next()){
        Dialog_info_film *info=new Dialog_info_film(q.value(0).toInt(),this);
        info->show();
    }
    cercafilm->clear();
}


void dx_film::cancellino(){
    cercafilm->clear();
}

void dx_film::cercaregistaslot(){

    Dialog_info_regista *info=new Dialog_info_regista(cercaregista->text(),this);
    info->show();
    cercaregista->clear();
}


void dx_film::cancellino2(){
    cercaregista->clear();
}

void dx_film::inseriscinuovo(){
    Dialog_nuovo_film_inserimento *ins=new Dialog_nuovo_film_inserimento(this);
    ins->show();
}
