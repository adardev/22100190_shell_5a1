#include <iostream>
#include <sstream>
using namespace std;

class MetodoShell {
private:
    int numeros[50];
    int numDatos;
    string preguntaIteracion;

    void mostrarIteracion();

public:
    MetodoShell();
    void ingresoDeDatos();
    void Shell();
    void imprimirArreglo();
};

void MetodoShell::mostrarIteracion() {
    for (int i = 0; i < numDatos; ++i) {
        cout << numeros[i];
        if (i != numDatos - 1) {
            cout << ", ";
        }
    }
    cout << endl;
}

MetodoShell::MetodoShell() {}

void MetodoShell::ingresoDeDatos() {
    cout << "METODO DE ORDENACION POR SHELL" << endl;
    cout << "Ingresa cuantos datos quieres ordenar: ";
    cin >> numDatos;
    cin.ignore(); // limpiar el buffer del salto de línea

    cout << "Ingresa los datos separados por espacios: ";
    string entrada;
    getline(cin, entrada);

    istringstream stream(entrada); // convierte este string a un stream
    int numero;
    int numNumeros = 0; // para ver la cantidad de datos que se ingresaron y poder compararlos

    while (stream >> numero && numNumeros < numDatos) {
        numeros[numNumeros] = numero;
        numNumeros++;
    }

    // Si no hay los datos que el usuario dijo
    if (numNumeros < numDatos) {
        cout << "Faltan datos" << endl;
        numDatos = numNumeros;
    }

    cout << "Quieres ver cada iteracion?";
    cin >> preguntaIteracion;

    // Convertir a minúsculas
    for (char& c : preguntaIteracion) {
        c = tolower(c);
    }
}

void MetodoShell::Shell() {
    for (int salto = numDatos / 2; salto > 0; salto /= 2) {
        for (int i = salto; i < numDatos; ++i) {
            int j = i;
            while (j >= salto && numeros[j - salto] > numeros[i]) {
                numeros[j] = numeros[j - salto];
                j -= salto;
            }
            numeros[j] = numeros[i];
        }
        if (preguntaIteracion == "si") {
            mostrarIteracion();
        }
    }
}

void MetodoShell::imprimirArreglo() {
    for (int i = 0; i < numDatos; ++i) {
        cout << numeros[i] << " ";
    }
}

int main() {
    MetodoShell ordenamiento;
    ordenamiento.ingresoDeDatos();
    ordenamiento.Shell();

    cout << endl;
    ordenamiento.imprimirArreglo();
}
