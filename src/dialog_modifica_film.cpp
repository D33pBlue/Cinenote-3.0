#include "dialog_modifica_film.h"
#include "ui_dialog_modifica_film.h"
#include <iostream>
using namespace std;

Dialog_modifica_film::Dialog_modifica_film(int id,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog_modifica_film)
{
    ui->setupUi(this);
    setWindowTitle("Modifica film");
    _id=id;
    QSqlQuery q;
    q.exec(QString("select * from film where id=")+QString::number(_id));
    q.next();
    lay=new QGridLayout;
    ltit=new QLabel("Titolo:");
    lay->addWidget(ltit,0,0);
    tit=new QLineEdit;
    tit->setText(q.value(1).toString());
    lay->addWidget(tit,0,1);
    lanno=new QLabel("Anno:");
    lay->addWidget(lanno,1,0);
    anno=new QLineEdit;
    anno->setText(q.value(4).toString());
    lay->addWidget(anno,1,1);
    lvoto=(q.value(2).toBool())? new QLabel("Voto:") : new QLabel("Aspettativa:");
    lay->addWidget(lvoto,2,0);
    voto=new QLineEdit;
    voto->setText(q.value(5).toString());
    lay->addWidget(voto,2,1);
    lconsigli=new QLabel("Consigliato da:");
    lay->addWidget(lconsigli,3,0);
    consigli=new QLineEdit;
    consigli->setText(q.value(7).toString());
    lay->addWidget(consigli,3,1);
    ldescri=new QLabel("Descrizione:");
    lay->addWidget(ldescri,4,0);
    descri=new QTextEdit;
    descri->setText(q.value(6).toString());
    lay->addWidget(descri,4,1);
    ldispo=new QLabel("Disponibile:");
    lay->addWidget(ldispo,5,0);
    dispo=new QCheckBox;
    if(q.value(3).toBool())dispo->setChecked(1);
    lay->addWidget(dispo,5,1);
    salva=new QPushButton;
    salva->setText("Salva");
    lay->addWidget(salva,6,0);
    connect(salva,SIGNAL(clicked()),this,SLOT(salva_modifiche()));
    annulla=new QPushButton;
    annulla->setText("Annulla");
    lay->addWidget(annulla,6,1);
    connect(annulla,SIGNAL(clicked()),this,SLOT(close()));
    setLayout(lay);
}


void Dialog_modifica_film::salva_modifiche(){
    QSqlQuery q;
    QString txq=QString("update film set titolo=\"")+tit->text()+QString("\"");
    txq+=QString(" where id=")+QString::number(_id)+QString(";");
    q.exec(txq);
    //cout<<txq.toStdString()<<endl;
    txq=QString("update film set anno=\"")+anno->text()+QString("\"");
    txq+=QString(" where id=")+QString::number(_id)+QString(";");
    q.exec(txq);
    //cout<<txq.toStdString()<<endl;
    txq=QString("update film set voto=")+voto->text();
    txq+=QString(" where id=")+QString::number(_id)+QString(";");
    q.exec(txq);
    //cout<<txq.toStdString()<<endl;
    txq=QString("update film set cosigliatoda=\"")+consigli->text()+QString("\"");
    txq+=QString(" where id=")+QString::number(_id)+QString(";");
    q.exec(txq);
    //cout<<txq.toStdString()<<endl;
    txq=QString("update film set descrizione=\"")+descri->toPlainText()+QString("\"");
    txq+=QString(" where id=")+QString::number(_id)+QString(";");
    q.exec(txq);
    //cout<<txq.toStdString()<<endl;
    if(dispo->isChecked()){
        txq=QString("update film set disponibile=1");
        txq+=QString(" where id=")+QString::number(_id)+QString(";");
        q.exec(txq);
        //cout<<txq.toStdString()<<endl;
    }else{
        txq=QString("update film set disponibile=0");
        txq+=QString(" where id=")+QString::number(_id)+QString(";");
        q.exec(txq);
        //cout<<txq.toStdString()<<endl;
    }

    close();
}

Dialog_modifica_film::~Dialog_modifica_film()
{
    delete ui;
    delete tit;
    delete ltit;
    delete anno;
    delete lanno;
    delete voto;
    delete lvoto;
    delete consigli;
    delete lconsigli;
    delete descri;
    delete ldescri;
    delete dispo;
    delete ldispo;
    delete annulla;
    delete salva;
    delete lay;
}
