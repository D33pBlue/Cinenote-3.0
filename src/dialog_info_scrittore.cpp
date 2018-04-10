#include "dialog_info_scrittore.h"
#include "ui_dialog_info_scrittore.h"
#include "dialog_info_libro.h"
#include "funzioni.h"

Dialog_info_scrittore::Dialog_info_scrittore(QString nome,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog_info_scrittore)
{
    ui->setupUi(this);
    _nome=nome;
    connect(ui->back,SIGNAL(clicked()),this,SLOT(deleteLater()));
    QSqlQuery q;
    q.exec(QString("select count(*) from libro where autore=\"")+nome+QString("\";"));
    q.next();
    ui->numlibri->setText(QString("#Libri: ")+q.value(0).toString());
    q.exec(QString("select count(*),avg(voto) from libro where letto=1 and autore=\"")+nome+QString("\";"));
    q.next();
    ui->numletti->setText(QString("#Letti: ")+q.value(0).toString());
    ui->medialibri->setText(QString("media letti: ")+q.value(1).toString());
    ui->pic->setPixmap(fun::imaglibri(nome));
    ui->pic->setFrameShape(QFrame::Box);
    ui->pic->setScaledContents(1);
    ui->tabella->setColumnCount(2);
    ui->tabella->hideColumn(1);
    ui->tabella->setColumnWidth(0,500);
    ui->nomecogn->setText(nome);
    setWindowTitle(nome);
    ui->tabella->horizontalHeader()->hide();
    ui->tabella->verticalHeader()->hide();
    q.exec(QString("select titolo,id,letto from libro where autore=\"")+nome+QString("\" order by voto desc;"));
    while(q.next()){
        ui->tabella->insertRow(ui->tabella->rowCount());
        QTableWidgetItem *it=new QTableWidgetItem(q.value(0).toString());
        if(!q.value(2).toBool())it->setTextColor(QColor(255,0,0));
        ui->tabella->setItem(ui->tabella->rowCount()-1,0,it);
        ele.append(it);
        it=new QTableWidgetItem(q.value(1).toString());
        ui->tabella->setItem(ui->tabella->rowCount()-1,1,it);
        ele.append(it);
    }
    connect(ui->tabella,SIGNAL(cellClicked(int,int)),this,SLOT(vedilibro(int,int)));
}

void Dialog_info_scrittore::vedilibro(int r, int c){
    Dialog_info_libro *inf=new Dialog_info_libro(ui->tabella->item(r,1)->text().toInt(),this);
    inf->show();
}

Dialog_info_scrittore::~Dialog_info_scrittore()
{
    delete ui;
    for(int i=0;i<ele.size();i++)delete ele[i];
}
