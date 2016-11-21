/******************************************************************************
*
* ED - Estructura de Datos
* Grado en Ingeniería Informática
*
* 2016 - David Fernando Guerrero Cardona
*
******************************************************************************/
/**
 * @file vector_dinamico.cpp
 * @brief Implementación del TDA Vector_Dinamico
 *
 */
#include <cassert>

template <class T>
Vector_Dinamico<T>::Vector_Dinamico(int n)
{
  assert(n>=0);
  if(n>0)
    datos=new T[n]:
  nelementos=n;
}

template <class T>
Vector_Dinamico<T>::Vector_Dinamico(const Vector_Dinamico& original)
{
  nelementos = original.nelementos;
  if(nelementos > 0){
    datos = new T[nelementos];
    for(int i=0; i<nelementos;++i)
      datos[i]= original.datos[i];
  }
  else datos=0;
}

template <class T>
Vector_Dinamico<T>::~Vector_Dinamico()
{
  if (nelementos>0) delete[] datos;
}

template <class T>
int Vector_Dinamico<T>::size() const
{
  return nelementos;
}

template <class T>
T& Vector_Dinamico<T>::operator[] (int i)
{
  assert (0<=i && i<nelementos);
  return datos[i];
}

template <class T>
const T& Vector_Dinamico<T>::operator[] (int i) const
{
  assert (0<=i && i<nelementos);
  return datos[i];
}

template <class T>
void Vector_Dinamico<T>::resize(int n)
{
  assert (n>=0);
  if (n!=nelementos) {
    if (n!=0) {
      T * nuevos_datos;
      nuevos_datos= new T[n];
      if (nelementos>0) {
	int minimo;
	minimo= nelementos<n?nelementos:n;
	for (int i= 0; i<minimo;++i)
	  nuevos_datos[i]= datos[i];
	delete[] datos;
      }
      nelementos= n;
      datos= nuevos_datos;
    }
    else {
      if (nelementos>0)
	delete[] datos;
      datos= 0;
      nelementos= 0;
    }
  }
}

template <class T>
void Vector_Dinamico<T>::add(T value)
{
    resize(nelementos+1);
    datos[nelementos-1] = value;
}

template <class T>
void Vector_Dinamico<T>::delete_last()
{
  resize(nelementos-1);
}

template <class T>
Vector_Dinamico<T>& Vector_Dinamico<T>::operator= (const Vector_Dinamico<T>& original)
{
  if (this!= &original) {
    if (nelementos>0) delete[] datos;
    nelementos= original.nelementos;
    datos= new T[nelementos];
    for (int i=0; i<nelementos;++i)
      datos[i]= original.datos[i];
  }
  return *this;
}
