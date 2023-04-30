#include <iostream>

using namespace std;
// Vacio no va a tener ningun valor, va a ser para inicialziar los enum
// Las diferentes opciones van a tomar valores diferentes en cada switch para poder simular
// Revisar porque no esta bien
enum Plato
{
    Vacio,
    Entrada,
    PlatoPrincipal,
    Postre
};

void comanda();
int main(int argc, char const *argv[])
{
    comanda();
    return 0;
}
// Funciona pero no me gusta como esta definida la funcion
// se podria modularizar la misma
void comanda()
{
    Plato primerPlato = Vacio;
    Plato platoPrincipal = Vacio;
    Plato postre = Vacio;
    int numeroMesa = 0;
    string mozo;
    string fecha;
    string comandaFinal;
    int opcion = 0;
    cout << "Ingrese la fecha: " << endl;
    cin >> fecha;
    cout << "Ingrese el nombre del mozo:" << endl;
    cin >> mozo;
    // En esta seccion de switch se establece el valor numero con el uso de switch
    cout << "primerPlato 1 Empanadas 2 ensalada" << endl;
    cin >> opcion;
    switch (opcion)
    {
        // Lo que se le asinga en cada caso son la posicion de cada Enumo
        // Entrada seria el valor 1
    case 1:
        primerPlato = Entrada;
        break;

    case 2:
        primerPlato = PlatoPrincipal;
        break;
    }

    cout << "platoPrincipal 1 carne 2 pollo" << endl;
    cin >> opcion;

    switch (opcion)
    {
    case 1:
        platoPrincipal = Entrada;
        break;

    case 2:
        platoPrincipal = PlatoPrincipal;
        break;
    }

    // Se asingan valor a los switch ya que los enum toman valores enteros
    switch (primerPlato)
    {
    case Entrada:
        comandaFinal = "Primer plato: empanadas";
        break;

    case PlatoPrincipal:
        comandaFinal = "Primer plato: ensalada";
        break;
    }
    switch (platoPrincipal)
    {
    case Entrada:
        comandaFinal += " Plato Principal: carne";
        break;

    case PlatoPrincipal:
        comandaFinal += " Plato Principal: pollo";
        break;
    }
    cout << comandaFinal << "\nMozo: " << mozo << " Fecha: " << fecha << endl;
}
