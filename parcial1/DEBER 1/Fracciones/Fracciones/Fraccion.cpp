#include "Fraccion.h"
#include<iostream>
#include<conio.h>
#include<Windows.h>
using std::cout;
using std::endl;
using std::cin;



Fraccion::Fraccion(float numerador, float denominador) {
	this->numerador = numerador;
	this->denominador = denominador;
}

Fraccion::Fraccion() {
	numerador = 0.0f;
	denominador = 1.0f;
}

Fraccion::~Fraccion() {
	// Destructor
}

float Fraccion::getNumerador() {
	return numerador;
}
float Fraccion::getDenominador() {
	return denominador;
}
void Fraccion::setNumerador(float numerador) {
	this->numerador = numerador;
}

void Fraccion::setDenominador(float denominador) {
	this->denominador = denominador;
}

Fraccion Fraccion::multiplicarFraccion(Fraccion fraccion) {
	return Fraccion(numerador * fraccion.getNumerador(), denominador * fraccion.getDenominador());
}

Fraccion Fraccion::obtenerFraccion() {
	float numerador;
	float denominador;

	do {

		cout << "Ingrese el numerador (numeros decimales o enteros): "; cin >> numerador;
		cout << "Ingrese el denominador (numeros decimales o enteros): "; cin >> denominador;

		if (cin.fail() || denominador == 0) {
			cin.clear();
			cin.ignore(10000, '\n');
			cout << "Debe ingresar numeros enteros o flotantes, Vuelva a intentarlo\n";
			system("pause");

			if (_WIN32) {
				system("cls");
			}
			else {
				system("clear");
			}
			
		} else {

			break;
		} 
	} while (true);
	
	

	return Fraccion(numerador, denominador);
}
