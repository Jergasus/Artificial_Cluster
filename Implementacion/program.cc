#include "Cluster.hh"
#include "Procesador.hh"
#include "Proceso.hh"
#include "Area_Procesos.hh"
#include <iostream>
#include <string>
#include <map>
using namespace std;

void fallos(map<int, string>& error) {
    error[0] = "error: no existe procesador";
    error[1] = "error: ya existe proceso";
    error[2] = "error: no cabe proceso";
    error[3] = "error: no existe proceso";
    error[4] = "error: no existe prioridad";
    error[5] = "error: ya existe prioridad";
    error[6] = "error: prioridad con procesos";
    error[7] = "error: procesador con auxiliares";
    error[8] = "error: procesador con procesos";
}

int main() {
    Cluster cluster;
    Area_Procesos area_proceso;
    map<int, string> errores;
    fallos(errores);
    int error;
    cluster.configurar_cluster();
    area_proceso.inicializar();
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
            area_proceso.alta_prioridad(ident, error);
            if (error != -1) cout << errores[error] << endl;

        }
        else if (comando == "baja_prioridad" or comando == "bp") {
            string ident;
            cin >> ident;
            cout << "#" << comando << " " << ident << endl;
            area_proceso.baja_prioridad(ident, error);
            if (error != -1) cout << errores[error] << endl;
        }
        else if (comando == "alta_proceso_espera" or comando == "ape") {
            string ident;
            cin >> ident;
            int ident_proceso, memoria, tiempo;
            cin >> ident_proceso >> memoria >> tiempo;
            Proceso proceso(ident_proceso, memoria, tiempo);
            cout << "#" << comando << " " << ident << " " << ident_proceso << endl;
            area_proceso.alta_proceso_espera(ident, proceso, error);
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
            area_proceso.enviar_procesos_cluster(cluster, num);
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
            area_proceso.imprimir_prioridad(identificador, error);
            if (error != -1) cout << errores[error] << endl;
        }
        else if (comando == "imprimir_area_espera" or comando == "iae") {
            cout << "#" << comando << endl;
            area_proceso.imprimir_area_espera();
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
        else if (comando == "mirar_huecos" or comando == "h") {
            string identificador;
            cin >> identificador;
            cout << "#" << comando << endl;
            cluster.mirar_huecos(identificador);
        }
        cin >> comando;
    }
}