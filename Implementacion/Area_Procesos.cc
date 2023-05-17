#include "Area_Procesos.hh"
using namespace std;

// Constructoras --------------------------------------------------------------

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

// Modificadoras --------------------------------------------------------------

void Area_Procesos::alta_prioridad(const string& ident, int& error) {
    map<string, Priority>::iterator it = area_procesos.find(ident);
    if (it != area_procesos.end()) error = 5;
    else {
        error = -1;
        area_procesos[ident];
    }
}

void Area_Procesos::baja_prioridad(const string& ident, int& error) {
    map<string, Priority>::iterator it = area_procesos.find(ident);
    if (it == area_procesos.end()) error = 4;
    else {
        if (not it->second.procesos.empty()) error = 6;
        else {
            error = -1;
            area_procesos.erase(it);
        }
    }
}

void Area_Procesos::alta_proceso_espera(const string& ident, const Proceso& proc, int& error) {
    map<string, Priority>::iterator it = area_procesos.find(ident);
    if (it == area_procesos.end()) error = 4;
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

void Area_Procesos::enviar_procesos_cluster(Cluster& clust, int n) {
    map<string, Priority>::iterator it = area_procesos.begin();
    while (it != area_procesos.end() and n > 0) {
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

void Area_Procesos::imprimir_prioridad(const string& ident, int& error) {
    map<string, Priority>::iterator it = area_procesos.find(ident);
    if (it == area_procesos.end()) error = 4;
    else {
        error = -1;
        for (list<Proceso>::iterator is = it->second.procesos.begin(); is != it->second.procesos.end(); ++is) {
            (*is).imprimir();
        }
        cout << it->second.procesos_aceptados << " " << it->second.procesos_rechazados << endl;
    }
}

void Area_Procesos::imprimir_area_espera() {
    for (map<string, Priority>::iterator it = area_procesos.begin(); it != area_procesos.end(); ++it) {
        cout << it->first << endl;
        for (list<Proceso>::iterator is = it->second.procesos.begin(); is != it->second.procesos.end(); ++is) {
            (*is).imprimir();
        }
        cout << it->second.procesos_aceptados << " " << it->second.procesos_rechazados << endl;
    }
}