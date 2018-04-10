#include "sx_film_classifica.h"
#include "dialog_info_film.h"

sx_film_classifica::sx_film_classifica(QWidget *parent) :
    QWidget(parent)
{
    lay=new QVBoxLayout;
    tit=new QLabel("Classifica film migliori");
    tit->setFont(QFont("Times",20));
    lay->addWidget(tit);
    tab=new QTableWidget;
    tab->setColumnCount(3);
    tab->setHorizontalHeaderLabels(QStringList()<<"Posizione"<<"Film"<<"id");
    tab->setColumnWidth(1,400);
    lay->addWidget(tab);
    QSqlQuery q;
    q.exec("select c.posizione,f.titolo,c.film from classifica as c join film as f on c.film=f.id order by c.posizione;");
    while(q.next()){
        tab->insertRow(tab->rowCount());
        QTableWidgetItem *e1=new QTableWidgetItem(q.value(0).toString());
        QTableWidgetItem *e2=new QTableWidgetItem(q.value(1).toString());
        QTableWidgetItem *e3=new QTableWidgetItem(q.value(2).toString());
        eltab.push_back(e1);
        eltab.push_back(e2);
        eltab.push_back(e3);
        tab->setItem(tab->rowCount()-1,0,e1);
        tab->setItem(tab->rowCount()-1,1,e2);
        tab->setItem(tab->rowCount()-1,2,e3);
    }
    connect(tab,SIGNAL(cellClicked(int,int)),this,SLOT(vediFilm(int,int)));
    setLayout(lay);
}


sx_film_classifica::~sx_film_classifica(){
    for(int i=0;i<eltab.size();i++) delete eltab[i];
    delete tab;
    delete tit;
    delete lay;
}

void sx_film_classifica::vediFilm(int r, int c){
    Dialog_info_film* info=new Dialog_info_film(tab->item(r,2)->text().toInt(),this);
    info->show();
}
