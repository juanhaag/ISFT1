#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

const int Max_solicitudes = 1000;
struct solicitud
{
    string nombre;
    string apellido;
    int codigo, DNI;
};

typedef solicitud infsolicitud[Max_solicitudes];

typedef struct
{
    infsolicitud carpsolicitudes;
    int contador = 0;
} contsolicitudes;

contsolicitudes tsolicitudes;

void menu();
void Archivo(contsolicitudes &tsolicitudes);
void cargarArchivo();
void listado(contsolicitudes &tsolicitudes);
void agregarCliente(contsolicitudes &tsolicitudes);
void bajaCliente(contsolicitudes &tsolicitudes);
int buscarposicion(contsolicitudes &tsolicitudes);
void buscarCliente(contsolicitudes &tsolicitudes);
void modificarCliente(contsolicitudes &tsolicitudes);
void clearconsole();
void pauseconsole();

int main()
{

    cargarArchivo();

    menu();
    return 0;
}

void menu()
{

    int opcion = 0;

    do
    {

        cout << "   \n ~~~Biuty-Sand~~~\n";
        cout << "  \n MENU \n";
        cout << "1. agregar solicitud\n";
        cout << "2. dar de baja solicitud\n";
        cout << "3. modificar solicitud\n";
        cout << "4. buscar solicitud\n";
        cout << "5. ver listado\n";
        cout << "6. guardar y salir\n";
        cout << "ingrese una opcion: ";
        cin >> opcion;

        switch (opcion)
        {
        case 1:
            agregarCliente(tsolicitudes);
            break;
        case 2:
            bajaCliente(tsolicitudes);
            break;
        case 3:
            modificarCliente(tsolicitudes);
            break;
        case 4:
            buscarCliente(tsolicitudes);
            break;
        case 5:
            listado(tsolicitudes);
            break;
        case 6:
            cout << "saliendo del programa...";
            break;
        default:
            cout << "opcion no valida...\n";
            break;
        }

    } while (opcion != 6);

    Archivo(tsolicitudes);
}

void Archivo(contsolicitudes &tsolicitudes)
{

    ofstream archivo;
    archivo.open("solicitud.txt");

    if (archivo.is_open())
    {

        for (int i = 0; i < tsolicitudes.contador; i++)
        {

            archivo << tsolicitudes.carpsolicitudes[i].codigo << " " << tsolicitudes.carpsolicitudes[i].nombre << " " << tsolicitudes.carpsolicitudes[i].apellido << tsolicitudes.carpsolicitudes[i].DNI;
        }

        archivo.close();
    }
}

void cargarArchivo()
{

    ifstream archivo;
    tsolicitudes.contador = 0;

    archivo.open("solicitud.txt");

    if (archivo.is_open())
    {
        string linea;
        while (tsolicitudes.contador < Max_solicitudes && getline(archivo, linea))
        {
            archivo >> tsolicitudes.carpsolicitudes[tsolicitudes.contador].codigo >> tsolicitudes.carpsolicitudes[tsolicitudes.contador].nombre >> tsolicitudes.carpsolicitudes[tsolicitudes.contador].apellido >> tsolicitudes.carpsolicitudes[tsolicitudes.contador].DNI;
            tsolicitudes.contador++;
        }

        archivo.close();
    }
}

void listado(contsolicitudes &tsolicitudes)
{

    if (tsolicitudes.contador == 0)
    {
        cout << "no se encontraron solicitud.";
    }

    else
    {

        cout << "lista de solicitud\n";
        for (int i = 0; i < tsolicitudes.contador; i++)
        {

            cout << "\ncodigo" << tsolicitudes.carpsolicitudes[i].codigo;
            cout << "\nnombre" << tsolicitudes.carpsolicitudes[i].nombre;
            cout << "\napellido" << tsolicitudes.carpsolicitudes[i].apellido;
            cout << "\nDNI" << tsolicitudes.carpsolicitudes[i].DNI;
            cout << " \n \n ";
        }
    }
}

