#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;
typedef struct
{
    int numberTicket;
    string name;
    string dni;
    bool attendance;

} guestStruct;

const int MAX_GUESTS = 100;

typedef struct
{
    guestStruct invitados[MAX_GUESTS];
    int counter;
} guestList;

void runCrud(guestList &guests);
void verifyAndFill(guestList &guests, string nameArchive);
void saveData(guestList &guests, string nameArchive);
void addClient(guestList &guests);
void removeClient(guestList &guests);
void showguests(guestList guests);
void modifyClient(guestList &guests);
void runCrud(guestList &guests)
{
    guests.counter = 0;
    verifyAndFill(guests, "guests.txt");
    int opcion;
    while (true)
    {
        cout << "1. Agregar invitado" << endl;
        cout << "2. Eliminar invitado" << endl;
        cout << "3. Mostrar invitados" << endl;
        cout << "4. Editar invitado" << endl;
        cout << "5. Salir y guardar" << endl;
        cout << "Ingrese una opcion: ";
        cin >> opcion;
        switch (opcion)
        {
        case 1:
            addClient(guests);
            system("cls");
            break;
        case 2:
            removeClient(guests);
            system("cls");
            break;
        case 3:
            showguests(guests);
            break;
        case 4:
            modifyClient(guests);
            break;
        case 5:
            saveData(guests, "guests.txt");
            exit(0);
        default:
            cout << "Opcion no valida" << endl;
        }
    }
}
void verifyAndFill(guestList &guests, string nameArchive)
{
    ifstream archive(nameArchive);

    if (archive.is_open())
    {
        string line;
        while (getline(archive, line) && guests.counter <= MAX_GUESTS)
        {
            stringstream stringToStream(line);
            string numberTicket, name, dni, attendance;
            getline(stringToStream, numberTicket, ',');
            getline(stringToStream, name, ',');
            getline(stringToStream, dni, ',');
            getline(stringToStream, attendance, ',');
            guests.invitados[guests.counter].numberTicket = stoi(numberTicket);
            guests.invitados[guests.counter].name = name;
            guests.invitados[guests.counter].dni = dni;
            guests.invitados[guests.counter].attendance = stoi(attendance);
            guests.counter++;
        }
        archive.close();
    }
}

void saveData(guestList &guests, string nameArchive)
{
    ofstream archive(nameArchive);

    if (archive.is_open())
    {
        if (guests.counter > 0)
        {
            for (int i = 0; i < guests.counter; i++)
            {
                archive << guests.invitados[i].numberTicket << ',';
                archive << guests.invitados[i].name << ',';
                archive << guests.invitados[i].dni << ',';
                archive << guests.invitados[i].attendance << endl;
            }
        }
        archive.close();
    }
}
void addClient(guestList &guests)
{
    guestStruct nuevoinvitado;
    nuevoinvitado.numberTicket = (guests.counter + 1) + 99;
    cout << "Ingrese el nombre del invitado: ";
    cin >> nuevoinvitado.name;
    cout << "Ingrese el DNI del invitado: ";
    cin >> nuevoinvitado.dni;
    cout << "Confirmar asistencia si(1) o no (0): ";
    cin >> nuevoinvitado.attendance;
    guests.invitados[guests.counter] = nuevoinvitado;
    guests.counter++;
}
void removeClient(guestList &guests)
{
    int numberTicket;
    cout << "Ingrese el codigo del invitado a eliminar: ";
    cin >> numberTicket;
    for (int i = 0; i < guests.counter; i++)
    {
        if (numberTicket == guests.invitados[i].numberTicket)
        {
            // Movemos los elementos para atras para que no quede un hueco
            // counter - 1 porque ya sacamos un elemento
            for (int j = i; j < guests.counter - 1; j++)
            {
                // Escribimos la siguiente posicion
                guests.invitados[j] = guests.invitados[j + 1];
            }
            // Decrementamos el counter ya que eliminamos un invitado
            guests.counter--;
            break;
        }
    }
}
void modifyClient(guestList &guests)
{
    int numberTicket;
    cout << "Ingrese el codigo del invitado a modificar: ";
    cin >> numberTicket;
    for (int i = 0; i < guests.counter; i++)
    {
        if (numberTicket == guests.invitados[i].numberTicket)
        {
            cout << "Ingrese el nuevo nombre del invitado:" << endl;
            cin >> guests.invitados[i].name;
            cout << "Ingrese el nuevo dni del invitado:" << endl;
            cin >> guests.invitados[i].dni;
            cout << "Ingrese el nuevo estado de asistencia SI(1) o NO(0):" << endl;
            cin >> guests.invitados[i].attendance;
        }
    }
}
void showguests(guestList guests)
{
    system("cls");
    cout << "-----------Fiesta Aniversario de Studio 54 en New York!.---------------" << endl;
    cout << "---------------------Listado invitados.--------------------------------" << endl;
    for (int i = 0; i < guests.counter; i++)
    {
        cout << "---------------------------------" << endl;
        cout << "Codigo: " << guests.invitados[i].numberTicket << endl;
        cout << "Nombre: " << guests.invitados[i].name << endl;
        cout << "DNI: " << guests.invitados[i].dni << endl;
        guests.invitados[i].attendance ==  1 ? cout << "ASISTE" << endl : cout << "NO ASISTE" << endl;
        cout << "---------------------------------" << endl;
    }
}
