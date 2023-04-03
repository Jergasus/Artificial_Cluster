/** @file Cluster.hh
    @brief Especificación de la clase Cluster 
*/

#ifndef _CLUSTER_HH_
#define _CLUSTER_HH_
#include "Procesador.hh"

#ifndef NO_DIAGRAM
#include "BinTree.hh"
#endif

/** @class Cluster
    @brief Representa un Cluster 
*/


class Cluster {
    public:
    // Constructoras ---------------------------------------------------
    /** @brief Creadora por defecto.
     Se ejecuta de forma automatica al declarar un cluster.
     \pre <em>Cierto</em>
     \post El resultado es un cluster no inicializado (sin procesadores).
    */
    Cluster();

    // Modificadoras ---------------------------------------------------

    // Estas 2 llaman a leer_cluster!!
    void configurar_cluster();
    void modificar_cluster(string identificador);
    bool existe_procesador(BinTree<Procesador>& cluster, string identificador);

    private:
    // Lee el BinTree de procesadores.
    BinTree<Procesador> cluster;
    void leer_cluster(BinTree<Procesador>& cluster);

    // Struct de prioridades

};
#endif
