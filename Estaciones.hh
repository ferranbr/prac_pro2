#ifndef ESTACIONES_HH
#define ESTACIONES_HH

#include <iostream>
#include "Estacion.hh"
#include "BinTree.hh"
#include "Bicicletas.hh"
using namespace std;

class Estaciones {

private:
    BinTree<string>&ids_estaciones;
    map<string,Estacion>&estaciones;
    Bicicletas bicicletas;
    int plazas_libres = 0;

public:
    Estaciones(BinTree<string>&ids_estaciones, map<string,Estacion>&estaciones);

    void alta(const string& idb,const string& ide);

    bool existe_estacion(const BinTree<string>& ids,const string& id);

    string ubi_bicicleta(const string& id);

    void consultar_libres();

    void cambiar_ubi(const string& id_bici,const string& ant_est,const string& new_est);

    bool existe_bicicleta(const string& id_bici);

    void eliminar_bicicleta(const string& id_bici);

    bool hay_hueco();

    void reestructurar_ubis(const BinTree<string>& ids);

    void meter_bici(const string& id_bici, string &id_correcto,int &plazas ,int &recs,const BinTree<string>& ids, double& max_desocup);

    void leer(BinTree<string>& a, map<string,Estacion>& m);
};
#endif