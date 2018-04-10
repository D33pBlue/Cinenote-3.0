#include "dialog_info_film.h"
#include "ui_dialog_info_film.h"
#include "dialog_visionato_film.h"
#include "dialog_modifica_film.h"
#include "metti_in_classifica.h"
#include "funzioni.h"
#include <QtSql>

Dialog_info_film::Dialog_info_film(int id,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog_info_film)
{
    ui->setupUi(this);
    _id=id;
    QSqlQuery q,q2,q3;
    q.exec(QString("select * from film where id=")+QString::number(id));
    q2.exec(QString("select genere from gen where film=")+QString::number(id));
    q3.exec(QString("select regista from direzione where film=")+QString::number(id));
    q.next();
    q2.next();
    _titolo=QString(q.value(1).toString());
    visto=q.value(2).toBool();
    setWindowTitle(_titolo);
    titolo=new QLabel(this);
    titolo->setText(QString("[")+QString::number(id)+QString("] ")+_titolo);
    titolo->setGeometry(218,0,700,30);
    titolo->setFont(QFont("Times",18));
    pic=new QLabel(this);
    pic->setPixmap(QPixmap(fun::imag(_titolo)));
    pic->setScaledContents(1);
    pic->setGeometry(0,0,210,300);
    pic->setFrameShape(QFrame::Box);
    anre=new EtichettaCliccabile(this);
    QString annoregi=q.value(4).toString();
    while (q3.next()) {
        anre->reg=q3.value(0).toString();
        annoregi+=QString(" - ")+q3.value(0).toString();
    }

    anre->setText(annoregi);
    anre->setGeometry(218,35,700,20);
    connect(anre,SIGNAL(clicked()),anre,SLOT(selezioneregista()));

    QString _generi=q2.value(0).toString();
    while (q2.next()) {
        _generi+=QString(" - ")+q2.value(0).toString();
    }
    generi=new QLabel(_generi,this);
    generi->setGeometry(218,55,700,20);
    votoconsiglio=new QLabel(this);
    votoconsiglio->setGeometry(218,75,700,30);
    votoconsiglio->setFont(QFont("Times",13));
    descri=new QTextBrowser(this);
    descri->setText(q.value(6).toString());
    descri->setGeometry(218,115,377,180);
    visionato=new QPushButton(this);
    visionato->setText("Visto");
    visionato->setGeometry(600,200,98,40);
    modifica=new QPushButton(this);
    modifica->setText("Modifica");
    modifica->setGeometry(600,150,98,40);
    back=new QPushButton(this);
    back->setText("Back");
    back->setGeometry(600,250,98,40);
    classifica=new QPushButton(this);
    classifica->setText("Classifica");
    classifica->setGeometry(600,100,98,40);
    connect(back,SIGNAL(clicked()),this,SLOT(deleteLater()));
    connect(visionato,SIGNAL(clicked()),this,SLOT(visionatore()));
    connect(modifica,SIGNAL(clicked()),this,SLOT(modificatore()));
    connect(classifica,SIGNAL(clicked()),this,SLOT(metti_classifica()));
    QString _votoc;

    if(visto){
        setMinimumSize(700,600);
        setMaximumSize(700,600);
        _votoc=QString("Voto: ")+q.value(5).toString()+QString(" - Consigliato da ");
        QSqlQuery qvisi;
        widvisioni=new QWidget();
        layvisio=new QGridLayout();
        areavisioni=new QScrollArea(this);
        areavisioni->setGeometry(10,320,680,270);
        int numvisio=0;
        qvisi.exec(QString("select * from visione where film=")+QString::number(id));
        while(qvisi.next()){
            Visione *vis=new Visione(id,qvisi.value(1).toString(),qvisi.value(5).toString(),qvisi.value(4).toDouble(),qvisi.value(2).toString(),qvisi.value(3).toString());
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
        _votoc=QString("Aspettativa: ")+q.value(5).toString()+QString(" - Consigliato da ");
    }

    _votoc+=(q.value(7).toString()==QString(""))? QString("nessuno in particolare") : q.value(7).toString();
    votoconsiglio->setText(_votoc);

}


Dialog_info_film::~Dialog_info_film()
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
    delete anre;
    delete generi;
    delete votoconsiglio;
    delete descri;
    delete modifica;
    delete visionato;
    delete back;
}

void Dialog_info_film::visionatore(){
    Dialog_visionato_film *vi=new Dialog_visionato_film(_id,this);
    vi->show();
}

void Dialog_info_film::modificatore(){
    Dialog_modifica_film *moo=new Dialog_modifica_film(_id,this);
    moo->show();
}

void Dialog_info_film::metti_classifica(){
    Metti_in_classifica* clas=new Metti_in_classifica(_id,this);
    clas->show();
}
