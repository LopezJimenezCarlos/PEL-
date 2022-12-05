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
   int nVeces;
public:
   void numeroAleatorio();
   void pedirNumero();
   void compararNumero();
   AdivinarNumero(){
    numUsuario=0;
    numPc=0;
    nVeces=0;
   }
   AdivinarNumero(int a, int b, int c){
        numUsuario=a;
        numPc=b;
        nVeces=c;
    }
    ~AdivinarNumero(){

    };
};
  void AdivinarNumero::pedirNumero(){
        
        cout<<"Escribe el numero\n";
        cin >>numUsuario;
        nVeces ++;
    };

    void AdivinarNumero::numeroAleatorio(){
         srand((unsigned int)time(NULL));
        numPc= 0 + rand() % (100 +1 - 0) ;

    };
    void AdivinarNumero::compararNumero(){
       
            if (numUsuario==numPc)
            {
                cout<<"El numero es el correcto";
            }
            do
            {
                if (numUsuario<numPc){
            cout<<"Error, el numero es  que buscas es mayor, escribelo otra vez: ";
            cin>>numUsuario;}
                else if(numUsuario>numPc)
                    {
                    cout<<"Error, el numero que buscas es menor, escribelo otra vez: ";
                    cin>>numUsuario;
            } 
            } while (numUsuario!=numPc);
        }

int main()
{
    AdivinarNumero();
    AdivinarNumero num1;
    num1.pedirNumero();
    num1.numeroAleatorio();
    num1.compararNumero();

    return 0;
}