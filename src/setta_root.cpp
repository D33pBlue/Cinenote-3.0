#include "setta_root.h"
#include "ui_setta_root.h"
#include <iostream>
#include <fstream>
using namespace std;

setta_root::setta_root(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::setta_root)
{
    ui->setupUi(this);
    completadir=new QCompleter(this);
    completadir->setModel(new QDirModel(completadir));
    ui->lineEdit->setCompleter(completadir);
    //compl2=new QCompleter(this);
    //compl2->setModel(new QDirModel(compl2));
    //ui->lineEdit_2->setCompleter(compl2);
    //compl3=new QCompleter(this);
    //compl3->setModel(new QDirModel(compl3));
    //ui->lineEdit_3->setCompleter(compl3);
}

setta_root::~setta_root()
{
    delete ui;
}

void setta_root::on_buttonBox_accepted()
{
if(ui->lineEdit->text().size()>1){
    ofstream out("settings.cinenote");
    out<<ui->lineEdit->text().toStdString()<<endl;
    //out<<ui->lineEdit_2->text().toStdString()<<endl;
    //out<<ui->lineEdit_3->text().toStdString();
    out.close();
}
}
