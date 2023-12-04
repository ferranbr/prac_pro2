#include "Estacion.hh"

Estacion::Estacion() : bicis() {
    id_estacion = "";
    capacidad = 0;
    plazas_libres = 0;
}

Estacion::Estacion(string id_estacion, int max) {
    this -> id_estacion = id_estacion;
    capacidad = max;
    plazas_libres = max;
}
string Estacion::consultar_id_est() {
    return id_estacion;
}

map<string,Bicicleta>Estacion::consultar_bicis() {
    return bicis;
}

void Estacion::borrar_bici(string id_bici) {
    auto i = bicis.find(id_bici);
    bicis.erase(i);
    ++plazas_libres;
}

void Estacion::sacar_viajes(string id_bici) {
    auto i = bicis.find(id_bici);
    vector<string>viajes = i -> second.consultar_viajes();
    for (int i = 0; i < viajes.size() - 1; ++i) {
        cout << viajes[i] << " " << viajes [i+1]<< endl;
    }
}

void Estacion::sacar_bicis() {
    for (auto i = bicis.begin(); i != bicis.end(); ++i) {
        cout << i->first << endl;
    }
}

int Estacion::ocupacion() {
    return bicis.size();
}

int Estacion::sitios_libres() {
    return plazas_libres;
}

bool Estacion::existe_bici(string id) {
    if(bicis.find(id) != bicis.end()) return true;
    else return false;
}

void Estacion::insertar_bici(Bicicleta& bici) {
    string id = bici.consultar_id_bici();
    bicis[id] = bici;
    --plazas_libres;
}

void Estacion::mod_capacidad(int nueva_capacidad) {
    capacidad = nueva_capacidad;
    plazas_libres = plazas_libres + (nueva_capacidad- plazas_libres);
}

void Estacion::menos_libres() {
    --plazas_libres;
}

void Estacion::mas_libres() {
    ++plazas_libres;
}
