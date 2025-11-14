@echo off

echo Compilado...

g++ -std=c++17 ^
    .\src\main.cpp ^
    .\src\Fecha.cpp ^
    .\src\Controlador.cpp ^
    .\src\CalendarioLaboral.cpp ^
    .\src\VistaConsola.cpp ^

echo listo

pause