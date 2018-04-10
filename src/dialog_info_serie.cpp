#include "dialog_info_serie.h"
#include "ui_dialog_info_serie.h"
#include "dialog_modifica_serie.h"
#include "dialog_vista_serie.h"
#include "funzioni.h"
#include <QtSql>

Dialog_info_serie::Dialog_info_serie(int id,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog_info_serie)
{
    ui->setupUi(this);
    _id=id;
    QSqlQuery q;
    q.exec(QString("select * from serie where id=")+QString::number(id));
    q.next();
    _titolo=q.value(1).toString();
    visto=q.value(3).toBool();
    setWindowTitle(_titolo);
    titolo=new QLabel(this);
    titolo->setText(QString("[")+QString::number(id)+QString("] ")+_titolo);
    titolo->setGeometry(218,0,700,30);
    titolo->setFont(QFont("Times",18));
    pic=new QLabel(this);
    pic->setPixmap(QPixmap(fun::imagserie(id)));
    pic->setScaledContents(1);
    pic->setGeometry(0,0,210,300);
    pic->setFrameShape(QFrame::Box);
    stagionius=new QLabel(QString("Stagioni uscite: ")+q.value(5).toString(),this);
    stagionius->setGeometry(218,35,700,20);
    votoconsiglio=new QLabel(this);
    votoconsiglio->setGeometry(218,75,700,30);
    votoconsiglio->setFont(QFont("Times",13));
    descri=new QTextBrowser(this);
    descri->setText(q.value(2).toString());
    descri->setGeometry(218,115,377,180);
    visionato=new QPushButton(this);
    visionato->setText("Vista");
    visionato->setGeometry(600,200,98,40);
    modifica=new QPushButton(this);
    modifica->setText("Modifica");
    modifica->setGeometry(600,150,98,40);
    back=new QPushButton(this);
    back->setText("Back");
    back->setGeometry(600,250,98,40);
    connect(back,SIGNAL(clicked()),this,SLOT(deleteLater()));
    connect(modifica,SIGNAL(clicked()),this,SLOT(modificaserie()));
    connect(visionato,SIGNAL(clicked()),this,SLOT(visualizzaserie()));

    QString _votoc;
    if(visto){
        terminata=new QPushButton(this);
        terminata->setGeometry(600,100,98,40);
        terminata->setText("Terminata");
        connect(terminata,SIGNAL(clicked()),this,SLOT(settaterminata()));
        setMinimumSize(700,600);
        setMaximumSize(700,600);
        _votoc=QString("Voto: ")+q.value(6).toString()+QString(" - Consigliato da ");
        QSqlQuery qvisi;
        widvisioni=new QWidget();
        layvisio=new QGridLayout();
        areavisioni=new QScrollArea(this);
        areavisioni->setGeometry(10,320,680,270);
        int numvisio=0;
        qvisi.exec(QString("select * from visionestagione where serie=")+QString::number(id)+QString(" order by datainizio;"));
        while(qvisi.next()){
            VisioneStagione *vis=new VisioneStagione(id,qvisi.value(1).toInt(),qvisi.value(2).toString(),qvisi.value(4).toString(),qvisi.value(5).toDouble(),qvisi.value(3).toString(),qvisi.value(6).toString());
            layvisio->addWidget(vis,numvisio,0);
            numvisio++;
            visioni.push_back(vis);
        }
        widvisioni->setGeometry(0,0,660,260*numvisio);
        widvisioni->setLayout(layvisio);
        areavisioni->setWidget(widvisioni);
        descrivisio=new QLabel(QString("Dettagli Visioni [")+QString::number(numvisio)+QString("]"),this);
        descrivisio->setGeometry(5,303,400,15);

    }else{
        setMinimumSize(700,300);
        setMaximumSize(700,300);
        _votoc=QString("Aspettativa: ")+q.value(6).toString()+QString(" - Consigliato da ");
    }

    _votoc+=(q.value(7).toString()==QString(""))? QString("nessuno in particolare") : q.value(7).toString();
    votoconsiglio->setText(_votoc);

}

Dialog_info_serie::~Dialog_info_serie()
{
    if(visto){
        delete descrivisio;
        for(int i=0;i<visioni.size();i++)delete visioni[i];
        delete layvisio;
        delete widvisioni;
        delete areavisioni;
    }
    delete ui;
    delete titolo;
    delete pic;
    delete stagionius;
    delete votoconsiglio;
    delete descri;
    delete modifica;
    delete visionato;
    delete back;
}

void Dialog_info_serie::visualizzaserie(){
    Dialog_vista_serie *vi=new Dialog_vista_serie(_id,this);
    vi->show();
}

void Dialog_info_serie::settaterminata(){
    QSqlQuery q;
    q.exec(QString("update serie set terminata=1 where id=")+QString::number(_id));
}

void Dialog_info_serie::modificaserie(){
    Dialog_modifica_serie *mod=new Dialog_modifica_serie(_id,this);
    mod->show();
}
