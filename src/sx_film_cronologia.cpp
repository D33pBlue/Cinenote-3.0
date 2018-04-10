#include "sx_film_cronologia.h"
#include "dialog_info_film.h"

sx_film_cronologia::sx_film_cronologia(QWidget *parent) :
    QWidget(parent)
{
    tit=new QLabel("Cronologia");
    tit->setFont(QFont("Times",15));
    tab=new QTableWidget;
    lay=new QVBoxLayout;
    //lay->setMargin(0);
    lay->addWidget(tit);
    tab->setColumnCount(3);
    tab->setHorizontalHeaderLabels(QStringList()<<"Data"<<"Titolo"<<"id");
    tab->setColumnWidth(0,200);
    tab->setColumnWidth(1,400);
    //tab->setColumnWidth(3,20);
    connect(tab,SIGNAL(cellClicked(int,int)),this,SLOT(vediFilm(int,int)));
    QSqlQuery q;
    q.exec("select v.data,f.titolo,f.id from film as f join visione as v on f.id=v.film order by v.data desc;");
    while(q.next()){
        QDate dat=q.value(0).toDate();
        QTableWidgetItem *_data;
        if(dat.isValid())
            _data=new QTableWidgetItem(dat.toString("dddd d MMMM yyyy"));
        else _data=new QTableWidgetItem("Sconosciuta");
        QTableWidgetItem *_titolo=new QTableWidgetItem(q.value(1).toString());
        QTableWidgetItem *_idf=new QTableWidgetItem(q.value(2).toString());
        tab->insertRow(tab->rowCount());
        tab->setItem(tab->rowCount()-1,0,_data);
        tab->setItem(tab->rowCount()-1,1,_titolo);
        tab->setItem(tab->rowCount()-1,2,_idf);
        elite.push_back(_data);
        elite.push_back(_titolo);
        elite.push_back(_idf);
    }
    lay->addWidget(tab);
    setLayout(lay);
}

void sx_film_cronologia::vediFilm(int r, int c){
    Dialog_info_film *inf=new Dialog_info_film(tab->item(r,2)->text().toInt(),this);
    inf->show();
}

sx_film_cronologia::~sx_film_cronologia(){
    for(int i=0;i<elite.size();i++)delete elite[i];
    delete tit;
    delete tab;
    delete lay;
}
