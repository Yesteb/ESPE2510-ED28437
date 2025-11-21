#include "ListaCircular.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include "Ordenamiento.h"
#include <vector>
#include "../modelo/Asiento.h"
using namespace std;



ListaCircular::ListaCircular() {
    cabeza = nullptr;
   
}

void ListaCircular::insertarFinal(const Asiento& a) {
    Nodo* nuevo = new Nodo{a, nullptr, nullptr};

    if (!cabeza) {
        cabeza = nuevo;
        cabeza->siguiente = cabeza;
        cabeza->anterior = cabeza;
    } else {
        Nodo* cola = cabeza->anterior;
        cola->siguiente = nuevo;
        nuevo->anterior = cola;
        nuevo->siguiente = cabeza;
        cabeza->anterior = nuevo;
    }
}

void ListaCircular::mostrar() const {
    if (!cabeza) {
        cout << "Lista vacia.\n";
        return;
    }
    Nodo* aux = cabeza;
    do {
        cout << "Asiento: " << aux->dato.getNombreAsiento()
             << " | Tipo: " << aux->dato.getTipoAsiento()
             << " | Usuario: " << aux->dato.getUsuario().getNombre()
             << " | Cedula: " << aux->dato.getUsuario().getCedula() << endl;
        aux = aux->siguiente;
    } while (aux != cabeza);
}
void ListaCircular::buscarPorCedula(const string& cedulaInicial) {
    if (!cabeza) {
        cout << "Lista vacia.\n";
        return;
    }

    string cedula = cedulaInicial;
    Validacion v;

    while (true) {
        // Pedir cedula si esta vacia o inicial invalida
        if (cedula.empty()) {
            cout << "Ingrese la cedula del usuario a buscar: ";
            cin >> cedula;
        }

        // Validar que solo tenga digitos (sin negativos ni decimales)
        bool soloDigitos = true;
        for (char c : cedula) {
            if (!isdigit(c)) {
                soloDigitos = false;
                break;
            }
        }

        if (!soloDigitos) {
            cout << "Error: la cedula solo puede contener numeros positivos sin decimales.\n";
            cedula.clear();
            continue; // repetir
        }

        // Validar cedula ecuatoriana
        if (!v.validarCedulaEcuatoriana(cedula)) {
            cout << "Error: cedula ecuatoriana invalida.\n";
            cedula.clear();
            continue; // repetir
        }

        // Buscar en la lista
        Nodo* aux = cabeza;
        bool encontrado = false;
        bool infoUsuarioMostrada = false; // para no repetir info del usuario

        do {
            if (aux->dato.getUsuario().getCedula() == cedula) {
                if (!infoUsuarioMostrada) {
                    cout << "\nUsuario: " << aux->dato.getUsuario().getNombre()
                         << " | Cedula: " << aux->dato.getUsuario().getCedula() << endl;
                    infoUsuarioMostrada = true;
                }
                cout << "Asiento reservado: " << aux->dato.getNombreAsiento()
                     << " | Tipo: " << aux->dato.getTipoAsiento() << endl;
                encontrado = true;
            }
            aux = aux->siguiente;
        } while (aux != cabeza);

        if (!encontrado) {
            cout << "No se encontraron asientos reservados con esa cedula.\n";
            cedula.clear(); // repetir hasta que ingrese una cedula registrada
            continue;
        }

        break; // cedula valida y encontrada, salir del bucle
    }
}


void ListaCircular::guardarEnArchivo(const string &nombreArchivo) const {
    ofstream archivo(nombreArchivo, ios::trunc);
    if (!archivo.is_open()) {
        cout << "No se pudo abrir archivo para guardar.\n";
        return;
    }
    if (!cabeza) return;

    Nodo* aux = cabeza;
    do {
        aux->dato.guardarEnArchivo(archivo);
        aux = aux->siguiente;
    } while (aux != cabeza);
}

void ListaCircular::cargarDesdeArchivo(const string &nombreArchivo) {

    ifstream archivo(nombreArchivo);
    if (!archivo.is_open()) return;

    string linea;
    while (getline(archivo, linea)) {
        Asiento a;
        a.cargarDesdeArchivo(linea);
        insertarFinal(a);
    }
    archivo.close();
}

void ListaCircular::eliminarPorCedula() {
    string cedula;
    // pedir cédula válida
    do {
        cout << "Ingrese la cedula: ";
        cin >> cedula;
        if (!Validacion::validar(cedula, "cedula"))
            cout << "Cedula no valida.\n";
    } while (!Validacion::validar(cedula, "cedula"));

    if (!cabeza) {
        cout << "Lista vacia.\n";
        return;
    }

    // Mostrar reservas
    Nodo* aux = cabeza;
    int contador = 0;
    do {
        if (aux->dato.getUsuario().getCedula() == cedula) {
            cout << static_cast<char>('a' + contador) << ") Asiento: "
                 << aux->dato.getNombreAsiento() << " | Tipo: "
                 << aux->dato.getTipoAsiento() << " | Usuario: "
                 << aux->dato.getUsuario().getNombre() << endl;
            contador++;
        }
        aux = aux->siguiente;
    } while (aux != cabeza);

    if (!contador) {
        cout << "No se encontraron reservas con esa cedula.\n";
        return;
    }

    // Selección de reserva
    char opcion;
    cout << "Ingrese la letra de la reserva a eliminar (x para cancelar): ";
    cin >> opcion;
    if (opcion == 'x' || opcion == 'X') return;

    int indice = opcion - 'a';
    if (indice < 0 || indice >= contador) {
        cout << "Opcion invalida.\n";
        return;
    }

    // Eliminar nodo
    aux = cabeza;
    Nodo* anterior = nullptr;
    int actual = 0;
    do {
        if (aux->dato.getUsuario().getCedula() == cedula) {
            if (actual == indice) {
                Nodo* sig = aux->siguiente;
                Nodo* ant = aux->anterior;
                if (aux == cabeza && aux->siguiente == cabeza) {
                    delete aux;
                    cabeza = nullptr;
                } else {
                    ant->siguiente = sig;
                    sig->anterior = ant;
                    if (aux == cabeza) cabeza = sig;
                    delete aux;
                }
                cout << "Reserva eliminada correctamente.\n";
                guardarEnArchivo("reservas.txt"); // actualizar archivo
                return;
            }
            actual++;
        }
        aux = aux->siguiente;
    } while (aux != cabeza);
}


void ListaCircular::ordenar() {
    if (!cabeza) return;

    std::vector<Asiento> asientos;
    Nodo* aux = cabeza;

    do {
        asientos.push_back(aux->dato);
        aux = aux->siguiente;
    } while (aux != cabeza);

    quickSortAsientos(asientos.data(), 0, asientos.size() - 1);

    aux = cabeza;
    int i = 0;
    do {
        aux->dato = *(asientos.data() + i);
        aux = aux->siguiente;
        i++;
    } while (aux != cabeza);
}
