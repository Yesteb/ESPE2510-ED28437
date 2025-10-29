#include "src/Matriz.h"

int main (){
        Matriz<int> control;
        int*** matriz;
        int*** matrizTranspuesta;
        int m = 3, n = 5, e = 7;

        matrizTranspuesta = control.crearMatriz(matrizTranspuesta, n, m, e);
        matriz = control.crearMatriz(matriz, m, n, e);
        control.encerarMatriz(matriz, m, n, e);
        control.encerarMatriz(matrizTranspuesta, n, m, e);
        control. rellenarMatriz(matriz, m, n, e);
        std::cout << "Matriz .- \n";
        control.mostrarMatriz(matriz, m, n, e);
        std::cout << "---------------------------------\n";
        std::cout << "Suma de la diagonal: " << control.sumarDiagonal(matriz, m , n ,e) << "\n";
        std::cout << "Sumar elementos: " << control.sumarElementos(matriz, m, n, e);
        control.transponerMatriz(matriz, matrizTranspuesta, m, n, e);
        std::cout << "---------------------------------\n";
        control.mostrarMatriz(matrizTranspuesta, n, m, e);

        control.limpiarMatriz(matrizTranspuesta, n, m);
        control.limpiarMatriz(matriz, m, n);

        std::cin.get();

}
