/** @file Area_Procesos.hh
    @brief Especificación de la clase Area_Procesos
*/

#ifndef _AREA_PROCESOS_HH_
#define _AREA_PROCESOS_HH_
#include "Proceso.hh"

#ifndef NO_DIAGRAM
#include <map>
#endif


/** @class Area_Procesos
    @brief Representa una area de procesos
*/
class Area_Procesos {
    public:
    // Constructoras --------------------------------------------------- 
    Area_Procesos();
    // Consultoras -----------------------------------------------------
    void añadir_prioridad(string identificador);
    // Poner un iterador que busque en todo el mapa. map<string, Proceso>::iterator i;
    // Si hemos encontrador un string igual al identificador, devolvemos un ERROR
    // else: lo añadimos al mapa. Se ordena automaticamente
    void eliminar_prioridad(string identificador);
    // Poner un iterador que busque en todo el mapa. map<string, Proceso>::iterator i;
    // Si no existe un string igual al identificador o tiene procesos pendientes: ERROR
    // else: Eliminamos dicha prioridad del area_procesos.
    // Modificadoras ----------------------------------------------------
    bool existe_prioridad(string identificador);

    bool existe_proceso(string identificador, int identificador_proceso);

    void añadir_proceso(string identificador, Proceso proceso);

    void escribir_procesos(string identificador);

    void escribir_area_procesos();
    private:
    pair<int,int> aceptados_rechazados;
    map<string, Proceso> area_procesos;


};
#endif