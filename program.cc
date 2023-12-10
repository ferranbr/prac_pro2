#include <iostream>
#include "Bicicleta.hh"
#include "Estacion.hh"
#include "Estaciones.hh"
using namespace std;

int main () {
    BinTree<string>ids_estaciones;
    map<string,Estacion> estaciones;
    Estaciones ests(ids_estaciones,estaciones);
    ests.leer(ids_estaciones,estaciones);
    string command;
    
    while (command != "fin") {
        int capacidad;
        string id_bici, id_est;
        
        if (command == "alta_bici" or command == "ab") {
            cin >> id_bici >> id_est;
            cout << "#ab " << id_bici << " " << id_est << endl;
            if (ests.existe_bicicleta(id_bici)) cout << "error: la bici ya existe" << endl;
            else if (!ests.existe_estacion(ids_estaciones,id_est)) cout << "error: la estacion no existe" << endl;
            else if (estaciones[id_est].sitios_libres() == 0) cout << "error: la bici no cabe" << endl;
            else {
                ests.alta(id_bici,id_est);
            }
        }
        
        else if (command == "baja_bici" or command == "bb") {
            cin >> id_bici;
            cout << "#bb " << id_bici << endl;
            if (!ests.existe_bicicleta(id_bici)) cout << "error: la bici no existe" << endl;
            else {
                string ubi = ests.ubi_bicicleta(id_bici);
                ests.eliminar_bicicleta(id_bici);
            }
        }
        
        else if (command == "estacion_bici" or command == "eb") {
            cin >> id_bici;
            cout << "#eb " << id_bici << endl;
            if (!ests.existe_bicicleta(id_bici)) cout << "error: la bici no existe" << endl;
            else cout << ests.ubi_bicicleta(id_bici) << endl;
        }
        
        else if (command == "viajes_bici" or command == "vb") {
            cin >> id_bici;
            cout << "#vb " << id_bici << endl;
            if (!ests.existe_bicicleta(id_bici)) cout << "error: la bici no existe" << endl;
            else {
                string estacion = ests.ubi_bicicleta(id_bici);
                estaciones[estacion].sacar_viajes(id_bici);
            }
        }
        
        else if (command == "mover_bici" or command == "mb") {
            cin >> id_bici >> id_est;
            cout << "#mb " << id_bici << " " << id_est << endl;
            if (!ests.existe_bicicleta(id_bici)) cout << "error: la bici no existe" << endl;
            else if (!ests.existe_estacion(ids_estaciones,id_est)) cout << "error: la estacion no existe" << endl;
            else if(estaciones[id_est].existe_bici(id_bici)) cout << "error: la bici ya esta en el sitio" << endl;
            else if (estaciones[id_est].sitios_libres() == 0) cout << "error: la bici no cabe" << endl;
            else {
                string estacion_act = ests.ubi_bicicleta(id_bici);
                ests.cambiar_ubi(id_bici,estacion_act,id_est);
            }
        }
        
        else if (command == "bicis_estacion" or command == "be") {
            cin >> id_est;
            cout << "#be " << id_est << endl;
            if (!ests.existe_estacion(ids_estaciones,id_est)) cout << "error: la estacion no existe" << endl;
            else {
                estaciones[id_est].sacar_bicis();
            }
        }
        
        else if (command == "modificar_capacidad" or command == "mc") {
            cin >> id_est >> capacidad;
            cout << "#mc " << id_est << " " << capacidad << endl;
            if (!ests.existe_estacion(ids_estaciones,id_est)) cout << "error: la estacion no existe" << endl;
            else if (capacidad < estaciones[id_est].ocupacion()) cout << "error: capacidad insuficiente" << endl;
            else estaciones[id_est].mod_capacidad(capacidad);
        }
        
        else if (command == "plazas_libres" or command == "pl") {
            cout << "#pl" << endl;
            ests.consultar_libres();
        }
        
        else if (command == "subir_bicis" or command == "sb") {
            cout << "#sb" << endl;
            ests.reestructurar_ubis(ids_estaciones);
        }
        
        else if (command == "asignar_estacion" or command == "ae") {
            cin >> id_bici;
            cout << "#ae " << id_bici << endl;
            if (ests.existe_bicicleta(id_bici)) cout << "error: la bici ya existe" << endl;
            else if(!ests.hay_hueco()) cout << "error: no hay plazas libres" << endl;
            else {
                string id_est_correcto = "";
                int plazas = 0,recs = 0;
                double coef = 0.0;
                ests.meter_bici(id_bici,id_est_correcto,plazas,recs,ids_estaciones,coef);
                ests.alta(id_bici,id_est_correcto);
                cout << id_est_correcto << endl;
            }
        }
        
        cin >> command;
    }
}