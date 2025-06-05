// Este es el programa principal "main.cpp" del juego interactivo "POV: Eres ITC" Esta es la clase en donde sucede cada parte d ela historia,  se crea el jugador, se ejecutan las escenas y se muestra el resultado final con base en sus decisiones
// Creado por: Oscar Alexander Vilchis Soto (A01713207)
// Creado el 20/05/2025
// Modificado el 28/05/2025 Para este tercer avance, se aplicó polimorfismo, usamos punteror hacia la clase padre "personaje"  donde se llama al  método virtual `reaccionar()` que es sobreescrito en las clase  jugador y profebenji

#include <iostream>
#include <string>
#include "Jugador.h"
#include "ProfeBenji.h"
#include "RegistroXP.h"
#include "Capitulo.h"
#include "EscenaPrincipal.h"
#include "EscenaSecundaria.h"
using namespace std;

int main() {
    string nombre;
    cout << "Bienvenido al juego interactivo 'POV: Eres ITC. \nLo que decidas afectara en tu caliicacion final, asi que escoge bien \ny en el camino asegurate de caerle bien al profe benji" << endl;
    cout << "Para poder empezar, di tu nombre inge: ";
    getline(cin, nombre);

    // Se crea el jugador y el profe Benji
    Jugador jugador(nombre);
    ProfeBenji profe("Benji");
    RegistroXP registro(&jugador);

    // CAPÍTULO 1
    Capitulo* capitulo1 = new Capitulo(1, "Semana 1");
    capitulo1->agregarEscena(new EscenaPrincipal(1)); // Escena 1
    capitulo1->agregarEscena(new EscenaPrincipal(2)); // Escena 2
    capitulo1->agregarEscena(new EscenaPrincipal(3)); // Escena 3
    cout << "\nCapitulo 1: " << capitulo1->getTitulo() << "\n";
    capitulo1->ejecutar(jugador);

    // CAPÍTULO 2
    Capitulo* capitulo2 = new Capitulo(2, "Semanas 2 y 3");
    capitulo2->agregarEscena(new EscenaPrincipal(4)); // Escena 4
    capitulo2->agregarEscena(new EscenaPrincipal(5)); // Escena 5
    cout << "\nCapitulo 2: " << capitulo2->getTitulo() << "\n";
    capitulo2->ejecutar(jugador);

    // CAPÍTULO 3
    Capitulo* capitulo3 = new Capitulo(3, "Semana 4 y 5");
    capitulo3->agregarEscena(new EscenaPrincipal(6)); // Escena 6
    capitulo3->agregarEscena(new EscenaPrincipal(7)); // Escena 7
    capitulo3->agregarEscena(new EscenaPrincipal(8)); // Escena 8
    cout << "\nCapitulo 3: " << capitulo3->getTitulo() << "\n";
    capitulo3->ejecutar(jugador);

    // BONUS: Si la relación con el becario fue buena (+4), gana 10 XP extra
    if (jugador.getAmistadBecario() >= 4) {
        cout << "\nTu amistad con el becario te ayuda, ganas 10XP extra.\n";
        jugador.ganarXp(10);
    }

    jugador.asignarResultado();
    cout << "\nInge  " << jugador.getNombre() << ":\n";
    cout << "En esta meatira te fue:  " << jugador.getResultadoFinal() << "\n";

    profe.reaccionar(jugador);

// aqui se implementa el polimorifsmo, se usan punteros a la clase padre "personaje" para llamar al métod Personaje* pJugador = &jugador;    Personaje* pJugador = &jugador;
    Personaje* pProfe = &profe;

    pJugador->reaccionar();
    pProfe->reaccionar();

    cout << "\nGracias por jugar " << endl;

    delete capitulo1;
    delete capitulo2;
    delete capitulo3;
    return 0;
}
