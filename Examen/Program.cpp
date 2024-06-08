// See https://aka.ms/new-console-template for more information
#include <iostream>
#include <conio.h>
#include <string>

using namespace std;

string obtenerPrimeraPalabra(string str){
    string abc="qwertyuiopasdfghjklzxcvbnmQWERTYUIOPSDFGHJKLZXCVBNM";
    while(0 < str.sixe() && abc.find(str[0]) == string::npos){
        str.erase(0,1);
    }
    int pos = str.find(' ');
    if(pos == string::npos){
        return str;
    }
    return str.substr(0,pos);

}

string eliminarPrimeraPalabra(string cadena){
    string abc="qwertyuiopasdfghjklzxcvbnmQWERTYUIOPASDFGHJKLZXCVBNM1234567890-+";
    while(0 < cadena.size() && cadena.find(cadena[0]) == string::npos){
        cadena.erase(0,1);
}
int pos = cadena.find(' ');
cadena.erase(0,pos);
return cadena;
}
