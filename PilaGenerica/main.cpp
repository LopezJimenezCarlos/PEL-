
#include <iostream>
#include "pilaNomb.h"
#include "pilaApell.h"
#include "pilaDni.h"
#include "pilaLibro.h"
using namespace std;

int i=0;
class Libro {
    public:
    string nombre;
    string categoria;
    bool disponible;
    Libro();
    Libro(string x, string y, bool z) ;
         
};
Libro::Libro(string x, string y, bool z) {
  nombre = x;
  categoria = y;
  disponible = z;}

class Usuario {
  public:
    string nombre;
    string apellido;
    string dni;
    Usuario(string x, string y, string z);
       
      
};
Usuario::Usuario(string x, string y, string z) {
  nombre = x;
  apellido = y;
  dni = z;}


  int main(){
  
  Libro l1("Spiderman", "Accion", true);
  Libro l2("Batman", "Accion", true);
  Libro l3("Superman", "Accion", true);
  Libro l4("Deadpool", "Accion", true);

  Libro l5("Forastera", "Romance", true);
  Libro l6("After", "Romance", true);
  Libro l7("Un cuento perfecto", "Romance", true);
  Libro l8("Bajo la misma estrella", "Romance", true);

  Libro l9("Drama", "Drama", true);
  Libro l10("El perro del hortelano", "Drama", true);
  Libro l11("Las dos esfinges", "Drama", true);
  Libro l12("Los hombres de Federico", "Drama", true);

  Libro l13("Dracula", "Terror", true);
  Libro l14("El exorcista", "Terror", true);
  Libro l15("It", "Terror", true);
  Libro l16("La casa infernal", "Terror", true);

  Libro l17("Maldito karma", "Comedia", true);
  Libro l18("Divina comedia", "Comedia", true);
  Libro l19("Ha vuelto", "Comedia", true);
  Libro l20("Asi es la puta vida", "Comedia", true);
  //------------------Usuario1 y libro 1---------------------------
  string nomb, apell, dni;
  cout <<"Dime tu nombre\n";
  cin >> nomb;
  cout <<"Dime tu apellido\n";
  cin >> apell;
  cout <<"Dime tu dni\n";
  cin >> dni;
  Usuario.add(nomb, apell, dni);
  cout << usuario1.nombre<<usuario1.apellido<<usuario1.dni<<"\n";

   string lib, cat;
   bool dispo = NULL;
   
  cout <<"Dime el libro que quieras coger\n";
  cin >> lib;
 
  cout <<"Dime su categoria\n";
  cin >> cat;
  dispo = false;
   Libro libro1(lib, cat, dispo);
//------------------------------------------------------------
 string nomb2, apell2, dni2;
  cout <<"Dime tu nombre\n";
  cin >> nomb2;
  cout <<"Dime tu apellido\n";
  cin >> apell2;
  cout <<"Dime tu dni\n";
  cin >> dni2;
   Usuario usuario2(nomb2, apell2, dni2);
  cout << usuario2.nombre<<usuario2.apellido<<usuario2.dni<<"\n";

   string lib2, cat2;
   bool dispo2=false;

  cout <<"Dime el libro que quieras coger\n";
  cin >> lib2;
  cout <<"Dime su categoria\n";
  cin >> cat2;
  if (libro1.disponible=false){
    cout<< "No esta disponible";

  }else(libro1.disponible=true);
    cout<<"El libro es tuyo";
  
  
  Libro libro2(lib2, cat2, dispo2);
  };
  


