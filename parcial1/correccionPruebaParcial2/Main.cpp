#include "Matriz.h"

int main() {
    Matriz<int> M(2, 3);

    M.llenarPorUsuario();

    std::cout << "\nMatriz ingresada:\n";
    M.mostrar();

    M.encriptar();

    std::cout << "\nMatriz encriptada:\n";
    M.mostrar();
}
