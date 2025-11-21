#include "Asiento.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include "../controlador/ListaCircular.h"    //Ojo 
using namespace std;

int Asiento::disponiblesGeneral = 10;
int Asiento::disponiblesPalco = 10;
int Asiento::disponiblesTribuna = 10;

Asiento::Asiento() = default;
Asiento::~Asiento() = default;

string Asiento::getNombreAsiento() const { return nombreAsiento; }
string Asiento::getTipoAsiento() const { return tipoAsiento; }
Usuario Asiento::getUsuario() const { return duenioAsiento; }

void Asiento::setNombreAsiento(const string& nombre) { nombreAsiento = nombre; }
void Asiento::setTipoAsiento(const string& tipo) { tipoAsiento = tipo; }
void Asiento::setUsuario(const Usuario& u) { duenioAsiento = u; }
#include <cstdlib>  // para malloc y free
#include <string>
#include <iostream>
using namespace std;


void Asiento::mostrarDisponibilidad(ListaCircular& listaReservas) {
    cout << "\nDisponibilidad de asientos:\n";

    int filas = 3;
    int columnas = 10;

    // Crear matriz dinámica
    char*** matriz = (char***) malloc(filas * sizeof(char**));
    for (int i = 0; i < filas; i++) {
        *(matriz + i) = (char**) malloc(columnas * sizeof(char*));
        for (int j = 0; j < columnas; j++) {
            *( *(matriz + i) + j ) = (char*) malloc(10); // buffer seguro
        }
    }

    // Lambda para verificar si un asiento está reservado
    auto estaReservado = [&](const string& codigo) {
        Nodo* aux = listaReservas.getCabeza();
        if (!aux) return false;

        do {
            string codigoAsiento = aux->dato.getNombreAsiento();
            codigoAsiento.erase(remove_if(codigoAsiento.begin(), codigoAsiento.end(), ::isspace), codigoAsiento.end());
            transform(codigoAsiento.begin(), codigoAsiento.end(), codigoAsiento.begin(), ::toupper);

            string codigoUpper = codigo;
            transform(codigoUpper.begin(), codigoUpper.end(), codigoUpper.begin(), ::toupper);

            if (codigoAsiento == codigoUpper)
                return true;

            aux = aux->siguiente;
        } while (aux != listaReservas.getCabeza());

        return false;
    };

    // Llenar matriz
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            char letra = 'A' + i;
            int numero = j + 1;
            string codigo = string(1, letra) + to_string(numero);

            bool ocupado = estaReservado(codigo);

            snprintf(*(*(matriz + i) + j), 10, "%c%d[%c]", letra, numero, (ocupado ? 'X' : ' '));
        }
    }

    // Imprimir matriz
    for (int i = 0; i < filas; i++) {
        if (i == 0) cout << "General: ";
        else if (i == 1) cout << "Palco:   ";
        else cout << "Tribuna: ";

        for (int j = 0; j < columnas; j++) {
            cout << *(*(matriz + i) + j) << " ";
        }
        cout << endl;
    }

    // Liberar memoria
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++)
            free(*(*(matriz + i) + j));
        free(*(matriz + i));
    }
    free(matriz);
}


