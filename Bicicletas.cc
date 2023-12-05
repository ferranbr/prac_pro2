#include "Bicicletas.hh"

Bicicletas::Bicicletas(map<string,Bicicleta);
    
string Bicicletas::consultar_ubicacion(string idb);

void Bicicletas::nueva_bici(string idb, string ide);

void Bicicletas::quitar_bici(string idb);

bool Bicicletas::existe_bicicleta(string idb);

void Bicicletas::cambiar_ubi(string idb, string new_ide);  

void Bicicletas::sacar_viajes(string idb);
