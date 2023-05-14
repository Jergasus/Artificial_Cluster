#include "Procesador.hh"
#include "Proceso.hh"
#include <list>
#include <map>
#include <string>
#include <iostream>
#include <set>
using namespace std;

Procesador::Procesador() {

}

void Procesador::inicializar(const string& ident, int mem) {
    identificador = ident;
    espacio_total = mem;
    espacio_libre = mem;
    huecos[mem].insert(0);
}

void Procesador::avanzar_tiempo(int time) {
    bool eliminado = false;
    map<int, Proceso>::iterator it = memoria.begin();
    while (it != memoria.end()) {
        if ((*it).second.avanzar_tiempo(time) <= 0) {
            espacio_libre += memoria[ident_pos[(*it).second.consultar_ident()]].consultar_memoria();
            ident_pos.erase((*it).second.consultar_ident());
            it = memoria.erase(it);
            eliminado = true;
        }
        else ++it;
    }
    if (eliminado) recalcular_huecos();
}

// void mover_procesos_memoria(); Igual la debo utilizar!!!

void Procesador::escribir_procesos() {
    for (map<int, Proceso>::iterator it = memoria.begin(); it != memoria.end(); ++it) {
        cout << (*it).first << " ";
        (*it).second.imprimir();
    }
}

void Procesador::introducir_proceso(const Proceso& proc) {
    int tamano_proceso = proc.consultar_memoria();
    map<int, set<int>>::iterator it = huecos.lower_bound(tamano_proceso);
    if (it != huecos.end()) {
        set<int>::iterator is = (*it).second.begin();
        int posicion_proceso = (*is);
        int tamano_hueco = (*it).first - tamano_proceso;
        (*it).second.erase((posicion_proceso));
        if ((*it).second.empty()) huecos.erase(it);
        if (tamano_hueco != 0) huecos[tamano_hueco].insert(posicion_proceso + tamano_proceso);
        ident_pos[proc.consultar_ident()] = posicion_proceso;
        memoria.insert(pair<int, Proceso>(posicion_proceso, proc));
        espacio_libre -= tamano_proceso;
    }
}

void Procesador::recalcular_huecos() {
    huecos = map<int, set<int>>();
    map<int, Proceso>::const_iterator it = memoria.begin();
    if (it == memoria.end()) huecos[espacio_total].insert(0);
    else if ((*it).first != 0) huecos[(*it).first].insert(0);
    while (it != memoria.end()) {
        int pos_siguiente_proceso = siguiente_proceso(it);
        int tamano_hueco = pos_siguiente_proceso - (*it).first - (*it).second.consultar_memoria();
        if (tamano_hueco > 0) huecos[tamano_hueco].insert((*it).first + (*it).second.consultar_memoria());
        ++it;
    }
}

int Procesador::siguiente_proceso(map<int, Proceso>::const_iterator it) {
    if (++it != memoria.end()) return (*it).first;
    else return espacio_total;
}

void Procesador::eliminar_proceso(int ident_proceso) {
    espacio_libre += memoria[ident_pos[ident_proceso]].consultar_memoria();
    memoria.erase(ident_pos[ident_proceso]);
    ident_pos.erase(ident_proceso);
    recalcular_huecos();
}

string Procesador::consultar_identificador() const {
    return identificador;
}

int Procesador::consultar_memoria() const {
    return espacio_libre;
}

// list<Proceso> consultar_procesos() const; --------------------------------------------------------------

bool Procesador::existe_proceso(int ident) {
    return (ident_pos.find(ident) != ident_pos.end());
}

bool Procesador::cabe_proceso(int mem) {
    return (huecos.lower_bound(mem) != huecos.end());
}

bool Procesador::no_tiene_procesos() {
    return memoria.empty();
}

int Procesador::hueco_min(int mem) {
    map<int, set<int>>::const_iterator it = huecos.lower_bound(mem);
    if (it != huecos.end()) return (*it).first;
    return 0;
}

void Procesador::compactar_memoria() {
    if (espacio_libre == 0) return;
    int i = 0;
    map<int, Proceso>::iterator it = memoria.begin();
    while (it != memoria.end()) {
        int aux = (*it).second.consultar_memoria();
        if (i != (*it).first) {
            memoria.insert(pair<int, Proceso>(i, (*it).second));
            ident_pos[(*it).second.consultar_ident()] = i;
            it = memoria.erase(it);
        }
        else {
            ++it;
        }
        i += aux;
    }
    huecos = map<int, set<int>>();
    huecos[espacio_libre].insert(i);
}

void Procesador::imprimir_huecos() {
    for (map<int, set<int>>::iterator it = huecos.begin(); it != huecos.end(); ++it) {
        cout << (*it).first << endl;;
        for (set<int>::iterator is = (*it).second.begin(); is != (*it).second.end(); ++is) {
            cout << (*is) << " ";
        }
        cout << endl;
    }
}
