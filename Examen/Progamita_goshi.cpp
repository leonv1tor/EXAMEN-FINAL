#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <iomanip>
using namespace std;
map<int, vector<string>> mapa1;

// pendiente void pausar
void pausar() {
  cout<<"Precione enter para continuar: ";
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
    cout<<"Evento agregado \n";
  }else{
    cout<<"Se encontro un evento con el mismo nombre";
  }
}

void eliminarEvento(string fecha, string evento) {
  bool bandera = false;
  for(auto i = mapa1.begin(); i != mapa1.end(); i++){
     if(i -> second[0] == fecha && i -> second[1] == evento){
      mapa1.erase(i);
      cout<<"Se elimino corrrectamente";
      bandera = true;
      break;
    }
  }
  if(!bandera){
    cout<<"Evento no encontrado";
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

int main() {
  string opcion, comando, evento, fechas;
  int identificadorUnico = 1;
  do {
    cout << "\t\t\t\t   Registro de eventos   \t\t\t\t \n\n";
    cout << " Para agregar un evento usa el comando: Add \n\n";
    cout << " Para eliminar un evento usa el comando: Del \n\n";
    cout << " Para eliminar todos los eventos de una fecha en especifico usa el comando:  Del \n\n";
    cout << " Para buscar un evento con fecha en especifico usa el comando: Find \n\n";
    cout << " Para imprimir todos los eventos usa el comando: Print \n\n";
    cout << " Para salir usa el comando: Salir \n\n";
    cout << " Escriba su opcion:\n";
    getline(cin, opcion);  // para leer toda la linea
    cout<<"\n";

    //Add 2024-08-29 cumple
    comando = obtenerPrimeraPalabra (opcion);
    //2024-05-29 cumple
    opcion = eliminarPrimeraPalabra(opcion);
    //2024-05-29
    fechas = obtenerFecha (opcion);
    //cumple
    opcion = eliminarPrimeraPalabra(opcion);
    //cumple
    evento = obtenerPrimeraPalabra(opcion);

    if (comando == "Add") {
      agregarEvento(identificadorUnico, fechas, evento);
      identificadorUnico += 1;
    } else if (comando == "Del") {
      eliminarEvento(fechas, evento);
    } else if (comando == "Print") {
      imprimir();
    } else if (comando == "Find") {
      buscarEventosConFecha(fechas);
    } else {
      cout << "Comando incorrecto\n";
    }
    pausar();

  } while(comando != "salir");

  return 0;
}