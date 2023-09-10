/** @file Proceso.cc
    @brief Implementación de la clase Proceso
*/

#include "Proceso.hh"
#ifndef NO_DIAGRAM
#include <iostream>
#endif
using namespace std;

// Constructoras --------------------------------------------------------------

Proceso::Proceso() {
    
}

Proceso::Proceso(int ident, int mem, int time) {
    identificador = ident;
    memoria = mem;
    tiempo = time;
}

// Consultoras ----------------------------------------------------------------

int Proceso::consultar_ident() const {
    return identificador;
}

int Proceso::consultar_memoria() const {
    return memoria;
}

int Proceso::consultar_tiempo() const {
    return tiempo;
}

// Modificadoras --------------------------------------------------------------

int Proceso::avanzar_tiempo(int time) {
    tiempo -= time;
    return tiempo;
}

void Proceso::imprimir() const {
    cout << identificador << " " << memoria << " " << tiempo << endl;
}
