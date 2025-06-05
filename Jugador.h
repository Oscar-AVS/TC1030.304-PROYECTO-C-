// Este es el progrma creado para la clase "Jugador.h" En esta clase se crea a un jugador que es la representación del usuario, Hereda atributos de Personaje y se delcara sus puntos de experencia (XP) y se calcula el resultado final del juego, es decir si aprobó o no "X" o "Y" esta clase e sla padre de distintas clases que vienenen en el juego, en esta clase solo se  guarda el nombre y como se menciono es  base para personajes como el jugador o el profesor. 
// Creado por: Oscar Alexander Vilchis Soto (A01713207) 
// Creado el 20/05/2025
// Modificado el 28/05/2025 Para este tercer avance de manera que pudiera integrar polimorfismo a mi proyecto, se  sobrescribió el método `reaccionar()` de la clase padre  para mostrar información personalizada del jugador ( un breve mensaje del jugador al finalizar el juego)


#ifndef JUGADOR_H
#define JUGADOR_H

#include "Personaje.h"   // Incluye la definición de la clase base

// Clase Jugador: hereda de Personaje y representa al usuario que juega
class Jugador : public Personaje {
private:
    int xp;                // Puntos de experiencia acumulados
    string resultadoFinal; // Mensaje final sobre el desempeño

public:
    // Constructor: recibe el nombre y llama al constructor base, inicia XP en 0 y resultado vacío
    Jugador(string nombre) : Personaje(nombre), xp(0), resultadoFinal("") {}

    // Suma cantidad a XP
    void ganarXp(int cantidad) { xp += cantidad; }

    // Resta cantidad a XP; si queda negativo, lo pone en 0
    void perderXp(int cantidad) { xp -= cantidad; if (xp < 0) xp = 0; }

    // Calcula el resultado final dependiendo del XP obtenido
    void asignarResultado() {
        if (xp >= 50) resultadoFinal = "Super, Te fue muy bien sacaste 10";
        else if (xp >= 30) resultadoFinal = "Bien pero puedes hacerlo mejor, pasaste con 8";
        else resultadoFinal = "mal, mejor suerte  a la proxima reprobaste con 6.9";
    }

    // Devuelve el XP actual
    int getXp() const { return xp; }

    // Devuelve el resultado final en texto
    string getResultadoFinal() const { return resultadoFinal; }

    // Permite establecer manualmente el resultado final
    void setResultadoFinal(const string& resultado) { resultadoFinal = resultado; }

    // Implementa el método virtual puro reaccionar() (muestra el XP)
    void reaccionar() override {
        cout << "Total :  " << xp << "XP"<< endl;
    }
};

#endif
