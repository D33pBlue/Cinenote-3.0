#include "dialog_visionato_film.h"
#include "ui_dialog_visionato_film.h"
#include <iostream>
using namespace std;

Dialog_visionato_film::Dialog_visionato_film(int id,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog_visionato_film)
{
    ui->setupUi(this);
    _id=id;
    setWindowTitle("- Visione -");
    lay=new QGridLayout;
    QSqlQuery q;
    q.exec(QString("select titolo from film where id=")+QString::number(id));
    q.next();
    tit=new QLabel(q.value(0).toString());
    data=new QDateEdit;
    data->setDate(QDate::currentDate());
    dove=new QLineEdit;
    voto=new QLineEdit;
    note=new QTextEdit;
    attore=new QLineEdit;
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


void Dialog_visionato_film::salva(){
    QString datafin=data->date().toString("yyyy-MM-dd");
    if(datafin.size()==10 && voto->text().size()>0){
        QSqlQuery qupd;
        QString co("insert into visione values(");
        co+=QString::number(_id)+QString(",'");
        co+=datafin+QString("',\"")+attore->text()+QString("\",\"");
        co+=note->toPlainText()+QString("\",")+voto->text()+QString(",\"");
        co+=dove->text()+QString("\");");
        qupd.exec(co);
        //cout<<co.toStdString()<<endl;
        co=QString("update film set voto=(select avg(v.voto) from visione as v where v.film=");
        co+=QString::number(_id)+QString(") where id=")+QString::number(_id)+QString(";");
        //cout<<co.toStdString()<<endl;
        qupd.exec(co);
        close();
    }

}

Dialog_visionato_film::~Dialog_visionato_film()
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
