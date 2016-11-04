/******************************************************************************
 *
 * ED - Estructura de Datos
 * Grado en Ingeniería Informática
 *
 * 2016 - David Fernando Guererro Cardona
 *
 ******************************************************************************/

/**
  * @file frase.h
  * @brief Fichero cabecera del TDA Frase
*/

#ifndef _FRASE_H_
#define _FRASE_H_
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

/**
  * @file frase.h
  * @brief T.D.A. Frase
  *
  * Una instancia f del tipo de datos abstracto Frase es un objeto
  * que contiene una frase y una coleccion de traducciones asociadas a esa
  * frase.
  *
  * Se compone de una frase en el idioma origen y se transforma en una o mas
  * frases  en el idioma destino. Las palabras pueden contener mas de un significado.
  * Asi tanto en el origen como en el destino puede tener mas de un vocablo.
  * Las vocablos no contendran acentos, tildes ni el caracter ñ.
  * Los vocablos si existe mas de uno se separan por un espacio.
  *
  * Lo representamos como:
  * "palabraOrigen" : <"traduccion1","traduccion2",.......,"traduccionN">
  *
  * Ejemplos:
  * "A bird in the hand is worth two in the bush":Mas vale pajaro en mano que ciento volando
  * "Give a dog a bad name and hang it":<Hazte fama y echate a dormir,Un perro mate y mataperros me llamaron>
  *
  */

class Frase {
  private:
  /**
    * @page repConjunto Representación del TDA Frases
    * string palabraOrigen
    * vector<string> traducciones;
    *
    * @section invConjunto Invariante de la representación
    * Si existe mas de una traduccion se separa por comas
    * Las Frases no contienen acentos ni caracteres "especiales"
    *
    * @section faConjunto Función de abstracción
    * La palabra origen es un String
    * Las traducciones asociadas se almacenan en un vector de string
    *
    * Un objeto válido @e rep del TDA Frase representa al valor
    * "A bird in the hand is worth two in the bush":<"Mas vale pajaro en mano que ciento volando">
    *
    */

    /**
    * @brief PalabraOrigen
    */
    string palabraOrigen;

    /**
    * @brief Colección de traducciones
    */
    vector<string> traducciones;

  public:
    /**
     * @brief Constructor de una frase en el cual inicializa los valores por defecto
    */
    Frase();

    /**
     * @brief Setter de una frase: PalabraOrigen = f
     * @pre f debe ser un string
    */
    void setPalabraOrigen(string f);

    /**
     * @brief Getter de una frase
     * @pre Debe estar en el vector de traducciones
     * @return Devuelve la palabra origen de una instancia de la clase Frase
     */
    string getPalabraOrigen();

    /**
     * @brief setter de las traducciones: traducciones = t
     * @pre Debe ser un vector de string
     */
    void setTraducciones(vector<string> t);

    /**
    * @brief Obtiene las traducciones de una Palabra Origen
    * @param i entero de la posicion donde esta la traduccion
    * @return Devuelve una coleccion de traducciones de una instancia de la clase Frase
    */
    vector<string> GetDestino();

    /**
    * @brief Obtiene el numero de traducciones de una Palabra Origen
    * @return Devuelve un entero sin signo el cual representa ese número
    */
    unsigned int numeroTraducciones();

    /**
      * @brief Entrada de una Frase desde istream
      * @param flujo stream de entrada
      * @param F Frase que recibe el valor
      * @return La referencia al istream flujo
      * @pre La entrada de una cadena separada por ";" con una palabra origen y al
      * menos una frase de traduccion
    */
    friend istream& operator>>(istream &flujo, Frase &F);

};
#endif
