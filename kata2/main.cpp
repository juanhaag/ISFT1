#include <iostream>
#include <fstream>;
typedef struct
{
    int legajo;
    std::string apellido;
    std::string nombre;
    std::string mail;
    int telefono;
    std::string dptoTrabajo;
    std::string cargo;
    int sueldo;
} Empleado;
void lecturaArchivo();
void guardarArchivo();
void mostrarNomina(Empleado empleados);
Empleado crearEmpleado();
void altaEmpleado(Empleado empleado);
void borrarEmpleado(Empleado empleado, Empleado empleados);
void editarEmpleado(Empleado empleado, Empleado empleados);
void buscarEmpleado(Empleado empleado, Empleado empleados);
int main(int argc, char const *argv[])
{
    Empleado *empleados = new Empleado[3];
    lecturaArchivo();
    return 0;
}

void lecturaArchivo()
{
    std::ifstream archivo("nomina.txt");
    if (archivo.is_open())
    {
        std::cout << "Se abrio el archivo y si tenia info se paso";
    }
    else
    {
        std::ofstream archivo2("nomina.txt", std::ios::app);
    }
}
Empleado crearEmpleado()
{
    Empleado empleado;
    std::cout << "Ingrese el legajo del  empleado:\n";
    std::cin >> empleado.legajo;
    std::cout << "Ingrese el nombre  del empleado:\n";
    std::cin >> empleado.nombre;
    std::cout << "Ingrese el apellido  del empleado:\n";
    std::cin >> empleado.apellido;
    std::cout << "Ingrese el telefono  del empleado:\n";
    std::cin >> empleado.telefono;
    std::cout << "Ingrese el mail del empleado:\n";
    std::cin >> empleado.mail;
    std::cout << "Ingrese el departamento de trabajo del empleado:\n";
    std::cin >> empleado.dptoTrabajo;
    std::cout << "Ingrese el cargo  del empleado:\n";
    std::cin >> empleado.cargo;
    std::cout << "Ingrese el sueldo  del empleado:\n";
    std::cin >> empleado.sueldo;
    return empleado;
}