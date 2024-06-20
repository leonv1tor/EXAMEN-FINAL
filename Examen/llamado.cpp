#include "cuerpo.cpp"
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