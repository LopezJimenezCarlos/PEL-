#include <iostream>
using namespace std;

template <typename T>   
T minum (T a, T b){
    return (a<b ? a : b);
}
template <typename T>   
T maximum (T a, T b){
    return (a>b ? a : b);
}

int main() {
    int a=5, b=2, n,x;
    float c=4.5 , d=4.4, m,y;
    n = minum (a,b);
    m = minum (c,d);
    x= maximum(a,b);
    y= maximum(c,d);    


    cout << "El entero menor es: "<< n << "\n";
    cout << "El entero mayor es: "<< x << "\n";
     cout << "El real menor es: "<< m << "\n";
    cout << "El real mayor es: "<< y << "\n";

    return 0;
    ;
}
