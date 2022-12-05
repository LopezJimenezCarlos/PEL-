#include<iostream>
#include<conio.h>
#include<stdlib.h>
using namespace std;
 
struct Usuario{
	int dato;
	Usuario *siguiente;
};
 
//Prototipos de Función
void agregarPila(Usuario *&,string);
//void sacarPila(Usuario *&,int &);
 
int main(){
	Usuario *pila = NULL;	//Inicializamos pila
	string eUsuario;
	char rpt;
 
	//Pedimos todos los elementos de la pila
		cout<<"Di tu nombre";
		cin>>eUsuario;
		agregarPila(pila,eUsuario);
        cout<<"Di tu apellido";
		cin>>eUsuario;
		agregarPila(pila,eUsuario);
        cout<<"Di tu dni";
		cin>>eUsuario;
		agregarPila(pila,eUsuario);
 

	cout<<"\nMostrando los elementos de la pila: ";
	while(pila != NULL){
		//sacarPila(pila,dato);
 
		if(pila != NULL){
			cout<<eUsuario<<" , ";
		}
		else{
			cout<<eUsuario<<".";
		}
	}
 
	getch();
	return 0;
}
 
void agregarPila(Usuario *&pila,int &n){
	Usuario *nuevo_usuario = new Usuario();
	nuevo_usuario->dato = n;
   nuevo_usuario->siguiente = pila;
    pila = nuevo_usuario;
    
 
	cout<<"\tElemento "<<n<<" agregado a PILA correctamente";
}
 
void sacarPila(Usuario *&pila,int &n){
	Usuario *aux = pila;
	n = aux->dato;
	pila = aux->siguiente;
	delete aux;
}