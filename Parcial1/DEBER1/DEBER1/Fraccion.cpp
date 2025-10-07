#include "Fraccion.h"
#include<iostream>

using namespace std;

Fraccion::Fraccion() {
    numerador = 0.0f;
    denominador = 1.0f;
}

Fraccion::Fraccion(float _numerador, float _denominador) {
    numerador = _numerador;
    denominador = _denominador;
}

Fraccion::~Fraccion() {}

float Fraccion::getNumerador() {
    return numerador;
}

float Fraccion::getDenominador() {
    return denominador;
}

void Fraccion::setNumerador(float _numerador) {
    numerador = _numerador;
}

void Fraccion::setDenominador(float _denominador) {
    denominador = _denominador;
}

Fraccion Fraccion::obtenerFraccion() {

    cout << "Ingrese el numerador" << endl; cin >> numerador;

    do {
        cout << "Ingrese el denominador" << endl; cin >> denominador;
    } while (denominador == 0);


    return Fraccion(numerador, denominador);
}

Fraccion Fraccion::multiplicarFraccion(Fraccion fraccion) {
    return Fraccion((numerador * fraccion.getNumerador()), (denominador * fraccion.getDenominador()));
}