#include <iostream>
#include <cmath>
using namespace std;
float mult(float num1, float num2);
float alCuadrado(float numeroElevar);
int funPot(int base, int exponente);
float parteFraccionaria(float numeroFraccionar);
void despliegue(float valorDesplegar);
void intercambiarVariables(float &numero1, float &numero2);
float cambio(float pesos);
void calcularHora(float segundos);

int main(int argc, char const *argv[])
{
    float numero1 = 5;
    float numero2 = 6;
    calcularHora(7450);
    despliegue(mult(5, 6));
    despliegue(alCuadrado(5));
    despliegue(funPot(4, 3));
    despliegue(parteFraccionaria(528.256));
    intercambiarVariables(numero1,numero2);
    despliegue(cambio(45000));
    calcularHora(3800);
    return 0;
}

float mult(float num1, float num2)
{
    return num1 * num2;
}
float alCuadrado(float numeroElevar)
{
    return pow(numeroElevar, 2);
}
int funPot(int base, int exponente)
{
    return pow(base, exponente);
}
float parteFraccionaria(float numeroFraccionar)
{
    int numeroEntero = numeroFraccionar;
    // Se retorna la diferencia entre el enterio y el fraccionario que va a ser los decimales
    return numeroFraccionar - numeroEntero;
}

void despliegue(float valorDesplegar)
{
    cout << "El valor a desplegar es: " << valorDesplegar << endl;
}

// Se pasa por referencia para poder intercambiar el valor de las variables en memoria
void intercambiarVariables(float &numero1, float &numero2)
{
    float aux = 0;
    aux = numero1;
    numero1 = numero2;
    numero2 = aux;
}
float cambio(float pesos)
{
    float valorDolar = 450;

    return pesos * valorDolar;
}

void calcularHora(float segundos)
{
    // 3600 es una hora en segundos
    int hora = segundos / 3600;
    // 60 son una hora en minutos
    int minutos = (segundos - hora * 3600) / 60;
    // 60 son 1 minuto en segundos
    int segundosRestante = segundos - hora * 3600 - minutos * 60;
    cout << "La hora es " << hora << "h " << minutos << "m ";
}

// Enunciado 9 lo realizo en esta funcion intercambiarVariables(float &numero1, float &numero2)