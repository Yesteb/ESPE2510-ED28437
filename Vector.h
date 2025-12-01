#pragma once
#include <iostream>

template <typename T>
class MiVector {
private:
    T* datos;      
    int nElementos;  
    int nTotal;     

    void redimensionar(int nuevaCapacidad) {
        T* nuevo = new T[nuevaCapacidad];


        for (int i = 0; i < nElementos; i++) {
            *(nuevo + i) = *(datos + i);
        }

        delete[] datos;
        datos = nuevo;
        nTotal = nuevaCapacidad;
    }

public:

    MiVector() {
        nElementos = 0;
        nTotal = 2;
        datos = new T[nTotal];
    }

 
    ~MiVector() {
        delete[] datos;
    }


    int size() const {
        return nElementos;
    }


    void push_back(const T& valor) {
        if (nElementos == nTotal) {
            redimensionar(nTotal * 2);
        }
        *(datos + nElementos) = valor; 
        nElementos++;
    }

    T getDato(int i) const {
        return *(datos + i); 
    }


    void setDato(int i, const T& valor) {
        *(datos + i) = valor;
    }


    friend void mostrar(const MiVector<T>& v) {
        for (int i = 0; i < v.nElementos; i++) {
            std::cout << *(v.datos + i) << " ";
        }
    }
};





