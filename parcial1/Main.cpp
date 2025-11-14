#include <iostream>
#include "FechaHora.h"


int main() {
int d, m, a;
std::cout << "Ingrese dia mes anio: ";
std::cin >> d >> m >> a;


Fecha fecha(d, m, a);
Fecha siguiente = fecha.siguienteDiaLaborable();


std::cout << "El siguiente dia laborable es: " << siguiente.toString() << std::endl;


return 0;
}
