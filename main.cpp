#include "List.h"
#include "nodo.h"
//#include "json/json-forwards.h"
#include "json/json.h"
#include<iostream>
#include<fstream>
#include<string>


using namespace std;

List <Json::Value>usuarios_glob;
    List <Json::Value>articulos_glob;
    List <Json::Value>movimientos_glob;
    List <Json::Value>categoria;

    Node<Json::Value> *cuenta;
    
   
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
    List<Json::Value> movimientos;
    tutorial(string an, string al, List<Json::Value> mov)
    {
        ancho = an;
        alto = al;
        movimientos = mov;
    }
   
};
List<Json::Value> perez;
 tutorial tutorial_global("j","jaja",perez);

Node<Json::Value> *login(List<Json::Value> usuarioh, string nombre, string contraseña)
{
     cout << "Estas dentro de la funcion de LOGIN :"<< endl;
    Node<Json::Value> *ahora;
            
            for(ahora = usuarioh.head; ahora != NULL; ahora=ahora->next)
            {
                cout << ahora->data << " \n";
                if (ahora->data["nick"].asString() == nombre && ahora->data["password"].asString()== contraseña)
                 {cout << "enconttro a betebetoven"<< endl;
                 return ahora;
                 break;
                 }
 
                
            }
            return new Node<Json::Value>;
            
} 
void eliminar_cuenta(Node<Json::Value> *cuenta_eliminar)
{
    if (cuenta_eliminar->Prev != NULL)
    cuenta_eliminar->Prev->next = cuenta_eliminar->next;
    else
    usuarios_glob.head = cuenta_eliminar->next;
    if (cuenta_eliminar->next != NULL)
    cuenta_eliminar->next->Prev = cuenta_eliminar->Prev;
    cuenta_eliminar = NULL;
    cuenta = new Node<Json::Value>;

    

}
void añadir_usuario()
{   
    string nick;
    string password;
    string edad;
    cout <<"Ingrese UserName: \n"<< endl;
    cin >> nick;
cout <<"Ingrese Contraseña: \n"<< endl;
cin >> password;
cout <<"Ingrese Edad: \n"<< endl;
cin >> edad;
    string jeson = "{\"nick\":\""+nick+"\",\"password\":\""+password+"\",\"monedas\":\"0\",\"edad\":\""+edad+"\"}";
    Json::Value actualJson;
    Json::Reader reader;
    reader.parse(jeson,actualJson);
    usuarios_glob.insert(actualJson);
    cout <<"Usuario Registrado: \n" <<actualJson<< endl;

}

void llenaderecha(Node<Json::Value> *n,Json::Value x)
{
    if (n->derecha == NULL)
    {
        Node<Json::Value> *nuevo = new Node<Json::Value>;
        nuevo -> data = x;
        nuevo -> derecha = NULL;
        n->derecha = nuevo;

    }
    else
    {
        llenaderecha(n->derecha,x);
    }
}
void imprimederecha(Node<Json::Value> *n)
{
    cout << n->data;
    if (n->derecha != NULL)
        imprimederecha(n->derecha);

}

void categoria_constructor(Json::Value object)//aca entra el actualjson de carga masiva
{
    string jeson = "[{\"categoria\": \"Comun\"},{\"categoria\": \"Epico\"},{\"categoria\": \"Raro\"},{\"categoria\": \"Legendario\"}]";
    Json::Value actualJson;
    Json::Reader reader;
    reader.parse(jeson,actualJson);
    for (Json::Value objeto : actualJson)
        categoria.insert(objeto);
    Node<Json::Value> *cabecita = categoria.head;
    while (cabecita->next != NULL)
    {
        cabecita->derecha = NULL;
        cabecita = cabecita->next;
    }
    cabecita->derecha = NULL;
    //hacemos ingreso a la matriz rara esta de c++
    cabecita = categoria.head;
    while (cabecita != NULL)
    {
        for (Json::Value n : object["articulos"])
        {
            if (cabecita->data["categoria"].asString()==n["categoria"].asString())
            {
                Node<Json::Value> *primero = cabecita;
                llenaderecha(cabecita,n);
                cabecita = primero;
            }
        }
        cabecita = cabecita->next;
    }

    //MOSTRADO EN CONSOLA LA TIENDA DE CATEGORIAS
    cabecita = categoria.head;
    cout << "Tienda: "<<endl;
    while (cabecita != NULL)
    {   cout << "----------------------------"<<endl;
        imprimederecha(cabecita);
        cout << "----------------------------"<<endl;
        
        cabecita = cabecita->next;
    }

    
        

}



