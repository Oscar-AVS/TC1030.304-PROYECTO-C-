// Este es el programa creado para la clase "EscenaPrincipal.h" en esta clase se representa las distintas escenas principales del juego donde el jugador toma decisiones que afectan su XP y pueden activar escenas secundarias.
// Creado por: Oscar Alexander Vilchis Soto (A01713207)
// Creado el 20/05/2025
// Modificado el 28/05/2025: Para este tercer avance, no se realizó ningún cambio 


#ifndef ESCENAPRINCIPAL_H
#define ESCENAPRINCIPAL_H

#include <vector>
#include <string>
#include <iostream>
#include "Jugador.h"
#include "EscenaSecundaria.h"
using namespace std;

class EscenaPrincipal {
private:
    string descripcion;
    vector<string> opciones;
    vector<int> consecuenciasXp;
    vector<EscenaSecundaria*> escenasSecundarias;

public:
    EscenaPrincipal(string desc) : descripcion(desc) {}

    ~EscenaPrincipal() {
        for (auto escena : escenasSecundarias) delete escena;
    }

    void agregarOpcion(string opcion, int xp, EscenaSecundaria* secundaria = nullptr) {
        opciones.push_back(opcion);
        consecuenciasXp.push_back(xp);
        escenasSecundarias.push_back(secundaria);
    }

    void mostrar() {
        cout << "\n" << descripcion << endl;
        for (size_t i = 0; i < opciones.size(); ++i)
            cout << i + 1 << ". " << opciones[i] << endl;
    }

    void elegirOpcion(int opcion, Jugador& jugador) {
        if (opcion >= 1 && opcion <= (int)opciones.size()) {
            int xp = consecuenciasXp[opcion - 1];
            if (xp >= 0) jugador.ganarXp(xp);
            else jugador.perderXp(-xp);

            EscenaSecundaria* secundaria = escenasSecundarias[opcion - 1];
            if (secundaria != nullptr) {
                secundaria->activar();
                secundaria->mostrar();
            }
        } else {
            cout << "lo siento, intenta otra vez :( .\n";
        }
    }

    static vector<EscenaPrincipal*> cargarEscenas() {
        vector<EscenaPrincipal*> escenas;

        EscenaPrincipal* escena1 = new EscenaPrincipal("Escena 1: Llegas al salon 4205, no hay nadie mas que el profe, que eliges?");
        escena1->agregarOpcion("Entras, lo saludas y te preparas tu material", 10,
            new EscenaSecundaria("El profe Benji esta satisfecho "));
        escena1->agregarOpcion("Entras, dejas tus cosas y vas por un snack", 5,
            new EscenaSecundaria("Te preparas para no salir en clase."));
        escena1->agregarOpcion("Decides esperar a tus amigos", 0,
            new EscenaSecundaria("Te quedas igual."));

        EscenaPrincipal* escena2 = new EscenaPrincipal("Escena 2: En clase, por chismear, se te olvida preguntar  que haces?");
        escena2->agregarOpcion("Le pides ayuda al profe al final", 5,
            new EscenaSecundaria("El profe aprecia el esfuerzo."));
        escena2->agregarOpcion("Consultas el material de apoyo", 15,
            new EscenaSecundaria("Buen autoestudio."));
        escena2->agregarOpcion("Sigues chismeando", -10,
            new EscenaSecundaria("tu y tu amiga no aprendieron."));

        EscenaPrincipal* escena3 = new EscenaPrincipal("Escena 3: En el quiz, tus notas no son completas que haces?");
        escena3->agregarOpcion("Intentas copiar, pero fallas", -5,
            new EscenaSecundaria("No sale como esperas "));
        escena3->agregarOpcion("Haces tu mejor esfuerzo", 10,
            new EscenaSecundaria("Recordaste lo importante."));
        escena3->agregarOpcion("Te rindes", -5,
            new EscenaSecundaria("Pudiste haberlo logrado."));

        escenas.push_back(escena1);
        escenas.push_back(escena2);
        escenas.push_back(escena3);
        return escenas;
    }
};

#endif
