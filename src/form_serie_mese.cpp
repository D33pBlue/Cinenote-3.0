#include "form_serie_mese.h"
#include "ui_form_serie_mese.h"
#include "dialog_info_serie.h"

Form_serie_mese::Form_serie_mese(QWidget *parent) :
    QLabel(parent),
    ui(new Ui::Form_serie_mese)
{
    ui->setupUi(this);
}

Form_serie_mese::~Form_serie_mese()
{
    delete ui;
    for(int i=0;i<el.size();i++)delete el[i];
}

int Form_serie_mese::settamese(QDate data){
    int num=0;
    ui->tableWidget->setColumnCount(2);
    ui->tableWidget->setColumnWidth(0,700);
    ui->tableWidget->verticalHeader()->hide();
    ui->tableWidget->horizontalHeader()->hide();
    ui->tableWidget->hideColumn(1);
    QSqlQuery q;
    QString tq("select s.nome,v.stagione,v.modo,s.id from serie as s join visionestagione as v on s.id=v.serie where substr(datainizio,0,8)<=\"");
    tq+=data.toString("yyyy-MM")+QString("\" and substr(datafine,0,8)>=\"");
    tq+=data.toString("yyyy-MM")+QString("\" order by s.nome,v.stagione;");
    q.exec(tq);
    while(q.next()){
        ui->tableWidget->insertRow(ui->tableWidget->rowCount());
        QTableWidgetItem *g=new QTableWidgetItem(q.value(0).toString()+QString(" - stagione ")+q.value(1).toString());
        QTableWidgetItem *ii=new QTableWidgetItem(q.value(3).toString());
        ui->tableWidget->setItem(ui->tableWidget->rowCount()-1,0,g);
        ui->tableWidget->setItem(ui->tableWidget->rowCount()-1,1,ii);
        if(q.value(2).toString().mid(0,2)==QString("Tv"))
            ui->tableWidget->item(ui->tableWidget->rowCount()-1,0)->setBackgroundColor(QColor(153,255,204));
        else if(q.value(2).toString().mid(0,2)==QString("Pc"))
            ui->tableWidget->item(ui->tableWidget->rowCount()-1,0)->setBackgroundColor(QColor(255,153,204));
        if(q.value(2).toString().mid(3,11)==QString("mentre esce"))
            ui->tableWidget->item(ui->tableWidget->rowCount()-1,0)->setFont(QFont("Times",14,QFont::Bold));
        el.append(g);
        num++;
    }
    connect(ui->tableWidget,SIGNAL(cellClicked(int,int)),this,SLOT(vedi(int,int)));
    ui->mese->setText(data.toString("MMMM yyyy")+QString(" [")+QString::number(num)+QString("]"));
    return num;
}

void Form_serie_mese::vedi(int r, int c){
    Dialog_info_serie *info=new Dialog_info_serie(ui->tableWidget->item(r,1)->text().toInt(),this);
    info->show();
}
