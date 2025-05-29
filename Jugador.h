// Este es el progrma creado para la clase "Jugador.h" En esta clase se crea a un jugador que es la representación del usuario, Hereda atributos de Personaje y se delcara sus puntos de experencia (XP) y se calcula el resultado final del juego, es decir si aprobó o no "X" o "Y" esta clase e sla padre de distintas clases que vienenen en el juego, en esta clase solo se  guarda el nombre y como se menciono es  base para personajes como el jugador o el profesor. 
// Creado por: Oscar Alexander Vilchis Soto (A01713207) 
// Creado el 20/05/2025
// Modificado el 28/05/2025 Para este tercer avance de manera que pudiera integrar polimorfismo a mi proyecto, se  sobrescribió el método `reaccionar()` de la clase padre  para mostrar información personalizada del jugador ( un breve mensaje del jugador al finalizar el juego)



#ifndef JUGADOR_H
#define JUGADOR_H

#include "Personaje.h"

class Jugador : public Personaje { //Se establece que es clase hija de Personaje y hereda sus atributos y métodos 
private:
    int xp; // Puntos de experiencia que acumula el juagador 
    string resultadoFinal; // Texto que dice al usuario si aprueba o no

public:
    Jugador(string nombre) : Personaje(nombre), xp(0), resultadoFinal("") {} // se manda llamar el contructor de la clase padre para el nombrey se le asigna el valor de 0 puntos XP al inicar el jeugo

// Métodos que modifican el XP 
    void ganarXp(int cantidad) { xp += cantidad; }
    void perderXp(int cantidad) { xp -= cantidad; if (xp < 0) xp = 0; }

//Métodos que determinan el resultado final con base al valor de XP acumulado
    void asignarResultado() {
        if (xp >= 30) resultadoFinal = "Super, pasaste con 10";
        else if (xp >= 15) resultadoFinal = "Bien pero puedes hacerlo mejor, pasar con 8";
        else resultadoFinal = "Venga, toma la materia otra vez, reprobaste con 6.9";
    }

    int getXp() const { return xp; } // Getter para obtener el valor de xp y regresa un numero sin modificar ningun atributo
    string getResultadoFinal() const { return resultadoFinal; } // Getter que permite ver el texto que arroja el juego dependiendo del resultado
    void setResultadoFinal(const string& resultado) { resultadoFinal = resultado; } // Setter que permite asigar de manera manual el resultado
void reaccionar() override {
        cout << "Mi XP en esta materia fue  "  << xp << endl;
    }
};

#endif
