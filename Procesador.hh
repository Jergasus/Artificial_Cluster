/** @file Procesador.hh
    @brief Especificación de la clase Procesador
*/

#ifndef _PROCESADOR_HH_
#define _PROCESADOR_HH_
#include "Proceso.hh"


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

    private:
    string identificador;
    int memoria;
};
#endif