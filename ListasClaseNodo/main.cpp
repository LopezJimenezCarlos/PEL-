#include <iostream>
using namespace std;

template <typename T> class Nodo{

    protected:
        T dato;
        Nodo<T>* enlace;
    public:
        Nodo(T d){
            Nodo::dato = d;
            Nodo::enlace = 0;
        }
        Nodo(T d, Nodo<T>* e){
            Nodo::dato = d;
            Nodo::enlace = e;
        }
        Nodo<T>* enlaceNodo(){
            return Nodo::enlace;
        }
        T datoNodo(){
            return Nodo::dato;
        }
        void ponerEnlace(Nodo<T>* e){
            Nodo::enlace = e;
        }
    };


template<typename T> void recorrerPseudolista(Nodo<T>* pseudo_lista){
    
    bool existe_enlace = true;
    while  (existe_enlace == true){
        cout<< pseudo_lista->datoNodo()<<endl;
        if(pseudo_lista->enlaceNodo() == NULL){
            existe_enlace = false;
        }
        else{
           
            pseudo_lista = pseudo_lista->enlaceNodo();
        }
    }
}

int main() {
    Nodo<int>* n1 = new Nodo<int>(2);
    Nodo<int>* n2 = new Nodo<int>(4);
    Nodo<int>* n3 = new Nodo<int>(8);
   
    n1->ponerEnlace(n2);
    n2->ponerEnlace(n3);

    recorrerPseudolista<int>(n1);
}
