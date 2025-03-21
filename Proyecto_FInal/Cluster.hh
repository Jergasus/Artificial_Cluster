/** @file Cluster.hh
    @brief Especificación de la clase Cluster 
*/

#ifndef _CLUSTER_HH_
#define _CLUSTER_HH_
#include "Procesador.hh"

#ifndef NO_DIAGRAM
#include "BinTree.hh"
#include <iostream>
#include <map>
#include <string>
#endif
using namespace std;

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
        en el procesador, ocupando su respectiva memoria. El proceso se coloca
        en la posición más pequeña que deje el hueco más ajustado.

    */
    void alta_proceso_procesador(const string& ident, const Proceso& proc, int& error);

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
        pertenecientes al procesador con identificador ident (en orden creciente de memoria).

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

    /** @brief Recibe los procesos del la acción: <em>enviar_procesos_cluster</em>

        \pre El parámetro implícito está inicializado.
        \post Recibe un proceso enviado por la acción:
        <em>enviar_procesos_cluster</em>.

    */
    bool recibir_proceso(Proceso& proc);

    private:

    /** @brief BinTree de iteradores. Los valores del árbol apuntan al mapa de procesadores <em>Procesadores</em>.
    */

    BinTree<map<string, Procesador>::iterator> cluster;

    /** @brief Mapa de procesadores. La llave hace referencia al identificador del procesador. El valor
        hace referencia al procesador.
    */

    map<string, Procesador> Procesadores;

    /** @brief Descartar un cluster en la funcion modificar_cluster(mc)

        \pre El parámetro implícito está inicializado.
        \post Descarta el bintree auxiliar creado a la hora de llamar a la funcion modificar_cluster. 
    */

    void descartar_bintree_aux();

    /** @brief Modifica un cluster auxiliar.

        \pre El parámetro implícito está inicializado.
        \post Busca por todo el árbol el procesador con identificador <em>ident</em>. Cuando lo encuentre, mirará
        si .left() y .right() son vacíos, con la intención de comenzar
        un nuevo árbol a partir de ahí. En caso que dicha comprovación dé afirmativo, se pondrá en 
        la posición del procesador el nuevo árbol. En caso contrario, no hará nada.
    */

    void modificar_cluster_aux(BinTree<map<string, Procesador>::iterator>& clust, const string& ident, int& error);

    /** @brief Lee un cluster.

        \pre El parámetro implícito está inicializado.
        \post Genera un cluster. Se utiliza en la función: configurar_cluster(cc).
    */

    void leer_cluster(BinTree<map<string, Procesador>::iterator>& clust);

    /** @brief Imprime la estructura de un cluster

        \pre El parámetro implícito está inicializado.
        \post Imprime la estructura del cluster.
    */

    void imprimir_estructura(const BinTree<map<string, Procesador>::iterator>& clust);

    /** @brief Mira el procesador apto para recibir el proceso en la función: enviar_procesos_cluster(epc)

        \pre El parámetro implícito está inicializado.
        \post Por el parámetro de <em>procesador</em> se pasa el procesador apto. En caso que no exista, 
        el proceso se mantiene en el área de espera.
    */

    void procesador_apto(const BinTree<map<string, Procesador>::iterator>& clust, map<string, Procesador>::iterator& procesador, int& hueco_min, int prof_actual, int& prof_procesador, Proceso& proc);

};
#endif
