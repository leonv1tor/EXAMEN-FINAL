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
}
