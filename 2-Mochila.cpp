/* Ejercicio 2: Implementar en C++ un programa sencillo que simule una 
mochila o almacén de objetos.

El programa debe permitir al usuario que se “almacene” cualquier tipo de objeto 
que quiera el usuario (solo validos tipos de datos estándar de C++). 

Para ello, se implementará un menú de “gestión de objetos”, que permitirá seleccionar si se 
quiere almacenar un objeto o eliminarlo, permitiendo elegir que objeto eliminar.

A la hora de almacenar los  datos, deben emplearse  las  técnicas  y métodos que 
hagan  que  el  almacenamiento  sea  lo  más  eficiente  posible  en  todo  momento. 
Para ello, deben emplearse los operadores de alineación. */

//Mohammed Azzouz

#include <iostream>
#include <vector>

using namespace std;

int cont=0;

struct almacen{ //Structura donde se declaran dos tipos de elementos
    string objeto;
    int cantidad;
    almacen* next;
};

vector <almacen> vAlmacen = {}; //Vector que usaremos para almacenar objetos y cantidades 

int agregar_elemento(){

    string objet;
    int cantida;

    almacen* free1 = new almacen(); //Creacion de puntero que se aloja en la free store

    cout << "Que objeto desea introducir en el almacen?\n";
    cin >> objet;

    while (cin.fail()) //Bucle para manejo de errores en input
    {
    cin.clear();
    cin.ignore();
    cout << "Error, introduzca dato de tipo string: ";
    cin >> objet;
    } 

    free1->objeto; //Le pasamos el obejeto para subirlo a la free store
    free1->next = NULL; //Lo igualamos a null para poder utilizarlo la proxima vez

    almacen* free2 = new almacen(); //Creacion de puntero que se aloja en la free store

    cout << "Cantidad de " << objet << " en el almacen\n";
    cin >> cantida;

    while (cin.fail()) //Bucle para manejo de errores en input
    {
    cin.clear();
    cin.ignore();
    cout << "Error, introduzca dato de tipo entero: ";
    cin >> cantida;
    } 

    free2->cantidad; //Le pasamos el obejeto para subirlo a la free store
    free2->next = NULL; //Lo igualamos a null para poder utilizarlo la proxima vez

    vAlmacen.push_back({objet, cantida}); //Pasamamos al vector los elementos introducidos por el usuario

    cont++;

    return 0;
}

int ver_elemento(){

    if (cont==0) //Si el contador vale 0 significara que no hay elementos en el almacen
    {
        cout << "\n";
        cout << "El almacen esta vacio\n";
    }
    else{
        cout << "\n";
        for (int i = 0; i < cont; i++) //Bucle donde se imprimira por pantalla los objetos y cantidades que hay en el vector
        {
            cout << "\n";
            cout << "Objeto: " << vAlmacen[i].objeto << endl; 
            cout << "Cantidad: " << vAlmacen[i].cantidad << endl;
        }
        cout << "\n";
    }
    
    return 0;
}

int sacar_elemento(){

    string eliminar;

    if (cont==0) //Si el contador vale 0 significara que no hay elementos en el almacen
    {
        cout << "\n";
        cout << "El almacen esta vacio\n";
    }
    else{
        ver_elemento(); //llamamos a la funcion para que el usuario pueda ver que objetos hay en el almacen

        cout << "Que objeto deseas sacar del alamacen?\n";
        cin >> eliminar;

        while (cin.fail()) //Bucle para manejo de errores en input
        {
        cin.clear();
        cin.ignore();
        cout << "Error, introduzca dato de tipo string: ";
        cin >> eliminar;
        } 

        for (int i = 0; i < cont; i++)
        {
            if (eliminar==vAlmacen[i].objeto) //Comparacion del objeto a eliminar con los actuales en el vector
            {
                vAlmacen.erase(vAlmacen.begin() + i); //Eliminacion del vector de dicho objeto 
                cout << "\n";
                cout << "Objeto eliminado\n";
                cont--;
                break;
            }
            else if ((i+1)==cont) //Condicional para que solo aparezca en la ultima iteracion del bucle en caso de no encontrar dicho objeto
            {
                cout << "Objeto no encotrado\n";
            }
        }
    }

    return 0;
}

int main() {

    int exit=0;

    while (exit!=4)
    {
        cout << "\n";
        cout << "[1] Agregar objeto y cantidad en el almacen\n";
        cout << "[2] Ver objetos en el almacen\n";
        cout << "[3] Sacar objeto del almacen\n";
        cout << "[4] Salir\n";
        cout << "Que accion desea realizar?\n";
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
            agregar_elemento();
            break;
        case 2:
            ver_elemento();
            break;
        case 3:
            sacar_elemento();
            break;
        case 4: 
            cout << "Gracias por visitar nuestro sistema.\n";   
            break;
        default:   
            cout << "\n"; 
            cout << "Opcion inexistente.\n";   
            break;
            
            }
    }

    return 0;
}