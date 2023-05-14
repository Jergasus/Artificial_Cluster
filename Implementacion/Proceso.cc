#include "Proceso.hh"
#include <iostream>
using namespace std;

Proceso::Proceso() {
    
}

Proceso::Proceso(int ident, int mem, int time) {
    identificador = ident;
    memoria = mem;
    tiempo = time;
}

int Proceso::consultar_ident() const {
    return identificador;
}

int Proceso::consultar_memoria() const {
    return memoria;
}

int Proceso::consultar_tiempo() const {
    return tiempo;
}

int Proceso::avanzar_tiempo(int time) {
    tiempo -= time;
    return tiempo;
}

void Proceso::imprimir() {
    cout << identificador << " " << memoria << " " << tiempo << endl;
}
