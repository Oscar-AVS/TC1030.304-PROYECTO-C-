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
