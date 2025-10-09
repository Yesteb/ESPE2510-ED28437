#include <iostream>

using std::cout;
using std::cin;
using std::endl;

template <typename T>
Fraccion<T>::Fraccion(T numerador, T denominador){
	this->numerador = numerador;
	this->denominador = denominador;
}

template <typename T>
Fraccion<T>::Fraccion(){
	numerador = 1.0f;
	denominador = 0.0f;
}

template <typename T>
Fraccion<T>::~Fraccion(){}

template <typename T>
T Fraccion<T>::getNumerador(){
	return numerador;
}

template <typename T>
T Fraccion<T>::getDenominador(){
	return denominador;
}

template <typename T>
void Fraccion<T>::setNumerador(T numerador){
	this->numerador = numerador;
}

template <typename T>
void Fraccion<T>::setDenominador(T denominador){
	this->denominador = denominador;
}

template <typename T>
Fraccion<T> Fraccion<T>::obtenerFraccion(){
	T numerador;
	T denominador;

	do {
		cout<<"Ingrese el numerador (No ingrese letras, vocales o caracteres especiales): "; cin>>numerador; cout<<endl;
		cout<<"Ingrese el denominador (No ingrese letras, vocales, caracteres especiales o el numero cero): "; cin>>denominador; cout<<endl;

		if(cin.fail()||denominador==0){
			cin.clear();
			cin.ignore(100000,'\n');

			cout<<"Ingrese unicamente numeros enteros o flotantes"<<endl;
			cin.get();
		} else {
			break;
		}


	} while(true);

	return Fraccion<T>(numerador, denominador);
}

template <typename T>
Fraccion<T> Fraccion<T>::multiplicarFraccion(Fraccion<T> fraccion){
	return Fraccion<T>(numerador * fraccion.getNumerador(), denominador * fraccion.getDenominador());
}
