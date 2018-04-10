#include "pannello_dx.h"
#include "esito_query.h"
#include "dx_film.h"
#include "dx_serie.h"
#include "dx_libro.h"
#include <iostream>
using namespace std;

Pannello_dx::Pannello_dx(sezione sez,QWidget *parent) :
    QWidget(parent)
{
    padre=reinterpret_cast<main_cinenote*>(parent);
    ins=0;
    pannello=0;
    lv=0;
    tastofilm=0;
    tastolibri=0;
    tastoserie=0;
    settaLayout(sez);
}


void Pannello_dx::settaLayout(sezione sez){
    cancellaLayout();
    lv=new QVBoxLayout;
    lv->setMargin(0);
    //setStyleSheet("background-color:rgb(214,214,214);");
    setMinimumWidth(275);
    setMaximumWidth(275);
    ins=new QTextEdit;
    ins->setText("\t[Inserisci Query]");
    ins->setFrameShape(QFrame::NoFrame);
    connect(ins,SIGNAL(selectionChanged()),ins,SLOT(clear()));
    connect(ins,SIGNAL(textChanged()),this,SLOT(RispondiQuery()));
    switch (sez) {
    case film:
        pannello=new dx_film(this);
        break;
    case serie:
        pannello=new dx_serie(this);
        break;
    case libri:
        pannello=new dx_libro(this);
        break;
    }
    lv->addWidget(pannello);
    lv->addWidget(ins);
    this->setLayout(lv);
    tastofilm=new EtichettaCliccabile(this);
    tastofilm->setPixmap(QPixmap(main_cinenote::radice+QString("risorse/film_icon2.png")));
    tastofilm->setGeometry(0,505,50,50);
    tastofilm->setScaledContents(1);
    tastoserie=new EtichettaCliccabile(this);
    tastoserie->setPixmap(QPixmap(main_cinenote::radice+QString("risorse/tv_icon2.png")));
    tastoserie->setGeometry(0,455,50,50);
    tastoserie->setScaledContents(1);
    tastolibri=new EtichettaCliccabile(this);
    tastolibri->setPixmap(QPixmap(main_cinenote::radice+QString("risorse/book_icon.png")));
    tastolibri->setGeometry(0,405,50,50);
    tastolibri->setScaledContents(1);
    connect(tastofilm,SIGNAL(clicked()),this,SLOT(sezioneFilm()));
    connect(tastolibri,SIGNAL(clicked()),this,SLOT(sezioneLibri()));
    connect(tastoserie,SIGNAL(clicked()),this,SLOT(sezioneSerie()));
}



void Pannello_dx::RispondiQuery(){
    QString que=ins->toPlainText();
    if(que.size()>2 && que.at(que.size()-1)=='\n' && que.at(que.size()-2)==';')
    {
    QSqlQuery q;
    q.exec(que);
    Esito_query *resp=new Esito_query(this,&q);
    resp->show();
    }
}

Pannello_dx::~Pannello_dx(){
    //cout<<"Distruttore pannello_dx"<<endl;
    cancellaLayout();
}

void Pannello_dx::cancellaLayout(){
    //cout<<"pannello_dx::cancellaLayout()"<<endl;
    if(ins)delete ins;
    ins=0;
    if(pannello)delete pannello;
    pannello=0;
    if(tastofilm)delete tastofilm;
    tastofilm=0;
    if(tastoserie)delete tastoserie;
    tastoserie=0;
    if(tastolibri)delete tastolibri;
    tastolibri=0;
    if(lv)delete lv;
    lv=0;
}

void Pannello_dx::sezioneFilm(){
    main_cinenote::io_sezione=film;
    main_cinenote::io_specifica=home;
    padre->cambiaSezione();
}

void Pannello_dx::sezioneFilmVisti(){
    main_cinenote::io_sezione=film;
    main_cinenote::io_specifica=visti;
    padre->cambiaSezione();
}

void Pannello_dx::sezioneFilmAttesi(){
    main_cinenote::io_sezione=film;
    main_cinenote::io_specifica=attesi;
    padre->cambiaSezione();
}

void Pannello_dx::sezioneFilmCronologia(){
    main_cinenote::io_sezione=film;
    main_cinenote::io_specifica=cronologia;
    padre->cambiaSezione();
}

void Pannello_dx::sezioneLibri(){
    main_cinenote::io_sezione=libri;
    main_cinenote::io_specifica=home;
    padre->cambiaSezione();
}

void Pannello_dx::sezioneSerie(){
    main_cinenote::io_sezione=serie;
    main_cinenote::io_specifica=home;
    padre->cambiaSezione();
}

void Pannello_dx::selezioneSerieViste(){
    main_cinenote::io_sezione=serie;
    main_cinenote::io_specifica=visti;
    padre->cambiaSezione();
}


void Pannello_dx::selezioneSerieAttese(){
    main_cinenote::io_sezione=serie;
    main_cinenote::io_specifica=attesi;
    padre->cambiaSezione();
}

void Pannello_dx::selezioneSerieCronologia(){
    main_cinenote::io_sezione=serie;
    main_cinenote::io_specifica=cronologia;
    padre->cambiaSezione();
}

void Pannello_dx::libriletti(){
    main_cinenote::io_sezione=libri;
    main_cinenote::io_specifica=visti;
    padre->cambiaSezione();
}

void Pannello_dx::libriattesi(){
    main_cinenote::io_sezione=libri;
    main_cinenote::io_specifica=attesi;
    padre->cambiaSezione();
}

void Pannello_dx::sezionelibricronologia(){
    main_cinenote::io_sezione=libri;
    main_cinenote::io_specifica=cronologia;
    padre->cambiaSezione();
}
