#include "esito_query.h"
#include "ui_esito_query.h"

Esito_query::Esito_query(QWidget *parent,QSqlQuery *q) :
    QDialog(parent),
    ui(new Ui::Esito_query)
{
    ui->setupUi(this);
    setWindowTitle("Query...");
    setBackgroundRole(QPalette::BrightText);
    QVBoxLayout *lay=new QVBoxLayout;
    tab=new QScrollArea(this);
    setMinimumWidth(600);
    QString t("");
    int col=-18;
    while (q->next()) {
        col=q->record().count();
        for(int i=0;i<col;i++)t+=QString("[")+q->value(i).toString()+QString("] ");
        t+=QString("\n");
    }
    if(col==-18)t=QString("Nessuna risposta.. \nErrore o valore null..");
    l=new QLabel;
    l->setText(t);
    tab->setWidget(l);

    nuovaq=new QLineEdit;
    connect(nuovaq,SIGNAL(returnPressed()),this,SLOT(nuovaQuery()));

    lay->addWidget(tab);
    lay->addWidget(nuovaq);
    this->setLayout(lay);
}

Esito_query::~Esito_query()
{
    delete l;
    delete nuovaq;
    delete tab;
    delete ui;
}


void Esito_query::nuovaQuery(){
    delete l;
    l=new QLabel;
    QSqlQuery q;
    q.exec(nuovaq->text());
    QString t("");
    int col=-18;
    while (q.next()) {
        col=q.record().count();
        for(int i=0;i<col;i++)t+=QString("[")+q.value(i).toString()+QString("] ");
        t+=QString("\n");
    }
    if(col==-18)t=QString("Nessuna risposta.. \nErrore o valore null..");
    l->setText(t);

    tab->setWidget(l);
    nuovaq->clear();
}
