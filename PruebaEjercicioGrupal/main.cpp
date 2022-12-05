/* Ejercicio  5:  Realizar  un  juego  de  un  usuario  que  consiste  en  adivinar  un 
número en C++.  

El  ordenador  debe  generar  un  número  aleatorio  entre  1  y  100,  mientras  que  el 
usuario  debe  intentar  adivinarlo.  Para  ello,  cada  vez  que  el  usuario  introduce  un 
valor,  el  ordenador  debe  decir  si  el  valor  es  mayor  o  menor  que  el  introducido. 
Cuando el usuario adivine el valor, debe imprimir por pantalla el numero de veces 
que se a intentado adivinar dicho número.  

El programa debe poder manejar las correspondientes excepciones posibles que 
genere el usuario.  
Deben  usarse  las  técnicas  necesarias  para  mejorar  la  eficiencia  del  programa  lo 
máximo posible implementando lo estudiado.   */

#include <iostream>
#include<stdlib.h>
using namespace std;

class AdivinarNumero
{
private:
   int numUsuario;
   int numPc;
public:
   void numeroAleatorio();
   void pedirNumero();
   void compararNumero();
   AdivinarNumero();
   AdivinarNumero(int a, int b){
        numUsuario=a;
        numPc=b;
    }
    ~AdivinarNumero(){

    };
};
  void AdivinarNumero::pedirNumero(){
        
        cout<<"Escribe el numero\n";
        cin >>numUsuario;

    };

    void AdivinarNumero::numeroAleatorio(){
        
        numPc= 0 + rand() % (100 +1 - 0) ;

    }
    void AdivinarNumero::compararNumero(){
        try
        {
            if (numUsuario==numPc)
            {
                cout<<"El numero es el correcto";
            }
            
            
        }
        catch(const std::exception& e)
        {
            do
            {
                if (numUsuario<numPc){
            cout<<"Error, el numero es menor, escribelo otra vez: ";
            cin>>numUsuario;}
                else if(numUsuario>numPc)
            {
                cout<<"Error, el numero es mayor, escribelo otra vez: ";
                cin>>numUsuario;
            } 
            } while (numUsuario!=numPc);
            
           
            
        }
    }
    

int main(){
    AdivinarNumero num1, num2,num3;
    num1.pedirNumero();
    num2.numeroAleatorio();
    num3.compararNumero();
    return 0;
}
