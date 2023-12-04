#include "Estaciones.hh"
#include "Bicicleta.hh"
#include <map>

Estaciones::Estaciones(BinTree<string>ids_estaciones, map<string,Estacion>estaciones) {
    this -> ids_estaciones = ids_estaciones;
    this -> estaciones = estaciones;
}

void Estaciones::alta(string idb,string ide) {
    Bicicleta b(idb,ide);
    estaciones[ide].insertar_bici(b);
    --plazas_libres;
    estaciones[ide].menos_libres();
}

bool Estaciones::existe_estacion(BinTree<string> ids, string id) {
    if (ids.value() == id) return true;
    else {
        bool left = false;
        bool right = false;
        if (!ids.left().empty()) left = existe_estacion(ids.left(),id);
        if(!ids.right().empty()) right = existe_estacion(ids.right(),id);
        return left or right;
    }
}

string Estaciones::ubi_bicicleta(string id) {
    string resultado = "";
    for (auto i = estaciones.begin(); i != estaciones.end(); ++i) {
        if (i->second.existe_bici(id)) {
            resultado = i->second.consultar_id_est();
            break;
        }
    }
    return resultado;
}

void Estaciones::consultar_libres() {
    cout << plazas_libres << endl;
}

void Estaciones::cambiar_ubi(string id_bici, string ant_est, string new_est) {
    map<string,Bicicleta>m = estaciones[ant_est].consultar_bicis();
    m[id_bici].nuevo_viaje(new_est);
    Bicicleta b = m[id_bici];
    estaciones[new_est].insertar_bici(b);
    estaciones[ant_est].borrar_bici(id_bici);
}

bool Estaciones::existe_bicicleta(string id) {
    for (auto i = estaciones.begin(); i != estaciones.end(); ++i) {
        if(i -> second.existe_bici(id)) {
            return true;
            break;
        }
    }
    return false;
}

void Estaciones::eliminar_bicicleta(string id_bici) {
    for (auto i = estaciones.begin(); i != estaciones.end(); ++i) {
        if (i->second.existe_bici(id_bici)) {
            i->second.borrar_bici(id_bici);
            break;
        }
    }
}

bool Estaciones::hay_hueco() {
    for (auto i = estaciones.begin(); i != estaciones.end(); ++i) {
        if (i -> second.sitios_libres() > 0) {
            return true;
            break;
        }
    }
    return false; 
}

void Estaciones::reestructurar_ubis(BinTree<string> ids) {
    if (!ids.left().empty() && !ids.right().empty()) {
        string valor = ids.value();
        string left = ids.left().value();
        string right = ids.right().value();
        map<string,Bicicleta>m = estaciones[valor].consultar_bicis();
        map<string,Bicicleta>ml = estaciones[left].consultar_bicis();
        map<string,Bicicleta>mr = estaciones[right].consultar_bicis();

        while (estaciones[valor].sitios_libres() > 0) {
            if (estaciones[left].ocupacion() >= estaciones[right].ocupacion()) {
                while (estaciones[left].ocupacion() >= estaciones[right].ocupacion()) {
                    estaciones[valor].insertar_bici(ml.begin() -> second);
                    estaciones[left].borrar_bici(ml.begin() -> first);
                }
            } 
            else {
                while (estaciones[left].ocupacion() < estaciones[right].ocupacion()) {
                    estaciones[valor].insertar_bici(mr.begin() -> second);
                    estaciones[right].borrar_bici(mr.begin() -> first); 
                }
            }
        }
        reestructurar_ubis(ids.left());
        reestructurar_ubis(ids.right());
    }
}


void Estaciones::meter_bici(string &id_bici, string &id_correcto,int &plazas ,int &recs,BinTree<string> ids) {
    string valor = ids.value();
    if(ids.right().empty() && ids.left().empty()) {
        id_correcto = valor;
        recs = 1;
        plazas = estaciones[valor].sitios_libres(); 
    }
    else {
        int recs2 = recs + 2;
        int plazas2 = plazas + estaciones[valor].sitios_libres(); 
        if(plazas2/recs2 > plazas/recs) {
            recs = recs2;
            plazas = plazas2;
            id_correcto = valor;
        }
    
    meter_bici(id_bici,id_correcto,plazas,recs,ids.left());
    meter_bici(id_bici,id_correcto,plazas,recs,ids.right());

    }

    Bicicleta b(id_bici,id_correcto);
    estaciones[id_correcto].insertar_bici(b);
    cout << id_correcto << endl;
}

void Estaciones::leer(BinTree<string>& a, map<string,Estacion>& m) {
    string x;
    cin >> x;

    if(x != "#") {
        int n;
        cin >> n;
        plazas_libres += n;
        Estacion e(x,n);
        m[x] = e;
        BinTree<string> left,right;
        leer(left,m);
        leer(right,m);
        a = BinTree<string>(x,left,right);
    }
}