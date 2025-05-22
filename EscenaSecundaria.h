#ifndef ESCENASECUNDARIA_H
#define ESCENASECUNDARIA_H

#include <string>
#include <iostream>
using namespace std;

class EscenaSecundaria {
private:
    bool activa;
    string descripcion;

public:
    EscenaSecundaria(const string& desc) : activa(false), descripcion(desc) {}

    void activar() { activa = true; }

    void mostrar() const {
        if (activa) cout << "Escena secundaria: " << descripcion << endl;
    }

    bool estaActiva() const { return activa; }
};

#endif
