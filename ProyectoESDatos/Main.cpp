#include <iostream>
#include <string>
#include <sstream>
#include "src/modelo/Usuario.h"
#include "src/modelo/Asiento.h"
#include "src/controlador/ListaCircular.h"
#include "src/modelo/FechaHora.h"
#include "includes/Validacion.h"
#include "includes/Include.h"
#include "src/vista/VistaReservarAsiento.h"
#include "src/controlador/Ordenamiento.h"

using namespace std;
int main() {
    VistaReservarAsiento vistaReservar;
    ListaCircular lista;
    const string archivo = "reservas.txt";

    // Cargar datos al iniciar
    lista.cargarDesdeArchivo(archivo);

    string opcionStr;
    int opcion;

    do {
        ImprimirArchivo::imprimirArchivo("resources/MenuPrincipal.txt", 696);
        cout << ">> ";
        cin >> opcionStr;

        // Validar que la entrada sea solo digitos
        bool soloDigitos = true;
        for (char c : opcionStr) {
            if (!isdigit(c)) {
                soloDigitos = false;
                break;
            }
        }

        if (!soloDigitos) {
            cout << "Opcion invalida. Ingrese un numero entre 1 y 6.\n";
            continue;
        }

        // Convertir a entero
        opcion = stoi(opcionStr);

        if (opcion < 1 || opcion > 6) {
            cout << "Opcion invalida. Ingrese un numero entre 1 y 6.\n";
            continue;
        }

        // Ejecutar opcion
        switch (opcion) {
            case 1:
                vistaReservar.vistaReservarAsiento(lista, archivo);
                break;
            case 2:
                lista.ordenar();
                lista.mostrar();
                break;
            case 3: {
                string cedula;
                lista.buscarPorCedula(cedula);
                break;
            }
            case 4:
                lista.eliminarPorCedula();
                lista.guardarEnArchivo(archivo);
                break;
            case 5:
                  {
        Asiento a;
        a.mostrarDisponibilidad(lista); // pasar la lista de reservas
    }
    break; 
            case 6:
                cout << "Saliendo del programa...\n";
                break;
        }

    } while (opcion != 6);

    // Guardar al salir
    lista.guardarEnArchivo(archivo);

    return 0;
}