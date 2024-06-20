#ifndef FINAL_H
#define FINAL_H

#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

map<int, vector<string>> mapa1;

// pendiente void pausar
void pausar();
void agregarEvento(int id, string fecha, string nombreEvento);
void eliminarEvento(string fecha, string evento);
void buscarEventosConFecha(string fecha);
void imprimir();

string obtenerPrimeraPalabra(string str);
string eliminarPrimeraPalabra(string cadena);
string obtenerFecha(string cadena);

#endif
