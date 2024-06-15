#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

map<int, vector<string>>map1;

void pausar(){
    cout<<"\n Presione Enter para continuar:";
    cin.ignore(); //Cuando ingrese una tecla esta funcion come la tecla y recien sigue la sgts linea
    cin.get(); //Esperamos a que se precione enter
}

void agregarEvento(int id, string fecha, string nombreEvento){//Para esta funcion necesitaremos map y vector
    bool bandera = false; //Determinar si hay un evento con las misma fecha
    for(auto i = mapa1.begin(); i != mapa1.end(); ++i){
        if (i->second[0] == fecha && i->second[1] == nombreEvento){//Este se debe seguir iterando mientras que i no haya alcanzado el final del contenedor
            bandera = true;//indica que se encontro un evento con la misma fecha y nombre
            break;
        }
    }
    if(!bandera){//Verifica si la variable de la bandera es falso
        mapa1[id] = {fecha, nombreEvento};//Declaramos el nuevo evento del mapa
        cout<<"Evengo agregado con exito";
    }else{
        cout<<"Ya hay un evento con la misma fecha y nombre";
    }
}

void imprimir(){
    if(mapa1.empty()){
        cout<<"No hay ningun Evento\n";
    }else{
        cout<<"Imprimiendo eventos: \n\n";
        for(auto i = mapa1.begin(); i !=mapa1.end(); i++){
            cout<<i->second[0]<<" | "<<i->second[1]<<"\n";
        }
    }
}

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
        evento = obtenerPrimeraPalabra(opcion);

        if(comando == "Add"){
            agregarEvento(identificadorUnico,fechas,evento);
            identificadorUnico += 1;

        }else if(comando == "Del"){
            eliminarEvento(fechas,evento);
        }else if(comando == "print"){
            imprimir();
        }else if(comando == "Find"){
            buscandoEventoConFecha(fechas);
        }else{
            cout<<"Comando Incorrecto";
        }
        pausar();
    }while(comando != "salir");

    return 0;
}