#include "Cluster.hh"
#include "Procesador.hh"
#include "Proceso.hh"
#include "Area_Procesos.hh"
#include <iostream>
#include <string>
using namespace std;

void errores(int error) {
    if (error == 0) {
        cout << "Error al intentar modificar el clúster" << endl;
    }
    else if (error = 1) {
        cout << "Error al intentar añadir una prioridad al área de procesos" << endl;
    }
    else if (error = 2) {
        cout << "Error al intentar eliminar una prioridad del área de procesos" << endl;
    }
    else if (error = 3) {
        cout << "Error al intentar añadir un proceso a un prioridad del área de procesos" << endl;
    }
    else if (error = 4) {
        cout << "Error al intentar añadir un proceso a un procesador" << endl;
    }
    else if (error = 5) {
        cout << "Error al intentar eliminar un proceso del procesador" << endl;
    }
    else if (error = 6) {
        cout << "Error al intentar escribir los procesos pendientes de una prioridad del área de procesos" << endl;
    }
    else if (error = 7) {
        cout << "Error al intentar escribir los procesos de un procesador" << endl;
    }
    else if (error = 8) {
        cout << "Error al intentar mover los procesos de un procesador al principio de su memoria" << endl;
    }
}

int main() {
    Cluster cluster;
    Area_Procesos area_proceso;
    int error;
    string comando;
    cin >> comando;
    while (comando != "fin") {
        if (comando == "configurar_cluster" or comando == "cc") {
            cluster.configurar_cluster();

        }
        else if (comando == "modificar_cluster" or comando == "mc") {
            string ident;
            cin >> ident;
            cluster.modificar_cluster(ident, error);
        }
        else if (comando == "alta_prioridad" or comando == "ap") {
            string ident;
            cin >> ident;
            area_proceso.alta_prioridad(ident, error);

        }
        else if (comando == "baja_prioridad" or comando == "bp") {
            string ident;
            cin >> ident;
            area_proceso.baja_prioridad(ident, error);
        }
        else if (comando == "alta_proceso_espera" or comando == "ape") {
            int ident_proceso, memoria, tiempo;
            cin >> ident_proceso >> memoria >> tiempo;
            Proceso proceso(ident_proceso, memoria, tiempo);
            string ident;
            cin >> ident;
            area_proceso.alta_proceso_espera(ident, proceso, error);
            
        }
        else if (comando == "alta_proceso_procesador" or comando == "app") {
            string ident_procesador;
            cin >> ident_procesador;
            int ident_proceso, memoria, tiempo;
            cin >> ident_proceso >> memoria >> tiempo;
            Proceso proceso(ident_proceso, memoria, tiempo);
            cluster.alta_proceso_procesador(ident_procesador, proceso, error);
            
        }
        else if (comando == "baja_proceso_procesador" or comando == "bpp") {
            string ident_procesador;
            cin >> ident_procesador;
            int ident_proceso;
            cin >> ident_proceso;
            cluster.baja_proceso_procesador(ident_procesador, ident_proceso, error)
        }
        else if (comando == "enviar_procesos_cluster" or comando == "epc") {
            int num;
            cin >> num;
            area_proceso.enviar_procesos_cluster(num);
        }
        else if (comando == "avanzar_tiempo" or comando == "at") {
            int t;
            cin >> t;
            cluster.avanzar_tiempo(t);
        }
        else if (comando == "imprimir_prioridad" or comando == "ipri") {
            string identificador;
            cin >> identificador;
            area_proceso.imprimir_prioridad(identificador, error);
        }
        else if (comando == "imprimir_area_espera" or comando == "iae") {
            area_proceso.imprimir_area_espera();
        }
        else if (comando == "imprimir_procesador" or comando == "ipro") {
            string identificador;
            cin >> identificador;
            cluster.imprimir_procesador(identificador, error);
        }
        else if (comando == "imprimir_procesadores_cluster" or comando == "ipc") {
            cluster.imprimir_procesadores_cluster();
        }
        else if (comando == "imprimir_estructura_cluster" or comando == "iec") {
            cluster.imprimir_estructura_cluster();
        }
        else if (comando == "compactar_memoria_procesador" or comando == "cmp") {
            string identificador;
            cin >> identificador;
            cluster.compactar_memoria_procesador(identificador, error);
        }
        else if (comando == "compactar_memoria_cluster" or comando == "cmc") {
            cluster.compactar_memoria_cluster();
        } 
        cin >> comando;
    }
}