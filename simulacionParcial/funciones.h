#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <iomanip> // Para utilizar setw()
using namespace std;
typedef struct
{
    int solicitudCode;
    string name;
    string apellido;
    string dni;

} solicitudStruct;

const int MAX_SOLICITUDES = 100;

typedef struct
{
    solicitudStruct solicitudes[MAX_SOLICITUDES];
    int counter;
} solicitudList;

void runCrud(solicitudList &solicitudes);
void verifyAndFill(solicitudList &solicitudes, string nameArchive);
void saveData(solicitudList &solicitudes, string nameArchive);
void addSolicitud(solicitudList &solicitudes);
void removeSolicitud(solicitudList &solicitudes);
void showSolicitudes(solicitudList solicitudes);
void mostrarSolicitud(solicitudStruct solicitud);
void buscarSolicitud(solicitudList solicitudes);
bool isCodeRepeated(solicitudList solicitudes, int code);

void modificarSolicitud(solicitudList &solicitudes);
void runCrud(solicitudList &solicitudes)
{
    solicitudes.counter = 0;
    verifyAndFill(solicitudes, "solicitudes.txt");
    int opcion;
    while (true)
    {
        cout << "1. Agregar solicitud" << endl;
        cout << "2. Eliminar solicitud" << endl;
        cout << "3. Mostrar solicitudes" << endl;
        cout << "4. Buscar y mostrar solicitud" << endl;
        cout << "5. Editar solicitud" << endl;
        cout << "6. Salir y guardar" << endl;
        cout << "Ingrese una opcion: ";
        cin >> opcion;
        switch (opcion)
        {
        case 1:
            addSolicitud(solicitudes);
            system("cls");
            break;
        case 2:
            removeSolicitud(solicitudes);
            system("cls");
            break;
        case 3:
            showSolicitudes(solicitudes);
            break;
        case 4:
            buscarSolicitud(solicitudes);
            break;
        case 5:
            modificarSolicitud(solicitudes);
            break;
        case 6:
            saveData(solicitudes, "solicitudes.txt");
            exit(0);
        default:
            cout << "Opcion no valida" << endl;
        }
    }
}
void verifyAndFill(solicitudList &solicitudes, string nameArchive)
{
    ifstream archive(nameArchive);

    if (archive.is_open())
    {
        string line;
        while (getline(archive, line) && solicitudes.counter <= MAX_SOLICITUDES)
        {
            stringstream stringToStream(line);
            string solicitudCode, name, apellido, dni;
            getline(stringToStream, solicitudCode, ',');
            getline(stringToStream, name, ',');
            getline(stringToStream, apellido, ',');
            getline(stringToStream, dni, ',');
            if (solicitudCode != " ")
            {
                solicitudes.solicitudes[solicitudes.counter].solicitudCode = stoi(solicitudCode);
            }
            solicitudes.solicitudes[solicitudes.counter].name = name;
            solicitudes.solicitudes[solicitudes.counter].apellido = apellido;
            solicitudes.solicitudes[solicitudes.counter].dni = dni;
            solicitudes.counter++;
        }
        solicitudes.counter >= MAX_SOLICITUDES ? cout << "No se puede cargar mas de 100 solicitudes \n" : cout << " ";

        archive.close();
    }
}

void saveData(solicitudList &solicitudes, string nameArchive)
{
    ofstream archive(nameArchive);

    if (archive.is_open())
    {
        if (solicitudes.counter > 0)
        {
            for (int i = 0; i < solicitudes.counter; i++)
            {
                archive << solicitudes.solicitudes[i].solicitudCode << ',';
                archive << solicitudes.solicitudes[i].name << ',';
                archive << solicitudes.solicitudes[i].apellido << ',';
                archive << solicitudes.solicitudes[i].dni << endl;
            }
        }
        archive.close();
    }
}
//Se
/* void addSolicitud(solicitudList &solicitudes)
{
    solicitudStruct nuevosolicitud;

    if (solicitudes.counter <= MAX_SOLICITUDES)
    {
        nuevosolicitud.solicitudCode = solicitudes.counter + 100;
        if (nuevosolicitud.solicitudCode == solicitudes.solicitudes[solicitudes.counter - 1].solicitudCode)
        {
            nuevosolicitud.solicitudCode++;
        }
        cout << "Ingrese el nombre del solicitude que desea la  solicitud: ";
        cin >> nuevosolicitud.name;
        cout << "Ingrese el apellido del solicitude que desea la  solicitud: ";
        cin >> nuevosolicitud.apellido;
        cout << "Ingrese el DNI del solicitude: ";
        cin >> nuevosolicitud.dni;
        solicitudes.solicitudes[solicitudes.counter] = nuevosolicitud;
        solicitudes.counter++;
    }
    else
    {
        cout << "No se puede exceder de 100 solicitudes" << endl;
    }
} */

