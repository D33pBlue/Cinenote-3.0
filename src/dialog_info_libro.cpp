#include "dialog_info_libro.h"
#include "ui_dialog_info_libro.h"
#include "dialog_modifica_libro.h"
#include "dialog_letto_libro.h"
#include "funzioni.h"
#include <QtSql>

Dialog_info_libro::Dialog_info_libro(int id,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog_info_libro)
{
    ui->setupUi(this);
    _id=id;
    QSqlQuery q,q2;
    q.exec(QString("select * from libro where id=")+QString::number(id));
    q2.exec(QString("select genere from generelibro where libro=")+QString::number(id));
    q.next();
    q2.next();
    _titolo=QString(q.value(1).toString());
    visto=q.value(4).toBool();
    setWindowTitle(_titolo);
    titolo=new QLabel(this);
    titolo->setText(QString("[")+QString::number(id)+QString("] ")+_titolo);
    titolo->setGeometry(218,0,700,30);
    titolo->setFont(QFont("Times",18));
    pic=new QLabel(this);
    pic->setPixmap(QPixmap(fun::imaglibri(_titolo)));
    pic->setScaledContents(1);
    pic->setGeometry(0,0,210,300);
    pic->setFrameShape(QFrame::Box);
    //pic->setStyleSheet("QLabel{border-radius:8px;}");
    anre=new EtichettaCliccabile(this);
    QString annoregi=q.value(3).toString();
    anre->reg=q.value(2).toString();
    annoregi+=QString(" - ")+q.value(2).toString();
    anre->setText(annoregi);
    anre->setGeometry(218,35,700,20);
    connect(anre,SIGNAL(clicked()),anre,SLOT(selezionescrittore()));

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
    visionato->setText("Letto");
    visionato->setGeometry(600,200,98,40);
    modifica=new QPushButton(this);
    modifica->setText("Modifica");
    modifica->setGeometry(600,150,98,40);
    back=new QPushButton(this);
    back->setText("Back");
    back->setGeometry(600,250,98,40);
    connect(back,SIGNAL(clicked()),this,SLOT(deleteLater()));
    connect(visionato,SIGNAL(clicked()),this,SLOT(letturasalva()));
    connect(modifica,SIGNAL(clicked()),this,SLOT(modificadialog()));
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
        qvisi.exec(QString("select * from lettura where libro=")+QString::number(id));
        while(qvisi.next()){
            Lettura *vis=new Lettura(_id,qvisi.value(1).toInt(),qvisi.value(2).toString(),qvisi.value(3).toString(),qvisi.value(4).toString(),qvisi.value(5).toString());
            layvisio->addWidget(vis,numvisio,0);
            numvisio++;
            visioni.push_back(vis);
        }
        widvisioni->setGeometry(0,0,660,260*numvisio);
        widvisioni->setLayout(layvisio);
        areavisioni->setWidget(widvisioni);
        descrivisio=new QLabel(QString("Dettagli Letture [")+QString::number(numvisio)+QString("]"),this);
        descrivisio->setGeometry(5,303,400,15);
    }else{
        setMinimumSize(700,300);
        setMaximumSize(700,300);
        _votoc=QString("Aspettativa: ")+q.value(5).toString()+QString(" - Consigliato da ");
    }

    _votoc+=(q.value(7).toString()==QString(""))? QString("nessuno in particolare") : q.value(7).toString();
    votoconsiglio->setText(_votoc);
}

void Dialog_info_libro::modificadialog(){
    Dialog_modifica_libro *mod=new Dialog_modifica_libro(_id,this);
    mod->show();
}

void Dialog_info_libro::letturasalva(){
    Dialog_letto_libro *le=new Dialog_letto_libro(_id,this);
    le->show();
}

Dialog_info_libro::~Dialog_info_libro()
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
