// Este es el programa creado para la clase "EscenaSecundaria.h". Define una escena secundaria que se activa con ciertas decisiones del jugador, mostrando un mensaje adicional al jugador.
// Creado por: Oscar Alexander Vilchis Soto (A01713207)
// Creado el 20/05/2025
// Modificado el 28/05/2025: De igual manera, en esta clase no se realizaron cambios en este tercer avance 

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
