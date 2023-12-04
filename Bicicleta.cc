#include "Bicicleta.hh"


Bicicleta::Bicicleta() {
    id_bici = "";
    ubi = "";
}

Bicicleta::Bicicleta(string id, string est_act) {
    id_bici = id;
    ubi = est_act;
    viajes.push_back(est_act);
}

string Bicicleta::consultar_id_bici() {
    return id_bici;
}

string Bicicleta::consultar_ubi() {
    return ubi;
}

vector<string>Bicicleta::consultar_viajes() {
    return viajes;
}

void Bicicleta::nuevo_viaje(string id_estacion) {
    viajes.push_back(id_estacion);
    ubi = id_estacion;
}