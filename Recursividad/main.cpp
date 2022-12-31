#include <iostream>
using namespace std;

int sumaRecursiva (int n){
   if (n <=9){
    return n;
   }else{
    return sumaRecursiva(n/10) + n % 10;
   }
    
}
 
    
int main(int, char**) {
    int n;
    cout<<"Dime un numero: ";
    cin>>n;
    sumaRecursiva(n);
    
}
