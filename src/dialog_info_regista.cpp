#include "dialog_info_regista.h"
#include "ui_dialog_info_regista.h"
#include "funzioni.h"
#include "dialog_info_film.h"
#include "dialog_modifica_regista.h"
#include <iostream>
using namespace std;


Dialog_info_regista::Dialog_info_regista(QString reg,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog_info_regista)
{
    ui->setupUi(this);
    connect(this,SIGNAL(chiusore()),this,SLOT(deleteLater()));
    setGeometry(0,0,700,600);
    QSqlQuery q,q2;
    //select * from film where upper(titolo) like upper('%la casa%') order by length(titolo);
    q.exec(QString("select * from regista where upper(nome) like upper(\"%")+reg+QString("%\") order by length(nome);"));

    if(! q.next()){emit chiusore();}
    nome=new QLabel(q.value(0).toString(),this);
    _nomeregi=nome->text();
    q2.exec(QString("select f.titolo,f.visto,f.voto from film as f join direzione as d on f.id=d.film where regista=\"")+nome->text()+QString("\" order by f.visto desc,f.voto desc;"));
    setWindowTitle(q.value(0).toString());
    nome->setFont(QFont("Times",15));
    pic=new QLabel(this);
    pic->setFrameShape(QFrame::Box);
    pic->setPixmap(QPixmap(fun::imag(q.value(0).toString())));
    pic->setScaledContents(1);
    datenm=new QLabel(QString("( ")+q.value(1).toString()+QString(" - ")+q.value(2).toString()+QString(" )"),this);
    descri=new QTextBrowser(this);
    descri->setText(q.value(6).toString());
    numeri=new QLabel(this);
    QString txnumeri("#film: ");
    txnumeri+=q.value(3).toString()+QString(" \t#visti: ");
    txnumeri+=q.value(4).toString()+QString(" \tmedia: ")+q.value(5).toString();
    numeri->setText(txnumeri);
    numeri->setFont(QFont("Times",14));
    filmi=new QTableWidget(this);
    filmi->setColumnCount(2);
    filmi->setHorizontalHeaderLabels(QStringList()<<"Film"<<"Voto");
    filmi->setColumnWidth(0,320);
    filmi->setColumnWidth(1,320);
    while(q2.next()){
        int k=filmi->rowCount();
        filmi->insertRow(k);
        QTableWidgetItem *fi=new QTableWidgetItem;
        QTableWidgetItem *fi2=new QTableWidgetItem;
        fi->setText(q2.value(0).toString());
        //cout<<q2.value(0).toString().toStdString()<<endl;
        if(q2.value(1).toBool())
            fi2->setText(q2.value(2).toString());
        else{
            fi2->setText(QString("Non ancora visto!"));
            fi->setTextColor(QColor(255,0,0));
            fi2->setTextColor(QColor(255,0,0));
        }
        filmi->setItem(k,0,fi);
        filmi->setItem(k,1,fi2);
        itemtab.push_back(fi);
        itemtab.push_back(fi2);
    }
    nome->setGeometry(218,0,700,30);
    pic->setGeometry(0,0,210,300);
    datenm->setGeometry(218,30,700,20);
    numeri->setGeometry(218,55,700,30);
    descri->setGeometry(218,115,377,180);
    filmi->setGeometry(10,320,680,270);
    connect(filmi,SIGNAL(cellClicked(int,int)),this,SLOT(mostrafilm(int,int)));
    modifica=new QPushButton(this);
    modifica->setText("Modifica");
    modifica->setGeometry(600,200,98,40);
    back=new QPushButton(this);
    back->setText("Back");
    back->setGeometry(600,250,98,40);
    connect(back,SIGNAL(clicked()),this,SLOT(deleteLater()));
    connect(modifica,SIGNAL(clicked()),this,SLOT(fai_modifiche()));
}

Dialog_info_regista::~Dialog_info_regista()
{
    delete ui;
    delete modifica;
    delete back;
    delete nome;
    delete pic;
    delete datenm;
    delete descri;
    delete numeri;
    for(int i=0;i<itemtab.size();i++)delete itemtab[i];
    delete filmi;
}

void Dialog_info_regista::mostrafilm(int r, int c){
    QSqlQuery q;
    q.exec(QString("select id from film where upper(titolo)=upper(\"")+filmi->item(r,0)->text()+QString("\");"));
    if(q.next()){
        Dialog_info_film *info=new Dialog_info_film(q.value(0).toInt(),this);
        info->show();
    }

}


void Dialog_info_regista::fai_modifiche(){
    Dialog_modifica_regista *moo=new Dialog_modifica_regista(_nomeregi,this);
    moo->show();
}






