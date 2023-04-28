#include <iostream>
#include <cmath>
using namespace std;

void leerMostrar();
double promedioNotas();
void resolverEcuacion();
void lineal();
float calcularVolumen(string forma);
double convertirCelcius();
void sumaRestaMultiDivi();
bool seEncuentraRango();

int main(int argc, char const *argv[])
{
    leerMostrar();
    promedioNotas();
    void sumaRestaMultiDivi();
    double convertirCelcius();
    bool seEncuentraRango();
    cout << "La nota final de los estudiantes es: " << promedioNotas() << endl;
    cout << "El volumen de la forma seleccionada es: " << calcularVolumen("cuadrado") << endl;
    resolverEcuacion();
    lineal();
    return 0;
}

double convertirCelcius()
{
    double gradosF = 0;
    double gradosC = 0;
    cout << "Ingrese grados Fahrenheit" << endl;
    cin >> gradosF;
    gradosC = ((gradosF - 32) * (5. / 9));
    cout << "La conversion a Grados celcius da como resultado C " << gradosC << endl;
    return gradosC;
}
void sumaRestaMultiDivi()
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
bool seEncuentraRango()
{
    bool encontrado;
    int rangoA, rangoB, numero;
    cout << "Ingrese el rango A:" << endl;
    cin >> rangoA;
    cout << "Ingrese el rango B" << endl;
    cin >> rangoB;
    cout << ">>Ingrese un numero para saber si se encuentra en el rango" << endl;
    cin >> numero;
    if (rangoA < numero && rangoB > numero)
    {
        encontrado = 1;
    }

    return encontrado;
}

void leerMostrar()
{
    int edad = 0;
    char sexo = 'b';
    float altura = 0;
    cout << "Ingrese edad: " << endl;
    cin >> edad;
    cout << "Ingrese Sexo M-F: " << endl;
    cin >> sexo;
    cout << "Ingrese Altura: " << endl;
    cin >> altura;
    cout << "La edad, altura y sexo es la siguiente:" << edad << " " << sexo << " "
         << " " << altura;
}

double promedioNotas()
{
    float notaLaboratior, notaTeorica, notaPractica, resultado;
    cout << "Ingrese notaLaboratorio: " << endl;
    cin >> notaLaboratior;
    cout << "Ingrese nota Teorica: " << endl;
    cin >> notaTeorica;
    cout << "Ingrese notaPractica: " << endl;
    cin >> notaPractica;
    notaLaboratior = (notaLaboratior * 30) / 100;
    notaTeorica = (notaTeorica * 0.60);
    notaPractica = (notaPractica * 0.1);
    resultado = notaLaboratior + notaPractica + notaTeorica;
    return resultado;
}

float calcularVolumen(string forma)
{
    float volumen;

    if (forma == "cuadrado")
    {
        float ladoCuadrado = 0;
        cout << "Ingrese la longitud del lado del cuadrado:" << endl;
        cin >> ladoCuadrado;
        volumen = 4 * ladoCuadrado;
    }
    else if (forma == "rectangulo")
    {
        float longitud, ancho;
        cout << "Ingrese la longitud rectangulo:" << endl;
        cin >> longitud;
        cout << "Ingrese el ancho rectangulo:" << endl;
        cin >> ancho;
        volumen = (2 * longitud) + (2 * ancho);
    }
    else if (forma == "triangulo")
    {
        float a, b, c;
        cout << "Ingrese la longitud del triangulo" << endl;
        cin >> a;
        cin >> b;
        cin >> c;
        volumen = a + b + c;
    }
    // Se retorna el valor ya que el enunciado no dice que se muestre por pantalla;
    return volumen;
}
void resolverEcuacion()
{
    float y, m, x;
    float resultado = 0;
    cout << "Ingrese el valor de y: ";
    cin >> y;
    cout << endl
         << "Ingrese el valor de m: ";
    cin >> m;
    cout << endl
         << "Ingrese el valor de x: " << endl;
    cin >> x;
    resultado = ((pow(y, 2)) - (pow(y, 1))) / ((pow(x, 2)) - (pow(x, 1)));
    cout << "El Resultado de la ecucacion es:" << resultado << endl;
}

void lineal()
{
    int x;
    cout << "para la funcion lineal Y=2X+1 ingrese el valor de X: " << endl;
    for (int contador = 0; contador < 4; contador++)
    {
        cout << "valor de x: ";
        cin >> x;
        cout << endl
             << "el valor de Y para X=" << x << " es = " << (2 * x + 1) << endl;
    }
    cin.ignore();
    cin.get();
}

#include <iostream>

using namespace std;

bool esPrimo(int num) {
    if (num <= 1) {  
        return false;
    }

    // iteramos desde 2 hasta num-1
    for (int i = 2; i < num; i++) {
        if (num % i == 0) {  
            return false;
        }
    }

    return true;  
}

