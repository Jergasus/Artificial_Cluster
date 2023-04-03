/** @file Procesador.hh
    @brief Especificación de la clase Procesador
*/

#ifndef _PROCESADOR_HH_
#define _PROCESADOR_HH_
#include "Proceso.hh"

#ifndef NO_DIAGRAM
#include <list>
#endif


/** @class Procesador
    @brief Representa un procesador

    Dispone de dos estados posibles (inicializado / no inicializado); si está inicializado tiene una memoria y unos procesos. En caso contrario, es vacío.
*/
class Procesador {
    public:
    //Constructoras ---------------------------------------------------------------

    /** @brief Creadora por defecto. 

        Se ejecuta automáticamente al declarar un procesador.
        \pre <em>cierto</em>
        \post El resultado es un procesador sin memoria ni procesos.
    */
    Procesador();
    //Modificadoras ---------------------------------------------------------------
    bool existe_proceso(int ident);
    bool cabe_proceso(int ident);
    void añadir_proceso(Proceso proceso);
    void eliminar_proceso(int ident_proceso);
    void consultar_identificador();
    void consultar_memoria();
    void mover_procesos();
    void ordenar_procesos_mem();
    void escribir_procesos(string ident);

    private:
    string identificador;
    int memoria;
    list<Proceso> procesos;
};
#endif