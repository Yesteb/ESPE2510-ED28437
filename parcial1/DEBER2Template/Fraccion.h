#pragma once
template <typename T>
class Fraccion {
private:
	T numerador;
	T denominador;

public:

	Fraccion(T numerador, T denominador);
	Fraccion();
	~Fraccion();

	T getNumerador();
	T getDenominador();

	void setNumerador(T numerador);
	void setDenominador(T denominador);

	static Fraccion obtenerFraccion();
	Fraccion<T> multiplicarFraccion(Fraccion<T> fraccion);
};

#include "Fraccion.cpp"