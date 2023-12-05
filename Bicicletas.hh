#ifndef BICICLETAS_HH
#define BICICLETAS_HH

#include <iostream>
#include <map>
#include "Bicicleta"
using namespace std;

class Bicicletas {

private:
    map<string,Bicicleta> cjt_bicis;

public:
    Bicicletas(map<string,Bicicleta);
    
    string consultar_ubicacion(string idb);

    void nueva_bici(string idb, string ide);

    void quitar_bici(string idb);

    bool existe_bicicleta(string idb);

    void cambiar_ubi(string idb, string new_ide);  

    void sacar_viajes(string idb);
};
#endif