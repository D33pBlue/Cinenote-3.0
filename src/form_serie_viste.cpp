#include "form_serie_viste.h"
#include "ui_form_serie_viste.h"
#include "dialog_info_serie.h"
#include "funzioni.h"

Form_serie_viste::Form_serie_viste(int id,QWidget *parent) :
    EtichettaCliccabile(parent),
    ui(new Ui::Form_serie_viste)
{
    ui->setupUi(this);
    _id=id;
    connect(this,SIGNAL(clicked()),this,SLOT(vedi()));
    QSqlQuery q;
    q.exec(QString("select * from serie where id=")+QString::number(id));
    q.next();
    ui->nome->setText(q.value(1).toString());
    ui->pic->setPixmap(QPixmap(fun::imagserie(_id)));
    ui->descri->setText(q.value(2).toString());
    ui->stagioni->setText(QString("Stagioni uscite: ")+q.value(5).toString());
    ui->voto->setText(QString("Voto: ")+q.value(6).toString());
    setMaximumHeight(250);
    setMinimumHeight(250);
    ui->pic->setScaledContents(1);
    ui->pic->setFrameShape(QFrame::Box);
    setFrameShape(QFrame::Box);
}

Form_serie_viste::~Form_serie_viste()
{
    delete ui;
}


void Form_serie_viste::vedi(){
    Dialog_info_serie *info=new Dialog_info_serie(_id,this);
    info->show();
}
