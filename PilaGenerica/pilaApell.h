//
// Created by geosm on 28/09/2022.
//

using namespace std;

template <typename T> class  PilaApell
{
private:
        T datos[50];
        int elementos;
public:
    // constructor de una pila vacía:
    PilaApell(): elementos(0) {}

    // Función de inserción de elementos dentro de una pila;
    void insert(T elem)
    {
        if (elementos < 50)
        {
            datos[elementos] = elem;
            elementos ++;
        }
        else
        {
            cout << "Error: Pila llena";
        }
    }

    // Función de extracción de elemento de una pila;
    T extract()
    {
        if (elementos > 0)
        {
            elementos --;
            return datos[elementos];
        }
        else
        {
            cout << "Error: Pila vacía";
        }
    }

    int Numero()
    {
        return elementos;
    }

    T Elemento(int e)
    {
        return datos[e];
    }

    bool es_vacia()
    {
        return elementos == 0;
    }
};