/**
@file Cluster.hh
@brief Especificación de la clase Cluster 
*/

#ifndef _CLUSTER_HH_
#define _CLUSTER_HH_
#include "Procesador.hh"

#ifndef NO_DIAGRAM
#include "BinTree.hh"
#endif

/**
@class Cluster
@brief Representa un Cluster 
*/


class Cluster {
    public:

    Cluster(BinTree<Procesador>& cluster);
};
#endif



/* Estudiant est;
    est.llegir();
    if (est.consultar_DNI() != 0) {
        BinTree<Estudiant> left, right;
        read_bintree_est(left);
        read_bintree_est(right);
        a = BinTree<Estudiant>(est, left, right);
    } */