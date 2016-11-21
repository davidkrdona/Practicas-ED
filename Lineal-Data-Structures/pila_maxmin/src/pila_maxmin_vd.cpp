/******************************************************************************
*
* ED - Estructura de Datos
* Grado en Ingeniería Informática
*
* 2016 - David Fernando Guerrero Cardona
*
*******************************************************************************/

#include <cassert>

elemento Pila_maxmin::tope()
{
  assert(num_elementos()>0);
  return datos[num_elementos()-1];
}

//MINIMO ADD

void Pila_maxmin::poner(int valor)
{
  elemento nuevo;
  nuevo.ele = valor;

  if (vacia())
  {
    nuevo.maximo = valor;
    nuevo.minimo = valor;
  }
  else
  {
    elemento anterior = tope();
    //Add minimo
    nuevo.maximo = (valor > anterior.maximo) ? valor : anterior.maximo;
  }

  datos.add(nuevo);
}
