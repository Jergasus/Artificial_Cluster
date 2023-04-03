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
            Cluster cluster;
            cluster.configurar_cluster();

        }
        else if (comando == "modificar_cluster" or comando == "mc") {
            string ident;
            cin >> ident;
            Cluster cluster_new;
            cluster.modificar_cluster(ident);
        }
        else if (comando == "alta_prioridad" or comando == "ap") {
            string ident;
            cin >> ident;
            area_proceso.añadir_prioridad(ident);

        }
        else if (comando == "baja_prioridad" or comando == "bp") {
            string ident;
            cin >> ident;
            area_proceso.eliminar_prioridad(ident);
        }
        else if (comando == "alta_proceso_espera" or comando == "ape") {
            int ident_proceso, memoria, tiempo;
            cin >> ident_proceso >> memoria >> tiempo;
            Proceso proceso(ident_proceso, memoria, tiempo);
            string ident;
            cin >> ident;
            if (area_proceso.existe_prioridad(ident) == false); // Mensaje de error
            else if (area_proceso.existe_proceso(ident, ident_proceso)); // Mensaje de error
            else area_proceso.añadir_proceso(ident, proceso);
            
        }
        else if (comando == "alta_proceso_procesador" or comando == "app") {
            string ident_procesador;
            cin >> ident_procesador;
            int ident_proceso, memoria, tiempo;
            cin >> ident_proceso >> memoria >> tiempo;
            Proceso proceso(ident_proceso, memoria, tiempo);
            if (cluster.existe_procesador(/*Preguntar como hacerlo*/, ident_procesador) == false); // Mensaje de error
            // existe_proceso(ident_proceso);
            // añadir_proceso(proceso);
            
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
            cluster.avanzar_tiempo(cluster, t);
        }
        else if (comando == "imprimir_prioridad" or comando == "ipri") {
            string identificador;
            cin >> identificador;
            //existe_prioridad(identificador)
        }
        else if (comando == "imprimir_area_espera" or comando == "iae") {
            area_proceso.escribir_area_procesos();
        }
        else if (comando == "imprimir_procesador" or comando == "ipro") {
            string identificador;
            cin >> identificador;
        }
        else if (comando == "imprimir_procesadores_cluster" or comando == "ipc") {
            // cluster.escribir_procesadores(cluster);
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