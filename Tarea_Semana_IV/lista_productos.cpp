#include <iostream>
#include <string>
#include <limits>
using namespace std;

// NOMBRE COMPLETO: RONY ALEXANDER BARRIOS
// CARNET : 9941 99 127

struct Producto {
    int codigo;
    string nombre;
    double precio;
};

struct Nodo {
    Producto data;
    Nodo* siguiente;
};

int main() {
    cout << "Nombre completo: RONY ALEXANDER BARRIOS" << endl << endl;

    // Crear dinámicamente 4 nodos
    Nodo* n1 = new Nodo;
    Nodo* n2 = new Nodo;
    Nodo* n3 = new Nodo;
    Nodo* n4 = new Nodo;

    // Inicializar y enlazar manualmente (en el orden de ingreso)
    n1->siguiente = n2;
    n2->siguiente = n3;
    n3->siguiente = n4;
    n4->siguiente = nullptr;

    // Puntero cabeza (no se modifica al recorrer)
    Nodo* cabeza = n1;

    // Solicitar datos al usuario
    Nodo* actual = cabeza;
    for (int i = 1; i <= 4; i++) {
        cout << "Producto " << i << endl;

        // Codigo (int) con validación
        while (true) {
            cout << "Codigo (solo numeros): ";
            if (cin >> actual->data.codigo) break;

            cout << "No se permite ese valor de variable." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        // Limpiar salto de línea antes del getline
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        // Nombre (string) con espacios
        cout << "Nombre: ";
        getline(cin, actual->data.nombre);

        // Precio (double) con validación
        while (true) {
            cout << "Precio: Q";
            if (cin >> actual->data.precio) break;

            cout << "No se permite ese valor de variable." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        // Limpiar para el siguiente ciclo
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        cout << "--------------------" << endl;

        actual = actual->siguiente;
    }

    // Recorrer e imprimir + total acumulado (usando puntero auxiliar)
    cout << "\n--- LISTA DE PRODUCTOS ---" << endl;

    double total = 0.0;
    actual = cabeza;

    while (actual != nullptr) {
        cout << "Codigo: " << actual->data.codigo << endl;
        cout << "Nombre: " << actual->data.nombre << endl;
        cout << "Precio: Q" << actual->data.precio << endl;
        cout << "--------------------" << endl;

        total += actual->data.precio;
        actual = actual->siguiente;
    }

    cout << "Total acumulado: Q" << total << endl;

    // Liberar memoria correctamente (delete en todos los nodos)
    actual = cabeza;
    while (actual != nullptr) {
        Nodo* temp = actual;
        actual = actual->siguiente;
        delete temp;
    }

    cabeza = nullptr;
    return 0;
}
