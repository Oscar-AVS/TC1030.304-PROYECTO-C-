// Este es el progrma creado para la clase "ProfeBenji.h" En esta clase se crea al personaje de ProfeBenji, esta clase representa al profesor este profe reacciona a las decisiones que toma el jugador 
// Creado por: Oscar Alexander Vilchis Soto (A01713207)
// Creado el 20/05/2025


#ifndef PROFEBENJI_H
#define PROFEBENJI_H


#include "Jugador.h"

class ProfeBenji : public Personaje { // Define la clase ProfeBenji  que hereda de la clase Personaje

private: // Método de acceso en la que nadie puede acceder al  estado de ánimo del profesor y su frase 
    string estadoAnimo;

    string frase;

public:
    ProfeBenji(string nombre) : Personaje(nombre), estadoAnimo("Neutral"), frase("chevere :)") {}

  
        int xp = jugador.getXp();

        if (xp >= 30) {
            estadoAnimo = "Feliz";
            frase = "chevere ";
        }
        else if (xp >= 10) {
            estadoAnimo = "Neutral";
            frase = "Vas bien, saca todas las dudas ";
        }
        else {
            estadoAnimo = "Molesto";
            frase = "pon atencion .";
        }
    }

    string getEstadoAnimo() const { return estadoAnimo; }

    string getFrase() const { return frase; }
};

// Fin del "include guard", asegura que este archivo no se incluya más de una vez.
#endif
