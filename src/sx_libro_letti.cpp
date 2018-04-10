#include "sx_libro_letti.h"
#include <QtSql>

sx_libro_letti::sx_libro_letti(QWidget *parent,bool attesi) :
    QWidget(parent)
{
    bg=new QWidget;
    lay=new QVBoxLayout;
    l=new QLabel("Libri letti e iniziati");
    if(attesi)l->setText("Libri attesi");
    l->setFont(QFont("Times",15));
    displayVisti=new QScrollArea;
    displayVisti->setFrameShape(QFrame::NoFrame);
    griglia=new QGridLayout;

    QSqlQuery q;
    if(attesi)
        q.exec("select * from libro where letto=0 order by voto desc;");
    else
        q.exec("select * from libro where letto=1 order by voto desc;");

    int r=0,c=0,numFilm=0;
    while(q.next()){
    QSqlQuery q3;
    q3.exec(QString("select genere from generelibro where libro=")+q.value(0).toString());
    q3.next();
    QString reg=q.value(2).toString();//q2.value(0).toString();
    QString gen=q3.value(0).toString();
    QString note=q.value(6).toString();
    QString vooto=(attesi)? QString("Aspettativa: ") : QString("Voto: ");
    vooto+=q.value(5).toString();
    Cartolina *ca=new Cartolina(q.value(0).toInt(),q.value(1).toString(),q.value(3).toInt(),vooto,reg,gen,note,0,1);
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
    l->setText(QString("Libri letti e iniziati [")+QString::number(numFilm)+QString("]"));
    if(attesi)
        l->setText(QString("Libri attesi [")+QString::number(numFilm)+QString("]"));
    griglia->setMargin(0);
    bg->setMinimumHeight(250*(r));
    bg->setMinimumWidth(750);
    bg->setLayout(griglia);
    displayVisti->setWidget(bg);
    lay->addWidget(l);
    lay->addWidget(displayVisti);
    this->setLayout(lay);
}

sx_libro_letti::~sx_libro_letti(){
    delete l;
    for(int i=0;i<elca.size();i++)delete elca[i];
    delete griglia;
    delete bg;
    delete displayVisti;
    delete lay;
}
