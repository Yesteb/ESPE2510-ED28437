#pragma once
#include <vector>
#include <algorithm>
#include "Fecha.h"

// ===== Template genérico =====
template <typename Contenedor, typename T>
bool contiene(const Contenedor& c, const T& x) {
    return std::any_of(c.begin(), c.end(),
                       [&](const T& elem) { return elem == x; });
}

// ===== Modelo de calendario laboral (feriados, etc.) =====
class CalendarioLaboral {
private:
    // Uso de puntero a std::vector como "lista" dinámica
    std::vector<Fecha>* feriados;

public:
    explicit CalendarioLaboral(int anio);
    ~CalendarioLaboral();

    // Métodos sobrecargados
    bool esFeriado(const Fecha& f) const;
    bool esFeriado(int d, int m, int a) const;
};

// Función de negocio: siguiente día laborable
Fecha siguienteDiaLaborable(const Fecha& fecha, const CalendarioLaboral& cal);
