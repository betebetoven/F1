#include<iostream>
using namespace std;

class Matriz {
public:
//* constructor con los pares límites
Matriz(int n[], int m[]);
virtual ~Matriz(); //* destructor
/** se ponen y obtienen valores */
int &operator[](int i[]) ;
/* crea una nueva matriz, que es la multiplicación de esta
matriz por m */
Matriz *operator* (Matriz m) ;
private:
//* pares límites
int n[2] ;
int m[2] ;
int *alfa ; // primer elemento
};


//ejemplo de uso
int main() {
cout << "Multiplicación" << endl;
/* se define la matriz m1: 10..12 * 1..4 */
Matriz m1({10,1}, {12,4});
/* se define la matriz m12 m2 = 11..14 * 1..5 */
Matriz m2({11,1}, {14,5}) ;
/* se inicializan algunas posiciones */
m1[10,2] = 1 ; m1[12,4] = 1 ;
m2[12,3] = 1 ; m2[14,4] = 1 ;
/* se obtiene la matriz resultado de la multiplicación
m3 = 10..12 * 1..5 */
Matriz *m3=m1 * m2 ;
/* se imprime la matriz resultante */
for (int i=10; i<=12; i++) {
for (int j=1; j<=5; j++) {
cout<<"["<<i<<","<<j<<"]="<<m3[{i,j}]<<"- " ;
}
cout << endl ;
}
delete m3 ;
return 0;
}