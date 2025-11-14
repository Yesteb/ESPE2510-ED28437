#pragma once
#include <string>
#include "Fecha.h"

class VistaConsola {
public:
    void mostrarMensaje(const std::string& msg) const;
    void pedirFecha(Fecha& f) const;
    void mostrarFecha(const std::string& titulo, const Fecha& f) const;
};
