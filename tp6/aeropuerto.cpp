#include <iostream>
using namespace std;

enum Clase
{
    primera,
    business,
    economica
};
enum Aeropuerto
{
    bhi,
    aep,
    epa,
    eze,
    brc,
    ctc,
    crd
};

typedef struct Pasajero
{
    string nombre;
    string apellido;
    Clase tipoClase;
    Aeropuerto origen;
    Aeropuerto destino;
};
Pasajero crearPasajero();
Aeropuerto elegirAeropuerto();
Clase elegirClase();
void mostarDatos(Pasajero pasajero);

int main()
{
    Pasajero pasajero1 = crearPasajero();
    mostarDatos(pasajero1);
    return 0;
}

Pasajero crearPasajero()
{
    Pasajero pasajero1;
    cout << "Ingrese nombre del pasajero:" << endl;
    cin >> pasajero1.nombre;
    cout << "Ingrese Apellido: " << endl;
    cin >> pasajero1.apellido;
    cout << "Ingrese aeropuerto origen:" << endl;
    pasajero1.origen = elegirAeropuerto();
    cout << "Ingrese aeropuerto: destino" << endl;
    pasajero1.destino = elegirAeropuerto();
    pasajero1.tipoClase = elegirClase();
    return pasajero1;
}
Aeropuerto elegirAeropuerto()
{
    Aeropuerto opcion;
    cout << "1. Bahía Blanca-BHI" << endl;
    cout << "2. Buenos Aires Aeroparque-AEP" << endl;
    cout << "3. Buenos Aires El Palomar-EPA" << endl;
    cout << "4. Buenos Aires Ezeiza-EZE" << endl;
    cout << "5. San Carlos de Bariloche-BRC" << endl;
    cout << "6. San Fernando del Valle de Catamarca-CTC" << endl;
    cout << "7. Comodoro Rivadavia-CRD" << endl;
    int opcionSwitch = 0;
    cin >> opcionSwitch;
    switch (opcionSwitch)
    {
    case 1:
        opcion = bhi;
        break;
    case 2:
        opcion = aep;
        break;
    case 3:
        opcion = epa;
        break;
    case 4:
        opcion = eze;
        break;
    case 5:
        opcion = brc;
        break;
    case 6:
        opcion = ctc;
        break;
    case 7:
        opcion = crd;
        break;
    default:
        cout << "Opción inválida" << endl;
        break;
    }
    return opcion;
}
Clase elegirClase()
{
    Clase opcion;
    cout << "1. Primera Clase" << endl;
    cout << "2. Business Clase" << endl;
    cout << "3. Economica clase" << endl;
    int opcionSwitch = 0;
    cin >> opcionSwitch;
    switch (opcionSwitch)
    {
    case 1:
        opcion = primera;
        break;
    case 2:
        opcion = business;
        break;
    case 3:
        opcion = economica;
        break;

    default:
        break;
    }
    return opcion;
}
void mostarDatos(Pasajero pasajero)
{
    string datosMostrar;
    datosMostrar = "Pasajero: " + pasajero.nombre + " " + pasajero.apellido + "\nCon origen en: ";
    switch (pasajero.origen)
    {
    case bhi:
        datosMostrar += "Bahía Blanca-BHI \nDestino en: ";
        break;

    case aep:
        datosMostrar += "Buenos Aires Aeroparque-AEP \nDestino en: ";
        break;

    case epa:
        datosMostrar += "Buenos Aires El Palomar-EPA \nDestino en: ";
        break;

    case eze:
        datosMostrar += "Buenos Aires Ezeiza-EZE \nDestino en: ";
        break;

    case brc:
        datosMostrar += "San Carlos de Bariloche-BRC \nDestino en: ";
        break;
    case ctc:
        datosMostrar += "San Fernando del Valle de Catamarca-CTC \nDestino en: ";
        break;
    case crd:
        datosMostrar += "Comodoro Rivadavia-CRD \nDestino en: ";
        break;

    default:
        break;
    }
    switch (pasajero.destino)
    {
    case bhi:
        datosMostrar += "Bahía Blanca-BHI";
        break;

    case aep:
        datosMostrar += "Buenos Aires Aeroparque-AEP";
        break;

    case epa:
        datosMostrar += "Buenos Aires El Palomar-EPA";
        break;

    case eze:
        datosMostrar += "Buenos Aires Ezeiza-EZE";
        break;

    case brc:
        datosMostrar += "San Carlos de Bariloche-BRC";
        break;
    case ctc:
        datosMostrar += "San Fernando del Valle de Catamarca-CTC";
        break;
    case crd:
        datosMostrar += "Comodoro Rivadavia-CRD";
        break;

    default:
        break;
    }
    system("cls");
    cout << datosMostrar;
}