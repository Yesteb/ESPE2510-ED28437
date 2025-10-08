#pragma once
class Fraccion
{
public:
	Fraccion(float numerador, float denominador);
	Fraccion();
	~Fraccion();

	float getNumerador();
	float getDenominador();

	void setNumerador(float numerador);
	void setDenominador(float denominador);

	Fraccion multiplicarFraccion(Fraccion fraccion);
	static Fraccion obtenerFraccion();

private:
	float numerador;
	float denominador;


};

