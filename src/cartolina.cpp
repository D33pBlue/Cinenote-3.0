#include "cartolina.h"
#include "funzioni.h"
#include <iostream>
using namespace std;

Cartolina::Cartolina(int _id,QString titolo,int anno,QString voto,QString regis,QString gene,QString desc,QWidget *parent,bool libro) :
    EtichettaCliccabile(parent)
{
    setFrameShape(QFrame::Box);
    //setStyleSheet("background-color:rgb(214,214,214);");
    setMaximumHeight(250);
    setMinimumHeight(250);
    lay=new QHBoxLayout;
    pic=new QLabel;
    dx=new QWidget;
    dxlay=new QVBoxLayout;
    if(libro)
        pic->setPixmap(fun::imaglibri(titolo));
    else
        pic->setPixmap(QPixmap(fun::imag(titolo)));
    pic->setFrameShape(QFrame::Box);
    pic->setGeometry(0,0,150,216);
    pic->setScaledContents(1);
    pic->setMaximumWidth(150);
    pic->setMaximumHeight(216);
    tit=new QLabel(titolo);
    reg=new QLabel(regis);
    ann=new QLabel(QString::number(anno));
    vot=new QLabel(voto);
    //cout<<"voto: "<<voto<<endl;
    ge=new QLabel(gene);
    descri=new QTextBrowser;
    descri->setText(desc);
    dxlay->addWidget(tit);
    dxlay->addWidget(ann);
    dxlay->addWidget(reg);
    dxlay->addWidget(ge);
    dxlay->addWidget(vot);
    dxlay->addWidget(descri);
    lay->addWidget(pic);
    dx->setLayout(dxlay);
    lay->addWidget(dx);
    setLayout(lay);
    id=_id;
    if(libro)
        connect(this,SIGNAL(clicked()),this,SLOT(selezionelibro()));
    else
        connect(this,SIGNAL(clicked()),this,SLOT(selezionefilm()));
}

Cartolina::~Cartolina(){
    delete pic;
    delete descri;
    delete tit;
    delete ge;
    delete ann;
    delete vot;
    delete reg;
    delete dxlay;
    delete dx;
    delete lay;
}
