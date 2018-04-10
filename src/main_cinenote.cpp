#include "main_cinenote.h"
#include "ui_main_cinenote.h"
#include "dialog_nuovo_film_inserimento.h"
#include "dialog_nuova_serie.h"
#include "dialog_nuovo_libro.h"
#include "trovatore_film.h"
#include "setta_root.h"
#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;


QString main_cinenote::radice;
QSqlDatabase main_cinenote::db;
sezione main_cinenote::io_sezione;
specifica main_cinenote::io_specifica;

main_cinenote::main_cinenote(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::main_cinenote)
{
    ui->setupUi(this);
    logo=0;
    pandx=0;
    pansx=0;
    lay=0;
    bg=0;
    trovatoreFilm=0;
    io_sezione=film;
    io_specifica=home;
    settaLayout(film,home);
}

main_cinenote::~main_cinenote()
{
    //cout<<"distruttore main_cinenote"<<endl;
    cancellaLayout();
    delete ui;
}

void main_cinenote::cancellaLayout(){
    //cout<<"main_cinenote::cancellaLayout()"<<endl;
    if(logo)delete logo;
    logo=0;
    if(pandx)delete pandx;
    pandx=0;
    if(pansx)delete pansx;
    pansx=0;
    if(lay)delete lay;
    lay=0;
    if(bg)delete bg;
    bg=0;
}


void main_cinenote::settaLayout(sezione sez, specifica spec){
    cancellaLayout();
    setStyleSheet("QMainWindow{background-color:rgb(214,214,214);margin:0;}");
    bg=new QWidget;
    lay=new QHBoxLayout;
    lay->setMargin(0);
    pansx=new Pannello_sx(sez,spec);
    pandx=new Pannello_dx(sez,this);
    lay->addWidget(pansx);
    lay->addWidget(pandx);
    bg->setLayout(lay);
    logo=new QLabel("Cinenote 3.0",bg);
    logo->setFont(QFont("Times",15));
    logo->setGeometry(975,0,200,17);
    logo->setStyleSheet("background-color:rgb(255,255,127);");
    this->setCentralWidget(bg);
    if(sez==film){
        trovatoreFilm=new QShortcut(QKeySequence("Ctrl+f"),pansx);
        connect(trovatoreFilm,SIGNAL(activated()),this,SLOT(on_actionFilm_triggered()));
        nuovoshofilm=new QShortcut(QKeySequence("Ctrl+n"),pansx);
        connect(nuovoshofilm,SIGNAL(activated()),this,SLOT(on_actionNuovo_2_triggered()));

    }
    else if(sez==serie){
        trovatoreFilm=new QShortcut(QKeySequence("Ctrl+f"),pansx);
        connect(trovatoreFilm,SIGNAL(activated()),this,SLOT(on_actionTrova_serie_triggered()));
        nuovashoserie=new QShortcut(QKeySequence("Ctrl+n"),pansx);
        connect(nuovashoserie,SIGNAL(activated()),this,SLOT(on_actionNuovaSerie_triggered()));
    }
    else if(sez==libri){
        trovatoreFilm=new QShortcut(QKeySequence("Ctrl+f"),pansx);
        connect(trovatoreFilm,SIGNAL(activated()),this,SLOT(on_actionLibro_triggered()));
        nuovashoserie=new QShortcut(QKeySequence("Ctrl+n"),pansx);
        connect(nuovashoserie,SIGNAL(activated()),this,SLOT(on_actionNuovo_Libro_triggered()));
    }
    registashofilm=new QShortcut(QKeySequence("Ctrl+r"),pansx);
    connect(registashofilm,SIGNAL(activated()),this,SLOT(on_actionRegista_triggered()));
}

void main_cinenote::cambiaSezione(){
    settaLayout(io_sezione,io_specifica);
}


void main_cinenote::on_actionVisti_triggered()
{
    settaLayout(film,visti);
}


void main_cinenote::on_actionHome_triggered()
{
    settaLayout(film,home);
}

void main_cinenote::on_actionAttesi_triggered()
{
    settaLayout(film,attesi);
}

void main_cinenote::on_actionNuovo_2_triggered()
{
    Dialog_nuovo_film_inserimento *ins=new Dialog_nuovo_film_inserimento(this);
    ins->show();
}

void main_cinenote::on_actionRoot_triggered()
{
    setta_root *ro=new setta_root(this);
    ro->show();
}

void main_cinenote::on_actionCronologia_triggered()
{
    settaLayout(film,cronologia);
}

void main_cinenote::on_actionRegisti_triggered()
{
    settaLayout(film,autori);
}

void main_cinenote::on_actionGeneri_triggered()
{
    settaLayout(film,generi);
}

void main_cinenote::on_actionCover_triggered()
{
    string com="loffice "+percorsoCover.toStdString()+"film.odg &";
    system(com.c_str());
}

void main_cinenote::on_actionFilm_2_triggered()
{
    settaLayout(film,classifica);
}

void main_cinenote::on_actionRegista_triggered()
{
    trovatore_film *trov=new trovatore_film(cercaregista,this);
    trov->show();
}

void main_cinenote::on_actionFilm_triggered()
{
    trovatore_film *trov=new trovatore_film(cercafilm,this);
    trov->show();
}

void main_cinenote::on_actionGenere_triggered()
{
    trovatore_film *trov=new trovatore_film(cercagenere,this);
    trov->show();
}

void main_cinenote::on_actionNuovaSerie_triggered()
{
    Dialog_nuova_serie *nu=new Dialog_nuova_serie(this);
    nu->show();
}

void main_cinenote::on_actionHomeSerie_triggered()
{
    settaLayout(serie,home);
}

void main_cinenote::on_actionHome_Libri_triggered()
{
    settaLayout(libri,home);
}

void main_cinenote::on_actionViste_triggered()
{
    settaLayout(serie,visti);
}

void main_cinenote::on_actionAttese_serie_triggered()
{
    settaLayout(serie,attesi);
}

void main_cinenote::on_actionTrova_serie_triggered()
{
    trovatore_film *trov=new trovatore_film(cercaserie,this);
    trov->show();
}

void main_cinenote::on_actionCronologia_Serie_triggered()
{
    settaLayout(serie,cronologia);
}

void main_cinenote::on_actionNuovo_Libro_triggered()
{
    Dialog_nuovo_libro *nu=new Dialog_nuovo_libro(this);
    nu->show();
}

void main_cinenote::on_actionLetti_Libri_triggered()
{
    settaLayout(libri,visti);
}

void main_cinenote::on_actionAttesi_Libri_triggered()
{
    settaLayout(libri,attesi);
}

void main_cinenote::on_actionLibro_triggered()
{
    trovatore_film *trov=new trovatore_film(cercalibro,this);
    trov->show();
}

void main_cinenote::on_actionAutore_triggered()
{
    trovatore_film *trov=new trovatore_film(cercaautore,this);
    trov->show();
}

void main_cinenote::on_actionCronologia_Libri_triggered()
{
    settaLayout(libri,cronologia);
}


void main_cinenote::on_actionTestuale_Serie_triggered()
{
    string com="gedit "+percorsoCover.toStdString()+"visti.py &";
    system(com.c_str());
}

void main_cinenote::on_actionTestuale_Libri_triggered()
{
    string com="gedit "+percorsoCover.toStdString()+"libri.py &";
    system(com.c_str());
}
