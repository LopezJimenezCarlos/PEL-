#include <iostream>
using namespace std;

void suma(int n1,int n2,int &resultado){
    resultado=n1+n2;
}
int main() {
    int n1=2,n2=3,res;
    suma(n1,n2,res);
    cout<<res;
}
