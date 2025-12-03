#pragma once
#include <iostream>

template <typename T>
class Matriz {
private:
    T* datos;
    int filas;
    int columnas;

    // ---------- Encriptar un solo valor ----------
    int encriptarValor(int x) const {
        if (x <= 9) return x;

        int suma = 0;
        int temp = x;

        while (temp > 0) {
            suma += temp % 10;
            temp /= 10;
        }

        return encriptarValor(suma); // Recursión
    }

    // ---------- Recorrido recursivo ----------
    void encriptarRec(int fila, int col) {
        if (fila == filas) return;

        if (at(fila, col) > 9) {
            at(fila, col) = encriptarValor(at(fila, col));
        }

        int sigFila = fila;
        int sigCol = col + 1;

        if (sigCol == columnas) {
            sigCol = 0;
            sigFila++;
        }

        encriptarRec(sigFila, sigCol);
    }

public:

    // Constructor
    Matriz(int nFilas, int nColumnas)
        : filas(nFilas), columnas(nColumnas) {
        datos = new T[filas * columnas];
    }

    // Destructor
    ~Matriz() {
        delete[] datos;
    }

    int getFilas() const { return filas; }
    int getColumnas() const { return columnas; }

    // Acceso por punteros
    T& at(int r, int c) {
        return *(datos + (r * columnas + c));
    }

    const T& at(int r, int c) const {
        return *(datos + (r * columnas + c));
    }

    // Llenar toda la matriz con un solo valor
    void llenar(const T& valor) {
        for (int i = 0; i < filas * columnas; i++) {
            *(datos + i) = valor;
        }
    }

    // ---------- NUEVO: Llenar desde teclado ----------
    void llenarPorUsuario() {
        std::cout << "Ingrese los valores de la matriz (" 
                  << filas << "x" << columnas << "):\n";

        for (int i = 0; i < filas; i++) {
            for (int j = 0; j < columnas; j++) {
                std::cout << "Elemento [" << i << "][" << j << "]: ";
                std::cin >> at(i, j);
            }
        }
    }

    // Mostrar
    void mostrar() const {
        for (int i = 0; i < filas; i++) {
            for (int j = 0; j < columnas; j++) {
                std::cout << at(i, j) << " ";
            }
            std::cout << "\n";
        }
    }

    // Encriptar toda la matriz
    void encriptar() {
        encriptarRec(0, 0);
    }
};

