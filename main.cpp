#include "List.h"
#include "nodo.h"
//#include "json/json-forwards.h"
#include "json/json.h"
#include<iostream>
#include<fstream>
#include<string>


using namespace std;


class usuario
{

public:
    string nick;
    string password;
    string monedas;
    string edad;


    usuario(string n, string p, string m, string e)
    {
        nick = n;
        password = p;
        monedas = m;
        edad = e;
    }
   
};
class articulo
{

public:
    string id;
    string categoria;
    string precio;
    string nombre;
    string src;


    articulo(string i, string c, string p, string n, string s)
    {
        id = i;
        categoria = c;
        precio = p;
        nombre = n;
        src = s;
    }
   
};

class tutorial
{

public:
    string ancho;
    string alto;
    List<string> movimientos;
    

    tutorial(string an, string al, List<string> mov)
    {
        ancho = an;
        alto = al;
        movimientos = mov;
    }
   
};








int main()
{//////////////////////////////////ESPACIO PARA PRUEBA DE JCPP ///////////////////////////////////////

    
    ifstream file("C:/Users/Alberto/Desktop/cys/EDDS2/F1/example.json");
    //cout << "total json data: \n"<<file.<< endl;
    Json::Value actualJson;
    Json::Reader reader;

    reader.parse(file,actualJson);
    
    //cout << "total json data: \n"<<actualJson<< endl;
    List <Json::Value>usuarios;
    
    
    for (Json::Value objeto : actualJson["usuarios"])
    {
        //usuario u(objeto["nick"].asString(), objeto["password"].asString(),objeto["monedas"].asString(), objeto["edad"].asString());
        usuarios.insert(objeto);

    }
     

   
    usuarios.display();
    
///////////////////////////////////////////////////////////////////////////////
   //menu
    
    bool bandera = true;
    while (bandera)
    {
     int entrada = 0;
    cout<<"1. Carga masiva" << endl;
    cout<<"2. Registrar Usuario" << endl;
    cout<<"3. Login" << endl;
    cout<<"4. Reportes" << endl;
    cout<<"5. Salida" << endl;
    cin >> entrada;
    switch (entrada)
    {
    case 1:
        cout<<"1. " << endl;
        break;
    case 2:
        cout<<"2. " << endl;
        break;
    case 3:
        cout<<"3. " << endl;
        break;
    case 4:
        cout<<"4. " << endl;
        break;
    case 5:
        cout<<"5. " << endl;
        bandera = false;
        break;
    
    default:
        break;
    }
    
    
       
    }
    
    
    return 0;
    
} 
