/******************************************************************************
 *
 * ED - Estructura de Datos
 * Grado en Ingeniería Informática
 *
 * 2016 - David Fernando Guerrero Cardona
 *
 ******************************************************************************/

 /**
   * @file vector_dinamico.h
   * @brief Fichero cabecera del TDA Vector Dinamico
   *
   * Se crea un vector con capacidad de incremente y decremento de tamaño
   */

#ifndef __Vector_Dinamico_H__
#define __Vector_Dinamico_H__

/**
 *  @brief T.D.A. Vector_Dinamico
 *
 * Una instancia @e v del tipo de datos abstracto @c Vector_Dinamico sobre el
 * tipo @c float es un array 1-dimensional de un determinado tamaño @e n, que
 * puede crecer y decrecer a peticion del usuario. Lo podemos representar como
 *
 *  {v[0],v[1],...,v[n-1]}
 *
 * donde  v[i] es el valor almacenado en la posición  i del vector
 *
 * La eficiencia en espacio es @e O(n).
 *
 *
 */

 template <class T>
 class Vector_Dinamico {
  private:
    T * datos; /**< Apunta a los elementos del vector */
    int nelementos; /**< Indica el número de elementos en @c datos */
  public:
};

#include <vector_dinamico.cpp>

#endif
