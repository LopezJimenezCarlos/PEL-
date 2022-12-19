/* Ejercicio 1. Implementar en C++ un programa, simulando la pila de usuario 
(y declarando sus valores en la misma) tenga las siguientes funciones: 

• Solicite al usuario por consola un valor que almacenar en la pila de usuario.  
• Permita ver que valores se almacenan en la pila del usuario en las diferentes 
posiciones.  
• Debe poder eliminarse el valor de cualquier posición de la pila de usuario. 

El  código  generado  debe  ser  a  prueba  de  errores.  Para  ello  implementa  los 
métodos necesarios para poder mantener el proceso de ejecución. */

//Mohammed Azzouz

#include <iostream>

using namespace std;

int main(){

    int size, dato, posicion=0, elemento, exit=0;

    cout << "Que tamano deseas que tenga la pila?\n";
    cin >> size;

    while (cin.fail()) //Bucle para manejo de errores en input
    {
    cin.clear();
    cin.ignore();
    cout << "Error, introduzca dato de tipo entero: ";
    cin >> size;
    } 

    int* array = new int [size]; //Creacion de array dinamico que aloja sus datos enla free store

    while (exit!=5)
    {
        cout << "\n";
        cout << "[1] Insertar elemento en pila\n";
        cout << "[2] Ver todos los elementos en pila\n";
        cout << "[3] Ver un elemento en concreto\n";
        cout << "[4] Sacar elemento de pila\n";
        cout << "[5] Salir\n";
        cout << "¿Que accion desea realizar?\n";
        cout << "\n";

        cin >> exit;

        while (cin.fail()) //Bucle para manejo de errores en input
        {
        cin.clear();
        cin.ignore();
        cout << "Error, introduzca dato de tipo entero: ";
        cin >> exit;
        } 

            switch (exit) {
        case 1:
            if (posicion==size) //En caso de no haber mas hueco enla pila no dejar meter datos
            {
                cout << "No queda espacio en la pilan\n";
            }
            else{
                cout << "Introduzca dato de tipo entero: ";
                cin >> dato;

                while (cin.fail()) //Bucle para manejo de errores en input
                {
                cin.clear();
                cin.ignore();
                cout << "Error, introduzca dato de tipo entero: ";
                cin >> dato;
                } 

                array[posicion] = dato; // Se asigna en la primera posicion el dato introducido por el usuario.
                posicion++; //Se incremente la posicion para asi el proximo dato guardado no se sobreescriba.
            }

            break;
        case 2:
            cout << "\n";
            if (posicion==0) //Si el contador esta a 0 significara que la pila esta vacia 
            {
                cout << "La pila esta vacia\n";
            }
            else{
                for (int i = 0; i < posicion; i++) //Buclque que recotre la pila imprimiendo todos los datos introducidos por el usuariosS
                {
                    cout << array[i]; 
                    cout << " ";
                }
            }
            
            break;
        case 3:
            cout << "\n";
            if (posicion==0) //Si el contador esta a 0 significara que la pila esta vacia 
            {
                cout << "La pila esta vacia\n";
            }
            else{
                cout << "Que elemento desea ver: ";
                cin >> elemento;

                while (cin.fail()) //Bucle para manejo de errores en input 
                {
                cin.clear();
                cin.ignore();
                cout << "Error, introduzca dato de tipo entero: ";
                cin >> elemento;
                }

                cout << "\n";
                cout << "En la posicion " << elemento << " hay: ";
                cout << array[elemento] << "\n"; //Muestra el elemento de dicha posición
            }
            break;
        case 4:
            cout << "\n";
            if (posicion==0) //Si el contador esta a 0 significara que la pila esta vacia
            {
                cout << "La pila esta vacia\n";
            }
            else{
                
                cout << "\n";
                cout << "Que elemento desea sacar de pila: ";
                cin >> elemento;

                while (cin.fail()) //Bucle para manejo de errores en input 
                {
                cin.clear();
                cin.ignore();
                cout << "Error, introduzca dato de tipo entero: ";
                cin >> elemento;
                }

                array[elemento] = 0; //Remplaza el elemento escogido por el usuario por un 0

            }
            break;
        case 5: 
            cout << "\n";
            cout << "Gracias por visitar nuestro sistema.\n";   
            break;

        default:   
            cout << "\n"; 
            cout << "Opcion inexistente.\n";   
            break;
            }
    }

    delete[] array; //Liberacion de la free store

    return 0;
}