#include "Controlador.h"
#include "CalendarioLaboral.h"

void Controlador::ejecutar() {
    vista.mostrarMensaje("=== Buscador de siguiente dia laborable ===");

    Fecha fecha;
    vista.pedirFecha(fecha);

    if (!fecha.esValida()) {
        vista.mostrarMensaje("Fecha invalida.");
        return;
    }

    CalendarioLaboral calendario(fecha.getAnio());
    Fecha siguiente = siguienteDiaLaborable(fecha, calendario);

    vista.mostrarFecha("Fecha ingresada", fecha);
    vista.mostrarFecha("Siguiente dia laborable", siguiente);
}
