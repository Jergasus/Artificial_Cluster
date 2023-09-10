#include "Cluster.hh"
#include "Area_de_Espera.hh"
#ifndef NO_DIAGRAM
#include <iostream>
#include <string>
#include <vector>
#endif
using namespace std;


/**
    @mainpage Documentación utilizada en la práctica de: Simulación del rendimiento de procesadores interconectados
    <em>Clases:</em>
    <ul>
        <li>Cluster</li>
        <li>Area_de_Espera</li>
        <li>Procesador</li>
        <li>Proceso</li>
    </ul>
*/


/** @file program.cc
    @brief Programa Principal
*/
// ----------------------------------------------------------------------------
// SALIDA DE ERRORES
void fallos(vector<string>& error) {
    error[0] = "error: no existe procesador";
    error[1] = "error: ya existe proceso";
    error[2] = "error: no cabe proceso";
    error[3] = "error: no existe proceso";
    error[4] = "error: no existe prioridad";
    error[5] = "error: ya existe prioridad";
    error[6] = "error: prioridad con procesos";
    error[7] = "error: procesador con auxiliares";
    error[8] = "error: procesador con procesos";
    error[9] = "error: se intenta borrar la raiz";
}
// ----------------------------------------------------------------------------

int main() {
    Cluster cluster;
    Area_de_Espera area_espera;
    vector<string> errores(10);
    fallos(errores);
    int error;
    cluster.configurar_cluster(); // Configurar el cluster inicial
    area_espera.inicializar(); // Inicilizar el area de espera
    string comando;
    cin >> comando;
    while (comando != "fin") {
        if (comando == "configurar_cluster" or comando == "cc") {
            cout << "#" << comando << endl;
            cluster.configurar_cluster();
        }
        else if (comando == "modificar_cluster" or comando == "mc") {
            string ident;
            cin >> ident;
            cout << "#" << comando << " " << ident << endl;
            cluster.modificar_cluster(ident, error);
            if (error != -1) cout << errores[error] << endl;
        }
        else if (comando == "alta_prioridad" or comando == "ap") {
            string ident;
            cin >> ident;
            cout << "#" << comando << " " << ident << endl;
            area_espera.alta_prioridad(ident, error);
            if (error != -1) cout << errores[error] << endl;

        }
        else if (comando == "baja_prioridad" or comando == "bp") {
            string ident;
            cin >> ident;
            cout << "#" << comando << " " << ident << endl;
            area_espera.baja_prioridad(ident, error);
            if (error != -1) cout << errores[error] << endl;
        }
        else if (comando == "alta_proceso_espera" or comando == "ape") {
            string ident;
            cin >> ident;
            int ident_proceso, memoria, tiempo;
            cin >> ident_proceso >> memoria >> tiempo;
            Proceso proceso(ident_proceso, memoria, tiempo);
            cout << "#" << comando << " " << ident << " " << ident_proceso << endl;
            area_espera.alta_proceso_espera(ident, proceso, error);
            if (error != -1) cout << errores[error] << endl;
            
        }
        else if (comando == "alta_proceso_procesador" or comando == "app") {
            string ident_procesador;
            cin >> ident_procesador;
            int ident_proceso, memoria, tiempo;
            cin >> ident_proceso >> memoria >> tiempo;
            Proceso proceso(ident_proceso, memoria, tiempo);
            cout << "#" << comando << " " << ident_procesador << " " << ident_proceso << endl;
            cluster.alta_proceso_procesador(ident_procesador, proceso, error);
            if (error != -1) cout << errores[error] << endl;
            
        }
        else if (comando == "baja_proceso_procesador" or comando == "bpp") {
            string ident_procesador;
            cin >> ident_procesador;
            int ident_proceso;
            cin >> ident_proceso;
            cout << "#" << comando << " " << ident_procesador << " " << ident_proceso << endl;
            cluster.baja_proceso_procesador(ident_procesador, ident_proceso, error);
            if (error != -1) cout << errores[error] << endl;
        }
        else if (comando == "enviar_procesos_cluster" or comando == "epc") {
            int num;
            cin >> num;
            cout << "#" << comando << " " << num << endl;
            area_espera.enviar_procesos_cluster(cluster, num);
        }
        else if (comando == "avanzar_tiempo" or comando == "at") {
            int t;
            cin >> t;
            cout << "#" << comando << " " << t << endl;
            cluster.avanzar_tiempo(t);
        }
        else if (comando == "imprimir_prioridad" or comando == "ipri") {
            string identificador;
            cin >> identificador;
            cout << "#" << comando << " " << identificador << endl;
            area_espera.imprimir_prioridad(identificador, error);
            if (error != -1) cout << errores[error] << endl;
        }
        else if (comando == "imprimir_area_espera" or comando == "iae") {
            cout << "#" << comando << endl;
            area_espera.imprimir_area_espera();
        }
        else if (comando == "imprimir_procesador" or comando == "ipro") {
            string identificador;
            cin >> identificador;
            cout << "#" << comando << " " << identificador << endl;
            cluster.imprimir_procesador(identificador, error);
            if (error != -1) cout << errores[error] << endl;
        }
        else if (comando == "imprimir_procesadores_cluster" or comando == "ipc") {
            cout << "#" << comando << endl;
            cluster.imprimir_procesadores_cluster();
        }
        else if (comando == "imprimir_estructura_cluster" or comando == "iec") {
            cout << "#" << comando << endl;
            cluster.imprimir_estructura_cluster();
        }
        else if (comando == "compactar_memoria_procesador" or comando == "cmp") {
            string identificador;
            cin >> identificador;
            cout << "#" << comando << " " << identificador << endl;
            cluster.compactar_memoria_procesador(identificador, error);
            if (error != -1) cout << errores[error] << endl;
        }
        else if (comando == "compactar_memoria_cluster" or comando == "cmc") {
            cout << "#" << comando << endl;
            cluster.compactar_memoria_cluster();
        }
        else if (comando == "podar_cluster" or comando == "pc") {
            int k;
            cin >> k;
            cout << "#" << comando << " " << k << endl;
            cluster.podar_cluster(k, error);
            if (error != -1) cout << errores[error] << endl;
        } 
        cin >> comando;
    }
}