#include "Cluster.hh"
#include "Procesador.hh"
#include "Proceso.hh"
#include "Area_Procesos.hh"
#include <iostream>
using namespace std;

int main() {
    // Inicializar cluster
    // Inicializar area de procesos
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
            Cluster cluster;
            cluster.modificar_cluster(ident);
        }
        else if (comando == "alta_prioridad" or comando == "ap") {
            
        }
        else if (comando == "baja_prioridad" or comando == "bp") {
            
        }
        else if (comando == "alta_proceso_espera" or comando == "ape") {
            
        }
        else if (comando == "alta_proceso_procesador" or comando == "app") {
            
        }
        else if (comando == "baja_proceso_procesador" or comando == "bpp") {
            
        }
        else if (comando == "enviar_procesos_cluster" or comando == "epc") {
            
        }
        else if (comando == "avanzar_tiempo" or comando == "at") {
            
        }
        else if (comando == "imprimir_prioridad" or comando == "ipri") {
            
        }
        else if (comando == "imprimir_area_espera" or comando == "iae") {
            
        }
        else if (comando == "imprimir_procesador" or comando == "ipro") {
            
        }
        else if (comando == "imprimir_procesadores_cluster" or comando == "ipc") {
            
        }
        else if (comando == "imprimir_estructura_cluster" or comando == "iec") {
            
        }
        else if (comando == "compactar_memoria_procesador" or comando == "cmp") {
            
        }
        else if (comando == "compactar_memoria_cluster" or comando == "cmc") {
            
        }
        cin >> comando;
    }
}