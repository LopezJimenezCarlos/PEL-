#include <iostream>
using namespace std;
class X{
private:
    int numero, numero2;
public:
    X(){  
        X::numero = 0;
        X::numero2 = 0;
    }
    X(int num1, int num2){
        X::numero = num1;
        X::numero2 = num2;
    }
    ~X(){};
    void verNumero1(){
        cout << X::numero << endl;
    }
    void verNumero2(){
        cout << X::numero2 << endl;
    }
};
int main() {
    X *p = new X[3]{X(1, 2), X(3, 5), X(6, 7)};
    p->verNumero1();
    p->verNumero2();
    for (int i = 0; i < 3; ++i) {
        p->~X();
        p++;
    }
    delete(p);
}