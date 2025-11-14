#include "FechaHora.cpp"
#include <ctime>
#include <sstream>


Fecha::Fecha(int d, int m, int a) : dia(d), mes(m), anio(a) {}


bool Fecha::esFeriado() const {
// Ejemplo de feriados simples (puedes agregar más):
// 1 enero, 25 diciembre, 31 diciembre
if ((dia == 1 && mes == 1) ||
(dia == 25 && mes == 12) ||
(dia == 31 && mes == 12)){
return true;
}
return false;
}


bool Fecha::esFinDeSemana() const {
std::tm timeStruct = {};
timeStruct.tm_mday = dia;
timeStruct.tm_mon = mes - 1;
timeStruct.tm_year = anio - 1900;
std::mktime(&timeStruct);


int diaSemana = timeStruct.tm_wday; // 0 = domingo, 6 = sábado
return diaSemana == 0 || diaSemana == 6;
}


void Fecha::sumarDia() {
std::tm timeStruct = {};
timeStruct.tm_mday = dia;
timeStruct.tm_mon = mes - 1;
timeStruct.tm_year = anio - 1900;


std::time_t t = std::mktime(&timeStruct);
t += 24 * 3600; // sumar 1 día
std::tm* next = std::localtime(&t);


dia = next->tm_mday;
mes = next->tm_mon + 1;
anio = next->tm_year + 1900;
}


Fecha Fecha::siguienteDiaLaborable() {
Fecha f = *this;


do {
f.sumarDia();
} while (f.esFinDeSemana() || f.esFeriado());


return f;
}


std::string Fecha::toString() const {
std::ostringstream os;
os << dia << "/" << mes << "/" << anio;
return os.str();
}

