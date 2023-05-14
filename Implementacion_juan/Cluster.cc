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
// void modificar_cluster(const string& ident, int& error); -----------------------------------------------------------------

void Cluster::alta_proceso_procesador(const string& ident, const Proceso& proc, int& error) {
    if (not existe_procesador(ident)) {
        error = 0;
        return;
    }
    if (Procesadores[ident].existe_proceso(proc.consultar_ident())) {
        error = 1;
        return;
    }
    error = Procesadores[ident].introducir_proceso(proc);
}

void Cluster::baja_proceso_procesador(const string& ident, int ident_proc, int& error) {
    if (not existe_procesador(ident)) {
        error = 0;
        return;
    }
    error = Procesadores[ident].eliminar_proceso(ident_proc);
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

// void compactar_memoria_procesador(const string& ident, int& error); -------------------------------------------------

// void compactar_memoria_cluster(); --------------------------------------------------------------------

// void recibir_proceso(const Proceso& proc); --------------------------------------------------------------

BinTree<map<string, Procesador>::iterator> Cluster::consultar_cluster() const {
    return cluster;
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

// static void compactar_memoria_procesadores(BinTree<Procesador>& clust); -------------------------------------------------------------
// static bool se_puede_colocar(BinTree<Procesador>& clust, Proceso proc, list<Procesador>& proces); ---------------------------------------------
// static void colocar_proceso_procesador(BinTree<Procesador>& clust, Proceso proc, Procesador& proces); ----------------------------------------------