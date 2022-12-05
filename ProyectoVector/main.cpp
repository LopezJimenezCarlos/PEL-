#include <iostream>
using namespace std;

template<typename T> class VectorPEL {
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

        auto begin() const -> T* {return v_;}
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
        }
};
    class album
    {
    public:
    string titulo;
    string grupo;
    string genero;
    
    album(){
        titulo = "";
        grupo = "";
        genero = "";
    };
    album(string x, string y, string z){
        titulo=x;
        grupo=y;
        genero=z;
    }
    ~album();
    };
    

int main() {
    VectorPEL<string>* v = new VectorPEL<string>;
    
    album a;
    string x;
    a.titulo="HotSpace";
    a.genero="Rock";
    a.grupo="Queen";
   
    
    v->push_back(a.titulo);
    v->push_back(a.genero);
    v->push_back(a.grupo);  
   
    cout<<"¿Que desea buscar?: ";
    cin>>x;
    cout<<v->size();
    for(int i=0;i<v->size(); i++){
        if (x==v->mostrar_dato(i)){
            cout<<"Ok";
        }
    }
}