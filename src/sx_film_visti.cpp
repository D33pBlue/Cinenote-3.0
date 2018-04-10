#include "sx_film_visti.h"
#include <QtSql>


sx_film_visti::sx_film_visti(QWidget *parent,bool attesi) :
    QWidget(parent)
{
    bg=new QWidget;
    lay=new QVBoxLayout;
    l=new QLabel("Film Visti");
    if(attesi)l->setText("Film Attesi");
    l->setFont(QFont("Times",15));
    displayVisti=new QScrollArea;
    displayVisti->setFrameShape(QFrame::NoFrame);
    griglia=new QGridLayout;


    QSqlQuery q;
    if(attesi)
        q.exec("select * from film where visto=0 order by voto desc;");
    else
        q.exec("select * from film where visto=1 order by voto desc;");

    int r=0,c=0,numFilm=0;
    while(q.next()){
    QSqlQuery q2,q3,q4;
    q2.exec(QString("select regista from direzione where film=")+q.value(0).toString());
    q3.exec(QString("select genere from gen where film=")+q.value(0).toString());
    if(!attesi){
    q4.exec(QString("select note from visione where film=")+q.value(0).toString());
    q4.next();
    }
    q2.next();
    q3.next();
    QString reg=q2.value(0).toString();
    QString gen=q3.value(0).toString();
    QString note=(attesi)? q.value(6).toString() : q4.value(0).toString();
    QString vooto=(attesi)? QString("Aspettativa: ") : QString("Voto: ");
    vooto+=q.value(5).toString();
    Cartolina *ca=new Cartolina(q.value(0).toInt(),q.value(1).toString(),q.value(4).toInt(),vooto,reg,gen,note);
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
    l->setText(QString("Film Visti [")+QString::number(numFilm)+QString("]"));
    if(attesi)
        l->setText(QString("Film Attesi [")+QString::number(numFilm)+QString("]"));
    griglia->setMargin(0);
    bg->setMinimumHeight(250*(r));
    bg->setMinimumWidth(750);
    bg->setLayout(griglia);
    displayVisti->setWidget(bg);
    lay->addWidget(l);
    lay->addWidget(displayVisti);
    this->setLayout(lay);
}


sx_film_visti::~sx_film_visti(){
    delete l;
    for(int i=0;i<elca.size();i++)delete elca[i];
    delete griglia;
    delete bg;
    delete displayVisti;
    delete lay;
}
