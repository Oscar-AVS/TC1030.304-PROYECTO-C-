// Este es el programa creado para la clase "Capitulo.h" Esta clase es en donde se agrupan  varias escenas principales de manera que permita una ejecución secuencial.
// Creado por: Oscar Alexander Vilchis Soto (A01713207)
// Creado el 20/05/2025
// Modificado el 28/05/2025 en este tercer avance no se cambió nada de la estructura o el código todo se mantiene igual
#ifndef CAPITULO_H
#define CAPITULO_H

#include <vector>
#include <string>
#include <iostream>
#include "EscenaPrincipal.h"
using namespace std;

class Capitulo {
private:
    int numero;
    string titulo;
    vector<EscenaPrincipal*> escenas;

public:
    Capitulo(int numero, const string& titulo) : numero(numero), titulo(titulo) {}

    ~Capitulo() {
        for (auto escena : escenas) delete escena;
    }

    void agregarEscena(EscenaPrincipal* escena) {
        escenas.push_back(escena);
    }

    void ejecutar(Jugador& jugador) {
        for (auto escena : escenas) {
            escena->mostrar();
            int opcion;
            cout << "Elige una opcion: ";
            cin >> opcion;
            escena->elegirOpcion(opcion, jugador);
        }
    }

    string getTitulo() const { return titulo; }
};

#endif
