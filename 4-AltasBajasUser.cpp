/* Ejercicio 4: Implementar en C++ un sistema sencillo de altas y bajas de 
usuarios. 

En dicho sistema de altas y bajas debe poder crearse un objeto “usuario” con 
nombre, apellidos y número de usuario, correspondiente al número de usuarios 
dados de alta.  

Importante remarcar que los ID de usuarios no se sustituyen. Si se han creado 3 
usuarios y se da de baja el tercero, el nuevo usuario tendrá el id 3.  

Para dar de baja un usuario, debe eliminarse usando el destructor del objeto 
usuario, mostrando por pantalla que usuarios han sido destruido.  */

#include <iostream>
#include <conio.h>
#include <vector>
#include <stdlib.h>
#include <algorithm>
using namespace std;

class Usuario { //Objeto Usuario   
    private: //Atributos de la clase
    string nombre, apellidos;
    int usernum;

    public:
    Usuario() { //Constructor de la Clase
        this->nombre = "";
        this->apellidos = "";
        this->usernum = 0;
    };

    // Métodos de la Clase
    void altaUsuario(string n, string a, int d) {
        this->nombre = n;
        this->apellidos = a;
        this->usernum = d;
    };
    int devolverID() {
        this->usernum;
    };
    void mostrarUsuario() { 
        cout<<"Usuario "<<this->usernum<<":"<<this->nombre<<" "<<this->apellidos<<endl; };
    
    void mostrarUsuarioBorrado() { 
        cout<<"El Usuario:"<<this->nombre<<" "<<this->apellidos<<"ha sido eliminado"<<endl; };
};

//Menu de nuestro programa
void menu() {
    cout<<"MENU DE GESTION DE USUARIOS"<<endl<<endl;
    cout<<"Escoge la opcion que deseas ejecutar:"<<endl;
    cout<<"1-Dar de alta a un Usuario"<<endl;
    cout<<"2-Dar de baja a un Usuario"<<endl;
    cout<<"3-Mostrar lista de Usuarios"<<endl;
    cout<<"0-Salir"<<endl<<endl;
    cout<<"Ingrese su opcion:";
}

int main() {
    
    system ("cls");
    vector<Usuario> users;
    menu(); //Llamada al menú
    int opcion;
    cin>>opcion; //Almacenamos la opción
    do { //Continuar proceso mientras que no se escoja el cero
    if (opcion==1) {
        system ("cls");
        string n, a;
        int d;
        Usuario u = Usuario();
        cout<<"DAR DE ALTA A UN USUARIO"<<endl<<endl;
        cout<<"Introduce su nombre:"<<endl;
        cin>>n;
        cout<<"Introduce su apellido:"<<endl;
        cin>>a;
        d = d + 1;
        u.altaUsuario(n,a,d);
        users.push_back(u);
        cout<<"Informacion guardada con exito."<<endl;
        cout<<"Introduce 4 para volver al menu o 0 para salir:"<<endl;
        cin>>opcion;

    } if (opcion==2) {
        system("cls");
        int d;
        cout<<"DAR DE BAJA A UN USUARIO"<<endl<<endl;
        cout<<"Introduce el número del Usuario que deseas eliminar:"<<endl;
        cin>>d;
        for (int i = 0; i < users.size();  i++) {
            if (users[i].devolverID() == d) {
                //Eliminamos elemento por posición
                users.erase(users.begin() + 1);
                break;
                }
        }
        cout<<"Informacion borrada con exito."<<endl;
        cout<<"\nIntroduce 4 para volver al menu o 0 para salir:"<<endl;
        cin>>opcion;
    } if (opcion==3) {
        system ("cls");
        cout<<"USUARIOS REGISTRADOS EN SISTEMA"<<endl<<endl;
        for (int i = 0; i < users.size();  i++) {
            users[i].mostrarUsuario(); }
        cout<<"\n\nIntroduce 4 para volver al menu o 0 para salir:"<<endl;
        cin>>opcion;

    } if (opcion==4) { 
        system("cls");
        menu();
        cin>>opcion;

    } else if (opcion!=0 && opcion!=1 && opcion!=2 && opcion!=3 && opcion!=4){ //En caso de no escoger una opcion válida
        system("cls");
        cout<<"\nOPCION NO VALIDA"<<endl; 
        cout<<"Introduce una opcion valida, 4 para volver o 0 para salir:"<<endl;
        cin>>opcion;}

    } while (opcion!=0);
    system ("pause"); // Pausamos el cmd antes del cierre
    return 0;
}