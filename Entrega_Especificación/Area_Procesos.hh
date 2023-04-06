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
#include <string>
#endif

/** @class Area_Procesos
    @brief Representa una area de procesos
*/
class Area_Procesos {
    public:

    //Constructoras -----------------------------------------------------------

    /** @brief Creadora por defecto.
     Se ejecuta de forma automática al declarar una área de procesos.
     \pre <em>Cierto</em>
     \post El resultado es una área de procesos (sin procesos).
    */
    Area_Procesos();

    //Modificadoras -----------------------------------------------------------

    /** @brief Añadir una prioridad al área de procesos. 

        \pre El parámetro implícito está inicializado.
        \post Si existe una prioridad con el mismo identificador que ident,
        error >= 0. En caso contrario, se añade dicha prioridad al área de
        procesos.
    */
    void alta_prioridad(const string& ident, int& error);

    /** @brief Eliminar una prioridad del área de procesos. 

        \pre El parámetro implícito está inicializado.
        \post Si no existe una prioridad con el mismo identificador que ident,
        o dicha prioridad tiene procesos pendientes, error >= 0. En caso
        contrario, se elimina dicha prioridad del área de procesos.
    */
    void baja_prioridad(const string& ident, int& error);

    /** @brief Añadir un proceso al área de procesos.

        \pre El parámetro implícito está inicializado.
        \post Si no existe una prioridad con el mismo identificador que ident,
        o uno de los procesos de dicha prioridad tiene el mismo identificador
        que proc, error >= 0. En caso contrario, error = -1 y añadimos el proceso al
        área de procesos (con la prioridad de identificador ident).
    */
    void alta_proceso_espera(const string& ident, Proceso proc, int& error);

    /** @brief Enviar los procesos del área de procesos al clúster.

        \pre El parámetro implícito está inicializado.
        \post Se intentan enviar n procesos al clúster. DARLE UNA VUELTA!!!!
    */
    void enviar_procesos_cluster(int n); // Igual tengo que añadir algo en el cluster. Echar un ojo!

    /** @brief Escribe los procesos pendientes de una prioridad.

        \pre El parámetro implícito está inicializado.
        \post Si no existe una prioridad con el mismo identificador que ident,
        error >= 0. En caso contrario, error = -1 y se escriben los procesos
        pendientes de la prioridad cuyo identificador es el mismo que
        ident (se escriben de más antiguo a más nuevo). Además, se escribe
        el número de procesos de la prioridad colocados correctamente
        en el clúster y el número de rechazados.
    */
    void imprimir_prioridad(const string& ident, int& error);

    /** @brief Escribe los procesos pendientes de todas las prioridades.

        \pre El parámetro implícito está inicializado.
        \post Se escriben todos los procesos de todas las prioridades
        del área de procesos (en orden creciente de prioridad).
    */
    void imprimir_area_espera();

};
#endif