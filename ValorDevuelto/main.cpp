#include <iostream>
using namespace std;
template <typename T>   
T intercambio (T a, T b){
   for (int i=0; i<2; i++){
    if (i==0){
      cout << b << " ";
    }else{
      cout << a << " ";
    }
   
   }
    return  0;
   }

int main(int,char**) {

  cout << intercambio <int> (6,9)<<endl;
    
    

}
