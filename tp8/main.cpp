#include <iostream>

using namespace std;
int calcularSalario();
int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}

int calcularSalario()
{
    int horasTrabajadas = 0;
    int totalACobrar = 0;

    cout << "Cuantas horas trabajo?:" << endl;
    cin >> horasTrabajadas;

    if (horasTrabajadas <= 40)
    {
        totalACobrar = horasTrabajadas * 200;
    }
    else if (horasTrabajadas > 40)
    {
        totalACobrar = horasTrabajadas * 250;
    }
    return totalACobrar;
}