#include "main_cinenote.h"
#include "setta_root.h"
#include <QApplication>
#include <fstream>
#include <string>
#include <iostream>
#include <QtSql>
using namespace std;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    string root="",datab="",cover="";
    ifstream inp("settings.cinenote");
    while(!inp){
        setta_root *roos=new setta_root;
        roos->exec();
        delete roos;
        inp.open("settings.cinenote");
    }
    getline(inp,root);
    //getline(inp,datab);
    //getline(inp,cover);
    datab = root+"risorse/";
    inp.close();
    main_cinenote::radice=QString::fromStdString(root);
    main_cinenote::db=QSqlDatabase::addDatabase("QSQLITE");
    main_cinenote::db.setDatabaseName(QString::fromStdString(datab)+QString("cinenote.db"));
    main_cinenote::db.open();
    main_cinenote w;
    w.percorsoCover=QString::fromStdString(cover);
    w.setWindowTitle("Cinenote 3.0  [by BF]");
    QString indi=main_cinenote::radice+QString("risorse/icona_cinenote2.jpg");
    w.setWindowIcon(QIcon(indi));
    w.show();

    return a.exec();
}
