// Este es el programa creado para la clase "EscenaSecundaria.h". Define las  escenas secundarias que se activan a la par de  ciertas decisiones del jugador
// Creado por: Oscar Alexander Vilchis Soto (A01713207)
// Creado el 20/05/2025
// Modificado el 28/05/2025: De igual manera, en esta clase no se realizaron cambios en este tercer avance 

#ifndef ESCENASECUNDARIA_H
#define ESCENASECUNDARIA_H

#include <string>
#include <iostream>
#include "Jugador.h"
using namespace std;

// Clase para escenas secundarias
class EscenaSecundaria {
private:
    string descripcion;         // Descripción de la escena secundaria
    string opciones[2];         // Máximo dos opciones (por simplicidad)
    int consecuenciasXp[2];     // Consecuencia en XP de cada opción
    int consecuenciasBecario[2];// Consecuencia en amistad con becario
    int numOpciones;            // Número real de opciones

public:
    // Constructor por default: define las opciones directamente aquí
    EscenaSecundaria(int id = 0) : numOpciones(0) {
        if (id == 1) {
            descripcion = "Consultas el material de estudio y vas con un becario, escoge:";
            agregarOpcion("Te haces amigo del becario: Haces un contacto que te ayuda :D", 15, 2);
            agregarOpcion("Solo vas una vez con el y decides no ir: De cualquier manera resolviste dudas de ese tema", 5, 1);
        } else if (id == 2) {
            descripcion = "No te fue bien en el examen semanal pero buscas opciones:";
            agregarOpcion("Te vas preparando por tu cuenta para el examen final y remontar", 5, 0);
            agregarOpcion("Te enfocas en tu proyecto pero descuidas los exámenes porque valen menos en la calificación final", 3, 0);
        } else if (id == 3) {
            descripcion = "Te empiezas a llevar con gente que participa y está atenta a clase, escoge:";
            agregarOpcion("Aprendes de tus compañeros y te juntas más con ellos", 15, 2);
            agregarOpcion("Decides juntarte por un tiempo pero después te ocupas con otras cosas", 5, 0);
        } else if (id == 4) {
            descripcion = "El becario te da buenos consejos para tu proyecto y examen, escoge:";
            agregarOpcion("Lo tomas en consideración, tienes prácticamente un 75 en tu proyecto asegurado", 5, 1);
            agregarOpcion("Implementas los consejos pero esperas la revisión del profe, el profe ve ciertos errores y te ayuda a corregirlos", 20, 0);
        } else if (id == 5) {
            descripcion = "Descubres que tienes que prepararte para el examen, escoge:";
            agregarOpcion("Como ya tienes buena relación con tu becario, te ayuda", 5, 2);
            agregarOpcion("Buscas videos y estudias con tus compañeros", 5, 0);
        }
    }

    // Agrega una opción y sus consecuencias (sólo si hay espacio)
    void agregarOpcion(string opcion, int xp, int becarioDelta = 0) {
        if (numOpciones < 2) {
            opciones[numOpciones] = opcion;
            consecuenciasXp[numOpciones] = xp;
            consecuenciasBecario[numOpciones] = becarioDelta;
            numOpciones++;
        }
    }

    void ejecutar(Jugador& jugador) {
        cout << "\nEscena secundaria: " << descripcion << endl;
        for (int i = 0; i < numOpciones; ++i)
            cout << i + 1 << ". " << opciones[i] << endl;
        int eleccion;
        cout << "Elige: ";
        cin >> eleccion;
        if (eleccion >= 1 && eleccion <= numOpciones) {
            if (consecuenciasXp[eleccion-1] >= 0) jugador.ganarXp(consecuenciasXp[eleccion-1]);
            else jugador.perderXp(-consecuenciasXp[eleccion-1]);
            jugador.mejorarRelacionBecario(consecuenciasBecario[eleccion-1]);
        }
    }
};

#endif
