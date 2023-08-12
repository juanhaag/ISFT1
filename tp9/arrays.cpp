#include <iostream>
#include <string>

using namespace std;

typedef struct
{
    string nombre;
    int edad;
} Persona;

const int dim = 50;

typedef struct
{
    int contador;
    Persona personas[dim];
} ListaPersonas;

int main()
{
    ListaPersonas listaPersonas;
    listaPersonas.contador = 0;
    int seguirCargando = 0;
    do
    {
        cout << "Ingrese el nombre" << endl;
        getline(cin, listaPersonas.personas[listaPersonas.contador].nombre);
        cout << "Ingrese la edad" << endl;
        cin >> listaPersonas.personas[listaPersonas.contador].edad;
        cin.ignore(); // Descartar el carácter de salto de línea en el búfer de entrada
        cout << "Desea seguir cargando (1 - 0)" << endl;
        cin >> seguirCargando;
        cin.ignore(); // Descartar el carácter de salto de línea en el búfer de entrada
        listaPersonas.contador += 1;
    } while (seguirCargando != 1);

    for (int i = 0; i < listaPersonas.contador; i++)
    {
        cout << "Nombre de la persona: " << listaPersonas.personas[i].nombre << endl;
        cout << "Edad de la persona: " << listaPersonas.personas[i].edad << endl;
    }

    return 0;
}