void agregarCliente(contsolicitudes &tsolicitudes)
{

    solicitud nuevoCliente;

    clearconsole();

    cout << "\n\t\t~~~Dar de alta Cliente~~~\n\n";

    if (tsolicitudes.contador >= Max_solicitudes)
    {

        cout << "no se puede agregar mas solicitud\n";
        return;
    }

    nuevoCliente.codigo = (tsolicitudes.contador + 1) + 99;

    cout << "Ingrese apellido del cliente: ";
    cin.ignore();
    getline(cin, nuevoCliente.apellido);
    cout << "Ingrese nombre del cliente: ";
    getline(cin, nuevoCliente.nombre);
    cout << "Ingrese DNI del cliente: ";
    cin >> nuevoCliente.DNI;
    cout << "El codigo de cliente es: " << nuevoCliente.codigo << endl;
    cout << "\nCliente agregado correctamente!\n";

    tsolicitudes.carpsolicitudes[tsolicitudes.contador] = nuevoCliente;
    tsolicitudes.contador++;

    cout << "\n\nPrecione ENTER para continuar";
    pauseconsole();
}

void bajaCliente(contsolicitudes &tsolicitudes)
{

    int posicion = buscarposicion(tsolicitudes);

    if (posicion != -1)
    {
        bool opcion;
        listado(tsolicitudes);

        cout << "Es el cliente que quiere dar de Baja?\n";
        cout << "Para si ingrese '1'\n";
        cout << "Para no ingrese '0'\n";
        cout << "opcion: ";
        cin >> opcion;

        if (opcion)
        {
            for (int i = posicion; i < tsolicitudes.contador - 1; i++)
            {
                tsolicitudes.carpsolicitudes[i] = tsolicitudes.carpsolicitudes[i + 1];
            }
            tsolicitudes.contador--;
            cout << "Cliente eliminado correctamente!\n";
        }
        else
        {
            cout << "No se dio de Baja al Cliente!\n";
        }
    }
    cout << "\n\nPrecione ENTER para continuar";
    pauseconsole();
}

int buscarposicion(contsolicitudes &tsolicitudes)
{

    int posicion = -1;
    int codigo = 0;

    cout << "Ingrese el codigo: ";
    cin >> codigo;

    for (int i = 0; i < tsolicitudes.contador; i++)
    {

        if (codigo == tsolicitudes.carpsolicitudes[i].codigo)
        {
            posicion = i;
            break;
        }
    }

    if (posicion != -1)
    {

        return posicion;
    }

    else
        cout << "cliente no encontredo... intente nuevamente";
}

void buscarCliente(contsolicitudes &tsolicitudes)
{

    clearconsole();

    cout << "buscar cliente";

    int posicion = buscarposicion(tsolicitudes);

    if (posicion != -1)
    {
        cout << "codigo del cliente: " << tsolicitudes.carpsolicitudes[posicion].codigo;
        cout << " \n nombre: " << tsolicitudes.carpsolicitudes[posicion].nombre;
        cout << " \n apellido " << tsolicitudes.carpsolicitudes[posicion].apellido;
        cout << "\n dni: " << tsolicitudes.carpsolicitudes[posicion].DNI;
    }

    cout << "presione ENTER para continuar";
    pauseconsole();
}

void modificarCliente(contsolicitudes &tsolicitudes)
{

    clearconsole();

    cout << "\n\t\t~~~Modificar cliente~~~\n\n";
    int posicion = buscarposicion(tsolicitudes);

    if (posicion != -1)
    {
        bool opcion;

        listado(tsolicitudes);

        cout << "Es el cliente que quiere Modificar?\n";
        cout << "Para si ingrese '1'\n";
        cout << "Para no ingrese '0'\n";
        cout << "opcion: ";
        cin >> opcion;

        if (opcion)
        {
            cout << "Ingrese el nuevo Apellido del Cliente: ";
            cin.ignore();
            getline(cin, tsolicitudes.carpsolicitudes[posicion].apellido);
            cout << "Ingrese el nuevo Nombre del Cliente: ";
            getline(cin, tsolicitudes.carpsolicitudes[posicion].nombre);
            cout << "Ingrese el nuevo DNI del Cliente: ";
            cin >> tsolicitudes.carpsolicitudes[posicion].DNI;
            cout << "Cliente modificado correctamente!\n";
        }
    }
    else
    {
        cout << "No se Modifico el Cliente!\n";
    }

    cout << "\n\nPrecione ENTER para continuar";
    pauseconsole();
}

void clearconsole()
{

#ifdef __unix__
    system("clear");
#elif __APPLE__
    system("clear");
#elif defined(_WIN32) || defined(WIN32)
    system("cls");
#endif defined
}

void pauseconsole()
{

    cin.ignore();
    cin.get();
}
