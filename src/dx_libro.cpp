#include "dx_libro.h"
#include "pannello_dx.h"
#include "main_cinenote.h"
#include "dialog_nuovo_libro.h"
#include "dialog_info_libro.h"

dx_libro::dx_libro(QWidget *parent) :
    QWidget(parent)
{
    Pannello_dx *padre=reinterpret_cast<Pannello_dx*>(parent);
    t=new QLabel(this);
    t->setGeometry(0,0,280,555);
    t->setPixmap(QPixmap(main_cinenote::radice+QString("risorse/wall6.png")));
    t->setScaledContents(1);
    this->setMinimumHeight(555);
    this->setMaximumHeight(555);
    nuova=new QPushButton(this);
    nuova->setText("Nuovo");
    nuova->setGeometry(200,490,70,30);
    connect(nuova,SIGNAL(clicked()),this,SLOT(nuovolibro()));
    viste=new QPushButton(this);
    viste->setText("Letti");
    viste->setGeometry(200,450,70,30);
    connect(viste,SIGNAL(clicked()),padre,SLOT(libriletti()));
    attese=new QPushButton(this);
    attese->setText("Attesi");
    attese->setGeometry(200,410,70,30);
    connect(attese,SIGNAL(clicked()),padre,SLOT(libriattesi()));
    cer=new QLineEdit(this);
    cer->setText("cerca libro");
    cer->setGeometry(120,530,150,20);
    connect(cer,SIGNAL(selectionChanged()),cer,SLOT(clear()));
    connect(cer,SIGNAL(returnPressed()),this,SLOT(cercalibro()));
    crono=new QPushButton(this);
    crono->setText("Cronologia");
    crono->setGeometry(200,370,70,30);
    connect(crono,SIGNAL(clicked()),padre,SLOT(sezionelibricronologia()));
}

void dx_libro::cercalibro(){
    QSqlQuery q;
    q.exec(QString("select id from libro where upper(titolo) like upper(\"%")+cer->text()+QString("%\") order by length(titolo);"));
    if(q.next()){
    Dialog_info_libro *inf=new Dialog_info_libro(q.value(0).toInt(),this);
    inf->show();
    }
    cer->clear();
}

void dx_libro::nuovolibro(){
    Dialog_nuovo_libro *nu=new Dialog_nuovo_libro(this);
    nu->show();
}
