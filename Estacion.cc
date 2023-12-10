#include "Estacion.hh"

Estacion::Estacion() : bicis() {
    id_estacion = "";
    capacidad = 0;
}

Estacion::Estacion(const string& ide,const int& c) {
    id_estacion = ide;
    capacidad = c;
}

string Estacion::consultar_id_est() {
    return id_estacion;
}

map<string,Bicicleta>Estacion::consultar_bicis() {
    return bicis;
}

void Estacion::borrar_bici(const string& id_bici) {
    auto i = bicis.find(id_bici);
    bicis.erase(i);
}

void Estacion::sacar_viajes(const string& id_bici) {
    bicis[id_bici].consultar_viajes();
}

void Estacion::sacar_bicis() {
    for (auto i = bicis.begin(); i != bicis.end(); ++i) {
        cout << i->second.consultar_id_bici() << endl;
    }
}

int Estacion::ocupacion() {
    return bicis.size();
}

bool Estacion::existe_bici(const string& id) {
    if(bicis.find(id) != bicis.end()) return true;
    else return false;
}

void Estacion::insertar_bici(const string& idb,const string& ide) {
    Bicicleta b(idb,ide);
    bicis.insert(make_pair(idb,b));
}

void Estacion::mover_bici(Bicicleta& b,const string& ide) {
    b.cambiar_ubicacion(ide);
    string id = b.consultar_id_bici();
    bicis[id] = b;
}
void Estacion::mod_capacidad(const int& nueva_capacidad) {
    capacidad = nueva_capacidad;
}

int Estacion::sitios_libres() {
    return (capacidad - bicis.size());
}