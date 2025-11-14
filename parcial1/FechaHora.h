#pragma once
#include <string>


class Fecha {
private:
int dia;
int mes;
int anio;


public:
Fecha(int d, int m, int a);
bool esFeriado() const;
bool esFinDeSemana() const;
void sumarDia();
Fecha siguienteDiaLaborable();
std::string toString() const;
};
