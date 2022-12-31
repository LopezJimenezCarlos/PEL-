//Convertir tablas en eestructuras de tipo vector, agregara uno a uno mediante pushback para agregar almacenar en una lista enlazada first in first output
//int de tabla con dos columnas id/numero--> objeto Dato a insertar
//el objeto se alamacena en vector pel par que sea transefirdo a lista enlazada de listatipoPila, añadir menu

#include <iostream>
using namespace std;
int exit_=0;
class Dato{
public:
    int id, num;
   static void info();
    Dato(){
        id=0,
        num=0;
    }
    Dato(int x, int y){
        id=x;
        num=y;
    }
    //~Dato();
};

template<typename T> class VectorPEL { //plantilla de vectro creado en clase
private:
    T * v_, * space_, * last_;

public:
    VectorPEL() : v_{new T [0]}, space_{v_}, last_{v_} {}
    VectorPEL(VectorPEL<T> const& v) : v_{new T[v.capacity()]}, space_{v_ + v.size()}, last_{v_ + v.capacity()} {
        try{
            for(auto i = size_t{0}; i< v.size(); i++){
                v_[i] = v[i];
            }
        }
        catch (...){
            delete[] v_;
            throw;
        }
    }

    ~VectorPEL() {delete[] v_;}

    auto capacity() const -> size_t { return last_ - v_; }
    auto size() const -> size_t { return space_ - v_; }
    auto empty() const -> bool { return v_ == last_; }

    T mostrar_dato(int n) {return v_[n];}

    auto begin(int n) const -> T* {return n + v_;} //funcion que espera un parametro y devuelve un puntero a dicha posicion en el vector
    auto end() const -> T* {return space_;}

    auto push_back(T const& valor) {
        if (space_ == last_) {
            size_t cp = capacity(), new_cp = (cp == 0)? 2:2*cp;
            T* new_block = new T[new_cp];
            try{
                for(auto i = size_t{0}; i < cp; i++) {
                    new_block[i] = v_[i];
                }
                new_block[cp] = valor;
            }
            catch (...) {
                delete[] new_block;
                throw;
            }
            delete[] v_;
            v_ = new_block;
            space_ = new_block + cp + 1;
            last_ = new_block + new_cp;
        }
        else{
            *space_ = valor;
            ++space_;
        }
    };
       void data(int posicion) { //funcion que muestra la busqueda, donde se espera; Posicion en el vector, el dato introducido por el usuario, y el tamaño del vector

        Dato aux; //creamos una variable auxiliar de tipo albunm
        aux = *begin(posicion); //le asignamos a la variable el puntero que apunta a begin pasandole la posicion que queremos ver

        cout <<"id: "<< aux.id <<" num: "<< aux.num <<"\n";
        

     
    };
};
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
        void push(T elemento){
            NodoLista* nuevo = new NodoLista(elemento);
            nuevo->siguiente = primero;
            primero = nuevo;
        }
       
    //funciones de EXTRACCION
        //Extraccion por la cabeza
    void pop(){
        NodoLista* aux = primero;
        primero = primero ->siguiente;
        delete aux;
    }

    T* dato(){
        return primero ->elemento;
    }
        //Extraccion por la cola
 
};



int main() {
VectorPEL<Dato>* v = new VectorPEL<Dato>; 
ListaPEL<int>* l = new ListaPEL<int>; 
Dato a, b, c, d;
int pos;
a.id=132156,a.num=7372823;
b.id=457931,b.num=231232;
c.id=241432,c.num=949572;
d.id=111018,d.num=554231;

l->push(5);
l->dato();

v->push_back(a), v->push_back(b), v->push_back(c), v->push_back(d); //mandamos al vector los 5 objetos creados
cout<<a.id;

/*for(int i=0; i<v->size(); i++){ //Realizamos un bucle tantas veces como objetos haya en el vector

            v->data(i); //lamada a la funcion pasandole los parametros de posicion en el vector, el dato introducido por el usuario y el tamaño del vector
        }*/
}
