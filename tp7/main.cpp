#include <iostream>
using namespace std;
/* Ej 1 */
float centimetrosPulgadas();
float celciusFar();
float librasToKg();
void menuEjercicioUno();
/* Ej 1 */
/* Ej2 */
float calcularAumento();
/* Ej2 */
/* EJ3 */
enum Productos
{
    simple = 1,
    medio,
    calidad,
    premiun
};
enum Envios
{
    normal = 1,
    express,
    fastDelivery

};
Productos elegirProducto();
Envios elegirEnvio();
void realizarPedido();
void mostrarSeleccion(Productos productoElegido, Envios envioElegido);

/* EJ3 */
int main(int argc, char const *argv[])
{
    realizarPedido();
    return 0;
}

/* Hacer un programa en C++ que convierta centímetros a pulgadas
Celsius a Farenheit y libras a kilogramos */
float centimetrosPulgadas()
{
    float centimetros = 0;
    cout << "Ingrese los centimetros a convertir en pulgadas:" << endl;
    cin >> centimetros;
    return centimetros / 2.54;
}
float celciusFar()
{
    float celcius = 0;
    cout << " Ingrese los grados celcius a convertir:" << endl;
    cin >> celcius;
    return (celcius * (9 / 5)) + 32;
}
float librasToKg()
{
    float libreas;
    cout << "Ingrese las libras para transformar a KG:" << endl;
    cin >> libreas;
    return libreas / 2.205;
}
void menuEjercicioUno()
{
    int opcion = 0;
    cout << "1 Para centimetros a Pulgadas" << endl;
    cout << "2 Para Celcius a farnheit" << endl;
    cout << "3 Para Libras to KG" << endl;
    cin >> opcion;
    switch (opcion)
    {
    case 1:
        cout << "Su resultado es: " << centimetrosPulgadas();
        break;
    case 2:
        cout << "Su resultado es: " << celciusFar();
        break;
    case 3:
        cout << "Su resultado es: " << librasToKg();
        break;

    default:
        cout << "Se ingreso una opcion incorrecta reinicie el programa" << endl;
        break;
    }
}
/* Hacer un programa en C++ que convierta centímetros a pulgadas
Celsius a Farenheit y libras a kilogramos */

/* Ej 2 */
float calcularAumento()
{
    float salario = 0;
    cout << " Ingrese su salario para calcular el aumento:" << endl;
    cin >> salario;
    if (salario < 9000)
    {
        salario = salario + ((salario * 20) / 100);
    }
    else if (salario >= 9000 && salario < 15000)
    {
        salario = salario + ((salario * 10) / 100);
    }
    else if (salario >= 15000 && salario < 20000)
    {
        salario = salario + ((salario * 5) / 100);
    }
    else if (salario >= 20000)
    {
        salario = salario + ((salario * 3) / 100);
    }

    return salario;
}

/* Ej 2 */
/* E3 */
Productos elegirProducto()
{
    Productos producto;
    int opcion = 0;
    cout << "1. Simple" << endl;
    cout << "2. medio" << endl;
    cout << "3. calidad" << endl;
    cout << "4. premiun" << endl;
    cin >> opcion;
    switch (opcion)
    {
    case 1:
        producto = simple;
        break;
    case 2:
        producto = medio;
        break;
    case 3:
        producto = calidad;
        break;
    case 4:
        producto = premiun;
        break;

    default:
        break;
    }
    return producto;
}

Envios elegirEnvio()
{
    Envios envio;
    int opcion = 0;
    cout << "1 Normal" << endl;
    cout << "2 express" << endl;
    cout << "3 fastDelivery" << endl;
    cin >> opcion;
    switch (opcion)
    {
    case 1:
        envio = normal;
        break;
    case 2:
        envio = express;
        break;
    case 3:
        envio = fastDelivery;
        break;

    default:
        break;
    }
    return envio;
}
void realizarPedido()
{
    Productos productoElegido;
    Envios envioElegido;
    cout
        << "Bienvendio app pedidosd\nIngrese su pedido: " << endl;
    productoElegido = elegirProducto();
    cout
        << "Ingrese su tipo de envio: " << endl;
    envioElegido = elegirEnvio();
    mostrarSeleccion(productoElegido, envioElegido);
}
void mostrarSeleccion(Productos productoElegido, Envios envioElegido)
{
    string mensaje = "";
    switch (productoElegido)
    {
    case 1:
        mensaje = "Eligio simple con envio: ";
        break;
    case 2:
        mensaje = "Eligio medio con envio: ";
        break;
    case 3:
        mensaje = "Eligio calidad con envio: ";
        break;
    case 4:
        mensaje = "Eligio premiun con envio: ";
        break;
    }
    switch (envioElegido)
    {
    case 1:
        mensaje += "Normal";
        break;
    case 2:
        mensaje += "express";
        break;
    case 3:
        mensaje += "fastDelivery";
        break;

    default:
        break;
    }

    cout << mensaje << endl;
}
/* E3 */