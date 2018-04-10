#include "sx_serie_viste.h"
#include <QtSql>

sx_serie_viste::sx_serie_viste(bool attesi,QWidget *parent) :
    QWidget(parent)
{
    bg=new QWidget;
    lay=new QVBoxLayout;
    l=new QLabel("Serie viste e iniziate");
    if(attesi)l->setText("Serie Attese");
    l->setFont(QFont("Times",15));
    displayVisti=new QScrollArea;
    displayVisti->setFrameShape(QFrame::NoFrame);
    griglia=new QGridLayout;

    QSqlQuery q;
    if(attesi)
        q.exec("select id from serie where iniziata=0 order by voto desc;");
    else
        q.exec("select id from serie where iniziata=1 order by voto desc;");

    int r=0,c=0,numFilm=0;
    while(q.next()){
    Form_serie_viste *ca=new Form_serie_viste(q.value(0).toInt());
    elca.push_back(ca);
    //ca->setGeometry(0,0,380,250);
    griglia->addWidget(ca,r,c);
    c++;
    if(c==2){
        c=0;
        r++;
    }
    numFilm++;
    }
    l->setText(QString("Serie Viste e iniziate [")+QString::number(numFilm)+QString("]"));
    if(attesi)
        l->setText(QString("Serie Attese [")+QString::number(numFilm)+QString("]"));
    griglia->setMargin(0);
    bg->setMinimumHeight(250*(r));
    bg->setMinimumWidth(750);
    bg->setLayout(griglia);
    displayVisti->setWidget(bg);
    lay->addWidget(l);
    lay->addWidget(displayVisti);
    this->setLayout(lay);
}


sx_serie_viste::~sx_serie_viste(){
    delete l;
    for(int i=0;i<elca.size();i++)delete elca[i];
    delete griglia;
    delete bg;
    delete displayVisti;
    delete lay;
}
