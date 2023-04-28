#include <iostream>
using namespace std;

void calcularEdad(int anioActua, int mesActual);
void promedio();
void calcularProducto();
void calcularVolumen();
void convertirCelcius();
void convertirSegundos(int segundos);

int main(int argc, char const * argv[])
{
    calcularEdad(2023, 4);
    promedio();
    calcularProducto();
    convertirCelcius();
    convertirSegundos(120000);

    return 0;
}

void calcularEdad(int anioActual, int mesActual)
{
    // Se puede realizar con librerias de tiempo para lograr mayor exactitud
    int dia, mes, anio;
    int edad = 0;
    cout << "Ingrese dia de nacimiento" << endl;
    cin >> dia;
    cout << "Ingrese mes de nacimiento" << endl;
    cin >> mes;
    cout << "Ingrese anio de nacimiento" << endl;
    cin >> anio;
    if (mes > mesActual)
    {
        cout << "Tu edad es: " << (anioActual - anio) - 1 << endl;
    }
    else
    {
        cout << "Tu edad es: " << anioActual - anio << endl;
    }
}

void promedio()
{
    double resultado = 0;
    for (int contador = 0; contador < 3; contador++)
    {
        double numero;
        cout << "Ingrese un numero para calcular el promedio" << endl;
        cin >> numero;
        resultado += numero;
    }
    cout << "El promedio es" << resultado / 3 << endl;
}

void calcularProducto()
{
    int flag = 0;
    while (flag != 1)
    {
        float numero = 0;
        cout << "Ingrese un numero para saber su producto" << endl;
        cin >> numero;
        cout << "El producto del numero ingresado es:" << numero * numero << endl;
        cout << "Desea seguir consultando productos? si=0 no=1" << endl;
        cin >> flag;
    }
}
void calcularVolumen()
{
    const double PI = 3.14;
    double radio = 14.5;
    double altura = 26.79;
    double volumen = (PI * (((radio) * (radio)) / altura)) / 3;
    cout << "volumen de un cono con"
         << "un radio de la base de 14,5 y una altura de 26,79, es: "
         << volumen << endl;
}

void convertirCelcius()
{
    double gradosF = 0;
    double gradosC = 0;
    cout << "Ingrese grados Fahrenheit" << endl;
    cin >> gradosF;
    gradosC = ((gradosF - 32) * (5. / 9));
    cout << "La conversion a Grados celcius da como resultado C " << gradosC << endl;
}

void convertirSegundos(int segundos)
{
    int horas, minutos, resto;

    horas = segundos / 3600;
    resto = segundos % 3600;

    minutos = resto / 60;
    segundos = resto % 60;

    cout << "Equivalente a: " << horas << "h " << minutos << "m " << segundos << "s" << endl;
}