/** @file Procesador.hh
    @brief Especificación de la clase Procesador
*/

#ifndef _PROCESADOR_HH_
#define _PROCESADOR_HH_
#include "Proceso.hh"

#ifndef NO_DIAGRAM
#include <list>
#include <map>
#include <string>
#include <iostream>
#include <set>
#endif
using namespace std;


/** @class Procesador
    @brief Representa un Procesador

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
        \post El resultado es un procesador inicializado con un identificador <em>ident</em> y una memoria <em>mem</em>.
    */
    void inicializar(const string& ident, int mem);

    /** @brief Avanzar <em>t</em> unidades de tiempo en los procesos del procesador.

        \pre El parámetro implícito está inicializado.
        \post Se avanza <em>t</em> unidades de tiempo en cada proceso. 
        Si el tiempo de un proceso ha finalizado, se elimina del
        procesador. En caso contrario, los procesos progresan <em>t</em> unidades
        de tiempo.

    */
    void avanzar_tiempo(int time);

    /** @brief Movimiento de procesos en la memoria del procesador.

        \pre El parámetro implícito está inicializado.
        \post Se mueven los procesos hacia el principio de la memoria
        del parámetro implícito (sin huecos, sin solaparse y respetando el orden inicial).

    */
    // void mover_procesos_memoria(); -------------------------------------------------------------

    /** @brief Escritura de los procesos de un procesador. 

        \pre El parámetro implícito debe estar inicializado.
        \post Escribe los procesos del parámetro implícito.
    */
    void escribir_procesos();

    /** @brief Añadir un proceso del procesador.

        \pre El parámetro implícito debe estar inicializado.
        \post Añade el proceso <em>proc</em> al parámetro implícito.
    */
    int introducir_proceso(const Proceso& proc);

    int siguiente_proceso(map<int, Proceso>::const_iterator it);

    void recalcular_huecos();

    /** @brief Eliminar un proceso del procesador.

        \pre El parámetro implícito debe estar inicializado.
        \post Elimina un proceso con el identificador <em>ident_proceso</em> del parámetro implícito.
    */
    int eliminar_proceso(int ident_proceso);

    int ultima_pos(map<int, Proceso>::const_iterator it) const;

    int primera_pos(map<int, Proceso>::const_iterator it) const;

    //Consultoras -------------------------------------------------------------

    /** @brief Consultora del identificador. 

        \pre El parámetro implícito debe estar inicializado.
        \post Devuelve el identificador del parámetro implícito.
    */
    string consultar_identificador() const;

    /** @brief Consultora de la memoria. 

        \pre El parámetro implícito debe estar inicializado.
        \post Devuelve la memoria del parámetro implícito.
    */
    int consultar_memoria() const;

    /** @brief Consultora de los procesos del parámetro implicito. 

        \pre El parámetro implícito debe estar inicializado.
        \post Devuelve los procesos del parámetro implícito.
    */
    // list<Proceso> consultar_procesos() const; --------------------------------------------------------------

    /** @brief Existencia de un determinado proceso en un procesador. 

        \pre El parámetro implícito debe estar inicializado.
        \post Devuelve true si el proceso con el identificador <em>ident</em> existe
        en el parámetro implícito. En caso contrario, devuelve false.
    */
    bool existe_proceso(int ident);

    bool cabe_proceso(int mem);

    void imprimir_huecos();

    private:

    string identificador;

    int espacio_libre;
    int espacio_total;

    map<int, Proceso> memoria; // Llave: posicion del proceso  Valor: Proceso

    map<int, int> ident_pos; // Llave: identificador del proceso  Valor: Posicion del proceso en memoria
    
    map<int, set<int>> huecos; // Llave: Valor de hueco  Valor: Posiciones donde se encuentra un hueco de ese valor 
    // Lower_bound --> it a la siguiente posicion que mejor está para el hueco. Sino, .end();
    
};
#endif