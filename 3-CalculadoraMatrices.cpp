/* Ejercicio 3: Implementar una calculadora de matrices en C++.  

El programa debe permitir, dadas 2 matrices de n elementos realizar las 
operaciones de suma, resta y multiplicación. Las matrices deben alojarse en el free 
store, tanto las dadas para operar como la matriz resultante.  

Punto  extra:  Adicionalmente  y  de  manera  opcional,  puede  generarse  funciones 
que permitan calcular la matriz traspuesta a la dada, y, en caso de ser una matriz 
cuadrática, obtener su determinante. */

#include<iostream>
#include<conio.h>
#include<stdlib.h>
using namespace std;

void pedirDatos();
void sumarMatrices(int **,int **,int,int);
void restarMatrices(int **,int **,int,int);
void multiplicarMatrices(int **,int **,int,int);
void mostrarMatrizSuma(int **,int,int);
void mostrarMatrizResta(int **,int,int);
void mostrarMatrizMultiplicacion(int **,int,int);


int **puntero_matriz1,**puntero_matriz2,nFilas,nCol;

int main(){
    //Pedimos los datos al usuario  
	pedirDatos();
    //Multiplicacimos y mostramos las matrices
    multiplicarMatrices(puntero_matriz1,puntero_matriz2,nFilas,nCol);
    mostrarMatrizMultiplicacion(puntero_matriz1,nFilas,nCol);

    //Sumamos y mostramos las matrices
	sumarMatrices(puntero_matriz1,puntero_matriz2,nFilas,nCol);
	mostrarMatrizSuma(puntero_matriz1,nFilas,nCol);

    //Restamos y mostramos las matrices
    restarMatrices(puntero_matriz1,puntero_matriz2,nFilas,nCol);
    mostrarMatrizResta(puntero_matriz1,nFilas,nCol);
    
	
	


	for(int i=0;i<nFilas;i++){
		delete[] puntero_matriz2[i];
	}
	delete[] puntero_matriz2;
	
	
	for(int i=0;i<nFilas;i++){
		delete[] puntero_matriz1[i];
	}
	delete[] puntero_matriz1;

    
	
	getch();
	return 0;
}

void pedirDatos(){

    //Input del usuario para las filas y columnas
	cout<<"Numero de filas deseado: ";
	cin>>nFilas;
	cout<<"Numero de columnas deseado: ";
	cin>>nCol;
	
	//Reservamos memoria para la primera matriz
	puntero_matriz1 = new int*[nFilas]; 
	for(int i=0;i<nFilas;i++){
		puntero_matriz1[i] = new int[nCol]; 
	}
	
	cout<<"\nDigitando los elementos de la primera matriz: \n";
	for(int i=0;i<nFilas;i++){
		for(int j=0;j<nCol;j++){
			cout<<"Digite un numero["<<i<<"]["<<j<<"]: ";
			cin>>*(*(puntero_matriz1+i)+j); 
		}
	}
	
	//Reservamos memoria para la segunda matriz
	puntero_matriz2 = new int*[nFilas]; 
	for(int i=0;i<nFilas;i++){
		puntero_matriz2[i] = new int[nCol]; 
	}
	
	cout<<"\nDigitando los elementos de la segunda matriz: \n";
	for(int i=0;i<nFilas;i++){
		for(int j=0;j<nCol;j++){
			cout<<"Digite un numero["<<i<<"]["<<j<<"]: ";
			cin>>*(*(puntero_matriz2+i)+j); 
		}
	}
}

void sumarMatrices(int **puntero_matriz1,int **puntero_matriz2,int nFilas,int nCol){
	for(int i=0;i<nFilas;i++){
		for(int j=0;j<nCol;j++){
			*(*(puntero_matriz1+i)+j) += *(*(puntero_matriz2+i)+j);  
		}
	}
}

void mostrarMatrizSuma(int **putero_matriz1,int nFilas,int nCol){
	cout<<"\nLa suma de ambas matrices es: \n";
	for(int i=0;i<nFilas;i++){
		for(int j=0;j<nCol;j++){
			cout<<*(*(puntero_matriz1+i)+j)<<" ";
		}
		cout<<"\n";
	}
}

void restarMatrices(int **puntero_matriz1,int **puntero_matriz2,int nFilas,int nCol){
	for(int i=0;i<nFilas;i++){
		for(int j=0;j<nCol;j++){
			*(*(puntero_matriz1+i)+j) -= *(*(puntero_matriz2+i)+j);  
		}
	}
}

void mostrarMatrizResta(int **putero_matriz1,int nFilas,int nCol){
	cout<<"\nLa resta de ambas matrices es: \n";
	for(int i=0;i<nFilas;i++){
		for(int j=0;j<nCol;j++){
			cout<<*(*(puntero_matriz1+i)+j)<<" ";
		}
		cout<<"\n";
	}
}

void multiplicarMatrices(int **puntero_matriz1,int **puntero_matriz2,int nFilas,int nCol){
	for(int i=0;i<nFilas;i++){
		for(int j=0;j<nCol;j++){
			*(*(puntero_matriz1+i)+j) *= *(*(puntero_matriz2+i)+j);  
		}
	}
}

void mostrarMatrizMultiplicacion(int **putero_matriz1,int nFilas,int nCol){
	cout<<"\nLa multiplicacion de ambas matrices es: \n";
	for(int i=0;i<nFilas;i++){
		for(int j=0;j<nCol;j++){
			cout<<*(*(puntero_matriz1+i)+j)<<" ";
		}
		cout<<"\n";
	}
}
