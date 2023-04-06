/** @file Cluster.hh
    @brief Especificación de la clase Cluster 
*/

#ifndef _CLUSTER_HH_
#define _CLUSTER_HH_
#include "Procesador.hh"
#include "Proceso.hh"
#include "Area_Procesos.hh"

#ifndef NO_DIAGRAM
#include "BinTree.hh"
#include <string>
#endif

/** @class Cluster
    @brief Representa un Cluster 
*/


class Cluster {
    public:

    // Constructoras ----------------------------------------------------------

    /** @brief Creadora por defecto.
     Se ejecuta de forma automatica al declarar un clúster.
     \pre <em>Cierto</em>
     \post El resultado es un clúster no inicializado (sin procesadores).
    */
    Cluster();

    // Modificadoras ----------------------------------------------------------

    /** @brief Configuración/Inicialización de un cluster. 

        \pre Cierto
        \post El resultado es un clúster inicializado, con procesadores y sus
        respectivas conexiones y memorias. Si ya existía un clúster, este deja
        de existir.
    */
    void configurar_cluster();

    /** @brief Modificación del cluster

        \pre El parámetro implícito está inicializado.
        \post Si no existe un procesador en el clúster con el mismo identificador
        que <em>ident</em>, el procesador tiene procesos pendientes o tiene hojas,
        <em>error</em> >= 0. En caso contario, <em>error</em> = -1 y en la posición del 
        procesador se pondrá un nuevo clúster.

    */
    void modificar_cluster(const string& ident, int& error);

    /** @brief Añadir proceso a un procesador

        \pre El parámetro implícito está inicializado.
        \post Si no existe un procesador en el clúster con el mismo identificador
        que <em>ident</em>, o el procesador ya tiene un proceso con el mismo
        identificador que <em>proc</em>, o el proceso no cabe en el procesador,
        <em>error</em> >= 0. En caso contrario, <em>error</em> = -1 y el proceso se ejecutará
        en el procesador, ocupando su respectiva memoria.

    */
    void alta_proceso_procesador(const string& ident, Proceso proc, int& error);

    /** @brief Eliminar proceso de un procesador

        \pre El parámetro implícito está inicializado.
        \post Si no existe un procesador en el clúster con el mismo identificador
        que <em>ident</em>, o el procesador no tiene un proceso con el mismo
        identificador que <em>ident_proc</em>, <em>error</em> >= 0. 
        En caso contrario, <em>error</em> = -1 y se eliminará el respectivo
        proceso del procesador.

    */
    void baja_proceso_procesador(const string& ident, int ident_proc, int& error);

    /** @brief Avanzar <em>t</em> unidades de tiempo en los procesadores del clúster.

        \pre El parámetro implícito está inicializado.
        \post Se avanza <em>t</em> unidades de tiempo a cada proceso de cada procesador
        del clúster. Si el tiempo de un proceso ha finalizado, se elimina del
        procesador. En caso contrario, los procesos progresan <em>t</em> unidades
        de tiempo.

    */
    void avanzar_tiempo(int t);

    /** @brief Escribir los procesos de un procesador

        \pre El parámetro implícito está inicializado.
        \post Si no existe un procesador en el clúster con el mismo identificador
        que <em>ident</em>, <em>error</em> >= 0. En caso contrario, <em>error</em> = -1 y se escriben los procesos
        pertenecientes al procesador con identificador ident (en orden
        creciente de memoria).

    */
    void imprimir_procesador(const string& ident, int& error);

    /** @brief Escribir los procesadores del clúster

        \pre El parámetro implícito está inicializado.
        \post Escribe todos los procesadores del clúster (orden creciente de
        identificador). Para cada procesador, se escriben sus
        respectivos procesos.

    */
    void imprimir_procesadores_cluster();

    /** @brief Escribe la estructura del clúster

        \pre El parámetro implícito está inicializado.
        \post Escribe la estructura de los procesadores del clúster.

    */
    void imprimir_estructura_cluster();

    /** @brief Compacta la memoria de un procesador

        \pre El parámetro implícito está inicializado.
        \post Si no existe un procesador en el clúster con el mismo identificador
        que <em>ident</em>, <em>error</em> >= 0. En caso contrario, <em>error</em> = -1 y se desplazan todos los
        procesos hacia el principio de la memoria del procesador (
        sin huecos, sin solaparse y respetando el orden inicial).

    */
    void compactar_memoria_procesador(const string& ident, int& error);

    /** @brief Compacta la memoria del clúster

        \pre El parámetro implícito está inicializado.
        \post En cada procesador, se desplazan todos los procesos hacia
        el principio de la memoria del procesador (
        sin huecos, sin solaparse y respetando el orden inicial).

    */
    void compactar_memoria_cluster();
    
};
#endif
