/** @file Area_Procesos.hh
    @brief Especificación de la clase Area_Procesos
*/

#ifndef _AREA_PROCESOS_HH_
#define _AREA_PROCESOS_HH_
#include "Proceso.hh"
#include "Cluster.hh"

#ifndef NO_DIAGRAM
#include <map>
#include <queue>
#endif


/** @class Area_Procesos
    @brief Representa una area de procesos
*/
class Area_Procesos {
    public:
    // Constructoras --------------------------------------------------- 
    Area_Procesos();
    // Consultoras -----------------------------------------------------
    void alta_prioridad(string identificador, int& error);
    // Poner un iterador que busque en todo el mapa. map<string, Proceso>::iterator i;
    // Si hemos encontrador un string igual al identificador, devolvemos un ERROR
    // else: lo añadimos al mapa. Se ordena automaticamente
    void baja_prioridad(string identificador, int& error);
    // Poner un iterador que busque en todo el mapa. map<string, Proceso>::iterator i;
    // Si no existe un string igual al identificador o tiene procesos pendientes: ERROR
    // else: Eliminamos dicha prioridad del area_procesos.
    // Modificadoras ----------------------------------------------------
    void alta_proceso_espera(string identificador, Proceso proceso, int& error);

    void enviar_procesos_cluster(int n); // Igual tengo que añadir algo en el cluster. Echar un ojo!


    void imprimir_prioridad(string identificador);

    void imprimir_area_espera();

    private:
    bool existe_prioridad(string identificador); // alta_proceso_espera
    bool existe_proceso(string identificador, int identificador_proceso);

    struct Priority {
        queue<Proceso> procesos;
        int procesos_aceptados;
        int procesos_rechazados;
    };
    map<string, Priority> area_procesos;


};
#endif