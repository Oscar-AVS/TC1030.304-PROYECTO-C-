// Este es el programa creado para la clase "RegistroXP.h". Esta clase sirve como un controlador para modificar y mostrar los puntos de experiencia (XP) del jugador.
// Creado por: Oscar Alexander Vilchis Soto (A01713207)
// Creado el 20/05/2025

// Modificado el 28/05/2025 de igual manera en esta clase no fue necesario hacer algún cambio


#ifndef REGISTROXP_H
#define REGISTROXP_H

#include "Jugador.h"
#include <iostream>

class RegistroXP {
private:
    Jugador* jugador;

public:
    RegistroXP(Jugador* jugador) : jugador(jugador) {}

    void modificarXP(int cantidad) {
        if (cantidad >= 0) jugador->ganarXp(cantidad);
        else jugador->perderXp(-cantidad);
    }

    void mostrarXP() const {
        cout << "XP actual: " << jugador->getXp() << endl;
    }
};

#endif
