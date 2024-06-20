#include "final.h"
// pendiente void pausar
void pausar() {
  cout<<"Precione enter para continuar:\n";
  cin.ignore();
  cin.get();
}

void agregarEvento(int id, string fecha, string nombreEvento) {
 bool bandera = false;
  for(auto i = mapa1.begin(); i != mapa1.end(); i++){
    if(i -> second[0] == fecha && i -> second[1] == nombreEvento){
      bandera  = true;
      break;
    }
  }
  if(!bandera){
    mapa1[id] = {fecha, nombreEvento};
    cout<<"Evento agregado, ";
  }else{
    cout<<"se encontro un evento con el mismo nombre";
  }
}

void eliminarEvento(string fecha, string evento) {
  bool bandera = false;
  for(auto i = mapa1.begin(); i != mapa1.end(); i++){
     if(i -> second[0] == fecha && i -> second[1] == evento){
      mapa1.erase(i);
      cout<<"Se elimino correctamente, ";
      bandera = true;
      break;
    }
  }
  if(!bandera){
    cout<<"Evento no encontrado \n";
  }
}

void buscarEventosConFecha(string fecha) {
  for(auto i = mapa1.begin(); i != mapa1.end(); i++){
    if(i -> second[0] == fecha){
      cout<<i -> second[0]<<" | "<<i -> second[1]<<"\n";
    }
  }
}

void imprimir() {
  if(mapa1.empty()){
    cout<<"El sistema esta vacio:";
  }else{
    cout<<"Imprimiendo eventos\n\n";
    multimap<string , string> eventosOrdenados;
    for(const auto& evento : mapa1){
      cout<<evento.second[0]<<" | "<<evento.second[1]<<"\n";
    }
  }
}


string obtenerPrimeraPalabra(string str) {
  string abc ="qwertyuiopasdfghjklzxcvbnm QWERTYUIOPASDFGHJKLZXCVBNM";
  while(0 < str.size() && abc.find(str[0]) == string::npos){
    str.erase(0,1);
  }
  int pos = str.find(' ');
  if(pos == string::npos){
    return str;
  }
  return str.substr(0, pos);
}

string eliminarPrimeraPalabra(string cadena) {
    size_t pos = cadena.find(' ');
    if (pos != string::npos) {
        cadena = cadena.substr(pos + 1);
    } else {
        cadena = "";
    }
    return cadena;
}

string obtenerFecha(string cadena) {
  string abc = "1234567890+-";
  while (0 < cadena.size() && abc.find(cadena[0]) == string::npos) {
    cadena.erase(0, 1);
  }
  int pos = cadena.find(' ');
  if (pos == string::npos) {
    return cadena;
  }
  return cadena.substr(0, pos);
}
