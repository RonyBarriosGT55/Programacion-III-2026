#include <iostream>
using namespace std;

struct Nodo {
    int dato;  //Guarda el Nú ingresado por el usuario
    Nodo* siguiente; //Guarda la dirección del siguiente nodo
};

int main() {
    // Puntero inicial HEAD que siempre apunta al primer nodo de la lista
    Nodo* head = NULL;

    //puntero auxiliar que se usa para recorrer la lista
    Nodo* actual = NULL;

    int valor;  //Variable que almacenará el número que ingresa el usuario
    char opcion = 's'; // Controla el seguimiento del programa

    /* Ciclo Principal que permitirá ingresar números indefinidamente
     * hasta que el usuario diga que no
     */

    cout << "Rony Alexander Barrios" << endl;
  while (opcion == 's') {

      cout << "\nIngresa un numero:";
      cin >> valor;
      /* Crear un nuevo nodo en memoria dinamica
       * se usa new para reservar memoria durante la ejecución
       * */
      Nodo* nuevo = new Nodo;
      // Guardar el valor ingresado dentro del nodo
      nuevo->dato = valor;
      //Inicializar el puntero siguiente en NUll
      // Indica que por ahora es el ultimo nodo
      nuevo->siguiente = NULL;
      /* si la lista está vacía
       * el nuevo nodo se convierte en el primer nodo
       * */
      if(head == NULL) {
          head = nuevo;

      }
      else {
          /* si la lista ya tiene nodos debemos buscar el útlimo nodo
           * */

          actual = head; // Comenzamos desde el inicio de la lista

          /* REcorremos la lista hasta encontrar el último nodo
          el ultimo nodo es el que tiene el sigjiente = null
          */
          while (actual-> siguiente != NULL) {

              actual = actual->siguiente;

          }
          // Conectar el ultimo nodo con el nuevo nodo
          actual->siguiente = nuevo;

      }
      // Preguntar al usuario si desea continuar
      cout << "Desea ingresar otro numero? (s/n);";
      cin >> opcion;

  }
   //mostrar lista generada

    cout << "\n Lista generada:\n";
    //comenzamos nuevamente desde el inicio
    actual= head;
    /* Recorremos la lista hasta llegar a Null
     * */
    while (actual != NULL){

    cout << actual->dato << " -> ";
    actual = actual->siguiente;
    }
    cout << "NULL";
    /*calcular cantidad de nodos y suma y promedio*/
    int cantidad = 0; // contador de nodos
    int suma = 0; // suma de valores
    float promedio = 0; //promedio de los valores


   // volver al inicio de la lista
    actual = head;
    // recorer nuevamente todos los nodos
    while(actual != NULL) {
        cantidad++;   //contar el nodo
        suma += actual->dato; //sumar el valor del nodo
        actual = actual->siguiente; //avanzar al siguiente nodo

    }
    //calcular el promedio si existe al menos un nodo
    if (cantidad > 0) {
        promedio = (float)suma / (float)cantidad;
    }
    // Mostrar resultados
    cout << "            " << endl;
    cout << "Rony Alexander Barrios" << endl;
    cout <<"\n\nCantidad total de nodos: "<< cantidad;
    cout << "\nSuma de los valores: " << suma;
    cout << "\nPromedio de los valores: " << promedio;
    return 0;
}