void carga_usuario(){
      ifstream file("C:/Users/Alberto/Desktop/cys/EDDS2/F1/example.json");
    //cout << "total json data: \n"<<file.<< endl;
    Json::Value actualJson;
    Json::Reader reader;
    Node<string> perez;
    perez.data = "hola mundio";


    reader.parse(file,actualJson);
    
    cout << perez.data<< endl;
    //List <Json::Value>usuarios;
    //List <Json::Value>articulos;
    List <Json::Value>movimientos;
    
    
    

    

    
    
    for (Json::Value objeto : actualJson["usuarios"])
        usuarios_glob.insert(objeto);
    //for (Json::Value objeto : actualJson["articulos"])
       // articulos_glob.insert(objeto);
    categoria_constructor(actualJson);
    
    for (Json::Value objeto : actualJson["tutorial"]["movimientos"])
        movimientos.insert(objeto);
    
     tutorial tut(actualJson["tutorial"]["ancho"].asString(),actualJson["tutorial"]["alto"].asString(), movimientos);
     tutorial_global = tut;

   
    usuarios_glob.display();
    articulos_glob.display();
    
    cout << tutorial_global.alto<< endl;
    cout << tutorial_global.ancho<< endl;
    tutorial_global.movimientos.display();
    

    





    
}




void opcion3()
{
    string user;
    string contraseña;
    cout << "Ingresa Username: "<< endl;
    cin >>user ;
    cout << "Ingresa Contraseña: "<< endl;
    cin >> contraseña;
    cuenta = login(usuarios_glob, user, contraseña);
    cout << "Esta en la cuenta de: "<< cuenta->data<< endl;
    //usuarios_glob.display();

}
void menu2()
{
    bool bandera = true;
    while (bandera)
    {
         int entradita = 0;
         string nombre_nuevo;
         string nueva_contraseña;
    cout<<"1. Cambiar Nombre" << endl;
    cout<<"2. cambiar Contraseña" << endl;
    cout<<"3. Eliminar Cuenta" << endl;
    cout<<"4. Salir al menú principal" << endl;
   
    cin >> entradita;
    switch (entradita)
    {
    case 1:
        cout<<"1. " << endl;
        cout<<"Ingresar nombre Nuevo: " << endl;
        cin >> nombre_nuevo;
        cuenta->data["nick"]=nombre_nuevo;
        cout << "Datos actualizados :"<< cuenta->data<< endl;

        break;
    case 2:
        cout<<"2. " << endl;
        cout<<"Ingresar nueva Contraseña: " << endl;
        cin >> nueva_contraseña;
        cuenta->data["password"]=nueva_contraseña;
        cout << "datos Actualizados :"<< cuenta->data<< endl;
        
        break;
    case 3:
        cout<<"3. " << endl;
        eliminar_cuenta(cuenta);
        usuarios_glob.display();

        bandera = false;
        
       
       
        break;
    case 4:
        cout<<"4. " << endl;
        bandera = false;
        break;
  
    
    default:
        break;
    }
        
    }
    
}


int main()
{
    //////////////////////////////////ESPACIO PARA PRUEBA DE JCPP ///////////////////////////////////////
    

   

    
  
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
        carga_usuario();
        
    
        break;
    case 2:
        cout<<"2. " << endl;
        añadir_usuario();
        
        break;
    case 3:
        cout<<"3. " << endl;
        opcion3();
        menu2();
       
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
