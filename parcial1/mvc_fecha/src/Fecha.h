#pragma once
#include <iostream>

class Fecha {
private:
    int dia;
    int mes;
    int anio;

    static bool esBisiesto(int y);
    static int diasEnMes(int m, int y);

public:
    Fecha(int d = 1, int m = 1, int a = 2000);

    bool esValida() const;
    int diaSemana() const;      // 0=domingo, 1=lunes, ..., 6=sábado
    bool esFinDeSemana() const;

    Fecha& operator++();        // siguiente día calendario
    bool operator==(const Fecha& other) const;

    int getDia()  const { return dia; }
    int getMes()  const { return mes; }
    int getAnio() const { return anio; }

    friend std::istream& operator>>(std::istream& in, Fecha& f);
    friend std::ostream& operator<<(std::ostream& out, const Fecha& f);
};
