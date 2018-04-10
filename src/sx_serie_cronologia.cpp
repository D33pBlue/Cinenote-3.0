#include "sx_serie_cronologia.h"
#include "form_serie_mese.h"
#include <QtSql>
#include <iostream>
using namespace std;

sx_serie_cronologia::sx_serie_cronologia(QWidget *parent) :
    QWidget(parent)
{
    lay=new QVBoxLayout(this);
    tit=new QLabel("Cronologia serie",this);
    tit->setFont(QFont("Times",15));
    area=new QScrollArea(this);

    QWidget *bg=new QWidget(this);
    QVBoxLayout *lbg=new QVBoxLayout(this);
    bg->setLayout(lbg);
    int altezza=0,numero=0;
    QSqlQuery q;
    q.exec("select min(datainizio),max(datafine) from visionestagione;");
    q.next();
    QDate curr=QDate::fromString(q.value(1).toString(),"yyyy-MM-dd");
    QDate fine=QDate::fromString(q.value(0).toString(),"yyyy-MM-dd");


    while(curr>=fine){
    Form_serie_mese *fo=new Form_serie_mese(this);
    numero+=fo->settamese(curr);
    lbg->addWidget(fo);
    altezza++;
    curr=curr.addMonths(-1);
    }

    tit->setText(QString("Cronologia serie [visioni: ")+QString::number(numero)+QString("]"));
    bg->setMinimumSize(770,altezza*200);
    area->setWidget(bg);

    lay->addWidget(tit);
    lay->addWidget(area);
    setLayout(lay);
}
