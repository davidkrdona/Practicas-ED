/******************************************************************************
 *
 * ED - Estructura de Datos
 * Grado en Ingeniería Informática
 *
 * 2016 - David Fernando Guererro Cardona
 *
 ******************************************************************************/

/**
  * @file conjuntofrases.h
  * @brief Fichero cabecera del TDA ConjuntoFrases
  *
*/
#ifndef _CONJUNTO_FRASES_H_
#define _CONJUNTO_FRASES_H_
#include <vector>
#include <string>
#include <fstream>
#include <string>
#include <cstdlib>
#include "frase.h"

using namespace std;
/**
  * @file conjuntofrases.h
	* @brief T.D.A. ConjuntoFrases
  *
  * Esta clase carga una serie de frases con sus respectivas traducciones y
  * permite consultar las traducciones de una determinada frase
  *
  * Un ejemplo de su uso:
  * @include pruebatrad_test.cpp
  *
  */
class ConjuntoFrases{
	private:
		/**
		  * @page repConjunto Representación del TDA ConjuntoFrases
		  * vector<Frase> FraseTradu
		  *
		  * @section invConjunto Invariante de la representación
		  * Las palabras deberan estar definidas corretamente segun las restricciones
		  * propias de la clase frase
		  *
		  * @section faConjunto Función de abstracción
		  * Un vector de objetos de la clase frase
		  *
		  * Un objeto válido @e rep del ConjuntoFrases representa al valor
		  * (vector de frase)
		  *
		  */

			/**
		   * @brief Coleccion de instancias de la clase frase
		   */
			 vector<Frase> FraseTradu;

	public:
    /**
		* @brief Obtiene el tamaño del ConjuntoFrases
		* @return Devuelve un entero sin signo
		*/
		unsigned int Size() const;

	  /**
  	* @brief Obtiene una Frase con su palabraOrigen f y respectivas traducciones
		* @pre el string f debe ser una Frase que ya exista
  	* @return Devuelve una Frase con sus atributos PalabraOrigen y traducciones
  	*/
		Frase GetTraducciones(string f);

		/**
	 * @brief Comprueba si un string f esta contenido dentro de una Frase en la coleccion de ConjuntoFrases
	 * @param f contiene una cadena
	 * @pre string f debe no tener acentos, ni caracteres especiales
	 * @return Devuelve el ConjuntoFrases en el cual el string f esta contenido
	 */
		ConjuntoFrases Contenga(string f);

		/**
		* @brief Inserta el objeto Palabra en el vector PalaDest
		* @param string f donde hay una posible frase
		*/
		bool Esta(string f);

		/**
		* @brief Inserta el objeto Frase en el vector FraseTradu
		* @param Frase &F objeto de la clase Frase
   	*/
		void add(Frase f);

		/**
  	* @brief Entrada de un objeto de la clase CF
  	* @param flujo ostream de salida
  	* @param CF ConjuntoFrases
		* @pre CF Flujo han de pasarse por referencia
  	*/
		friend ostream& operator<<(ostream &flujo, ConjuntoFrases &CF);

		/**
		  * @brief Entrada de un ConjuntoFrases desde istream
		  * @param flujo stream de entrada
		  * @param CF ConjuntoFrases que recibe el valor
		  * @return La referencia al istream
		  * @pre La entrada es un fichero separado por ";" con una palabra origen y al
		  * menos una palabra de traduccion
		  */
		friend istream& operator>>(istream &flujo, ConjuntoFrases &CF);
};

#endif
