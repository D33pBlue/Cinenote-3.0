#include "sx_serie_home.h"
#include <QtSql>
#include "funzioni.h"

sx_serie_home::sx_serie_home(QWidget *parent) :
    QWidget(parent)
{
    lay=new QVBoxLayout(this);
    t=new QLabel("Serie Aperte",this);
    t->setFont(QFont("Times",15));

    bg_dispo=new QWidget;
    int posx=0,fila=0,posy=0,riga=0;
    QSqlQuery q;
    if(q.exec("select l.nome,l.id from serie as l where l.terminata=0 and l.iniziata=1 order by l.voto desc;")){
        while (q.next()) {
            EtichettaCliccabile *tex=new EtichettaCliccabile(bg_dispo);
            tex->setPixmap(QPixmap(fun::imagserie(q.value(1).toInt())));
            tex->setGeometry(posx,posy,145,208);
            tex->setScaledContents(1);
            tex->id=q.value(1).toInt();
            tex->setFrameShape(QFrame::Box);
            connect(tex,SIGNAL(clicked()),tex,SLOT(selezioneserie()));
            posx+=155;
            fila++;
            if(fila>0 && fila%5==0){
                riga++;
                posx=0;
                posy+=218;
            }
            vettore_dispo.append(tex);
        }
    }

    riga++;
    if(fila%5==0)riga--;
    bg_dispo->setGeometry(0,0,765,riga*218);
    disp=new QScrollArea(this);
    disp->setFrameShape(QFrame::NoFrame);
    disp->setWidget(bg_dispo);


    posx=0;posy=0;
    bg_atte=new QWidget;
    bg_atte->setGeometry(0,0,700,187);
    QSqlQuery q2;
    if(q2.exec("select nome,id from serie where iniziata=0 order by random() limit 5;")){
        while (q2.next()) {
            EtichettaCliccabile *tex=new EtichettaCliccabile(bg_atte);
            tex->setPixmap(QPixmap(fun::imagserie(q2.value(1).toInt())));
            tex->setGeometry(posx,posy,130,187);
            tex->setScaledContents(1);
            tex->setFrameShape(QFrame::Box);
            tex->id=q2.value(1).toInt();
            connect(tex,SIGNAL(clicked()),tex,SLOT(selezioneserie()));
            posx+=140;
            vettore_atte.append(tex);
        }
    }

    atte=new QScrollArea(this);
    atte->setFrameShape(QFrame::NoFrame);
    atte->setWidget(bg_atte);

    des2=new QLabel("Consigli random:");
    des2->setFont(QFont("Times",15));
    lay->addWidget(t);
    lay->addWidget(disp);
    lay->addWidget(des2);
    lay->addWidget(atte);


    this->setLayout(lay);
}

sx_serie_home::~sx_serie_home(){
    delete des2;
    delete t;
    for(int i=0;i<vettore_dispo.size();i++)delete vettore_dispo[i];
    for(int i=0;i<vettore_atte.size();i++)delete vettore_atte[i];
    delete bg_dispo;
    delete bg_atte;
    delete disp;
    delete atte;
    delete lay;
}
