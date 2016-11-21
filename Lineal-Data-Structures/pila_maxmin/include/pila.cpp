/******************************************************************************
*
* ED - Estructura de Datos
* Grado en Ingeniería Informática
*
* 2016 - David Fernando Guerrero Cardona
*
******************************************************************************/
/**
  * @file pila.cpp
  * @brief Implementación del TDA Pila
  *
  */

#include <cassert>


template <class T>
Pila<T>::Pila(const Pila<T> & p)
{
  if (p.primera!=0) {
    Celda *orig=p.primera;
    Celda *nueva;
    primera=nueva= new Celda(orig->elemento,0);
    orig=orig->siguiente;
    while (orig!=0) {
      nueva->siguiente=new Celda(orig->elemento,0);
      nueva=nueva->siguiente;
      orig=orig->siguiente;
    }
  }
  else primera=0;
  num_elem=p.num_elem;
}

template <class T>
Pila<T>::~Pila()
{
  Celda *aux;
  while (primera!=0) {
    aux= primera;
    primera=primera->siguiente;
    delete aux;
  }
}


template <class T>
Pila<T>& Pila<T>::operator=(const Pila<T> & p)
{
  if (this!=&p) {
    Celda *aux;
    while (primera!=0) {
      aux= primera;
      primera=primera->siguiente;
      delete aux;
    }
    if (p.primera!=0) {
      Celda *orig=p.primera;
      Celda *nueva;
      primera=nueva= new Celda(orig->elemento,0);
      orig=orig->siguiente;
      while (orig!=0) {
        nueva->siguiente=new Celda(orig->elemento,0);
        nueva=nueva->siguiente;
        orig=orig->siguiente;
      }
    }
    num_elem=p.num_elem;
  }
  return *this;
}

template <class T>
void Pila<T>::poner(const T & elem)
{
  primera= new Celda(elem,primera);
  num_elem++;
}

template <class T>
void Pila<T>::quitar()
{
  assert(primera!=0);
  Celda *aux=primera;
  primera= primera->siguiente;
  delete aux;
  num_elem--;
