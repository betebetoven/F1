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
    List<Json::Value>tut_global;

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
void va(Node <Json::Value> *root, Json::Value entrada)
{
    if(root==NULL)
    {
    string jeson = "{\"categoria\": \""+entrada["categoria"].asString()+"\"}";
    Json::Value actualJson;
    Json::Reader reader;
    reader.parse(jeson,actualJson);
    categoria.insert(actualJson);
    }
    else 
    if (root->data["categoria"].asString()!=entrada["categoria"].asString() && root-> next != NULL)
    va(root->next, entrada);
    else 
    if (root->data["categoria"].asString()!=entrada["categoria"].asString() && root-> next == NULL)
    {
        string jeson = "{\"categoria\": \""+entrada["categoria"].asString()+"\"}";
        Json::Value actualJson;
        Json::Reader reader;
        reader.parse(jeson,actualJson);
        categoria.insert(actualJson);
        return;
        /* code */
    }
    else 
    return;
    
    
    
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
    
    for (Json::Value objeto : object["articulos"])
        va(categoria.head,objeto);

    //ingresan todos los tipos de categorias sin repetirse


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
    
    
    
//PARA LA COMPRA AGREGAR UN APUNTARODR AL INVENTARIO DE SKINS QUE TIENE EL USUARIO
//INICIALIZARLA OCMO NULL ANTES Y DE ULTIMO EN LA COMPRA AGREGARLE ALGUNA MIERDA POR AHI//
//APUNTADOR LISTA = NEW lISTA DE JSON VALUE POR SUPUESTO PARA IGRESAR LA REFERENCIA D ELOS DATOS 
//DE LA LISTA DE LA TIENDA
    

    
    
    for (Json::Value objeto : actualJson["usuarios"])
        usuarios_glob.insert(objeto);
    for (Json::Value objeto : actualJson["articulos"])
       articulos_glob.insert(objeto);
    categoria_constructor(actualJson);
    
    tut_global.insert(actualJson["tutorial"]);
    for (Json::Value objeto : actualJson["tutorial"]["movimientos"])
        tut_global.insert(objeto);
    
    

    cout << "USUARIOS---------------------------------"<< endl;
    usuarios_glob.display();
    cout << "TUTORIAL---------------------------------"<< endl;
    tut_global.display();
    

    





    
}

Json::Value dequeue_tutorial()
{
    Node<Json::Value> *n = tut_global.head;
    tut_global.head = tut_global.head->next;
    tut_global.tamaño = tut_global.tamaño-1;
    return n->data;
    
    


}
void mostrar_tutorial()
{
    //lo raro de esta funcion es que solo se puede realizar una sola vez
    cout << "DEQUEUE DE TUTORIAL: "<<endl;
    while (tut_global.tamaño>=1)
    {
        cout << dequeue_tutorial()<<endl;
    }
    tut_global.display();
    
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


void jugar(string x, string y)
{
    Node<Json::Value> *n = cuenta;
    if(cuenta->movimientos == NULL)
    {
    
    n->movimientos = new Node <Json::Value>;//el nodo movimientos es el head de la lista de movimientos
    n->movimientos->next = NULL;
    }
    Node<Json::Value> *t = n->movimientos;
    while (t->next != NULL)
    t = t->next;

    string jeson = "{\"x\": \""+x+"\",\"y\": \""+y+"\"}";
    Json::Value actualJson;
    Json::Reader reader;
    reader.parse(jeson,actualJson);
    Node<Json::Value> *nv = new Node<Json::Value>;
    nv->data = actualJson;
    t->next = nv;
    nv->next = NULL;

}
void imprimir_jugadas(Node<Json::Value>*root)
{
    cout << root->data << endl;
    if(root-> next != NULL)
        imprimir_jugadas(root->next);
    else
    return;

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
    cout<<"5. Ver tutorial" << endl;
    cout <<"6. Jugar" << endl;
    cout << "7. ver jugadas "<< endl;

   
    cin >> entradita;
    string x;
        string y;
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
    case 5:
    cout<<"5. " << endl;
        mostrar_tutorial();
        break;
    case 6:
        cout<<"6. " << endl;
        
        cout <<"Ingresar cordenada x: "<< endl ;
        cin >> x;
        cout <<"Ingresar cordenada y: "<< endl ;
        cin >> y;
        jugar(x,y);
        break;
    case 7:
    cout<<"7. " << endl;
        imprimir_jugadas(cuenta->movimientos);
        break;


  
    
    default:
        break;
    }
        
    }
    
}
List<Json::Value> auxiliar_usuarios ;
List<Json::Value> auxiliar_articulos;
void sort(List<Json::Value> n,string parametro)
{
    Node<Json::Value> *temp2 = n.head;
    //int result = stoi(temp2->data["edad"].asString());
    cout << "ASCENDENTE: "<<endl;
    while (temp2 != NULL)
    {
       Node<Json::Value> *temp1 = temp2->next;
        while (temp1 != NULL)
        {
            
            if (stoi(temp1->data[parametro].asString()) < stoi(temp2->data[parametro].asString()))
            { 
                Node<Json::Value> *temp3 = new Node<Json::Value>;
                temp3->data = temp2->data;
                temp2->data = temp1->data;
                temp1->data = temp3->data;

            }
            temp1 = temp1->next;
        
        }
        temp2 = temp2->next;
        
    }
    n.display();
    

}

