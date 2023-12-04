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
    int plazas_libres;

public:
    Estacion();

    Estacion(string id_estacion, int max);
    
    string consultar_id_est();

    map<string,Bicicleta> consultar_bicis();

    void borrar_bici(string id_bici);

    void sacar_viajes(string id_bici);

    void sacar_bicis();

    int ocupacion();

    bool cabe_bici();

    bool existe_bici(string id);

    void insertar_bici(Bicicleta& bici);

    void mod_capacidad(int nueva_capacidad);

    int sitios_libres();

    void menos_libres();

    void mas_libres();
};
#endif

