#include "Fecha.h"

Fecha::Fecha(int d, int m, int a) : dia(d), mes(m), anio(a) {}

bool Fecha::esBisiesto(int y) {
    return ( (y % 4 == 0 && y % 100 != 0) || (y % 400 == 0) );
}

int Fecha::diasEnMes(int m, int y) {
    switch (m) {
        case 1: case 3: case 5: case 7: case 8: case 10: case 12:
            return 31;
        case 4: case 6: case 9: case 11:
            return 30;
        case 2:
            return esBisiesto(y) ? 29 : 28;
        default:
            return 0;
    }
}

bool Fecha::esValida() const {
    if (anio < 1) return false;
    if (mes < 1 || mes > 12) return false;
    int maxDia = diasEnMes(mes, anio);
    return dia >= 1 && dia <= maxDia;
}

// Zeller modificado: 0=domingo, 1=lunes, ..., 6=sábado
int Fecha::diaSemana() const {
    int d = dia;
    int m = mes;
    int y = anio;

    if (m < 3) {
        m += 12;
        y -= 1;
    }

    int K = y % 100;
    int J = y / 100;
    int h = (d + (13 * (m + 1)) / 5 + K + K / 4 + J / 4 + 5 * J) % 7;
    // h: 0=sábado, 1=domingo, 2=lunes, ... 6=viernes
    int dow = (h + 6) % 7; // 0=domingo, 1=lunes, ..., 6=sábado
    return dow;
}

bool Fecha::esFinDeSemana() const {
    int dow = diaSemana();
    return (dow == 0 || dow == 6); // domingo o sábado
}

Fecha& Fecha::operator++() {
    dia++;
    int maxDia = diasEnMes(mes, anio);
    if (dia > maxDia) {
        dia = 1;
        mes++;
        if (mes > 12) {
            mes = 1;
            anio++;
        }
    }
    return *this;
}

bool Fecha::operator==(const Fecha& other) const {
    return dia == other.dia && mes == other.mes && anio == other.anio;
}

std::istream& operator>>(std::istream& in, Fecha& f) {
    in >> f.dia >> f.mes >> f.anio;
    return in;
}

std::ostream& operator<<(std::ostream& out, const Fecha& f) {
    out << (f.dia < 10 ? "0" : "") << f.dia << "/"
        << (f.mes < 10 ? "0" : "") << f.mes << "/"
        << f.anio;
    return out;
}
