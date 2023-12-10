#ifndef ESTACION_HH
#define ESTACION_HH

#include <iostream>
#include <map>
#include "Bicicleta.hh"
using namespace std;

class Estacion {

private:
    map<string,Bicicleta>bicis;
    string id_estacion;
    int capacidad;

public:
    Estacion();

    Estacion(const string& ide,const int& max);
    
    string consultar_id_est();

    map<string,Bicicleta> consultar_bicis();

    void borrar_bici(const string& id_bici);

    void sacar_viajes(const string& id_bici);

    void sacar_bicis();

    int ocupacion();

    bool existe_bici(const string& id);

    void insertar_bici(const string& idb,const string& ide);

    void mover_bici(Bicicleta& b,const string& ide);

    void mod_capacidad(const int& nueva_capacidad);

    int sitios_libres();
};
#endif

