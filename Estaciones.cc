#include "Estaciones.hh"

Estaciones::Estaciones(BinTree<string>& ids_estaciones, map<string, Estacion>& estaciones): ids_estaciones(ids_estaciones),estaciones(estaciones),bicicletas(map<string, Bicicleta>()),plazas_libres(0){}

void Estaciones::alta(const string& idb,const string& ide) {
    estaciones[ide].insertar_bici(idb,ide);
    bicicletas.nueva_bici(idb,ide);
    --plazas_libres;
}

bool Estaciones::existe_estacion(const BinTree<string>& ids,const string& id) {
    if (ids.value() == id) return true;
    else {
        bool left = false;
        bool right = false;
        if (!ids.left().empty()) left = existe_estacion(ids.left(),id);
        if(!ids.right().empty()) right = existe_estacion(ids.right(),id);
        return left or right;
    }
}

string Estaciones::ubi_bicicleta(const string& id) {
    return bicicletas.consultar_ubicacion(id);
}

void Estaciones::consultar_libres() {
    cout << plazas_libres << endl;
}

void Estaciones::cambiar_ubi(const string& id_bici,const string& ant_est,const string& new_est) {
    map<string,Bicicleta>m = estaciones[ant_est].consultar_bicis();
    m[id_bici].nuevo_viaje(new_est);
    Bicicleta b = m[id_bici];
    estaciones[new_est].mover_bici(b,new_est);
    estaciones[ant_est].borrar_bici(id_bici);
    bicicletas.nueva_ubi(id_bici,new_est);
}

bool Estaciones::existe_bicicleta(const string& id) {
    if(bicicletas.buscar_bicicleta(id)) return true;
    else return false;
}

void Estaciones::eliminar_bicicleta(const string& id_bici) {
    bicicletas.quitar_bici(id_bici);
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

void Estaciones::reestructurar_ubis(const BinTree<string>& ids) {
    if (!ids.left().empty() && !ids.right().empty()) {
        string valor = ids.value();
        string left = ids.left().value();
        string right = ids.right().value();
        map<string,Bicicleta>m = estaciones[valor].consultar_bicis();
        map<string,Bicicleta>ml = estaciones[left].consultar_bicis();
        map<string,Bicicleta>mr = estaciones[right].consultar_bicis();
        while (estaciones[valor].sitios_libres() > 0) { 
            if ((estaciones[left].ocupacion() > estaciones[right].ocupacion()) or (estaciones[left].ocupacion() == estaciones[right].ocupacion() && (estaciones[left].consultar_id_est() < estaciones[right].consultar_id_est()))) {
                auto i = ml.begin();
                if (i != ml.end()) {
                    bicicletas.cambiar_la_ubi(i->first, valor);
                    estaciones[valor].mover_bici(i->second, valor);
                    estaciones[left].borrar_bici(i->first);
                    ml.erase(i);
                } 
                else break;
            } 
            else if ((estaciones[left].ocupacion() < estaciones[right].ocupacion()) or (estaciones[left].ocupacion() == estaciones[right].ocupacion() && (estaciones[left].consultar_id_est() > estaciones[right].consultar_id_est()))) {
                auto i = mr.begin();
                if (i != mr.end()) {
                    bicicletas.cambiar_la_ubi(i->first, valor);
                    estaciones[valor].mover_bici(i->second, valor);
                    estaciones[right].borrar_bici(i->first);
                    mr.erase(i);  
                } 
                else break;
            }
            if (estaciones[valor].sitios_libres() > 0 && ((estaciones[left].ocupacion() > 0) or (estaciones[right].ocupacion() > 0))) continue;
            else break;
        }
        reestructurar_ubis(ids.left());
        reestructurar_ubis(ids.right());
    }
}

void Estaciones::meter_bici(const string& id_bici, string &id_correcto,int &plazas ,int &recs,const BinTree<string>& ids, double& max_desocup) {
    double desocup_act;
    if (ids.left().empty()) {
        auto i = estaciones.find(ids.value());
        recs = 1;
        plazas = i -> second.sitios_libres();
        desocup_act = double(plazas)/double(recs);
        if ((desocup_act > max_desocup)) {
            max_desocup = desocup_act;
            id_correcto = ids.value();
        }
        else if (desocup_act == max_desocup) {
            if (ids.value() < id_correcto) id_correcto = ids.value();
        }
    }
    else {
        auto i = estaciones.find(ids.value());
        int recs_izq;
        int pl_izq;
        meter_bici(id_bici,id_correcto,pl_izq,recs_izq,ids.left(),max_desocup);
        int recs_dre;
        int pl_dre;
        meter_bici(id_bici,id_correcto,pl_dre,recs_dre,ids.right(),max_desocup);
        
        plazas = pl_izq + pl_dre + i -> second.sitios_libres();
        recs = recs_izq + recs_dre + 1;

        desocup_act = double(plazas)/double(recs);
        if (desocup_act > max_desocup) {
            max_desocup = desocup_act;
            id_correcto = ids.value();
        }
        else if(desocup_act == max_desocup) {
            if (ids.value() < id_correcto) id_correcto = ids.value();
        }
    }
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