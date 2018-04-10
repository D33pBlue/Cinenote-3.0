#include "dialog_modifica_regista.h"
#include "ui_dialog_modifica_regista.h"
#include <iostream>
using namespace std;

Dialog_modifica_regista::Dialog_modifica_regista(QString nome,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog_modifica_regista)
{
    ui->setupUi(this);
    setWindowTitle("Modifica regista");
    _nome=nome;
    lay=new QGridLayout;
    tit=new QLabel(nome);
    lay->addWidget(tit,0,1);
    QSqlQuery q;
    q.exec(QString("select * from regista where upper(nome)=upper(\"")+nome+QString("\");"));
    q.next();
    lnas=new QLabel("Anno nascita:");
    lay->addWidget(lnas,1,0);
    nas=new QLineEdit;
    nas->setText(q.value(1).toString());
    lay->addWidget(nas,1,1);
    lmor=new QLabel("Anno morte:");
    lay->addWidget(lmor,2,0);
    mor=new QLineEdit;
    mor->setText(q.value(2).toString());
    lay->addWidget(mor,2,1);
    ldescri=new QLabel("Descrizione:");
    lay->addWidget(ldescri,3,0);
    descri=new QTextEdit;
    descri->setText(q.value(6).toString());
    lay->addWidget(descri,3,1);
    back=new QPushButton;
    back->setText("Back");
    lay->addWidget(back,4,1);
    salva=new QPushButton;
    salva->setText("Salva");
    lay->addWidget(salva,4,0);
    connect(back,SIGNAL(clicked()),this,SLOT(close()));
    connect(salva,SIGNAL(clicked()),this,SLOT(modificatore()));
    setLayout(lay);
}


void Dialog_modifica_regista::modificatore(){
    QSqlQuery q;
    QString txq=QString("update regista set nascita=")+nas->text();
    txq+=QString(" where upper(nome)=upper(\"")+_nome+QString("\");");
    if(nas->text().size()==4){q.exec(txq);
    //cout<<txq.toStdString()<<endl;
    }
    txq=QString("update regista set morte=")+mor->text();
    txq+=QString(" where upper(nome)=upper(\"")+_nome+QString("\");");
    if(mor->text().size()==4){q.exec(txq);
    //cout<<txq.toStdString()<<endl;
    }
    txq=QString("update regista set descrizione=\"")+descri->toPlainText();
    txq+=QString("\" where upper(nome)=upper(\"")+_nome+QString("\");");
    q.exec(txq);
    //cout<<txq.toStdString()<<endl;
    close();
}

Dialog_modifica_regista::~Dialog_modifica_regista()
{
    delete ui;
    delete tit;
    delete nas;
    delete lnas;
    delete mor;
    delete lmor;
    delete descri;
    delete ldescri;
    delete back;
    delete salva;
    delete lay;
}
