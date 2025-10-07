#include<iostream>
#include "Fraccion.h"

int main() {

    Fraccion f1;
    Fraccion f2;
    Fraccion resultado;

    std::cout << "Bienvenido!!" << std::endl;
    f1.obtenerFraccion();
    f2.obtenerFraccion();

    resultado = f1.multiplicarFraccion(f2);

    std::cout << "La fraccion es: " << resultado;


    return 0;
}