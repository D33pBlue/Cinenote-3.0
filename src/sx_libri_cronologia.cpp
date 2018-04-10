#include "sx_libri_cronologia.h"
#include "ui_sx_libri_cronologia.h"
#include "dialog_info_libro.h"

sx_libri_cronologia::sx_libri_cronologia(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::sx_libri_cronologia)
{
    ui->setupUi(this);
    ui->tableWidget->setColumnCount(4);
    ui->tableWidget->hideColumn(3);
    ui->tableWidget->verticalHeader()->hide();
    ui->tableWidget->setHorizontalHeaderLabels(QStringList()<<"Finito"<<"Iniziato"<<"Titolo");
    ui->tableWidget->setColumnWidth(0,200);
    ui->tableWidget->setColumnWidth(1,200);
    ui->tableWidget->setColumnWidth(2,350);
    connect(ui->tableWidget,SIGNAL(cellClicked(int,int)),this,SLOT(vedilib(int,int)));

    QSqlQuery q;
    q.exec("select v.datainizio,v.datafine,f.titolo,f.id from libro as f join lettura as v on f.id=v.libro order by v.datafine desc;");
    while(q.next()){
        QTableWidget *tab=ui->tableWidget;
        QDate dat=q.value(0).toDate();
        QTableWidgetItem *_data;
        if(dat.isValid())
            _data=new QTableWidgetItem(dat.toString("dddd d MMMM yyyy"));
        else _data=new QTableWidgetItem("Sconosciuta");
        QDate dat2=q.value(1).toDate();
        QTableWidgetItem *_data2;
        if(dat2.isValid())
            _data2=new QTableWidgetItem(dat2.toString("dddd d MMMM yyyy"));
        else _data2=new QTableWidgetItem("Sconosciuta");
        QTableWidgetItem *_titolo=new QTableWidgetItem(q.value(2).toString());
        QTableWidgetItem *_idf=new QTableWidgetItem(q.value(3).toString());
        tab->insertRow(tab->rowCount());
        tab->setItem(tab->rowCount()-1,0,_data2);
        tab->setItem(tab->rowCount()-1,1,_data);
        tab->setItem(tab->rowCount()-1,2,_titolo);
        tab->setItem(tab->rowCount()-1,3,_idf);
        ele.append(_data);
         ele.append(_data2);
          ele.append(_titolo);
           ele.append(_idf);
    }
}

sx_libri_cronologia::~sx_libri_cronologia()
{
    delete ui;
    for(int i=0;i<ele.size();i++)delete ele[i];
}

void sx_libri_cronologia::vedilib(int r, int c){
    Dialog_info_libro *inf=new Dialog_info_libro(ui->tableWidget->item(r,3)->text().toInt(),this);
    inf->show();
}
