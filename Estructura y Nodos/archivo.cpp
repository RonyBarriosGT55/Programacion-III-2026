#include <iostream>
#include <string>
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

    cout << "NOMBRE COMPLETO: RONY ALEXANDER BARRIOS" << endl;
    cout << "===============================" << endl;

    // Paso 2 – Crear el primer nodo
    Nodo* primero = new Nodo;

    primero->data.codigo = 101;
    primero->data.nombre = "Laptop";
    primero->data.precio = 5500.50;
    primero->siguiente = nullptr;

    // Paso 3 – Crear el segundo nodo
    Nodo* segundo = new Nodo;

    segundo->data.codigo = 102;
    segundo->data.nombre = "Mouse";
    segundo->data.precio = 150.75;
    segundo->siguiente = nullptr;

    // Enlazar primero -> segundo
    primero->siguiente = segundo;

    // Paso 4 – Crear el tercer nodo
    Nodo* tercero = new Nodo;

    tercero->data.codigo = 103;
    tercero->data.nombre = "Teclado";
    tercero->data.precio = 300.00;
    tercero->siguiente = nullptr;

    // Enlazar segundo -> tercero
    segundo->siguiente = tercero;

    // Paso 5 – Recorrer e imprimir la lista
    Nodo* actual = primero;

    while (actual != nullptr) {
        cout << "Codigo: " << actual->data.codigo << endl;
        cout << "Nombre: " << actual->data.nombre << endl;
        cout << "Precio: Q" << actual->data.precio << endl;
        cout << "--------------------------" << endl;

        actual = actual->siguiente;
    }

    // Paso 6 – Liberar memoria
    actual = primero;

    while (actual != nullptr) {
        Nodo* temp = actual;
        actual = actual->siguiente;
        delete temp;
    }

    primero = nullptr;

    return 0;
}
