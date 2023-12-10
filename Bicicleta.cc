#include "Bicicleta.hh"


Bicicleta::Bicicleta() {
    id_bici = "";
    ubi = "";
}

Bicicleta::Bicicleta(const string& id, const string& est_act) {
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

void Bicicleta::cambiar_ubicacion(const string& nueva) {
    ubi = nueva;
}

void Bicicleta::consultar_viajes() {
    for (int i = 0; i < viajes.size() - 1; ++i) {
        cout << viajes[i] << " " << viajes[i + 1] << endl;
    }
}

void Bicicleta::nuevo_viaje(const string& id_estacion) {
    viajes.push_back(id_estacion);
    ubi = id_estacion;
}