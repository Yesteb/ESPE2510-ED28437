#include "Fraccion.h"
#include <iostream>

using std::cout;
using std::cin;
using std::endl;

int main(){
	Fraccion fraccion1, fraccion2, resultado;

	fraccion1 = fraccion1.obtenerFraccion();
	fraccion2 = fraccion2.obtenerFraccion();

	resultado = fraccion1.multiplicarFraccion(fraccion2);

	cout<<"El resultado de multiplicar la fraccion: "
	<<fraccion1.getNumerador()<<"/"<<fraccion1.getDenominador()
	<<" y la fraccion: "
	<<fraccion2.getNumerador()<<"/"<<fraccion2.getDenominador()
	<<" Es:"
	<<resultado.getNumerador()<<"/"<<fraccion2.getDenominador()
	<<"=="
	<<resultado.getNumerador()/resultado.getDenominador();	



	return 0;
}
