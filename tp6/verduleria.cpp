#include <iostream>
using namespace std;

enum Frutas
{
    banana,
    manzana,
    naranja,
    pomelo,
    limon
};
typedef struct Pedido
{
    int codigoProveedor;
    string razonSocial;
    string fechaSolicitud;
    string fechaEntrega;
    string frutas;
};
Pedido realizarPedido();
string seleccionaFruta();
int main(int argc, char const *argv[])
{
    Pedido pedido1 = realizarPedido();
    return 0;
}

Pedido realizarPedido()
{
    Pedido pedido1;
    cout << "Ingrese el codigo de proveedor" << endl;
    cin >> pedido1.codigoProveedor;
    cout << "Ingrese la razon social del proveedor" << endl;
    cin >> pedido1.razonSocial;
    cout << "Ingrese la fecha de solicitud" << endl;
    cin >> pedido1.fechaSolicitud;
    cout << "Ingrese la fecha de entrega" << endl;
    cin >> pedido1.fechaEntrega;
    pedido1.frutas = seleccionaFruta();
    return pedido1;
}

string seleccionaFruta()
{
    string frutas;
    int fruta;

    do
    {
        cout << "Las frutas son:" << endl;
        cout << "1 -Banana" << endl;
        cout << "2 -Manzana" << endl;
        cout << "3 -Naranja" << endl;
        cout << "4 -Pomelo" << endl;
        cout << "5 -Lemon" << endl;
        cin >> fruta;
        switch (fruta)
        {
        case 1:
            frutas += "\tbanana";
            break;
        case 2:
            frutas += "\tManzana";
            break;
        case 3:
            frutas += "\tNaranja";
            break;
        case 4:
            frutas += "\tPomelo";
            break;
        case 5:
            frutas += "\tLemon";
            break;
        }
        cout << "introduce 27(esc en ascii) para dejar de cargar" << endl;
        cin >> fruta;

    } while (fruta != 27);
    return frutas;
}
