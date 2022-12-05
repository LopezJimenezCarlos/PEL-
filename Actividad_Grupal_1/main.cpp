#include <iostream>
#include <string.h>
#include <string.h>
#include <array>
using namespace std;

int i=0;

template <typename T>
T almacenarDatos(T a) {
    T array[50];
    array[i]= a;
    cout << array[i] << "\n";

    i++;
    return 0;
}
int main(int, char**) {

    string nomb;
    string apll;
    string dni;
    

    cout << "Nombre: ";
    cin >> nomb; 
    cout << "Apellido: ";
    cin >> apll; 
    cout << "DNI: ";
    cin >> dni; 
    
    cout << almacenarDatos <string> () << endl;
    }/*
    cout << "Apellido: ";
    cin >> b;
    cout << "Dni: ";
    cin >> c;
    
   
    b= almacenarDatos(apll);
    c = almacenarDatos(dni);

    cout <<a<<b<<c;
}

/*class Persona {        
  public:          
    string nombre;  
    string apellidos;
    string dni;
    Persona(string x, string y, string z) { 
      nombre = x;
      apellidos = y;
     dni = z;
    }
};

int main() {
  
  string n, ap, dni;
  cout << "Nombre: ";
  cin >> n;
  cout << "Apellidos: ";
  cin >> ap;
  cout << "Dni: ";
  cin >> dni;
  Persona carObj1(n, ap, dni);


  // Print values
  cout << carObj1.nombre << " " << carObj1.apellidos << " " << carObj1.dni<< "\n";
 // cout << carObj2.brand << " " << carObj2.model << " " << carObj2.year << "\n";
  return 0;
}*/