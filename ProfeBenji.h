// Este es el progrma creado para la clase "ProfeBenji.h" En esta clase se crea al personaje de ProfeBenji, esta clase representa al profesor este profe reacciona a las decisiones que toma el jugador 
// Creado por: Oscar Alexander Vilchis Soto (A01713207)
// Creado el 20/05/2025
// Modificado el 28/05/2025 Para el tercer avance igual que a la clase Jugado, se añadió el método `reaccionar()` como sobrescritura  del método virtual en la clase base "Personaje"

#ifndef PROFEBENJI_H
#define PROFEBENJI_H

#include "Jugador.h"
#include <iostream>
using namespace std;

// Clase ProfeBenji: representa al profe, hereda de Personaje
class ProfeBenji : public Personaje {
private:
    string estadoAnimo;  // Estado de ánimo del profe (según desempeño del jugador)
    string frase;        // Frase del profe según desempeño

public:
    // Constructor: recibe el nombre, inicializa estado y frase
    ProfeBenji(string nombre) : Personaje(nombre), estadoAnimo("Neutral"), frase("chevere :)") {}

    // Método para actualizar estado de ánimo y frase según XP del jugador
    void reaccionar(Jugador& jugador) {
        int xp = jugador.getXp();
        if (xp >= 50) {
            estadoAnimo = "Feliz";
            frase = "chevere, muy bien";
        }
        else if (xp >= 30) {
            estadoAnimo = "Neutral";
            frase = " saca todas las dudas";
        }
        else {
            estadoAnimo = "Molesto";
            frase = "pon atencion .";
        }
    }

    // Devuelve el estado de ánimo
    string getEstadoAnimo() const { return estadoAnimo; }
    // Devuelve la frase
    string getFrase() const { return frase; }

    // Implementa el método virtual puro reaccionar() (muestra mensaje)
    void reaccionar() override {
        cout << "Profe benji esta: " << estadoAnimo << ", " << frase << endl;
    }
};

#endif
