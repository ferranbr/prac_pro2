#ifndef BICICLETAS_HH
#define BICICLETAS_HH

#include <iostream>
#include <map>
#include "Bicicleta.hh"
using namespace std;

class Bicicletas {

private:
    map<string,Bicicleta> cjt_bicis;

public:
    Bicicletas(const map<string,Bicicleta>& m);
    
    string consultar_ubicacion(const string& idb);

    void nueva_bici(const string& idb,const string& ide);

    void quitar_bici(const string& idb);

    bool buscar_bicicleta(const string& idb);

    void nueva_ubi(const string& idb, const string& new_ide);

    void cambiar_la_ubi(const string& idb,const string& nueva);  

    void sacar_viajes(const string& idb);
};
#endif