void sortd(List<Json::Value> n,string parametro)
{
    Node<Json::Value> *temp2 = n.head;
    //int result = stoi(temp2->data["edad"].asString());
    cout << "DESCENDENTE: "<<endl;
    while (temp2 != NULL)
    {
       Node<Json::Value> *temp1 = temp2->next;
        while (temp1 != NULL)
        {
            
            if (stoi(temp1->data[parametro].asString()) > stoi(temp2->data[parametro].asString()))
            { 
                Node<Json::Value> *temp3 = new Node<Json::Value>;
                temp3->data = temp2->data;
                temp2->data = temp1->data;
                temp1->data = temp3->data;

            }
            temp1 = temp1->next;
        
        }
        temp2 = temp2->next;
        
    }
    n.display();
    

}

void imprimirusuarios()
{
    string texto = "digraph G\n{\n        node[shape = circle]\n        node[style = filled]\n        node[fillcolor = \"#EEEEE\"]\n        node[color = \"#EEEEE\"]\n        node[color = \"#31CEF0\"]\n";
    Node<Json::Value> *temp = auxiliar_usuarios.head;
    while (temp != NULL)
    {
        ostringstream get_the_address; 
        get_the_address << temp;
        string address =  "A"+get_the_address.str(); 
        ostringstream get_the_address2; 
        get_the_address2 << temp->next;
        string addressnext =  "A"+get_the_address2.str(); 
        string datos = temp->data["nick"].asString()+"\n"+temp->data["edad"].asString()+"\n"+temp->data["monedas"].asString();
        string j = address+"[label=\""+datos+ "\"]\n";
        if(temp->next != NULL)
        {
        j+= address+"->"+addressnext+";\n";
        j+= addressnext+"->"+address+";\n";
        }
        else
        {
            ostringstream get_the_address; 
            get_the_address << auxiliar_usuarios.head;
            string addresshead =  "A"+get_the_address.str(); 
            j+= address+"->"+addresshead+";\n";
            j+= addresshead+"->"+address+";\n";

            



        }
        texto += j;
        temp = temp->next;
    }

    ///aca ponemos los ranks
    string p = "\n";
    p += "\n{rank = same; ";
    Node<Json::Value> *rank = auxiliar_usuarios.head;
    while (rank != NULL)
    {
        ostringstream get_the_address; 
        get_the_address << rank;
        string address =  "A"+get_the_address.str(); 
        if(rank->next != NULL)
        p+=" "+address+"; ";
        else
        p+=" "+address+" ";
        rank = rank->next;
     
    }
    p+= "}\n";
    
    

    texto += p;
    texto += "}";

    cout << texto <<endl;


}
string conectarderecha(Node<Json::Value> *temp)
{
    string texto = "";
    Node<Json::Value> *n = temp;
    while (n!=NULL)
    {
        ostringstream get_the_address; 
        get_the_address << n;
        string address =  "A"+get_the_address.str(); 
        ostringstream get_the_address2; 
        get_the_address2 << n->derecha;
        string addressnext =  "A"+get_the_address2.str(); 
        string datos = n->data["nombre"].asString()+"\n"+n->data["id"].asString()+"\n"+n->data["precio"].asString()+"\n"+n->data["categoria"].asString()+"\n";
        string j = address+"[label=\""+datos+ "\"]\n";
        if(n->derecha != NULL)
        {
        j+= address+"->"+addressnext+";\n";
       
        }
        else
        {
            ostringstream get_the_address; 
            get_the_address << categoria.head;
            string addresshead =  "A"+get_the_address.str(); 
           

        }
        texto += j;
        n = n->derecha;
    }
    return texto;
    
        
        


}
void imprimirarticulos()
{
    //impresion vertical
    string texto = "digraph G\n{\n        node[shape = circle]\n        node[style = filled]\n        node[fillcolor = \"#EEEEE\"]\n        node[color = \"#EEEEE\"]\n        node[color = \"#31CEF0\"]\n";
    Node<Json::Value> *temp = categoria.head;
    while (temp != NULL)
    {
        ostringstream get_the_address; 
        get_the_address << temp;
        string address =  "A"+get_the_address.str(); 
        ostringstream get_the_address2; 
        get_the_address2 << temp->next;
        string addressnext =  "A"+get_the_address2.str(); 
        string datos = temp->data["categoria"].asString();
        string j = address+"[label=\""+datos+ "\"]\n";
        if(temp->next != NULL)
        {
        j+= address+"->"+addressnext+";\n";
       
        }
        else
        {
            ostringstream get_the_address; 
            get_the_address << categoria.head;
            string addresshead =  "A"+get_the_address.str(); 
           

        }
        texto += j+"\n";
        texto += conectarderecha(temp);




        temp = temp->next;
    }
    ///aca ponemos los ranks
    string p = "\n";
    p += "\n{rank = same; ";
    Node<Json::Value> *rank = categoria.head;
    while (rank != NULL)
    {
        ostringstream get_the_address; 
        get_the_address << rank;
        string address =  "A"+get_the_address.str(); 
        if(rank->next != NULL)
        p+=" "+address+"; ";
        else
        p+=" "+address+" ";
        rank = rank->next;
     
    }
    p+= "}\n";
    
    

    texto += p;



    texto += "}";

    cout << texto <<endl;




    ////////////////
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
        
        cout << &auxiliar_usuarios <<"||||||"<< &usuarios_glob<<endl;
    
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
        auxiliar_usuarios = usuarios_glob;
        auxiliar_articulos = articulos_glob;
        sort(auxiliar_usuarios,"edad");
        sortd(auxiliar_usuarios,"edad");
        sort(auxiliar_articulos,"precio");
        sortd(auxiliar_articulos,"precio");
        imprimirusuarios();
        imprimirarticulos();

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
