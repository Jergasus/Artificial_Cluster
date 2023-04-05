#include "Cluster.hh"
#include "Procesador.hh"
#include "Proceso.hh"
#include "Area_Procesos.hh"
#include <iostream>
using namespace std;

int main() {
    Cluster cluster;
    Area_Procesos area_proceso;
    string comando;
    cin >> comando;
    while (comando != "fin") {
        if (comando == "configurar_cluster" or comando == "cc") {
            //Procesadores del cluster (sus memorias y sus tiempos de ejecución)
            //Si ya existe un cluster, deja de existir.
            cluster.configurar_cluster();

        }
        else if (comando == "modificar_cluster" or comando == "mc") {
            string ident;
            cin >> ident;
            cluster.modificar_cluster(ident);
        }
        else if (comando == "alta_prioridad" or comando == "ap") {
            string ident;
            cin >> ident;
            area_proceso.alta_prioridad(ident);

        }
        else if (comando == "baja_prioridad" or comando == "bp") {
            string ident;
            cin >> ident;
            area_proceso.baja_prioridad(ident);
        }
        else if (comando == "alta_proceso_espera" or comando == "ape") {
            int ident_proceso, memoria, tiempo;
            cin >> ident_proceso >> memoria >> tiempo;
            Proceso proceso(ident_proceso, memoria, tiempo);
            string ident;
            cin >> ident;
            area_proceso.alta_proceso_espera(ident, proceso);
            
        }
        else if (comando == "alta_proceso_procesador" or comando == "app") {
            string ident_procesador;
            cin >> ident_procesador;
            int ident_proceso, memoria, tiempo;
            cin >> ident_proceso >> memoria >> tiempo;
            Proceso proceso(ident_proceso, memoria, tiempo);
            cluster.alta_proceso_procesador(ident_procesador, proceso);
            
        }
        else if (comando == "baja_proceso_procesador" or comando == "bpp") {
            string ident_procesador;
            cin >> ident_procesador;
            int ident_proceso;
            cin >> ident_proceso;
            //Existe Procesador¿?
            // Si existe procesador, ¿existe proceso? existe_proceso(clase procesador)
        }
        else if (comando == "enviar_procesos_cluster" or comando == "epc") {
            int num;
            cin >> num;
        }
        else if (comando == "avanzar_tiempo" or comando == "at") {
            int t;
            cin >> t;
            cluster.avanzar_tiempo(t);
        }
        else if (comando == "imprimir_prioridad" or comando == "ipri") {
            string identificador;
            cin >> identificador;
            area_proceso.imprimir_prioridad(identificador);
        }
        else if (comando == "imprimir_area_espera" or comando == "iae") {
            area_proceso.imprimir_area_espera();
        }
        else if (comando == "imprimir_procesador" or comando == "ipro") {
            string identificador;
            cin >> identificador;
            cluster.imprimir_procesador(identificador);
        }
        else if (comando == "imprimir_procesadores_cluster" or comando == "ipc") {
            cluster.imprimir_procesadores_cluster();
        }
        else if (comando == "imprimir_estructura_cluster" or comando == "iec") {
            // ¿?
        }
        else if (comando == "compactar_memoria_procesador" or comando == "cmp") {
            string identificador;
            cin >> identificador;
            // cluster.existe_procesador()
            // cluster.compactar_memoria_procesador
        }
        else if (comando == "compactar_memoria_cluster" or comando == "cmc") {
            
        } 
        cin >> comando;
    }
}