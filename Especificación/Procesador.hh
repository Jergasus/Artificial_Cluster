/** @file Procesador.hh
    @brief Especificación de la clase Procesador
*/

#ifndef _PROCESADOR_HH_
#define _PROCESADOR_HH_
#include "Proceso.hh"

#ifndef NO_DIAGRAM
#include <list>
#include <vector>
#include <string>
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

    /** @brief Inicialización de un procesador. 

        \pre mem >= 0
        \post El resultado es un procesador inicializado con un identificador ident y una memoria mem.
    */
    void inicializar(string ident, int mem); // Crear vector con size mem y luego ponerlo en procesos_pendientes

    void avanzar_tiempo(int tiempo);

    void mover_procesos_memoria();
    /** @brief Escritura de los procesos de un procesador. 

        \pre El parámetro implícito debe estar inicializado.
        \post Escribe los procesos del parámetro implícito.
    */
    void escribir_procesos();

    void añadir_proceso(Proceso proceso);

    void eliminar_proceso(int ident_proceso);

    //Consultoras -------------------------------------------------------------

    /** @brief Consultora del identificador. 

        \pre El parámetro implícito debe estar inicializado.
        \post Devuelve el identificador del parámetro implícito.
    */
    string consultar_identificador();
    /** @brief Consultora de la memoria. 

        \pre El parámetro implícito debe estar inicializado.
        \post Devuelve la memoria del parámetro implícito.
    */
    int consultar_memoria();
    /** @brief Consultora de los procesos del parámetro implicito. 

        \pre El parámetro implícito debe estar inicializado.
        \post Devuelve los procesos del parámetro implícito.
    */
    list<Proceso> consultar_procesos();
    /** @brief Existencia de un determinado proceso en un procesador. 

        \pre El parámetro implícito debe estar inicializado.
        \post Devuelve true si el proceso con el identificador ident existe
        en el parámetro implícito. En caso contrario, devuelve false.
    */
    bool existe_proceso(int ident);

    private:
    string identificador;
    int memoria;
    list<Proceso> procesos;
    vector<int> procesos_pendientes;
    
};
#endif