//Perdon por el spaninglish
bool isCodeRepeated(solicitudList solicitudes, int code)
{
    for (int i = 0; i < solicitudes.counter; i++)
    {
        if (solicitudes.solicitudes[i].solicitudCode == code)
        {
            return true;
        }
    }
    return false;
}
//Perdon por el spaninglish
void addSolicitud(solicitudList &solicitudes)
{
    solicitudStruct nuevosolicitud;
    if (solicitudes.counter <= MAX_SOLICITUDES)
    {
        int code = solicitudes.counter + 100;
        while (isCodeRepeated(solicitudes, code))
        {
            code++;
        }
        nuevosolicitud.solicitudCode = code;

        cout << "Ingrese el nombre del solicitante: ";
        cin >> nuevosolicitud.name;
        cout << "Ingrese el apellido del solicitante: ";
        cin >> nuevosolicitud.apellido;
        cout << "Ingrese el DNI del solicitante: ";
        cin >> nuevosolicitud.dni;

        solicitudes.solicitudes[solicitudes.counter] = nuevosolicitud;
        solicitudes.counter++;
    }
    else
    {
        cout << "No se puede exceder de 100 solicitudes" << endl;
    }
}

void removeSolicitud(solicitudList &solicitudes)
{
    int solicitudCode, foundsolicitud = 0;
    cout << "Ingrese el codigo del solicitud a eliminar: ";
    cin >> solicitudCode;
    for (int i = 0; i < solicitudes.counter; i++)
    {
        if (solicitudCode == solicitudes.solicitudes[i].solicitudCode)
        {
            // Movemos los elementos para atras para que no quede un hueco
            // counter - 1 porque ya sacamos un elemento
            for (int j = i; j < solicitudes.counter - 1; j++)
            {
                // Escribimos la siguiente posicion
                solicitudes.solicitudes[j] = solicitudes.solicitudes[j + 1];
            }
            // Decrementamos el counter ya que eliminamos un solicitud
            solicitudes.counter--;
            foundsolicitud = 1;
            break;
        }
    }
    foundsolicitud == 1 ? cout << "Se elimino correctamente" << endl : cout << "No se encontro solicitud" << endl;
}
void modificarSolicitud(solicitudList &solicitudes)
{
    int solicitudCode, foundsolicitud = 0;

    cout << "Ingrese el codigo del solicitud a modificar: ";
    cin >> solicitudCode;
    for (int i = 0; i < solicitudes.counter; i++)
    {
        if (solicitudCode == solicitudes.solicitudes[i].solicitudCode)
        {
            mostrarSolicitud(solicitudes.solicitudes[i]);
            cin.ignore();
            cout << "Ingrese el nuevo nombre del solicitude:" << endl;
            cin >> solicitudes.solicitudes[i].name;
            cout << "Ingrese el nuevo apellido del solicitude:" << endl;
            cin >> solicitudes.solicitudes[i].apellido;
            cout << "Ingrese el nuevo DNI del solicitude:" << endl;
            cin >> solicitudes.solicitudes[i].dni;

            foundsolicitud = 1;
        }
    }
    foundsolicitud == 1 ? cout << "Se modifco correctamente la solicitud" << endl : cout << "No se encontro solicitud con es codigo" << endl;
}
void showSolicitudes(solicitudList solicitudes)
{
    system("cls");
    // Si hay 1 elemento por mas de que ese elemnto este en 0
    // El contador va a incremetnar
    if (solicitudes.counter == 0)
    {
        cout << "No hay solicitudes que mostrar" << endl;
    }
    else
    {
        cout << "---------------------------------" << endl;
        cout << "|        Informacion solicitud     |" << endl;
        cout << "---------------------------------" << endl;
        for (int i = 0; i < solicitudes.counter; i++)
        {

            cout << "| Codigo: " << setw(10) << solicitudes.solicitudes[i].solicitudCode << "\t\t"
                 << " |" << endl;
            cout << "| Nombre: " << setw(10) << solicitudes.solicitudes[i].name << "\t\t"
                 << " |" << endl;
            cout << "| Apellido: " << setw(10) << solicitudes.solicitudes[i].apellido << "\t\t"
                 << " |" << endl;
            cout << "|   DNI: " << setw(10) << solicitudes.solicitudes[i].dni << "\t\t"
                 << " |" << endl;
            cout << "---------------------------------" << endl;
        }
    }
}
void mostrarSolicitud(solicitudStruct solicitud)
{

    system("cls");
    cout << "---------------------------------" << endl;
    cout << "Codigo: " << solicitud.solicitudCode << endl;
    cout << "Nombre: " << solicitud.name << endl;
    cout << "Apellido: " << solicitud.apellido << endl;
    cout << "DNI: " << solicitud.dni << endl;
    cout << "---------------------------------" << endl;
}
void buscarSolicitud(solicitudList solicitudes)
{
    int solicitudCode;
    bool record = false;
    system("cls");
    // Si hay 1 elemento por mas de que ese elemnto este en 0
    // El contador va a incremetnar
    cout << "Ingrese el codigo del solicitud a modificar: ";
    cin >> solicitudCode;
    if (solicitudes.counter == 0)
    {
        cout << "No hay solicitudes que mostrar" << endl;
    }
    else
    {
        for (int i = 0; i < solicitudes.counter; i++)
        {
            if (solicitudes.solicitudes[i].solicitudCode == solicitudCode)
            {
                cout << "---------------------------------" << endl;
                cout << "Codigo: " << solicitudes.solicitudes[i].solicitudCode << endl;
                cout << "Nombre: " << solicitudes.solicitudes[i].name << endl;
                cout << "Apellido: " << solicitudes.solicitudes[i].apellido << endl;
                cout << "DNI: " << solicitudes.solicitudes[i].dni << endl;
                cout << "---------------------------------" << endl;
                record = true;
            }
        }

        record == false ? cout << "No se encuentra esa solicitud \n" : cout << " ";
        ;
    }
}
