#include "Ordenamiento.h"

void swapAsiento(Asiento* a, Asiento* b) {
    Asiento aux = *a;
    *a = *b;
    *b = aux;
}

int partisicion(Asiento* arr, int abajo, int arriba) {
    std::string pivote = (*(arr + arriba)).getNombreAsiento();

    int i = abajo - 1;

    for (int j = abajo; j < arriba; j++) {
        if ((*(arr + j)).getNombreAsiento() < pivote) {
            i++;
            swapAsiento(arr + i, arr + j);
        }
    }

    swapAsiento(arr + i + 1, arr + arriba);
    return i + 1;
}

void quickSortAsientos(Asiento* arr, int abajo, int arriba) {
    if (abajo < arriba) {
        int pivote = partisicion(arr, abajo, arriba);
        quickSortAsientos(arr, abajo, pivote - 1);
        quickSortAsientos(arr, pivote + 1, arriba);
    }
}
