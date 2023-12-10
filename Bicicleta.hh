#ifndef BICICLETA_HH
#define BICICLETA_HH

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Bicicleta {

private:
    string id_bici; //identificador de la bicicleta
    vector<string>viajes; //contiene las estaciones por las que ha pasado en ordoen
    string ubi; //contiene el id de la estacion en la que esta

public:
    Bicicleta();

    Bicicleta(const string& id, const string& est_act);

    string consultar_id_bici();

    string consultar_ubi();

    void cambiar_ubicacion(const string& nueva);

    void consultar_viajes();

    void nuevo_viaje(const string& id_estacion);

};
#endif