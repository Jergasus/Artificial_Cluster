#include "Cluster.hh"
#include "Procesador.hh"
#include "Proceso.hh"
#include "Area_Procesos.hh"
#include "BinTree.hh"
#include <iostream>
#include <string>
#include <set>
using namespace std;

Cluster::Cluster() {

}

void Cluster::configurar_cluster() {
    Procesadores = map<string, Procesador>();
    leer_cluster(cluster);
}
void Cluster::modificar_cluster(const string& ident, int& error) {
    if (not existe_procesador(ident)) {
        error = 0;
        descartar_bintree_aux();
        return;
    }
    if (not Procesadores[ident].no_tiene_procesos()) {
        error = 8;
        descartar_bintree_aux();
        return;
    }
    error = 7;
    recorrer_cluster(cluster, ident, error);
}

void Cluster::alta_proceso_procesador(const string& ident, const Proceso& proc, int& error) {
    if (not existe_procesador(ident)) {
        error = 0;
        return;
    }
    if (Procesadores[ident].existe_proceso(proc.consultar_ident())) {
        error = 1;
        return;
    }
    if (not Procesadores[ident].cabe_proceso(proc.consultar_memoria())) {
        error = 2;
        return;
    }
    error = -1;
    Procesadores[ident].introducir_proceso(proc);
}

void Cluster::baja_proceso_procesador(const string& ident, int ident_proc, int& error) {
    if (not existe_procesador(ident)) {
        error = 0;
        return;
    }
    if (not Procesadores[ident].existe_proceso(ident_proc)) {
        error = 3;
        return;
    }
    error = -1;
    Procesadores[ident].eliminar_proceso(ident_proc);
}

void Cluster::avanzar_tiempo(int t) {
    for (map<string, Procesador>::iterator it = Procesadores.begin(); it != Procesadores.end(); ++it) {
        (*it).second.avanzar_tiempo(t);
    }
}

void Cluster::imprimir_procesador(const string& ident, int& error) {
    if (not existe_procesador(ident)) error = 0;
    else {
        error = -1;
        Procesadores[ident].escribir_procesos();
    }
}

void Cluster::imprimir_procesadores_cluster() {
    for (map<string, Procesador>::iterator it = Procesadores.begin(); it != Procesadores.end(); ++it) {
        cout << (*it).first << endl;
        (*it).second.escribir_procesos();
    }
}

void Cluster::imprimir_estructura_cluster() {
    imprimir_estructura(cluster);
    cout << endl;
}

void Cluster::compactar_memoria_procesador(const string& ident, int& error) {
    map<string, Procesador>::iterator it = Procesadores.find(ident);
    if (it != Procesadores.end()) {
        error = -1;
        (*it).second.compactar_memoria();
    }
    else error = 0;
}

void Cluster::compactar_memoria_cluster() {
    for (map<string, Procesador>::iterator it = Procesadores.begin(); it != Procesadores.end(); ++it) {
        (*it).second.compactar_memoria();
    }
}

bool Cluster::recibir_proceso(Proceso& proc) {
    int hueco_min = -1;
    int prof_procesador = -1;
    map<string, Procesador>::iterator it = Procesadores.end();
    meter_proceso_cluster(cluster, it, hueco_min, 0, prof_procesador, proc);
    if (hueco_min != -1) {
        (*it).second.introducir_proceso(proc);
        return true;
    }
    else return false;
}

void Cluster::meter_proceso_cluster(const BinTree<map<string, Procesador>::iterator>& clust, map<string, Procesador>::iterator& procesador, int& hueco_min, int prof_actual, int& prof_procesador, Proceso& proc) {
    if (not clust.empty()) {
        meter_proceso_cluster(clust.right(), procesador, hueco_min, prof_actual + 1, prof_procesador, proc);
        int hueco_procesador = (*clust.value()).second.hueco_min(proc.consultar_memoria());
        if (not (*clust.value()).second.existe_proceso(proc.consultar_ident()) and hueco_procesador != 0) {
            if (hueco_min == -1 or hueco_procesador < hueco_min) {
                hueco_min = hueco_procesador;
                prof_procesador = prof_actual;
                procesador = clust.value();
            }
            else if (hueco_procesador == hueco_min) {
                if ((*clust.value()).second.consultar_memoria() > (*procesador).second.consultar_memoria()) {
                    prof_procesador = prof_actual;
                    procesador = clust.value();
                }
                else if ((*clust.value()).second.consultar_memoria() == (*procesador).second.consultar_memoria() and prof_procesador >= prof_actual) {
                    prof_procesador = prof_actual;
                    procesador = clust.value();
                }
            }
        }
        meter_proceso_cluster(clust.left(), procesador, hueco_min, prof_actual + 1, prof_procesador, proc);
    }
}

void Cluster::leer_cluster(BinTree<map<string, Procesador>::iterator>& clust) {
    string ident;
    cin >> ident;
    if (ident != "*") {
        int mem;
        cin >> mem;
        Procesador procesador;
        procesador.inicializar(ident, mem);
        pair<map<string, Procesador>::iterator, bool> it = Procesadores.insert(pair<string, Procesador>(ident, procesador));
        BinTree<map<string, Procesador>::iterator> left, right;
        leer_cluster(left);
        leer_cluster(right);
        clust = BinTree<map<string, Procesador>::iterator>(it.first, left, right);
    }
}

void Cluster::recorrer_cluster(BinTree<map<string, Procesador>::iterator>& clust, const string& ident, int& error) {
    if (not clust.empty()) {
        if ((*clust.value()).first == ident) {
            if (clust.right().empty() and clust.left().empty()) {
                error = -1;
                Procesadores.erase(ident);
                BinTree<map<string, Procesador>::iterator> clust_aux;
                leer_cluster(clust_aux);
                clust = BinTree<map<string, Procesador>::iterator>(clust_aux.value(), clust_aux.left(), clust_aux.right());
            }
        }
        BinTree<map<string, Procesador>::iterator> left = clust.left();
        BinTree<map<string, Procesador>::iterator> right = clust.right();
        recorrer_cluster(left, ident, error);
        recorrer_cluster(right, ident, error);
        clust = BinTree<map<string, Procesador>::iterator>(clust.value(), left, right);
    }
}

void Cluster::descartar_bintree_aux() {
    string ident;
    cin >> ident;
    if (ident != "*") {
        int mem;
        cin >> mem;
        descartar_bintree_aux(); // Left
        descartar_bintree_aux(); // Right
    }
}

bool Cluster::existe_procesador(const string& ident) {
    return (Procesadores.find(ident) != Procesadores.end());
}

void Cluster::imprimir_estructura(const BinTree<map<string, Procesador>::iterator>& clust) {
    if (clust.empty()) cout << " ";
    else {
        cout << "(";
        cout << (*clust.value()).first;
        BinTree<map<string, Procesador>::iterator> left = clust.left();
        BinTree<map<string, Procesador>::iterator> right = clust.right();
        imprimir_estructura(left);
        imprimir_estructura(right);
        cout << ")";
    }
}

void Cluster::mirar_huecos(string identificador) {
    (Procesadores[identificador]).imprimir_huecos();
}