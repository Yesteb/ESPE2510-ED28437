/***********************************************************************
 * Module:  Fraccion.h
 * Author:  esteb
 * Modified: Monday, October 6, 2025 7:47:09 PM
 * Purpose: Declaration of the class Fraccion
 ***********************************************************************/

#if !defined(__Class_Diagram_1_Fraccion_h)
#define __Class_Diagram_1_Fraccion_h

#include <ostream>


class Fraccion
{
public:
	Fraccion(float, float);
	Fraccion();
	~Fraccion();

	friend std::ostream& operator<<(std::ostream& os, const Fraccion& f) {
		os << f.numerador << "/" << f.denominador;
		return os;
	}

	float getNumerador(void);
	void setNumerador(float newNumerador);
	float getDenominador(void);
	void setDenominador(float newDenominador);
	Fraccion multiplicarFraccion(Fraccion);
	Fraccion obtenerFraccion();
protected:
private:
	float numerador = 0.0f;
	float denominador = 0.0f;
};

#endif
