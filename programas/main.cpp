#include <iostream>
using namespace std;

class RelojVacio{
     public:          
    int h=0;
    int m=0;
    int s=0;      
    RelojVacio(int x, int y, int z) { 
      h = x;
      m = y;
      s = z;}
};

class Reloj1 {        
  public:          
    int h;
    int m;
    int s;      
    Reloj1(int x, int y, int z) { 
      h = x;
      m = y;
      s = z;
    }
};
class Reloj2 {        
  public:          
    int h;
    int m;
    int s;      
    Reloj2(int x, int y, int z) { 
      h = x;
      m = y;
      s = z;
    }
};
int a, b, c, d, e, f;

int datos(){
     
    cout <<"Di la hora del primer reloj\n";
    cout <<"hora: \n";
    cin>> a;
    cout <<"minutos: \n";
    cin>> b;
    cout <<"segundos: \n";
    cin>> c;
    cout <<"Di la hora del segundo reloj\n";
    cout <<"hora: \n";
    cin>> d;
    cout <<"minutos: \n";
    cin>> e;
    cout <<"segundos: \n";
    cin>> f;
    return a,b,c,d,e,f;

}
void leer(int a, int b, int c, int d, int e, int f){

    Reloj1 carObj1(a,b,c);
    cout << carObj1.h << " " << carObj1.m << " " << carObj1.s << "\n";
    Reloj2 carObj2(d,e,f);
    cout << carObj2.h << " " << carObj2.m << " " << carObj2.s << "\n";
    
};
void sumar(int a, int b, int c, int d, int e, int f){
    int sol, seg, min, hora;
    sol = c+f;
    if (sol>59){
        seg=sol-60;
        min=1;
    }else{
      seg=sol;
    }
    min=min+b+e;
    if(min>59){
        min=min-60;
        hora=1;
    }
    hora=hora+a+d;
    if(hora>23){
        hora=0;
    }

    cout << "La hora sumada: ";
     RelojVacio carObj0(hora,min,seg);
    cout << carObj0.h << " " << carObj0.m << " " << carObj0.s << "\n";
}

int main(){
    datos();
    leer(a,b,c,d,e,f);
    
    sumar(a,b,c,d,e,f);

}