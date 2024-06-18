#include <iostream>
#include <algorithm>
#include <limits> 

using namespace std;

// Función para leer y validar la entrada de edades
int edadesHijos(const string& mensaje) {
    int edad;
    while (true) {
        cout << mensaje;
        cin >> edad;
        // verificams que la entrada sea valida, limitamos las edades  hasta 100
        if (cin.fail() || edad < 0 || edad > 100 || cin.peek() != '\n') {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignora la entrada inválida ingresada
            cout << "Entrada inválida. Por favor ingrese una edad valida (0-100)." << endl;
        } else {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return edad;
        }
    }
}

int main() {
    // Lee las edades de los tres hijos y lo guardamos en un arreglo
    int edades[3];
    edades[0] = edadesHijos("Ingrese la edad del primer hijo: ");
    edades[1] = edadesHijos("Ingrese la edad del segundo hijo: ");
    edades[2] = edadesHijos("Ingrese la edad del tercer hijo: ");

    // Ordenar las edades de menor a mayor
    sort(edades, edades + 3);

    // Calcular la edad media
    double media = (edades[0] + edades[1] + edades[2]) / 3.0;

    // Muestra las edades del hijo menor, del medio y del mayor
    cout << "\nEdad del hijo menor: " << edades[0] << endl;
    cout << "Edad del hijo del medio: " << edades[1] << endl;
    cout << "Edad del hijo mayor: " << edades[2] << endl;
    cout << "\nEdad media: " << media << endl;

    return 0;
}
