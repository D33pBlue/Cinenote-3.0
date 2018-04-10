#include "sx_film_classifica_generi.h"
#include "dialog_info_genere.h"

sx_film_classifica_generi::sx_film_classifica_generi(QWidget *parent) :
    QWidget(parent)
{
    lay=new QVBoxLayout;
    tit=new QLabel("Classifica Generi");
    tit->setFont(QFont("Times",15));
    lay->addWidget(tit);
    tab=new QTableWidget;
    tab->setColumnCount(4);
    tab->setHorizontalHeaderLabels(QStringList()<<"Nome"<<"Media"<<"Visti"<<"Numero");
    tab->setColumnWidth(0,400);
    lay->addWidget(tab);
    QSqlQuery q;
    q.exec("select nome,media,numvisti,numfilm from genere order by numvisti desc;");
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
    connect(tab,SIGNAL(cellClicked(int,int)),this,SLOT(vediGenere(int,int)));
    setLayout(lay);
}

void sx_film_classifica_generi::vediGenere(int r, int c){
    Dialog_info_genere *ifg=new Dialog_info_genere(tab->item(r,0)->text(),this);
    ifg->show();
}

sx_film_classifica_generi::~sx_film_classifica_generi(){
    for(int i=0;i<eltab.size();i++)delete eltab[i];
    delete tab;
    delete tit;
    delete lay;
}