bool Asiento::reservarAsiento(ListaCircular& listaReservas, const string& tipoInicial, const Usuario& u, const string& nombre) {
    string tipo = tipoInicial;
    string tipoLower;
    bool reservado = false;

    // Lambda para verificar si un asiento ya está reservado
    auto estaReservado = [&](const string& codigo) {
        Nodo* aux = listaReservas.getCabeza();
        if (!aux) return false;

        do {
            string codigoAsiento = aux->dato.getNombreAsiento();
            codigoAsiento.erase(remove(codigoAsiento.begin(), codigoAsiento.end(), ' '), codigoAsiento.end());
            if (codigoAsiento == codigo) return true;
            aux = aux->siguiente;
        } while (aux != listaReservas.getCabeza());

        return false;
    };

    while (!reservado) {
        // Convertir a minúsculas y limpiar espacios
        tipoLower = tipo;
        transform(tipoLower.begin(), tipoLower.end(), tipoLower.begin(), ::tolower);
        tipoLower.erase(remove_if(tipoLower.begin(), tipoLower.end(), ::isspace), tipoLower.end());

        // Validar tipo
        if (tipoLower != "general" && tipoLower != "palco" && tipoLower != "tribuna") {
            cout << "Tipo invalido. Ingrese general, palco o tribuna: ";
            cin >> tipo;
            continue;
        }

        // Determinar fila
        char fila = (tipoLower == "general") ? 'A' : (tipoLower == "palco") ? 'B' : 'C';

        // Validar número de asiento
        string entrada;
        int numero = 0;
        bool numeroValido = false;

        while (!numeroValido) {
            cout << "Ingrese el numero de asiento (1-10) para la fila " << fila << ": ";
            cin >> entrada;

            // Revisar que solo sean dígitos
            if (!all_of(entrada.begin(), entrada.end(), ::isdigit)) {
                cout << "Entrada invalida. Solo numeros enteros del 1 al 10.\n";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                continue;
            }

            numero = stoi(entrada);
            if (numero < 1 || numero > 10) {
                cout << "Numero fuera de rango. Debe estar entre 1 y 10.\n";
                continue;
            }

            numeroValido = true;
        }

        // Crear código
        string codigo = string(1, fila) + to_string(numero);

        // Verificar si ya está reservado
        if (estaReservado(codigo)) {
            cout << "Asiento ya reservado. Elija otro.\n";
            continue;
        }

        // Reservar asiento
        setTipoAsiento((tipoLower == "general") ? "General" : (tipoLower == "palco") ? "Palco" : "Tribuna");
        setUsuario(u);
        setNombreAsiento(codigo);

        // Reducir disponibilidad
        if (tipoLower == "general") disponiblesGeneral--;
        else if (tipoLower == "palco") disponiblesPalco--;
        else disponiblesTribuna--;

        reservado = true;
        cout << "Asiento " << codigo << " reservado correctamente para " << u.getNombre() << ".\n";
    }

    return true;
}



void Asiento::guardarEnArchivo(ofstream &archivo) const {
    archivo << nombreAsiento << "|"
            << tipoAsiento << "|"
            << duenioAsiento.getNombre() << "|"
            << duenioAsiento.getCedula() << endl;
}

// Función auxiliar para quitar espacios al inicio y final
inline string trim(const string& str) {
    size_t first = str.find_first_not_of(" \t");
    if (first == string::npos) return "";
    size_t last = str.find_last_not_of(" \t");
    return str.substr(first, last - first + 1);
}

// Función auxiliar para convertir a mayúsculas (opcional, para coincidencia exacta)
inline string toUpper(const string& s) {
    string r = s;
    transform(r.begin(), r.end(), r.begin(), ::toupper);
    return r;
}

void Asiento::cargarDesdeArchivo(const string &linea) {
    stringstream ss(linea);
    string nombreUsuario, cedula;

    getline(ss, nombreAsiento, '|');
    nombreAsiento = toUpper(trim(nombreAsiento));   // Quitar espacios y pasar a mayúsculas

    getline(ss, tipoAsiento, '|');
    tipoAsiento = trim(tipoAsiento);

    getline(ss, nombreUsuario, '|');
    nombreUsuario = trim(nombreUsuario);

    getline(ss, cedula, '|');
    cedula = trim(cedula);

    Usuario u;
    u.setNombre(nombreUsuario);
    u.setCedula(cedula);
    duenioAsiento = u;

    // Actualizar disponibilidad
    if (tipoAsiento == "General") disponiblesGeneral--;
    else if (tipoAsiento == "Palco") disponiblesPalco--;
    else if (tipoAsiento == "Tribuna") disponiblesTribuna--;
}

