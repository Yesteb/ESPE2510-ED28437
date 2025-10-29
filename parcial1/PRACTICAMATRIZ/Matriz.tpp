#pragma once
#include "Matriz.h"

template <typename T>
Matriz<T>::Matriz(){}

template <typename T>
Matriz<T>::~Matriz(){}

template <typename T>
T*** Matriz<T>::crearMatriz(T*** matriz, int m, int n ,int e){
	matriz = new T**[m];

	for(int i = 0; i < m; i++){
		*(matriz + i) = new T*[n];
		for(int j = 0; j < n; j++){
			*(*(matriz + i) + j) = new T[e];
		}

	}
	return matriz;
}

template <typename T>
void Matriz<T>::encerarMatriz(T*** matriz, int m, int n, int e){
	for(int i = 0; i < m; i++){
		for(int j = 0; j < n; j++){
			for(int k = 0; k < e; k++){
				*(*(*(matriz + i) + j) + k) = 0;

			}
		}

	}

}

template <typename T>
void Matriz<T>::rellenarMatriz(T*** matriz, int m, int n ,int e){
	for(int i = 0; i < m; i++){
		for(int j = 0; j < n; j++){
			for(int k = 0; k < e; k++){
				*(*(*(matriz + i) + j) + k) = i + j;

			}
		}

	}

}

template <typename T>
void Matriz<T>::mostrarMatriz(T*** matriz, int m , int n, int e){
	for(int i = 0; i < m; i++){
		std::cout << "Caras i .- " << i << "\n";
		for(int j = 0; j < n; j++){
			for(int k = 0; k < e; k++){
			std::cout << *(*(*(matriz + i) + j) + k) << " ";
			}
			std::cout << "\n";
		}
	std::cout << "\n";
		
	}
}

template <typename T>
void Matriz<T>::limpiarMatriz(T*** matriz, int m, int n){
	for(int i = 0; i < m; i++){
		for(int j = 0; j < n; j++){
			delete[] *(*(matriz + i) + j);
		}
		delete[] *(matriz + i);
	}
	delete[] matriz;
	



}

template <typename T>
T Matriz<T>::sumarDiagonal(T*** matriz, int m ,int n, int e){
	std::function<T(int)> sumar = [&](int i) -> T{
		if( i >= m || i >= n || i>= e) return T{};

		return *(*(*(matriz + i) + i) + i) + sumar(i + 1);
	};

	return sumar(0);

}

template <typename T>
T Matriz<T>::sumarElementos(T*** matriz, int m, int n, int e){
	std::function<T(int, int ,int)> sumar = [&](int i, int j, int k) -> T{
	if(i >= m) return T{};
	if(j >= n) return sumar(i + 1, 0, 0);
	if(k >= e) return sumar(i, j + 1, 0);

	return *(*(*(matriz + i) + j) + k) + sumar(i, j, k + 1); 
	};
	return sumar(0, 0, 0);
}

template <typename T>
void Matriz<T>::transponerMatriz(T*** matriz, T*** matrizTranspuesta, int m, int n, int e){

	std::function<void(int, int, int)> transponer = [&](int i, int j, int k){
		if ( i < 0) return;
		if ( j < 0) {
			transponer(i - 1, n - 1, e - 1);
			return;
		}
		if(k < 0){
			transponer(i, j - 1, e - 1);
			return;

		}
		*(*(*(matrizTranspuesta + j) + i) + k) = *(*(*(matriz + i) + j) + k);
		transponer(i, j, k - 1); 
	

	};

	transponer(m - 1, n - 1, e - 1);

}
