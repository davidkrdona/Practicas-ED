#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include "frase.h"
#include "conjuntofrases.h"

using namespace std;

unsigned int ConjuntoFrases::Size() const{
  return FraseTradu.size()-1;
}

Frase ConjuntoFrases::GetTraducciones(string f){
    bool found =  false;
    Frase ff;
    string ffcomp = f;
    std::transform(ffcomp.begin(), ffcomp.end(), ffcomp.begin(), ::tolower);
    ff.setPalabraOrigen(ffcomp);
    unsigned int i=0;
    vector<string> aux;

    for (i=0; !found && i<FraseTradu.size(); ++i){
      string frase = FraseTradu[i].getPalabraOrigen();
      std::transform(frase.begin(), frase.end(), frase.begin(), ::tolower);
      if (frase == ff.getPalabraOrigen()){
          aux = FraseTradu[i].GetDestino();
          found = true;
      }
    }
    ff.setTraducciones(aux);
    return ff ;
}

ConjuntoFrases ConjuntoFrases::Contenga(string f){
  ConjuntoFrases CF_;
  vector<string> aux;
  unsigned int i,j,k = 0;
  std::transform(f.begin(), f.end(), f.begin(), ::tolower);
  for (i = 0; i < FraseTradu.size(); i++) {
    string frase = FraseTradu[i].getPalabraOrigen();
    std::transform(frase.begin(), frase.end(), frase.begin(), ::tolower);
    //j = FraseTradu[i].getPalabraOrigen().find(f);
    j = frase.find(f);
    if (j >= 0 && j < FraseTradu.size()) {
      Frase ff;
      ff.setPalabraOrigen(FraseTradu[i].getPalabraOrigen());
      for (k = 0; k < FraseTradu[k].GetDestino().size(); k++) {
        aux = FraseTradu[i].GetDestino();
      }
      ff.setTraducciones(aux);
      CF_.add(ff);
    }
  }
  return CF_;
}

bool ConjuntoFrases::Esta(string f){
  bool found = false;
  string ff = f;
  std::transform(ff.begin(), ff.end(), ff.begin(), ::tolower);
  for ( unsigned int i=0; i < FraseTradu.size() && !found; i++ ){
    string frase = FraseTradu[i].getPalabraOrigen();
    std::transform(frase.begin(), frase.end(), frase.begin(), ::tolower);
    if(frase.compare(ff) == 0){
      found = true;
    }
  }
  return found;
}

void ConjuntoFrases::add(Frase f){
  FraseTradu.push_back(f);
}

ostream& operator<<(ostream &flujo, ConjuntoFrases &CF){
  for(unsigned int i=0; i<CF.Size();++i){
      flujo << CF.FraseTradu[i].getPalabraOrigen() << endl;
      flujo << "Traduccion:  \t" << CF.FraseTradu[i].GetDestino()[0] << endl;
  }
	return flujo;
}

istream& operator>>(istream &flujo, ConjuntoFrases &CF){
  while(flujo){
    Frase f;
    flujo >> f;
    CF.add(f);
  }
	return flujo;
}
