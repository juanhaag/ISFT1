#include <iostream>
using namespace std;

float descuentoBazar();
int calcularSalario();
bool calcularSiAprueba();
int calcularSumaNumerosImparesYpares();
void mostrarCondicional();
int calcularSuma();
int sumaPositivos();

int main(int argc, char const *argv[])
{

    cout << descuentoBazar();
    //No se llamaron las funciones para tener un mayor orden en el main sin tener que hacer un menu
    return 0;
}

float descuentoBazar()
{
    float totalConDescuento = 0;
    int precioProducto = 80;
    int cantidadProcuctos = 0;

    cout << "Ingrese cantidad de productos que desea llevar:" << endl;
    cin >> cantidadProcuctos;

    if (cantidadProcuctos >= 10)
    {
        totalConDescuento = (precioProducto * cantidadProcuctos) - (((precioProducto * cantidadProcuctos) * 12) / 100);
    }
    else if (cantidadProcuctos >= 20 && cantidadProcuctos < 30)
    {
        totalConDescuento = (precioProducto * cantidadProcuctos) - (((precioProducto * cantidadProcuctos) * 25) / 100);
    }
    else if (cantidadProcuctos >= 30)
    {
        totalConDescuento = (precioProducto * cantidadProcuctos) - (((precioProducto * cantidadProcuctos) * 40) / 100);
    }
    return totalConDescuento;
}

int calcularSalario()
{
    int horasTrabajadas = 0;
    int totalACobrar = 0;

    cout << "Cuantas horas trabajo?:" << endl;
    cin >> horasTrabajadas;

    if (horasTrabajadas <= 40)
    {
        totalACobrar = horasTrabajadas * 200;
    }
    else if (horasTrabajadas > 40)
    {
        totalACobrar = horasTrabajadas * 250;
    }
    return totalACobrar;
}

bool calcularSiAprueba()
{
    const int NUM_NOTAS = 3;
    const int NOTA_MINIMA_APROBACION = 7;
    float sumaNotas = 0.0;
    float nota = 0.0;
    for (int i = 0; i < NUM_NOTAS; i++)
    {
        cout << "Ingrese nota: ";
        cin >> nota;
        sumaNotas += nota;
    }
    return sumaNotas / NUM_NOTAS >= NOTA_MINIMA_APROBACION;
}

int calcularSuma()
{
    int numero = 0;
    int numeros = 0;
    int contador = 0;
    while (numero != 99)
    {
        cout << "Ingrese un numero diferente a 99 para calcular su suma:" << endl;
        cin >> numero;
        numeros += numero;
        contador++;
    }
    return numeros / contador;
}

int calcularSumaNumerosImparesYpares()
{
    int suma = 0;
    int numeroCorte = 0;
    for (int i = 0; i <= numeroCorte; i++)
    {
        suma += i;
    }
    return suma;
}

void mostrarCondicional()
{
    int numero1 = 0;
    int numero2 = 0;
    cout << "Ingrese el numero 1:" << endl;
    cin >> numero1;
    cout << "Ingrese el numero 2:" << endl;
    cin >> numero2;
    while (numero1 < numero2)
    {
        cout << "Ingrese el numero 2 que sea mayor al numero 1" << endl;
        cin >> numero2;
    }
    cout << "Los dos numeros son" << numero1 << " " << numero2 << endl;
}

int sumaPositivos()
{
    int suma = 0;
    int numero = 0;
    int numeros = 0;
    while (numero >= 0)
    {
        cout << "Ingrese numeros positvos para sumar" << endl;
        cin >> numero;
        numeros += numero;
    }

    return suma;
}