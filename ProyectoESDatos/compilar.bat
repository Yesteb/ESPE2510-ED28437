@echo off

echo Compilando...

g++ -std=c++17 ^
    .\Main.cpp ^
    .\src\modelo\FechaHora.cpp ^
    .\src\modelo\Usuario.cpp ^
    .\src\modelo\Asiento.cpp ^
    .\src\controlador\Ordenamiento.cpp ^
    .\src\vista\VistaReservarAsiento.cpp ^
    .\src\controlador\ListaCircular.cpp ^
    .\includes\Include.cpp ^
    .\includes\Validacion.cpp ^
    -o Main.exe

echo Listo.
pause