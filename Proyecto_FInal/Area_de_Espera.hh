/** @file Area_de_Espera.hh
    @brief Especificación de la clase Area_de_Espera
*/

#ifndef _AREA_DE_ESPERA_HH_
#define _AREA_DE_ESPERA_HH_
#include "Proceso.hh"
#include "Cluster.hh"

#ifndef NO_DIAGRAM
#include <map>
#include <list>
#include <string>
#include <iostream>
#endif
using namespace std;

/** @class Area_de_Espera
    @brief Representa una Area_de_Espera
*/
class Area_de_Espera {
    public:

    //Constructoras -----------------------------------------------------------

    /** @brief Creadora por defecto.
     Se ejecuta de forma automática al declarar una área de espera.
     \pre <em>Cierto</em>
     \post El resultado es una área de espera (sin procesos).
    */
    Area_de_Espera();

    //Modificadoras -----------------------------------------------------------

    /** @brief Inicializa una área de espera. 

        \pre El parámetro implícito no está inicializado
        \post Duevuelve una área de espera inicializada con propiedades.
    */

    void inicializar();

    /** @brief Añadir una prioridad al área de espera. 

        \pre El parámetro implícito está inicializado.
        \post Si existe una prioridad con el mismo identificador que <em>ident</em>,
        <em>error</em> >= 0. En caso contrario, <em>error</em> = -1 y se añade dicha prioridad al área de
        espera.
    */
    void alta_prioridad(const string& ident, int& error);

    /** @brief Eliminar una prioridad del área de espera. 

        \pre El parámetro implícito está inicializado.
        \post Si no existe una prioridad con el mismo identificador que <em>ident</em>,
        o dicha prioridad tiene procesos pendientes, <em>error</em> >= 0. En caso
        contrario, <em>error</em> = -1 y se elimina dicha prioridad del área de espera.
    */
    void baja_prioridad(const string& ident, int& error);

    /** @brief Añadir un proceso al área de espera.

        \pre El parámetro implícito está inicializado.
        \post Si no existe una prioridad con el mismo identificador que <em>ident</em>,
        o uno de los procesos de dicha prioridad tiene el mismo identificador
        que <em>proc</em>, <em>error</em> >= 0. En caso contrario, <em>error</em> = -1 y añadimos el proceso al
        área de espera (con la prioridad de identificador <em>ident</em>).
    */
    void alta_proceso_espera(const string& ident, const Proceso& proc, int& error);

    /** @brief Enviar los procesos del área de espera al clúster.

        \pre El parámetro implícito está inicializado.
        \post Se intentan enviar <em>n</em> procesos pendientes al clúster.
        Dichos procesos se intentan colocar por prioridad. En caso que
        tengan la misma prioridad, se intentarán colocar por orden
        de antiguedad. El envío finalizará cuando:
        1. Los <em>n</em> procesos pendientes se hayan colocado.
        2. No queden procesos pendientes.
        3. Todos los procesos pendientes se hayan intentado colocar sin éxito.
        Los procesos que hayan sido rechazados volverán al área de procesos
        (con la misma prioridad). Si un proceso cabe en más de un procesador,
        se elige el que tenga el hueco más ajustado. Si hay un empate, es decir, que los
        huecos tienen el mismo tamaño, el proceso irá al procesador que tenga
        más memoria. Si el empate persiste, el proceso se colocará en el
        procesador más cercano a la raíz. Si el empate persiste, irá al
        procesador que esté más a la izquierda.
    */
    void enviar_procesos_cluster(Cluster& clust, int n);

    /** @brief Escribe los procesos pendientes de una prioridad.

        \pre El parámetro implícito está inicializado.
        \post Si no existe una prioridad con el mismo identificador que <em>ident</em>,
        <em>error</em> >= 0. En caso contrario, <em>error</em> = -1 y se escriben los procesos
        pendientes de la prioridad cuyo identificador es el mismo que
        <em>ident</em> (se escriben de más antiguo a más nuevo). Además, se escribe
        el número de procesos de la prioridad colocados correctamente
        en el clúster y el número de rechazados.
    */
    void imprimir_prioridad(const string& ident, int& error);

    /** @brief Escribe los procesos pendientes de todas las prioridades.

        \pre El parámetro implícito está inicializado.
        \post Se escriben todos los procesos de todas las prioridades
        del área de espera (en orden creciente de prioridad).
    */
    void imprimir_area_espera();

    private:

    /** @brief Estructura de una prioridad.
    */

    struct Prioridad {
        /** @brief Lista de procesos. Hace referencia a los procesos que se encuentran en una prioridad.
        */
        list<Proceso> procesos;
        /** @brief Procesos aceptados. Hace referencia a la cantidad de procesos aceptados en una prioridad.
        */
        int procesos_aceptados = 0;
        /** @brief Procesos rechazados. Hace referencia a la cantidad de procesos rechazados en una prioridad.
        */
        int procesos_rechazados = 0;
    };

    /** @brief Mapa del área de espera. La llave hace referencia al identificador de la prioridad. El valor
        hace referencia al struct de prioridad.
    */
    map<string, Prioridad> area_de_espera;
};
#endif