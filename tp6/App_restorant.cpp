#include <iostream>
#include <string>

using namespace std;

// Prototipo de funciones
void mostrarInfo(string mesa, string mozo, string fecha, string hora, int primerPlato, int platoPrincipal, int postre);

int main()
{
    // Variables para almacenar los datos de la comanda
    string mesa, mozo, fecha, hora;
    int primerPlato, platoPrincipal, postre;

    // Solicitar los datos de la comanda al usuario
    cout << "Bienvenidos al restaurante Verona." << endl;
    cout << "-------------------------------------------------------" << endl;
    cout << "Ingrese el numero de mesa: "; cin >> mesa;
    cout << "Ingrese el nombre del mozo: "; cin >> mozo;
    cout << "Ingrese la fecha (dd/mm/aaaa): ";cin >> fecha; 
    cout << "Ingrese la hora (hh:mm): "; cin >> hora;
    cout << " " << endl;

    cout << "Primer plato." << endl;
    cout << "1) Vitel tone"<< endl; 
    cout << "2) Sopa" << endl;
    cout << "3) Empanadas de carne cortada a cuchillo: "<< endl;
    cout << "4) Igresar el numero correspondiente al primer plato: "; cin >> primerPlato;
    cout << " " << endl;

    cout << "Plato principal."<< endl;
    cout << "1) Carne asada con papas fritas" << endl;
    cout << "2) Pollo a la plancha con ensalada" << endl;
    cout << "3) Pescado frito con pure de papas" << endl;
    cout << "Ingrese el numero correspondiente al plato principal: "; cin >> platoPrincipal;
    cout << " " << endl;

    cout << "Postres." << endl;
    cout << "1) Flan casero" << endl;
    cout << "2) Bochas de helado" << endl;
    cout << "3) Mousse de chocolate" << endl;
    cout << "Ingrese el numero correspondiente al postre: "; cin >> postre;
    cout << " " << endl;
    
    // Mostrar la información de la comanda
    mostrarInfo(mesa, mozo, fecha, hora, primerPlato, platoPrincipal, postre);

    return 0;
}

// Implementación de funciones
void mostrarInfo(string mesa, string mozo, string fecha, string hora, int primerPlato, int platoPrincipal, int postre) {
    // Mostrar los datos de la comanda
    cout << "-------------------------------------------------------" << endl;
    cout << "Su pedido ah sido realizado con exito." << endl;
    cout << "-------------------------------------------------------" << endl,
    cout << "Numero de mesa: " << mesa << endl;
    cout << "Nombre del mozo: " << mozo << endl;
    cout << "Fecha: " << fecha << endl;
    cout << "Hora: " << hora << endl;

    // Mostrar los platos seleccionados
    cout << "Primer plato: ";
    switch (primerPlato) {
        case 1:
            cout << "Vitel tone" << endl;
            break;
        case 2:
            cout << "Sopa" << endl;
            break;
        case 3:
            cout << "Empanadas" << endl;
            break;
        default:
            cout << "Opción inválida" << endl;
            break;
    }

    cout << "Plato principal: ";
    switch (platoPrincipal) {
        case 1:
            cout << "Carne asada con guarnicion" << endl;
            break;
        case 2:
            cout << "Pollo a la plancha con guarnicion" << endl;
            break;
        case 3:
            cout << "Pescado frito con guarnicion" << endl;
            break;
        default:
            cout << "Opción inválida" << endl;
            break;
    }

    cout << "Postre: ";
    switch (postre) {
        case 1:
            cout << "Flan" << endl;
            break;
        case 2:
            cout << "Helado" << endl;
            break;
        case 3:
            cout << "Mousse de chocolate" << endl;
            break;
        default:
            cout << "Opción inválida" << endl;
            break;
    }
}
