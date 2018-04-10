#include "dialog_modifica_visione_film.h"
#include "ui_dialog_modifica_visione_film.h"
#include <iostream>
using namespace std;

Dialog_modifica_visione_film::Dialog_modifica_visione_film(int id,QString dat,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog_modifica_visione_film)
{
    ui->setupUi(this);
    _id=id;
    _dat=dat;
    setWindowTitle("- Modifica Visione -");
    lay=new QGridLayout;
    QSqlQuery q;
    q.exec(QString("select * from visione where film=")+QString::number(id)+QString(" and data='")+dat+QString("';"));
    q.next();
    tit=new QLabel(QString("Film ID: ")+q.value(0).toString());
    data=new QLabel;
    data->setText(q.value(1).toString());
    dove=new QLineEdit;
    dove->setText(q.value(5).toString());
    voto=new QLineEdit;
    voto->setText(q.value(4).toString());
    note=new QTextEdit;
    note->setText(q.value(3).toString());
    attore=new QLineEdit;
    attore->setText(q.value(2).toString());
    _data=new QLabel("Data");
    _dove=new QLabel("Luogo");
    _note=new QLabel("Note");
    _attore=new QLabel("Attore");
    _voto=new QLabel("Voto");
    vai=new QPushButton;
    annulla=new QPushButton;
    vai->setText("Salva");
    annulla->setText("Annulla");
    lay->addWidget(tit,0,1);
    lay->addWidget(_data,1,0);
    lay->addWidget(_dove,2,0);
    lay->addWidget(_attore,3,0);
    lay->addWidget(_note,4,0);
    lay->addWidget(_voto,5,0);
    lay->addWidget(data,1,1);
    lay->addWidget(dove,2,1);
    lay->addWidget(attore,3,1);
    lay->addWidget(note,4,1);
    lay->addWidget(voto,5,1);
    lay->addWidget(vai,6,0);
    lay->addWidget(annulla,6,1);

    setLayout(lay);
    connect(vai,SIGNAL(clicked()),this,SLOT(salva()));
    connect(annulla,SIGNAL(clicked()),this,SLOT(close()));
}

void Dialog_modifica_visione_film::salva(){
    QSqlQuery q;
    QString txq=QString("update visione set attore=\"")+attore->text()+QString("\"");
    txq+=QString(" where film=")+QString::number(_id)+QString(" and data=\"")+_dat+QString("\";");
    q.exec(txq);
    //cout<<txq.toStdString()<<endl;
    txq=QString("update visione set note=\"")+note->toPlainText()+QString("\"");
    txq+=QString(" where film=")+QString::number(_id)+QString(" and data=\"")+_dat+QString("\";");
    q.exec(txq);
   // cout<<txq.toStdString()<<endl;
    txq=QString("update visione set voto=")+voto->text();
    txq+=QString(" where film=")+QString::number(_id)+QString(" and data=\"")+_dat+QString("\";");
    q.exec(txq);
    //cout<<txq.toStdString()<<endl;
    txq=QString("update visione set luogo=\"")+dove->text()+QString("\"");
    txq+=QString(" where film=")+QString::number(_id)+QString(" and data=\"")+_dat+QString("\";");
    q.exec(txq);
    //cout<<txq.toStdString()<<endl;
    close();
}


Dialog_modifica_visione_film::~Dialog_modifica_visione_film()
{
    delete ui;
    delete tit;
    delete data;
    delete dove;
    delete voto;
    delete note;
    delete attore;
    delete _data;
    delete _dove;
    delete _voto;
    delete _note;
    delete _attore;
    delete lay;
    delete vai;
    delete annulla;
}
