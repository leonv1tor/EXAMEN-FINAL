#include <iostream>
#include <string>

using namespace std;

 string obtenerPrimeraPalabra( string str){
    string abc = "qwertyuiopasdfghjkl zxcvbnQERTYUIOPASDFGHJKL ZXCVBNM";
    while(0 < str.size() && abc.find(str[0]) == string::npos){
        str.erase(0,1);
    }
    int pos = str.find(' ');
    if (pos == string::npos){
        return str;
    }
    return str.substr(0, pos);
 }

 string eliminarPrimeraPalabra(string cadena){
    string abc = "qwertyuiopasdfghjkl zxcvbnmQWERTYUIOPASDFGHJKL ZXCVBNM 123456789-+"
    while(0 < cadena.size() && abc.find(cadena[o]) == string::npos){
        cadena.erase(0,1);
    }
    int pos = cadena.find(' ');
    cadena.erase(0,pos);
    return cadena;
 } 

 string obtenerLafecha(string cadena){
    string abc = "1234567890+-";
    while(0 < cadena.size() && abc.find(cadena[o]) == strin::npos){
        cadena.erase(0,1);
    }
    int pos = cadena.find(' ');
    if (pos == string::npos){
        return cadena;
    }
    return cadena.substr(0,pos);
 }


int main(){
    string opcion,comando,evento,fechas;
    int identificadorUnico = 1;
    do{
        system("cls")
        cout << "\t\t\t\t Resgistro de eventos \t\t\t\t \n\n";
        cout << "Para Agregar nuevo evento se usa el comando: Add: \n\n";
        cout << "Para Eliminar evento se usa el comando: Del \n\n";
        cout << "Para Eliminar todos los eventos de una fecha especifica se usa el comando: Del \n\n";
        cout << "Para Buscar evento en especifico se usa el comando: Find \n\n";
        cout << "Para  Imprimir todos los eventos se usa el comando: Print \n\n";
        cout << "Para Salir se usa el comando: Salir \n\n";
        cout << " Escriba su opcion: ";
        getline(cin,opcion);
        cout<<"\n";
        comando = obtenerPrimeraPalabra(opcion);
        opcion  = eliminarPrimeraPalabra(opcion);
        fechas = obtenerLafecha(opcion);
        opcion = eliminarPrimeraPalabra(opcion);
    }


    return 0;
}