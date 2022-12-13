#include <iostream>

using namespace std;

template <typename T> class ListaPEL{
private:
    class NodoLista{
        public:
        T elemento;
        NodoLista* siguiente;
        NodoLista(T x){
            elemento = x;
            siguiente = 0;
        };
    };
    NodoLista* primero;
public:
    ListaPEL(){
        primero = 0;
    }
    //Funciones de INSERCION
        //Insercion cabeza
        void insertar_cabeza(T elemento){
            NodoLista* nuevo = new NodoLista(elemento);
            nuevo->siguiente = primero;
            primero = nuevo;
        }
        //Insercion cola
        void insertar_cola(T elemento){
           NodoLista* aux = primero;
           NodoLista* nuevo = new NodoLista(elemento);
           bool existe_enlace = true;
            if (esVacia() == false){
            while(existe_enlace == true){
                if(aux->siguiente == NULL){
                    aux->siguiente = nuevo;
                }
            }
        }
    }    
    
    //Insercion entre dos nodos
    void insertar_posicion(T elemento, int posicion){
        if(posicion > size()){
            cout<<"No se puede insertar en dicha posicion";
        }else{
            inc c = 0;
            NodoLista* aux = primero;
            NodoLista* nuevo = new NodoLista(elemento);
            for (int i = 0; i<posicion; i++){
                aux = aux->siguiente;
            }
            nuevo->siguiente = aux->siguiente;
            aux->siguiente = nuevo;
        }
    }
    //Funciones de TAMAÑO
    bool esVacia(){
        return primero == NULL;//si el primero es null es vacia
    }
    //funciones de EXTRACCION

    //funciones de ACCESO
    int size(){
        bool existe_enlace = true;
        NodoLista* aux = primero;
        int contador = 0;
        while(existe_enlace == true){
            if (aux->siguiente !=NULL){
                ++contador;
            }else{
                existe_enlace = false;
            }
        }return contador;
    }
};

int main() {

}
