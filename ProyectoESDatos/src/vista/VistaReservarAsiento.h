#pragma once
#include <iostream>
#include <string>
#include <sstream>

#include "../modelo/Usuario.h"
#include "../modelo/Asiento.h"
#include "../controlador/ListaCircular.h"
#include "../modelo/FechaHora.h"
#include "../../includes/Validacion.h"
#include "../../includes/Include.h"

using namespace std;

class VistaReservarAsiento {

public:
    VistaReservarAsiento();

    // Pasar lista por referencia para guardar reservas
    void vistaReservarAsiento(ListaCircular& lista, const string& archivo);

};
