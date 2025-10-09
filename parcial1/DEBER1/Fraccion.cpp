#include "Fraccion.h"
#include <iostream>

using std::cout;
using std::cin;
using std::endl;

Fraccion::Fraccion(float numerador, float denominador){
	this->numerador = numerador;
	this->denominador = denominador;
}
Fraccion::Fraccion(){
	numerador = 0.0f;
	denominador = 1.0f;
}
Fraccion::~Fraccion(){}

float Fraccion::getNumerador(){
	return numerador;
}
float Fraccion::getDenominador(){
	return denominador;
}

void Fraccion::setNumerador(float numerador){
	this->numerador = numerador;
}
void Fraccion::setDenominador(float denominador){
	this->denominador = denominador;
}

Fraccion Fraccion::obtenerFraccion(){
	float numerador, denominador;

	do{
	cout<<"Ingrese el numerador (no ingrese letras o caracteres especiales: "; cin>>numerador;
	cout<<"Ingrese el denominador (no ingrese letras, caracteres especiales y el cero): "; cin>>denominador;
	cout<<"\n";
	if(cin.fail()||denominador==0){
		cin.clear();
		cin.ignore(10000,'\n');
	cout<<"\n";
	cout<<"\nSe debe ingresar solamente numeros enteros o flotantes, intente de nuevo"<<endl;

	system("pause");

	} else{
	break;
	}
	
	} while(true);

	return Fraccion(numerador,denominador);
}
Fraccion Fraccion::multiplicarFraccion(Fraccion fraccion){
	return Fraccion(numerador * fraccion.getNumerador(), denominador * fraccion.getDenominador());
}

