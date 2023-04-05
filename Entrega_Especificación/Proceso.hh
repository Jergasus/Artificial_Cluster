/** @file Proceso.hh
    @brief Especificación de la clase Proceso 
*/

#ifndef _PROCESO_HH_
#define _PROCESO_HH_


/** @class Proceso
    @brief Representa un proceso

    Dispone de dos estados posibles (inicializado / no inicializado); si está inicializado tiene un identificador, la memoria que ocupan y un tiempo de ejecución determinado. Si no está incializado, no contiene propiedades. En este caso, solo se puede inicilizar

*/
class Proceso {
    public:
    //Constructoras ---------------------------------------------------------------

    /** @brief Creadora por defecto. 

        Se ejecuta automáticamente al declarar un proceso.
        \pre <em>cierto</em>
        \post El resultado es un proceso sin identificador, memoria ni tiempo de ejecución.
    */
    Proceso();
    /** @brief Creadora por defecto. 

        Se ejecuta automáticamente al declarar una proceso.
        \pre ident >= 0, mem >= 0, timeo >= 0.
        \post El resultado es un proceso inicializado con dicho identificador, la memoria que ocupa y el tiempo de ejecución;
    */
    Proceso(int ident, int mem, int time);

    //Consultoras ------------------------------------------------------------------

    /**
     @brief Consultora del identificador
     \pre Que el parámetro ímplicito esté inicializado.
     \post Devuelve el identificador del parámetro ímplicito.
    */
    int consultar_ident() const;
    /**
     @brief Consultora de la memoria
     \pre Que el parámetro ímplicito esté inicializado.
     \post Devuelve la memoria del parámetro ímplicito.
    */
    int consultar_mem() const;
    /**
     @brief Consultora del tiempo de ejecución
     \pre Que el parámetro ímplicito esté inicializado.
     \post Devuelve el tiempo de ejecución del parámetro ímplicito
    */
    int consultar_tiempo() const;

    //Modificadoras -------------------------------------------------

    /**
     @brief Modificadora del tiempo de ejecución del procesador.
     \pre Que el parámetro ímplicito esté inicializado.
     \post Devuelve el nuevo tiempo de ejecución después de haber restado al tiempo anterior el tiempo pasado por parámetro. Si el tiempo es del parámetro es mayor que el anterior, se elimina el proceso.
    */
    void avanzar_tiempo(int time);
    // bool avanzar_tiempo() --> Hacer aqui lo relacionado con el avanzar tiempo
};
#endif