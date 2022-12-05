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

int main() {
    VectorPEL<string>* v = new VectorPEL<string>;
    string x;
    int n=-1;

    while (x != "end") {
    cout << "Escribe una palabra: ";
    cin >> x;
    v-> push_back(x);
    ++n;
    }

    cout << "El vector es: ";
    for (auto i = 0; i < n; i++) {
        cout <<"[ " + v->mostrar_dato(i) + " ], ";
    }
    
    return 0;
}