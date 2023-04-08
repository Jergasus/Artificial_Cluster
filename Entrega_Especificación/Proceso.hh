/** @file Proceso.hh
    @brief Especificación de la clase Proceso 
*/

#ifndef _PROCESO_HH_
#define _PROCESO_HH_


/** @class Proceso
    @brief Representa un Proceso

    Dispone de dos estados posibles (inicializado / no inicializado); si está inicializado tiene un identificador, la memoria que ocupan y un tiempo de ejecución determinado. Si no está incializado, no contiene propiedades. En este caso, solo se puede inicilizar

*/
class Proceso {
    public:

    //Constructoras ---------------------------------------------------------------

    /** @brief Creadora por defecto. 

        Se ejecuta automáticamente al declarar un proceso.
        \pre <em>cierto</em>
        \post El resultado es un proceso sin identificador, sin memoria y sin tiempo.
    */
    Proceso();

    /** @brief Creadora por defecto. 

        \pre <em>ident</em> >= 0, <em>mem</em> >= 0, <em>time</em> >= 0.
        \post El resultado es un proceso inicializado con un identificador <em>ident</em>,
        memoria <em>mem</em> y tiempo <em>time</em>.
    */
    Proceso(int ident, int mem, int time);

    //Consultoras ------------------------------------------------------------------

    /**
     @brief Consultora del identificador

     \pre El parámetro implícito debe estar inicializado.
     \post Devuelve el identificador del parámetro implícito.
    */
    int consultar_ident() const;

    /**
     @brief Consultora de la memoria

     \pre El parámetro implícito debe estar inicializado.
     \post Devuelve la memoria del parámetro implícito.
    */
    int consultar_memoria() const;

    /**
     @brief Consultora del tiempo de ejecución

     \pre El parámetro implícito debe estar inicializado.
     \post Devuelve el tiempo de ejecución del parámetro implícito
    */
    int consultar_tiempo() const;

    //Modificadoras -------------------------------------------------

    /**
     @brief Avanza el tiempo de un proceso.

     \pre El parámetro implícito debe estar inicializado.
     \post Devuelve true si el tiempo del proceso - <em>time</em> es > 0.
     En caso contrario, devuelve false.
    */
    bool avanzar_tiempo(int time);
};
#endif