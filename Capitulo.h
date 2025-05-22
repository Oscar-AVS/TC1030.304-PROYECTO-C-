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
