#ifndef ESTACIONES_HH
#define ESTACIONES_HH

#include <iostream>
#include "Estacion.hh"
#include "BinTree.hh"
#include "Bicicleta.hh"
using namespace std;

class Estaciones {

private:
    BinTree<string>ids_estaciones;
    map<string,Estacion> estaciones;
    int plazas_libres = 0;

public:
    Estaciones(BinTree<string>ids_estaciones, map<string,Estacion>estaciones);

    void alta(string idb,string ide);

    bool existe_estacion(BinTree<string>ids,string id);

    string ubi_bicicleta(string id);

    void consultar_libres();

    void cambiar_ubi(string id_bici, string ant_est, string new_est);

    bool existe_bicicleta(string id_bici);

    void eliminar_bicicleta(string id_bici);

    bool hay_hueco();

    void reestructurar_ubis(BinTree<string>ids);

    void meter_bici(string &id_bici,string &id_correcto,int &plazas ,int &recs,BinTree<string> ids);

    void leer(BinTree<string>& a, map<string,Estacion>& m);
};
#endif