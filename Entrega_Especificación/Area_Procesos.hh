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
        que proc, error >= 0. En caso contrario, añadimos el proceso al
        área de procesos (con la prioridad de identificador ident).
    */
    void alta_proceso_espera(const string& ident, Proceso proc, int& error);

    /** @brief Enviar los procesos del área de procesos al clúster.

        \pre El parámetro implícito está inicializado.
        \post Se intentan enviar n procesos al clúster. DARLE UNA VUELTA!!!!
    */
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