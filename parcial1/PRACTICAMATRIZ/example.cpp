  GNU nano 8.3                                                     Test.cpp
#include "../ext/googletest/googletest/include/gtest/gtest.h"
#include "../src/Matriz.h"

TEST (MatrizTest, CrearEncerar)
{
        Matriz<int> control;
        int m = 2, n = 2, e = 2;

        int*** matriz = nullptr;

        matriz = control.crearMatriz(matriz, m, n, e);
        control.encerarMatriz(matriz, m, n, e);

        bool estaInicializada = true;
        for(int i = 0; i < m; i++){
                for(int j = 0; j < n; j++){
                        for(int k = 0; k < e; k++){
                                if(*(*(*(matriz + i) + j) + k) != 0){
                                        estaInicializada = false;
                                };
                        }
                }
        }

        EXPECT_TRUE(estaInicializada);

        control.limpiarMatriz(matriz, m, n);


}

TEST (MatrizTest, limpiarMatriz){
        Matriz<int> control;
        int*** matriz = nullptr;
        matriz = control.crearMatriz(matriz, 1, 1, 1);
        *(*(*(matriz + 0) + 0) + 0) = 42;
        EXPECT_EQ(*(*(*(matriz + 0) + 0) + 0), 42);
        EXPECT_NO_THROW(control.limpiarMatriz(matriz, 1, 1));

}
