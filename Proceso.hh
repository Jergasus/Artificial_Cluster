/** @file Proceso.hh
    @brief Especificación de la clase Proceso 
*/

#ifndef _PROCESO_HH_
#define _PROCESO_HH_


/** @class Lavadora
    @brief Representa una lavadora 

    Dispone de dos estados posibles (inicializada / no inicializada); si está inicializada tiene un peso máximo y un color y puede contener prendas de dicho color hasta alcanzar dicho peso máximo; si no está inicializada no contiene ninguna prenda y solo se puede inicializar

    Todas las operaciones son de <b>coste constante</b> salvo las indicadas */
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
        \pre Identificador >= 0, memoria >= 0, tiempo >= 0.
        \post El resultado es un proceso inicializado con dicho identificador, memoria y tiempo de ejecución;
    */
    Proceso(int identificador, int memoria, int tiempo);

    //Consultoras ------------------------------------------------------------------
    /**
     @brief Consultora del identificador
     \pre Que el parámetro ímplicito esté inicializado.
     \post Devuelve el identificador del parámetro ímplicito.
    */
    void consultar_ident() const;
    /**
     @brief Consultora de la memoria
     \pre Que el parámetro ímplicito esté inicializado.
     \post Devuelve la memoria del parámetro ímplicito.
    */
    void consultar_mem() const;
    /**
     @brief Consultora del tiempo de ejecución
     \pre Que el parámetro ímplicito esté inicializado.
     \post Devuelve el tiempo de ejecución del parámetro ímplicito
    */
    void consultar_tiempo() const;
    //Modificadoras -------------------------------------------------
    /**
     @brief Modificadora del tiempo del ejecución del procesador.
     \pre Que el parámetro ímplicito esté inicializado.
     \post Devuelve el nuevo tiempo de ejecución después de haber restado al tiempo anterior el tiempo pasado por parámetro. Si el tiempo es del parámetro es mayor que el anterior, se elimina el proceso.
    */
    void modificar_tiempo(int tiempo);
    
    



    private:
    int identificador;
    int memoria;
    int tiempo;


};
#endif