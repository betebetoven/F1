#include<iostream>
using namespace std;
int main()
{

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
    
    
        /* code */
    }
    
    
    return 0;
    
} // namespace name
