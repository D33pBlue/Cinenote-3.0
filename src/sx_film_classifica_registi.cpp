#include "sx_film_classifica_registi.h"
#include "dialog_info_regista.h"

sx_film_classifica_registi::sx_film_classifica_registi(QWidget *parent) :
    QWidget(parent)
{
    lay=new QVBoxLayout;
    tit=new QLabel("Classifica Registi (con almeno 2 visioni)");
    tit->setFont(QFont("Times",15));
    lay->addWidget(tit);
    tab=new QTableWidget;
    tab->setColumnCount(4);
    tab->setHorizontalHeaderLabels(QStringList()<<"Nome"<<"Voto"<<"Media"<<"Visti");
    tab->setColumnWidth(0,400);
    lay->addWidget(tab);
    QSqlQuery q;
    q.exec("select nome,(media-1+numvisti/5.)as voo,media,numvisti from regista where numvisti>1 order by voo desc;");
    while(q.next()){
        tab->insertRow(tab->rowCount());
        QTableWidgetItem *an=new QTableWidgetItem(q.value(0).toString());
        QTableWidgetItem *av=new QTableWidgetItem(q.value(1).toString());
        QTableWidgetItem *am=new QTableWidgetItem(q.value(2).toString());
        QTableWidgetItem *avs=new QTableWidgetItem(q.value(3).toString());
        eltab.push_back(an);
        eltab.push_back(av);
        eltab.push_back(am);
        eltab.push_back(avs);
        tab->setItem(tab->rowCount()-1,0,an);
        tab->setItem(tab->rowCount()-1,1,av);
        tab->setItem(tab->rowCount()-1,2,am);
        tab->setItem(tab->rowCount()-1,3,avs);
    }
    connect(tab,SIGNAL(cellClicked(int,int)),this,SLOT(mostraAutore(int,int)));
    setLayout(lay);
}

void sx_film_classifica_registi::mostraAutore(int r, int c){
    Dialog_info_regista *reg=new Dialog_info_regista(tab->item(r,0)->text(),this);
    reg->show();
}


sx_film_classifica_registi::~sx_film_classifica_registi(){
    for(int i=0;i<eltab.size();i++)delete eltab[i];
    delete tab;
    delete tit;
    delete lay;
}
