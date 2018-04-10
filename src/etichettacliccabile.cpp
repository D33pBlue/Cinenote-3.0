#include "etichettacliccabile.h"
#include "dialog_info_film.h"
#include "dialog_info_regista.h"
#include "dialog_info_serie.h"
#include "dialog_info_libro.h"
#include "dialog_info_scrittore.h"
#include <iostream>
using namespace std;

EtichettaCliccabile::EtichettaCliccabile(QWidget *parent) :
    QLabel(parent)
{
    id=-1;
    QWidget::setAttribute(Qt::WA_TranslucentBackground);
}


void EtichettaCliccabile::mousePressEvent(QMouseEvent *e){
    emit clicked();
}

void EtichettaCliccabile::selezionefilm(){
    //cout<<"selezionato film: "<<id<<endl;
    Dialog_info_film *info=new Dialog_info_film(id,this);
    info->show();
}

void EtichettaCliccabile::selezioneregista(){
    Dialog_info_regista *info=new Dialog_info_regista(reg,this);
    info->show();
}

void EtichettaCliccabile::selezionelibro(){
    Dialog_info_libro *info=new Dialog_info_libro(id,this);
    info->show();
}

void EtichettaCliccabile::selezioneserie(){
   Dialog_info_serie *info=new Dialog_info_serie(id,this);
   info->show();
}

void EtichettaCliccabile::selezionescrittore(){
    Dialog_info_scrittore *scr=new Dialog_info_scrittore(reg,this);
    scr->show();
}
