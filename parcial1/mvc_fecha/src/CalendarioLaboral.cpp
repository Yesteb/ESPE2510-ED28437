#include "CalendarioLaboral.h"

CalendarioLaboral::CalendarioLaboral(int anio) {
    // Creamos dinámicamente la lista de feriados
    feriados = new std::vector<Fecha>{
        Fecha(1, 1,  anio),  // 01/01
        Fecha(1, 5,  anio),  // 01/05
        Fecha(25, 12, anio), // 25/12
        Fecha(31, 12, anio)  // 31/12 (ejemplo: "valida feriados como el 31")
    };
}

CalendarioLaboral::~CalendarioLaboral() {
    delete feriados;
}

bool CalendarioLaboral::esFeriado(const Fecha& f) const {
    // Uso de template + lambda (definida en el template)
    return contiene(*feriados, f);
}

bool CalendarioLaboral::esFeriado(int d, int m, int a) const {
    // Método sobrecargado
    Fecha tmp(d, m, a);
    return esFeriado(tmp);
}

Fecha siguienteDiaLaborable(const Fecha& fecha, const CalendarioLaboral& cal) {
    Fecha siguiente = fecha;
    ++siguiente; // arranca desde el día siguiente

    while (true) {
        if (!siguiente.esValida()) {
            return siguiente;
        }

        if (!siguiente.esFinDeSemana() && !cal.esFeriado(siguiente)) {
            break; // día laborable
        }
        ++siguiente;
    }

    return siguiente;
}
