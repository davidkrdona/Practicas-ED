//Pila_maxmin.cpp
#include “Pila_maxmin.h”
#if CUAL_COMPILA==1
#include <pila_maxmin_vd.cpp>
#elif CUAL_COMPILA==2
#include <pila_maxmin_list.cpp>
#else
#include <pila_maxmin_cola.cpp>
#endif
