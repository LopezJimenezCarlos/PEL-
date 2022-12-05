#include <iostream>
#include "pilaApell.h"
#include "pilaDNI.h"
#include "pilaLibro.h"
#include "pilaNomb.h"

#include <string>

using namespace std;

int a=0, i=0, cont=0;

string nombre;
string apellido;
string dni;
string libro;

pilaNomb<string> listNomb;
pilaApell<string> listApell;
pilaDNI<string> listDni;
pilaLibro<string> listLibro;

class Libro {
    public:
    string nombre;
    string categoria;
    bool disponible;
    Libro();
    Libro(string nombre, string categoria, bool disponible) {
        this->nombre = nombre;
        this->disponible = disponible;
        this->categoria = categoria;
    }  
};

Libro Libros[20] = {
  
Libro("Spiderman", "Accion", true),
Libro("Batman", "Accion", true),
Libro("Superman", "Accion", true),
Libro("Deadpool", "Accion", true),

Libro("Forastera", "Romance", true),
Libro("After", "Romance", true),
Libro("Un cuento perfecto", "Romance", true),
Libro("Bajo la misma estrella", "Romance", true),

Libro("Drama", "Drama", true),
Libro("El perro del hortelano", "Drama", true),
Libro("Las dos esfinges", "Drama", true),
Libro("Los hombres de Federico", "Drama", true),

Libro("Dracula", "Terror", true),
Libro("El exorcista", "Terror", true),
Libro("It", "Terror", true),
Libro("La casa infernal", "Terror", true),

Libro("Maldito karma", "Comedia", true),
Libro("Divina comedia", "Comedia", true),
Libro("Ha vuelto", "Comedia", true),
Libro("Asi es la puta vida", "Comedia", true),

};

int PedirDatos() {

    cout << "Nombre: ";
    cin >> nombre;
    listNomb.insert(nombre);
     
    cout << "Apellido: ";
    cin>> apellido;
    listApell.insert(apellido); 
     
    cout << "DNI: ";
    cin>> dni;
    listDni.insert(dni);

    cont++;

    return 0;

}

int comprobar_disponibilidad(){

    int size = sizeof(Libros);

    cout << size << endl;

    for (int i = 0; i < 20; i++){
    cout << Libros[i].categoria  << "  " << Libros[i].nombre << "  " << Libros[i].disponible << endl;
    }

    return 0;

}

int historial_persona(){

    string nombreC, apellidoC, dniC;
    cout << "Introduzaca el Nombre del usuario: ";
    cin >> nombreC;
    cout << "Introduzaca el Apellido del usuario: ";
    cin >> apellidoC;
    cout << "Introduzaca el DNI del usuario: ";
    cin >> dniC;

    for (int i = 0; i < cont; i++){

        if (listNomb.Elemento(i)==nombreC)
        {
            if (listApell.Elemento(i)==apellidoC)
            {
                if (listDni.Elemento(i)==dniC)
                {
                    cout << "El usuario " << nombreC << " " << apellidoC << " dispone de " << listLibro.Elemento(i)<<"\n";
                    //break;
                }
            }
        }
    }
        
    return 0;
}

int ver_libro(){

    cout << "Que libro deseas ver: ";
    cin>> libro;

    for (int i = 0; i < cont; i++)
    {
        if (listLibro.Elemento(i)==libro)
        {
            cout << "Lo tiene " << listNomb.Elemento(i) << " " << listApell.Elemento(i) << endl;
        } 
    }
    
    return 0;
}

int sacar_libro(){

    PedirDatos();

    cout << "Que libro deseas: ";
    cin>> libro;
    listLibro.insert(libro);

    for (int i = 0; i < 20; i++)
    {
        if (Libros[i].nombre==libro)
        {
            Libros[i].disponible = false;
        }   
    }

    return 0;
}

int devolver_libro(){

    string nombreC, apellidoC, dniC;
    cout << "Introduzaca el Nombre del usuario: ";
    cin >> nombreC;
    cout << "Introduzaca el Apellido del usuario: ";
    cin >> apellidoC;
    cout << "Introduzaca el DNI del usuario: ";
    cin >> dniC;

    cout << "Que libro deseas devolver: ";
    cin>> libro;

    for (int i = 0; i < cont; i++){
            if (listNomb.Elemento(i)==nombreC)
        {
            if (listApell.Elemento(i)==apellidoC)
            {
                if (listDni.Elemento(i)==dniC)
                {
                    if (listLibro.Elemento(i)==libro)
                    {
                        listLibro.ElementoC(i);
                    }
                }
            }
        }
    }

    for (int i = 0; i < 20; i++)
    {
        if (Libros[i].nombre==libro)
        {
            Libros[i].disponible = true;
        }   
    }

    return 0;
}

int main() {

    while (a!=6)
    {
        cout << "\n";
        cout << "[1] Comprobar libros disponibles\n";
        cout << "[2] Historial de libros de una persona\n";
        cout << "[3] Quien tiene un libro\n";
        cout << "[4] Sacar un libro\n";
        cout << "[5] Devolver un libro\n";
        cout << "[6] Salir\n";
        cout << "¿Que accion desea realizar?\n";
        cout << "\n";

        cin >> a; 

            switch (a) {
        case 1:
            comprobar_disponibilidad();
            break;
        case 2:
            historial_persona();
            break;
        case 3:
            ver_libro();
            break;
        case 4:
            sacar_libro();
            break;
        case 5:
            devolver_libro();
            break;
        case 6: 
            cout << "Gracias por visitar nuestro sistema.\n";   
            break;
            }
    } 
}