
#include <QString>
#include "funzioni.h"



QString fun::imag(QString s){
    QString res=main_cinenote::radice+QString("risorse/imm/");
    QString ap("c'a");
    for(int i=0;i<s.size();i++){
        if(s.at(i)==ap.at(1))res+=QString("_");
        else res+=s.at(i);
    }
    res+=QString(".jpg");
    return res;
}

QString fun::imaglibri(QString s){
    QString res=main_cinenote::radice+QString("risorse/immLibri/");
    QString ap("c'a");
    for(int i=0;i<s.size();i++){
        if(s.at(i)==ap.at(1))res+=QString("_");
        else res+=s.at(i);
    }
    res+=QString(".jpg");
    return res;
}


QString fun::imagserie(int id){
    QSqlQuery q;
    q.exec(QString("select s.nome,(select case when stagione isnull then 1 else max(stagione) end from visionestagione where serie=s.id) from serie as s where s.id=")+QString::number(id)+QString(";"));
    q.next();
    QString s=q.value(0).toString()+QString(" s")+q.value(1).toString();
    QString res=main_cinenote::radice+QString("risorse/immSerie/");
    QString ap("c'a");
    for(int i=0;i<s.size();i++){
        if(s.at(i)==ap.at(1))res+=QString("_");
        else res+=s.at(i);
    }
    res+=QString(".jpg");
    return res;
}

QString fun::imagserie(int id,int stagione){
    QSqlQuery q;
    q.exec(QString("select s.nome,(select case when stagione isnull then 1 else max(stagione) end from visionestagione where serie=s.id) from serie as s where s.id=")+QString::number(id)+QString(";"));
    q.next();
    QString s=q.value(0).toString()+QString(" s")+QString::number(stagione);
    QString res=main_cinenote::radice+QString("risorse/immSerie/");
    QString ap("c'a");
    for(int i=0;i<s.size();i++){
        if(s.at(i)==ap.at(1))res+=QString("_");
        else res+=s.at(i);
    }
    res+=QString(".jpg");
    return res;
}
