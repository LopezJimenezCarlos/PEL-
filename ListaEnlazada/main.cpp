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
    int size(){
        bool existe_enlace = true;
        NodoLista* aux = primero;
        int contador = 0;
        while(existe_enlace == true){
            if (aux->siguiente !=NULL){
                ++contador;
            }
                else{
                 existe_enlace = false;
              }
        }return contador;
    }
    //funciones de EXTRACCION
        //Extraccion por la cabeza
    void cortar_cabeza(){
        NodoLista* aux = primero;
        primero = primero ->siguiente;
        delete aux;
    }
        //Extraccion por la cola
    void saca_colas(){
        NodoLista* aux = primero;
        for (int i = 0; i < size()-1; i++){
            aux = aux->siguiente;
        }
        NodoLista* aux2= aux->siguiente;
        aux->siguiente = 0 ;
        delete aux2;
    }
        //Extraccion de una posicion concreta
        void eliminar_posicion(int pos){
           NodoLista* aux = primero;
                if (pos > size() && pos <= 0){
                    cout "No existen tantos elementos en la lista"<<endl;
                }
                
            }else{
                for(int i = 0; i < pos-1;i++){
                      aux = aux->siguiente;
                }
                    NodoLista* aux2= aux->siguiente;
                    aux->siguiente = aux2->siguiente;
                    delete aux2;
            }
     
    //funciones de ACCESO
        //Funcion de busqueda booleana
        bool existe_elemento(T elemento){
            NodoLista* aux = primero;
            bool existe= false;
            int contador = 0;
            while(contador < size()){
                if (aux->elemento == elemento){
                    existe = true;
                   // contador = size();
                }else{
                    ++contador;
                }
            }
            return existe;
        }
        //Funcion de busqueda posicional

        //Funcion de obtencion de dato por la cabeza

        //Funcion de obtencion de dato por la cola

        //Funcion de obtencion de dato por cualquier lado
};


int main() {

}
