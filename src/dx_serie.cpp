#include "dx_serie.h"
#include "pannello_dx.h"
#include "main_cinenote.h"
#include "dialog_nuova_serie.h"
#include "dialog_info_serie.h"

dx_serie::dx_serie(QWidget *parent) :
    QWidget(parent)
{
    Pannello_dx *padre=reinterpret_cast<Pannello_dx*>(parent);
    t=new QLabel(this);
    t->setGeometry(0,0,280,555);
    t->setPixmap(QPixmap(main_cinenote::radice+QString("risorse/wall4.jpg")));
    t->setScaledContents(1);
    this->setMinimumHeight(555);
    this->setMaximumHeight(555);
    nuova=new QPushButton(this);
    nuova->setText("Nuova");
    nuova->setGeometry(200,490,70,30);
    connect(nuova,SIGNAL(clicked()),this,SLOT(inseriscinuova()));
    viste=new QPushButton(this);
    viste->setText("Viste");
    viste->setGeometry(200,450,70,30);
    connect(viste,SIGNAL(clicked()),padre,SLOT(selezioneSerieViste()));
    attese=new QPushButton(this);
    attese->setText("Attese");
    attese->setGeometry(200,410,70,30);
    connect(attese,SIGNAL(clicked()),padre,SLOT(selezioneSerieAttese()));
    cer=new QLineEdit(this);
    cer->setText("cerca serie");
    cer->setGeometry(120,530,150,20);
    connect(cer,SIGNAL(selectionChanged()),cer,SLOT(clear()));
    connect(cer,SIGNAL(returnPressed()),this,SLOT(cercaserie()));
    crono=new QPushButton(this);
    crono->setText("Cronologia");
    crono->setGeometry(200,370,70,30);
    connect(crono,SIGNAL(clicked()),padre,SLOT(selezioneSerieCronologia()));
}

void dx_serie::inseriscinuova(){
    Dialog_nuova_serie *nu=new Dialog_nuova_serie(this);
    nu->show();
}


void dx_serie::cercaserie(){
    QSqlQuery q;
    q.exec(QString("select id from serie where upper(nome) like upper(\"%")+cer->text()+QString("%\") order by length(nome);"));
    if(q.next()){
    Dialog_info_serie *inf=new Dialog_info_serie(q.value(0).toInt(),this);
    inf->show();
    }
    cer->clear();
}




