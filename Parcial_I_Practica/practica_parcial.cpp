#include <iostream>
#include <string>
#include <limits>
using namespace std;

// NOMBRE COMPLETO: RONY ALEXANDER BARRIOS
// CARNET : 9941 99 127
// SECCIÓN B DOMINGOS
/*
El programa crea una lista enlazada con tres productos.
Luego muestra sus datos y libera la memoria utilizada.

Guarda código nombre y precio dentro de cada nodo.
Los nodos se conectan formando una cadena de productos.
*/
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

    cout << "NOMBRE COMPLETO: RONY ALEXANDER BARRIOS" << endl;
    cout << "===============================" << endl;

    // Crear nodos dinamicamente
    Nodo* primero = new Nodo;
    Nodo* segundo = new Nodo;
    Nodo* tercero = new Nodo;

    // Enlazar nodos
    primero->siguiente = segundo;
    segundo->siguiente = tercero;
    tercero->siguiente = nullptr;

    Nodo* actual = primero;

    for (int i = 1; i <= 3; i++) {
        cout << "\nProducto " << i << endl;

        // Validar CODIGO
        while (true) {
            cout << "Codigo (solo numeros): ";
            if (cin >> actual->data.codigo) break;

            cout << "No se permite ese valor de variable.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        // nombre
        cout << "Nombre: ";
        getline(cin, actual->data.nombre);

        // Validar el precio
        while (true) {
            cout << "Precio: Q";
            if (cin >> actual->data.precio) break;

            cout << "No se permite ese valor de variable.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        actual = actual->siguiente;
    }

    // Mostrar datos
    cout << "\n--- LISTA DE PRODUCTOS ---" << endl;
    actual = primero;

    while (actual != nullptr) {
        cout << "\nCodigo: " << actual->data.codigo << endl;
        cout << "Nombre: " << actual->data.nombre << endl;
        cout << "Precio: Q" << actual->data.precio << endl;
        actual = actual->siguiente;
    }

    // soltar memoria
    actual = primero;
    while (actual != nullptr) {
        Nodo* temp = actual;
        actual = actual->siguiente;
        delete temp;
    }

    primero = nullptr;

    return 0;
}
