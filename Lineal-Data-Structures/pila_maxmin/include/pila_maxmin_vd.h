/******************************************************************************
*
* ED - Estructura de Datos
* Grado en Ingeniería Informática
*
* 2016 - David Fernando Guerrero Cardona
*
******************************************************************************/

/**
  * @file pila_maxmin_vd.h
  * @brief Fichero cabecera del TDA Pila_max usando un vector dinámico
  *
  * Gestiona una secuencia de elementos con su máximo
  */

#ifndef __PILA_MAXMIN_
#define __PILA_MAXMIN_

#include <iostream>
#include <vector_dinamico.h>

using namespace std;

class Pila_maxmin
{

  private:
  /**
    * @brief Rep de pila_maxmin
    *
    * Guardamos los datos de vector_dinamico de tipo elemento
    * En este caso no hay invariante de la representación ya que
    * todo se define en la clase vector_dinamico
    *
    */
    Vector_Dinamico<elemento> datos;

  public:

      /**
       * @brief Indica si la pila está vacia
       * @return Un valor booleano, true si la pila esta vacia, false si contiene
       * al menos un elemento
       */
      bool vacia() const
      {
        return (datos.size() == 0);
      }

      /**
       * @brief Añade un elemento al final de la cola
       * @param ele Elemento que se va a añadir.
       */
      void poner(int ele);

      /**
       * @brief Quita el elemento del frente de la cola
       */
      void quitar()
      {
        datos.delete_last();
      };

      /**
       * @brief Devuelve el número de elementos de la cola
       */
      int num_elementos() const
      {
        return datos.size();
      }

      /**
       * @brief Devuelve el ultimo elemento de la pila
       * @return Un elemento
       */
      elemento tope();

  };

  #include <pila_maxmin_vd.cpp>

  #endif
