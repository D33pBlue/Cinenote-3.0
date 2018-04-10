#ifndef TIPI_USATI_H
#define TIPI_USATI_H

#include <string>
#include <vector>

using namespace std;

enum sezione{film,serie,libri};
enum specifica{home,visti,attesi,classifica,autori,cronologia,generi};
enum datitrovatore{cercaregista,cercafilm,cercagenere,cercaserie,cercalibro,cercaautore};


 struct _film{
        int id;
        string titolo;
        vector<string>autori;
        int anno;
        vector<string>generi;
        bool visto;
        bool disponibile;
        double voto;
        string descrizione;
        string ConsigliatoDa;
        };


#endif // TIPI_USATI_H
