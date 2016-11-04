#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cstring>
#include "frase.h"

using namespace std;

Frase::Frase(){
  palabraOrigen="";
}

string Frase::getPalabraOrigen(){
  return palabraOrigen;
}

void Frase::setPalabraOrigen(string f){
  palabraOrigen = f;
}

void Frase::setTraducciones(vector<string> t){
  traducciones = t;
}

vector<string> Frase::GetDestino(){
  return traducciones;
}

unsigned int Frase::numeroTraducciones(){
  return traducciones.size();
}

istream& operator>>(istream &flujo, Frase &F){
  string aux;
  unsigned int pos =0;
  string palabra_Origen;
  string traduccion_es;
  getline(flujo,aux); //obtiene todo el flujo
  pos=aux.find(";"); //cuando encontramos el ; guardamos su posicion
  palabra_Origen = aux.substr(0,pos); //se guarda desde 0 a posicion
  F.palabraOrigen =palabra_Origen;
  traduccion_es = aux.substr(pos+1);
  F.traducciones.push_back(traduccion_es);
  return flujo;
}
