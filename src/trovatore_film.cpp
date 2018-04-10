#include "trovatore_film.h"
#include "dialog_info_regista.h"
#include "dialog_info_film.h"
#include "dialog_info_genere.h"
#include "dialog_info_serie.h"
#include "dialog_info_libro.h"
#include "dialog_info_scrittore.h"

trovatore_film::trovatore_film(datitrovatore cosa,QWidget *parent) :
    QDialog(parent)
{
    ok=0;
    cer=0;
    tit=0;
    annulla=0;
    setMinimumSize(QSize(350,100));
    setMaximumSize(QSize(350,100));
    padre=parent;
    settaLayout(cosa);
}


void trovatore_film::cerca_Film(){
    QSqlQuery q;
    q.exec(QString("select id from film where upper(titolo) like upper(\"%")+cer->text()+QString("%\") order by length(titolo);"));
    //select * from film where upper(titolo) like upper('%la casa%') order by length(titolo);
    if(q.next()){
        Dialog_info_film *info=new Dialog_info_film(q.value(0).toInt(),padre);
        info->show();
        close();
    }
    else
        cer->clear();
}

void trovatore_film::cerca_serie(){
    QSqlQuery q;
    q.exec(QString("select id from serie where upper(nome) like upper(\"%")+cer->text()+QString("%\") order by length(nome);"));
    if(q.next()){
        Dialog_info_serie *info=new Dialog_info_serie(q.value(0).toInt(),padre);
        info->show();
        deleteLater();
    }
    else
        cer->clear();

}

void trovatore_film::cerca_Libro(){
    QSqlQuery q;
    q.exec(QString("select id from libro where upper(titolo) like upper(\"%")+cer->text()+QString("%\") order by length(titolo);"));
    if(q.next()){
        Dialog_info_libro *info=new Dialog_info_libro(q.value(0).toInt(),padre);
        info->show();
        deleteLater();
    }
    else
        cer->clear();

}

void trovatore_film::cerca_Autore(){
    QSqlQuery q;
    q.exec(QString("select autore from libro where upper(autore) like upper(\"%")+cer->text()+QString("%\") order by length(autore);"));
    if(q.next()){
        Dialog_info_scrittore *info=new Dialog_info_scrittore(q.value(0).toString(),padre);
        info->show();
        deleteLater();
    }
    else
        cer->clear();

}

void trovatore_film::cerca_Regista(){
    Dialog_info_regista *info=new Dialog_info_regista(cer->text(),padre);
    info->show();
    close();
}

void trovatore_film::cerca_Genere(){
    Dialog_info_genere *info=new Dialog_info_genere(cer->text(),padre);
    info->show();
    close();
}

void trovatore_film::settaLayout(datitrovatore tipo){
    cancella();
    tit=new QLabel(this);
    tit->setGeometry(10,10,350,25);
    tit->setFont(QFont("Times",18));
    cer=new QLineEdit(this);
    cer->setGeometry(20,40,300,25);
    ok=new QPushButton("Cerca",this);
    ok->setGeometry(290,70,50,20);
    annulla=new QPushButton("Annulla",this);
    annulla->setGeometry(230,70,50,20);
    connect(annulla,SIGNAL(clicked()),this,SLOT(close()));
    switch (tipo) {
    case cercaregista:
        tit->setText("Cerca Regista");
         setWindowTitle("Cerca regista");
         connect(ok,SIGNAL(clicked()),this,SLOT(cerca_Regista()));
        break;
    case cercafilm:
        tit->setText("Cerca Film");
        setWindowTitle("Cerca film");
        connect(ok,SIGNAL(clicked()),this,SLOT(cerca_Film()));
        break;
    case cercaserie:
        tit->setText("Cerca Serie");
        setWindowTitle("Cerca serie");
        connect(ok,SIGNAL(clicked()),this,SLOT(cerca_serie()));
        break;
    case cercalibro:
        tit->setText("Cerca Libro");
        setWindowTitle("Cerca libro");
        connect(ok,SIGNAL(clicked()),this,SLOT(cerca_Libro()));
        break;
    case cercaautore:
        tit->setText("Cerca Autore");
        setWindowTitle("Cerca autore");
        connect(ok,SIGNAL(clicked()),this,SLOT(cerca_Autore()));
        break;
    case cercagenere:
        tit->setText("Cerca Genere");
         setWindowTitle("Cerca genere");
         connect(ok,SIGNAL(clicked()),this,SLOT(cerca_Genere()));
        break;
    }

}


void trovatore_film::cancella(){
    if(ok)delete ok;
    ok=0;
    if(annulla)delete annulla;
    annulla=0;
    if(cer)delete cer;
    cer=0;
    if(tit)delete tit;
    tit=0;
}

trovatore_film::~trovatore_film(){
    cancella();
}
