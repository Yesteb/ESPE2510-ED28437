#pragma once
#include <iostream>
#include <functional>

template <typename T>
class Matriz {
public:
        Matriz();
        ~Matriz();

        T*** crearMatriz(T***, int ,int ,int);
        void encerarMatriz(T***, int, int ,int);
        void rellenarMatriz(T***, int, int ,int);
        void mostrarMatriz(T***, int ,int ,int);
        void limpiarMatriz(T***, int, int);

        T sumarDiagonal(T***, int, int, int);
        T sumarElementos(T***, int, int ,int);
        void transponerMatriz(T***, T***, int, int, int);

};

#include "Matriz.tpp"
