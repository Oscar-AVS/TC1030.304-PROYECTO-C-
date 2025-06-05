// Este es el programa creado para la clase "EscenaPrincipal.h" en esta clase se representa las distintas escenas principales del juego donde el jugador toma decisiones que afectan su XP y pueden activar escenas secundarias.
// Creado por: Oscar Alexander Vilchis Soto (A01713207)
// Creado el 20/05/2025
// Modificado el 28/05/2025: Para este tercer avance, no se realizó ningún cambio 

#ifndef ESCENAPRINCIPAL_H
#define ESCENAPRINCIPAL_H

#include <string>
#include <iostream>
#include "Jugador.h"
#include "EscenaSecundaria.h"
using namespace std;

// Clase para escenas principales
class EscenaPrincipal {
private:
    string descripcion;                         // Descripción de la escena
    static const int MAX_OPCIONES = 5;          // Máximo de opciones posibles
    string opciones[MAX_OPCIONES];              // Texto de cada opción
    int consecuenciasXp[MAX_OPCIONES];          // XP que da cada opción
    int consecuenciasBecario[MAX_OPCIONES];     // Amistad con becario por opción
    EscenaSecundaria* escenasSecundarias[MAX_OPCIONES]; // Punteros a escenas secundarias (si aplica)
    int numOpciones;                            // Contador de opciones agregadas

public:
    // Constructor que recibe un id para inicializar cada escena automáticamente
    EscenaPrincipal(int id = 0) : numOpciones(0) {
        for (int i = 0; i < MAX_OPCIONES; ++i)
            escenasSecundarias[i] = nullptr;

        if (id == 1) {
            descripcion = "Llegas al salon 4205, no hay nadie mas que el profe, ¿que eliges?";
            agregarOpcion("Entras lo saludas y te preparas tu material", 10, 0);
            agregarOpcion("Entras y dejas tus cosas y vas por un snack", 5, 0);
            agregarOpcion("Decides esperar a tus amigos", 0, 0);
        } else if (id == 2) {
            descripcion = "En la clase, ves el tema de 'Herencia' pero por andar chismeando con tu amiga no entiendes todo ¿que haces?";
            agregarOpcion("Le pides al profe si te ayuda al final de clase", 5, 0);
            agregarOpcion("Intentas entender lo que puedas con ayuda del material de apoyo", 15, 0, new EscenaSecundaria(1));
            agregarOpcion("Sigues chismeando", -10, 0);
        } else if (id == 3) {
            descripcion = "En el quiz semanal, decides sacar tus notas pero están incompletas y no te sirven de mucho ¿que haces?";
            agregarOpcion("Intentas copiarle a tu compañero a tu derecha, pero no lo consigues", -5, 0);
            agregarOpcion("Haces tu mayor esfuerzo para acordarte del tema", 10, 0);
            agregarOpcion("Decides rendirte", -5, 0, new EscenaSecundaria(2));
        } else if (id == 4) {
            descripcion = "Se te olvida realizar el autoestudio para la siguiente clase, ¿que haces?";
            agregarOpcion("Estas atento a las preguntas de tus companeros", 10, 1, new EscenaSecundaria(3));
            agregarOpcion("Te quedas callado", -5, 0);
            agregarOpcion("Intentas anotar lo más que puedes para leerlo después", 3, 0);
        } else if (id == 5) {
            descripcion = "Estás avanzando en tu proyecto y tu segundo avance no te va tan bien, ¿que haces?";
            agregarOpcion("Le pides ayuda a tu becario de confianza", 10, 2, new EscenaSecundaria(4));
            agregarOpcion("Haces trampa", 3, 0);
            agregarOpcion("Olvidas corregirlo hasta el ultimo dia", 5, 0);
        } else if (id == 6) {
            descripcion = "El profe Benji explica toda la dinamica de las ultimas clases pero estas chismeando otra vez  ¿que haces?";
            agregarOpcion("Buscas a tus companeros para que te digan que  dijo el profe ", 10, 0, new EscenaSecundaria(5));
            agregarOpcion("Le preguntas al profe si lo repite", 0, 0);
        } else if (id == 7) {
            descripcion = "En tus examenes  semanales no te fue tan bien, dependes del examen final, ¿como te preparas?";
            agregarOpcion("Organizas una sesion de estudio en grupo", 10, 1);
            agregarOpcion("Decides estudiar solo en la madrugada", 5, 0);
            agregarOpcion("No estudias ", -10, 0);
        } else if (id == 8) {
            descripcion = "Llegas al examen y ves que es muy largo, son todos los temas. ¿como reaccionas?";
            agregarOpcion("Respiras hondo y aplicas todo lo que estudiaste", 10, 0);
            agregarOpcion("Das lo mejor pero te equivocas en ciertas cosas", 7, 0);
            agregarOpcion("No recuerdas mucho y usas chat, te dan una FIA", -50, 0);
        }
    }

    // Destructor: libera las escenas secundarias creadas dinámicamente
    ~EscenaPrincipal() {
        for (int i = 0; i < numOpciones; ++i)
            if (escenasSecundarias[i] != nullptr) delete escenasSecundarias[i];
    }

    // Agrega una opción, con posibles consecuencias y escena secundaria
    void agregarOpcion(string opcion, int xp, int becarioDelta = 0, EscenaSecundaria* secundaria = nullptr) {
        if (numOpciones < MAX_OPCIONES) {
            opciones[numOpciones] = opcion;
            consecuenciasXp[numOpciones] = xp;
            consecuenciasBecario[numOpciones] = becarioDelta;
            escenasSecundarias[numOpciones] = secundaria;
            numOpciones++;
        }
    }

    // Muestra la escena y las opciones al usuario
    void mostrar() {
        cout << "\n" << descripcion << endl;
        for (int i = 0; i < numOpciones; ++i)
            cout << i + 1 << ". " << opciones[i] << endl;
    }

    // Procesa la elección del usuario
    void elegirOpcion(int opcion, Jugador& jugador) {
        if (opcion >= 1 && opcion <= numOpciones) {
            int xp = consecuenciasXp[opcion - 1];
            if (xp >= 0) jugador.ganarXp(xp);
            else jugador.perderXp(-xp);

            jugador.mejorarRelacionBecario(consecuenciasBecario[opcion - 1]);

            EscenaSecundaria* secundaria = escenasSecundarias[opcion - 1];
            if (secundaria != nullptr) {
                secundaria->ejecutar(jugador);
            }
        } else {
            cout << "Lo siento, intenta otra vez :( .\n";
        }
    }
};

#endif
