/******************************************************************************
 *
 * ED - Estructura de Datos
 * Grado en Ingeniería Informática
 *
 * 2016 - David Fernando Guerrero Cardona
 * ---------------------------------------------
 *
 *  Cabecera Clase Pila_max
 *
 * De esta forma eligiendo un valor para  CUAL_COMPILA elegimos que
 * representación usar para nuestra pila_maxmin. Por lo tanto cuando
 * compilemos nuestros proyectos a la hora de compilar Pila
 * solamente tenemos que compilar Pila_maxmin.cpp.
 * No se compila ni Pila_maxmin_VD.cpp, ni
 * Pila_maxmin_Lista.cpp ni Pila_maxmin_Cola.cpp.
 *
 ******************************************************************************/
using namespace std;

/**
 * @brief TDA Elemento
 * Es un contenedor donde almacenaremos los valores a agregar a la pila <valor,max,min>
 *
 */
struct elemento
 {
     int ele;
     int maximo;
     int minimo;

     /**
      * @brief Sobrecarga del operador <<
      * @details pinta el elemento y su máximo de la siguiente forma:
      * elemento (maximo) (minimo)
      *
      * @param os stream de salida
      * @param e elemento
      * @return salida dependiendo de lo que se quiera imprimir
      */
     friend ostream & operator<<(ostream &os, const  elemento& e)
     {
   	   os << e.ele << " (" << e.maximo << ")" << " (" << e.minimo << ")" endl;
     	 return os;
     };
 };

#define CUAL_COMPILA 3
#if CUAL_COMPILA==1
#include <pila_maxmin_vd.h>
#elif CUAL_COMPILA==2
#include <pila_maxmin_list.h>
#else
#include <pila_maxmin_cola.h>
#endif
