#include "VistaConsola.h"
#include <iostream>

void VistaConsola::mostrarMensaje(const std::string& msg) const {
    std::cout << msg << std::endl;
}

void VistaConsola::pedirFecha(Fecha& f) const {
    std::cout << "Ingrese fecha (dia mes anio): ";
    std::cin >> f;  // usa operador >> sobrecargado
}

void VistaConsola::mostrarFecha(const std::string& titulo, const Fecha& f) const {
    std::cout << titulo << " : " << f << std::endl;
}
