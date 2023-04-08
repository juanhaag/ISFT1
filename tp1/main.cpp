/* 1. Resolver y Realizar en c++
a. La suma de 45 + 34 mostrar x pantalla el resultado
b. La resta de 45 -40 mostrar le resultado x pantalla
c. La división de 46 y 3
d. Un programa que multiplique 65 * 3 con la salida en pantalla
2. Resolver usando Variables y operadores, mostrar el resultado x pantalla.
a. Calcula el volumen, de una habitación que tiene 5 m de largo, 4 m de ancho y
2.5 m de alto.
b. Escribe un programa en C++ que nos diga cuál es el volumen de un cono con
un radio de la base de 14,5 y una altura de 26,79. La fórmula que debes usar
es: (Pi x (radio)2 / altura) /3, recordar Pi=3.14.
c. ¿Modificar el programa anterior para que usen variables Dobles, que
diferencia nota? ¿Por qué? */

#include <iostream>
using namespace std;
void ejercicioUno();
void ejercicioDos();
int main()
{
    ejercicioUno();
    ejercicioDos();
    return 0;
}

void ejercicioUno()
{
    int resultadoSumaHardcodeada = 45 + 34;
    int resultadoRestaHardcodeada = 45 - 40;
    double resultadoDivisionHardcodeada = 46 / 3;
    double resultadoMultiHardcodeada = 65 * 3;
    cout << "----------------EJERCICIO 1------------------------------" << endl;
    cout << "El resultado de la suma es: " << resultadoSumaHardcodeada << endl;
    cout << "El resultado de la resta es: " << resultadoRestaHardcodeada << endl;
    cout << "El resultado de la division es: " << resultadoDivisionHardcodeada << endl;
    cout << "El resultado de la division es: " << resultadoMultiHardcodeada << endl;
    cout << "----------------EJERCICIO 1------------------------------" << endl;
}

void ejercicioDos()
{
    const double PI = 3.14;
    double radio =14.5;
    double altura =26.79;
    double volumen = (PI * (((radio) * (radio)) / altura)) / 3;
    cout << "----------------EJERCICIO 2------------------------------" << endl;
    cout << "volumen de un cono con"
         << "un radio de la base de 14,5 y una altura de 26,79, es: "
         << volumen << endl;
    cout << "----------------EJERCICIO 2------------------------------" << endl;
}