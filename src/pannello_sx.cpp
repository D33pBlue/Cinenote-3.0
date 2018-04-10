#include "pannello_sx.h"
#include "sx_film_home.h"
#include "sx_film_visti.h"
#include "sx_film_cronologia.h"
#include "sx_film_classifica_registi.h"
#include "sx_film_classifica_generi.h"
#include "sx_film_classifica.h"
#include "sx_serie_home.h"
#include "sx_libro_home.h"
#include "sx_serie_viste.h"
#include "sx_serie_cronologia.h"
#include "sx_libro_letti.h"
#include "sx_libri_cronologia.h"

Pannello_sx::Pannello_sx(sezione sez,specifica spec,QWidget *parent) :
    QWidget(parent)
{
    setMinimumWidth(800);
    setMaximumWidth(800);
    oggetto=0;
    lay=0;
    settaLayout(sez,spec);
}


void Pannello_sx::settaLayout(sezione sez, specifica spec){
    cancellaLayout();
    switch (sez) {
    case film:
        switch (spec) {
        case home:
            oggetto=new sx_film_home;
            break;
        case visti:
            oggetto=new sx_film_visti(0,0);
            break;
        case attesi:
            oggetto=new sx_film_visti(0,1);
            break;
        case cronologia:
            oggetto=new sx_film_cronologia;
            break;
        case autori:
            oggetto=new sx_film_classifica_registi;
            break;
        case generi:
            oggetto=new sx_film_classifica_generi;
            break;
        case classifica:
            oggetto=new sx_film_classifica;
            break;
        }
        break;
    case serie:
        switch (spec) {
        case home:
            oggetto=new sx_serie_home;
            break;
        case visti:
            oggetto=new sx_serie_viste(0);
            break;
        case attesi:
            oggetto=new sx_serie_viste(1);
            break;
        case cronologia:
            oggetto=new sx_serie_cronologia;
            break;
        }
        break;
    case libri:
        switch (spec) {
        case home:
            oggetto=new sx_libro_home;
            break;
        case visti:
            oggetto=new sx_libro_letti(0,0);
            break;
        case attesi:
            oggetto=new sx_libro_letti(0,1);
            break;
        case cronologia:
            oggetto=new sx_libri_cronologia;
            break;
        }
        break;
    }
    lay=new QGridLayout;
    lay->addWidget(oggetto,0,0);
    lay->setMargin(0);
    this->setLayout(lay);
}

void Pannello_sx::cancellaLayout(){
    if(oggetto)delete oggetto;
    if(lay)delete lay;
}

Pannello_sx::~Pannello_sx(){
    cancellaLayout();
}
