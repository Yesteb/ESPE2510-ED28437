#include "Fraccion.h"
#include <iostream>
#include <stdlib.h>
using std::cout;
using std::endl;
using std::cin;

int main() {
	Fraccion fraccion1;
	Fraccion fraccion2;
	Fraccion resultado;

	cout << "Bienvenido!!" << endl;
	cout << "Ingrese la primera fraccion: " << endl;
	fraccion1 = Fraccion::obtenerFraccion();
	cout << "\nIngrese la segunda fraccion: " << endl;
	fraccion2 = Fraccion::obtenerFraccion();

	resultado = fraccion1.multiplicarFraccion(fraccion2);
	cout << "\nEl resultado de la multiplicacion de la fraccion: "
		<< fraccion1.getNumerador()
		<< "/"
		<< fraccion1.getDenominador()
		<< " y la fraccion: "
		<< fraccion2.getNumerador()
		<< "/"
		<< fraccion2.getDenominador()
		<< "\nEs: " << resultado.getNumerador() << "/" << resultado.getDenominador();
	
	cout<<"\n";

	system("pause");

	return 0;
}
