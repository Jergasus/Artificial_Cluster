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

int Procesador::introducir_proceso(const Proceso& proceso) {
    map<int, set<int>>::iterator it = huecos.lower_bound(proceso.consultar_memoria());

    if (it == huecos.end()) return 2;

    int pos = (*(*it).second.begin());
    int hueco = (*it).first;

    ident_pos[proceso.consultar_ident()] = pos;
    memoria.insert(make_pair(pos, proceso));
    (*it).second.erase((*it).second.begin());

    if ((*it).second.empty()) huecos.erase(it);
    if (hueco != proceso.consultar_memoria()) {
        huecos[hueco - proceso.consultar_memoria()].insert(proceso.consultar_memoria() + pos);
    }

    espacio_libre -= proceso.consultar_memoria();

    return -1;
}

void Procesador::recalcular_huecos() {
    huecos = map<int, set<int>>();

    int pos = 0;
    map<int, Proceso>::const_iterator it = memoria.begin();

    while (it != memoria.end()) {
        int tam = (*it).first - pos;
        if (tam != 0) {
            huecos[tam].insert(pos);
        }
        pos = (*it).first + (*it).second.consultar_memoria();
        ++it; 
    }
    if (espacio_total != pos) huecos[espacio_total - pos].insert(pos);
}

int Procesador::siguiente_proceso(map<int, Proceso>::const_iterator it) {
    if (++it != memoria.end()) return (*it).first;
    else return espacio_total;
}

int Procesador::ultima_pos(map<int, Proceso>::const_iterator it) const {
    ++it;
    if (it == memoria.end()) return espacio_total;
    return (*it).first;
}

int Procesador::primera_pos(map<int, Proceso>::const_iterator it) const {
    if (it == memoria.begin()) return 0;
    --it;
    return (*it).first + (*it).second.consultar_memoria();
}

int Procesador::eliminar_proceso(int id) {
    map<int, int>::iterator it1 = ident_pos.find(id);
    int pos, primera, ultima, mem;
    if (it1 == ident_pos.end()) return 3;
    else {
        pos = (*it1).second;
        map<int, Proceso>::iterator it2 = memoria.find(pos);
        primera = primera_pos(it2);
        ultima = ultima_pos(it2);

        mem = (*it2).second.consultar_memoria();
        espacio_libre += mem;

        huecos[ultima - primera].insert(primera);
        memoria.erase(it2);
        ident_pos.erase(it1);
    }

    if (pos != primera) {
        map<int, set<int>>::iterator it = huecos.find(pos- primera);
        (*it).second.erase(primera);

        if ((*it).second.empty()) huecos.erase(it);
    }

    if (ultima - pos - mem != 0){
        map<int, set<int>>::iterator it = huecos.find(ultima - pos - mem);
        (*it).second.erase(pos + mem);

        if ((*it).second.empty()) huecos.erase(it);
    }

    return -1;
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

void Procesador::imprimir_huecos() {
    for (map<int, set<int>>::iterator it = huecos.begin(); it != huecos.end(); ++it) {
        cout << (*it).first << endl;;
        for (set<int>::iterator is = (*it).second.begin(); is != (*it).second.end(); ++is) {
            cout << (*is) << " ";
        }
        cout << endl;
    }
}
