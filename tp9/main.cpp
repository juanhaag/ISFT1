#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;
void ingresarFrases(string nombreArchivo);
void leerArchivo(string nombreArchivo);
int cantidadPalabras(string linea);
void calcularPromedioLineas(string nombreArchivo);
float calcularPromedio(int numeroPalabrasTotales, int cantidadLineas);

int main(int argc, char const *argv[])
{
    // ingresarFrases("frasesDeBjarme.txt");
    // leerArchivo("frasesDeBjarme.txt");
    calcularPromedioLineas("frasesDeBjarme.txt");

    return 0;
}

void ingresarFrases(string nombreArchivo)
{
    ofstream archivo(nombreArchivo, ios::app);

    if (archivo.is_open())
    {
        string frase;
        while (frase != "fin")
        {
            cout << "Ingrese una frase: " << endl;
            getline(cin, frase);
            if (frase != "fin")
            {
                archivo << frase << endl;
            }
        }
        archivo.close();
    }
}

void leerArchivo(string nombreArchivo)
{
    ifstream archivo(nombreArchivo);
    if (archivo.is_open())
    {
        string frase;
        while (getline(archivo, frase))
        {
            cout << "---------------------------------------" << endl;
            cout << frase << endl;
            cout << "---------------------------------------" << endl;
        }
        archivo.close();
    }
}

void calcularPromedioLineas(string nombreArchivo)
{
    ifstream archivo(nombreArchivo);
    if (archivo.is_open())
    {
        string frase;
        int cantidadLineas = 0;
        vector<int> cantidadPalabrasPorLinea;
        while (getline(archivo, frase))
        {
            cantidadLineas++;
            cantidadPalabrasPorLinea.push_back(cantidadPalabras(frase) + 1);
        }
        for (int i = 0; i < cantidadPalabrasPorLinea.size(); i++)
        {
            cout << "Cantidad de palabras en esta linea: " << cantidadPalabrasPorLinea[i] << " Promedio en esta linea " << calcularPromedio(cantidadPalabrasPorLinea[i], cantidadPalabrasPorLinea.size()) << endl;
        }
        archivo.close();
    }
}
int cantidadPalabras(string linea)
{
    int cantidadPalabras = 0;
    for (int i = 0; i < linea.length(); i++)
    {
        if (linea[i] == ' ')
        {
            cantidadPalabras++;
        }
    }
    return cantidadPalabras;
}
float calcularPromedio(int numeroPalabrasTotales, int cantidadLineas)
{
      if (cantidadLineas == 0) {
        return 0.0f;  
    }

    return static_cast<float>(numeroPalabrasTotales) / cantidadLineas;
}