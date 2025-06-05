// Este es el programa creado para la clase "Capitulo.h" Esta clase es en donde se agrupan  varias escenas principales de manera que permita una ejecución secuencial.
// Creado por: Oscar Alexander Vilchis Soto (A01713207)
// Creado el 20/05/2025
// Modificado el 28/05/2025 en este tercer avance no se cambió nada de la estructura o el código todo se mantiene igual
#ifndef CAPITULO_H
#define CAPITULO_H

#include <string>
#include <iostream>
#include "EscenaPrincipal.h"
using namespace std;

class Capitulo {
private:
    int numero;                          // Número del capítulo
    string titulo;                       // Título del capítulo
    static const int MAX_ESCENAS = 5;    // Máximo de escenas por capítulo
    EscenaPrincipal* escenas[MAX_ESCENAS]; // Arreglo de punteros a escenas
    int numEscenas;                      // Contador de escenas agregadas

public:
    // Constructor: inicializa el número, título y contador
    Capitulo(int numero, const string& titulo) : numero(numero), titulo(titulo), numEscenas(0) {}

    // Destructor: libera la memoria de las escenas
    ~Capitulo() {
        for (int i = 0; i < numEscenas; ++i)
            delete escenas[i];
    }

    void agregarEscena(EscenaPrincipal* escena) {
        if (numEscenas < MAX_ESCENAS) {
            escenas[numEscenas] = escena;
            numEscenas++;
        }
    }

    // Ejecuta las escenas del capítulo una por una
    void ejecutar(Jugador& jugador) {
        for (int i = 0; i < numEscenas; ++i) {
            escenas[i]->mostrar();
            int opcion;
            cout << "Elige: ";
            cin >> opcion;
            escenas[i]->elegirOpcion(opcion, jugador);
        }
    }

    // Devuelve el título del capítulo
    string getTitulo() const { return titulo; }
};

#endif
