
class Fraccion {
public:
	Fraccion(float numerador, float denominador);
	Fraccion();
	~Fraccion();
	
	float getNumerador();
	float getDenominador();

	void setNumerador(float numerador);
	void setDenominador(float denominador);

	Fraccion obtenerFraccion();
	Fraccion multiplicarFraccion(Fraccion fraccion);

private:
	float numerador;
	float denominador;

};
