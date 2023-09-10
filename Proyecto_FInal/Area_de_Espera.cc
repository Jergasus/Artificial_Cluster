/** @file Area_de_Espera.cc
    @brief Implementación de la clase Area_de_Espera
*/

#include "Area_de_Espera.hh"
using namespace std;

// Constructoras --------------------------------------------------------------

Area_de_Espera::Area_de_Espera() {

}
void Area_de_Espera::inicializar() {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        string llave;
        cin >> llave;
        area_de_espera[llave];
    }
}

// Modificadoras --------------------------------------------------------------

void Area_de_Espera::alta_prioridad(const string& ident, int& error) {
    map<string, Prioridad>::iterator it = area_de_espera.find(ident);
    if (it != area_de_espera.end()) error = 5;
    else {
        error = -1;
        area_de_espera[ident];
    }
}

void Area_de_Espera::baja_prioridad(const string& ident, int& error) {
    map<string, Prioridad>::iterator it = area_de_espera.find(ident);
    if (it == area_de_espera.end()) error = 4;
    else {
        if (not it->second.procesos.empty()) error = 6;
        else {
            error = -1;
            area_de_espera.erase(it);
        }
    }
}

void Area_de_Espera::alta_proceso_espera(const string& ident, const Proceso& proc, int& error) {
    map<string, Prioridad>::iterator it = area_de_espera.find(ident);
    if (it == area_de_espera.end()) error = 4;
    else {
        bool found = false;
        for (list<Proceso>::iterator is = it->second.procesos.begin(); is != it->second.procesos.end() and not found; ++is) {
            if ((*is).consultar_ident() == proc.consultar_ident()) {
                found = true;
                error = 1;
            }
        }
        if (not found) {
            error = -1;
            it->second.procesos.insert(it->second.procesos.end(), proc);
        }
    }
}

void Area_de_Espera::enviar_procesos_cluster(Cluster& clust, int n) {
    map<string, Prioridad>::iterator it = area_de_espera.begin();
    while (it != area_de_espera.end() and n > 0) {
        list<Proceso>::iterator is = it->second.procesos.begin();
        while (is != it->second.procesos.end() and n > 0) {
            if (clust.recibir_proceso((*is))) {
                --n;
                is = it->second.procesos.erase(is);
                ++it->second.procesos_aceptados;
            }
            else {
                ++is;
                ++it->second.procesos_rechazados;
            }
        }
        ++it;
    }
}

void Area_de_Espera::imprimir_prioridad(const string& ident, int& error) {
    map<string, Prioridad>::iterator it = area_de_espera.find(ident);
    if (it == area_de_espera.end()) error = 4;
    else {
        error = -1;
        for (list<Proceso>::iterator is = it->second.procesos.begin(); is != it->second.procesos.end(); ++is) {
            (*is).imprimir();
        }
        cout << it->second.procesos_aceptados << " " << it->second.procesos_rechazados << endl;
    }
}

void Area_de_Espera::imprimir_area_espera() {
    for (map<string, Prioridad>::iterator it = area_de_espera.begin(); it != area_de_espera.end(); ++it) {
        cout << it->first << endl;
        for (list<Proceso>::iterator is = it->second.procesos.begin(); is != it->second.procesos.end(); ++is) {
            (*is).imprimir();
        }
        cout << it->second.procesos_aceptados << " " << it->second.procesos_rechazados << endl;
    }
}