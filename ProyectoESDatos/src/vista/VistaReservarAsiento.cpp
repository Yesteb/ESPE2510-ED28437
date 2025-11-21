#include "VistaReservarAsiento.h"

VistaReservarAsiento::VistaReservarAsiento(){}
void VistaReservarAsiento::vistaReservarAsiento(ListaCircular& lista, const string& archivo) {
    Usuario u;
    u.ingresarDatos();
    int cantidad;

    // Pedir cantidad de asientos a reservar
    while (true) {
        cout << "\nCuantos asientos desea reservar? (maximo 10): ";
        string entrada;
        cin >> entrada;

        bool soloDigitos = all_of(entrada.begin(), entrada.end(), ::isdigit);

        if (!soloDigitos) {
            cout << "Entrada invalida. Ingrese un numero entero positivo.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        cantidad = stoi(entrada);
        if (cantidad < 1 || cantidad > 10) {
            cout << "Cantidad invalida. Debe estar entre 1 y 10.\n";
            continue;
        }
        break;
    }

    // Reservar cada asiento
    for (int i = 0; i < cantidad; i++) {
        Asiento a;
        string tipo, codigoAsiento;

        a.mostrarDisponibilidad(lista);

        // Validacion del tipo de asiento
        while (true) {
            cout << "Ingrese tipo de asiento (General/Palco/Tribuna): ";
            cin >> tipo;
            string tipoLower = tipo;
            transform(tipoLower.begin(), tipoLower.end(), tipoLower.begin(), ::tolower);

            if (tipoLower == "general") { codigoAsiento = "A1"; break; }
            else if (tipoLower == "palco") { codigoAsiento = "B1"; break; }
            else if (tipoLower == "tribuna") { codigoAsiento = "C1"; break; }
            else { cout << "Tipo invalido. Ingrese General, Palco o Tribuna.\n"; }
        }

        // Reservar asiento (nombre se genera dentro de reservarAsiento)
        if (a.reservarAsiento(lista, tipo, u, codigoAsiento)) {
            lista.insertarFinal(a);
            cout << "Asiento reservado correctamente. Codigo: " << codigoAsiento << "\n";
        } else {
            cout << "No se pudo reservar el asiento #" << (i + 1) << ".\n";
        }
    }

    // Guardar cambios en archivo
    lista.guardarEnArchivo(archivo);
}
