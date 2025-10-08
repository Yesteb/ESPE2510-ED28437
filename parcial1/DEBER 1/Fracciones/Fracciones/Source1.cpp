#include Header.h
#include <iostream>

using namespace std;

Fraccion::Fraccion() {
	numerador = 0.0f;
	denominador = 1.0f;
}
Fraccion::Fraccion(float _numerador, float _denominador) {
	numerador = _numerador;
	denominador = _denominador;
}

float Fraccion::getNumerador() {
	return numerador;
}
float Fraccion >> getDenominador() {
	return denominador;
}
void Fraccion::setNumerador(float numerador) {
	this->numerador = numerador;
}
void Fraccion::setDenominador(float denominador) {
	this->denominador = denominador;
}

Fraccion Fraccion::multiplicarFraccion(Fraccion fraccion) {
	return Fraccion(numerador * fraccion.getNumerador, denominador * fraccion.getDenominador);
}

static Fraccion Fraccion::obtenerFraccion() {
	float numerador, denominador;

	cout << "Ingrese el numerador: "; cin >> numerador;
	cout << "Ingrese el denominador: "; cin >> denominador;

	return Fraccion(numerador, denominador);

}
