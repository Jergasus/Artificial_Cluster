#include "Area_Procesos.hh"
#include "Proceso.hh"
#include "Cluster.hh"
#include "BinTree.hh"
#include "Procesador.hh"
#include <map>
#include <queue>
#include <string>
#include <iostream>
using namespace std;

Area_Procesos::Area_Procesos() {

}

void Area_Procesos::inicializar() {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        string llave;
        cin >> llave;
        area_procesos[llave];
    }
}

void Area_Procesos::alta_prioridad(const string& ident, int& error) {
    if (area_procesos.find(ident) != area_procesos.end()) error = 5;
    else {
        error = -1;
        area_procesos[ident];
    }
}

void Area_Procesos::baja_prioridad(const string& ident, int& error) {
    if (area_procesos.find(ident) == area_procesos.end()) error = 4;
    else {
        if (not area_procesos[ident].procesos.empty()) error = 6;
        else {
            error = -1;
            area_procesos.erase(area_procesos.find(ident));
        }
    }
}

void Area_Procesos::alta_proceso_espera(const string& ident, const Proceso& proc, int& error) {
    if (area_procesos.find(ident) == area_procesos.end()) error = 4;
    else {
        bool found = false;
        for (list<Proceso>::iterator it = area_procesos[ident].procesos.begin(); it != area_procesos[ident].procesos.end() and not found; ++it) {
            if ((*it).consultar_ident() == proc.consultar_ident()) {
                found = true;
                error = 1;
            }
        }
        if (not found) {
            error = -1;
            area_procesos[ident].procesos.insert(area_procesos[ident].procesos.end(), proc);
        }
    }
}

// void enviar_procesos_cluster(const BinTree<Procesador>& cluster, int n); ---------------------------------------------------

// void eliminar_proceso_prioridad(int ident_proc); -----------------------------------------------------------------------

void Area_Procesos::imprimir_prioridad(const string& ident, int& error) {
    if (area_procesos.find(ident) == area_procesos.end()) error = 4;
    else {
        error = -1;
        for (list<Proceso>::iterator it = area_procesos[ident].procesos.begin(); it != area_procesos[ident].procesos.end(); ++it) {
            cout << (*it).consultar_ident() << " " << (*it).consultar_memoria() << " " << (*it).consultar_tiempo() << endl;
        }
        cout << area_procesos[ident].procesos_aceptados << " " << area_procesos[ident].procesos_rechazados << endl;
    }
}

void Area_Procesos::imprimir_area_espera() {
    for (map<string, Priority>::iterator it = area_procesos.begin(); it != area_procesos.end(); ++it) {
        cout << (*it).first << endl;
        for (list<Proceso>::iterator is = (*it).second.procesos.begin(); is != (*it).second.procesos.end(); ++is) {
            (*is).imprimir();
        }
        cout << (*it).second.procesos_aceptados << " " << (*it).second.procesos_rechazados << endl;
    }
}