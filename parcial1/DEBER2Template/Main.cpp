#include "Fraccion.h"
#include <iostream>

using std::cout;
using std::cin;
using std::endl;

int main (){
	Fraccion<float> fraccion1, fraccion2, resultado;

	cout<<"Ingrese la primera fraccion"<<endl;
	fraccion1 = fraccion1.obtenerFraccion();
	cout<<"Ingrese la segunda fraccion"<<endl;
	fraccion2 = fraccion2.obtenerFraccion();

	resultado = fraccion1.multiplicarFraccion(fraccion2);
	cout<<"\n";
	cout<<"El resultado de multiplicar la fraccion: "
	<<fraccion1.getNumerador()<<"/"<<fraccion1.getDenominador()
	<<" y la fraccion: "
	<<fraccion2.getNumerador()<<"/"<<fraccion2.getDenominador()
	<<" Es: "<<resultado.getNumerador()<<"/"<<resultado.getDenominador();


	cin.get();
}