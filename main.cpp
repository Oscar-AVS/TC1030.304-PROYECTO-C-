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
using namespace std;

int main() {
    string nombre;
    cout << "Bienvenido al juego interactivo 'POV: Eres ITC'" << endl;
    cout << "Para poder empezar, di tu nombre inge: ";
    getline(cin, nombre);

    Jugador jugador(nombre);
    ProfeBenji profe("Benji");
    RegistroXP registro(&jugador);

    Capitulo capitulo1(1, "Primer dia ");
    vector<EscenaPrincipal*> escenas = EscenaPrincipal::cargarEscenas();

    for (auto escena : escenas)
        capitulo1.agregarEscena(escena);

    cout << "\nCapitulo 1 " << capitulo1.getTitulo() << "\n";
    capitulo1.ejecutar(jugador);

    jugador.asignarResultado();
    cout << "\nResumen final para " << jugador.getNombre() << ":\n";
    cout << "XP acumulado: " << jugador.getXp() << "\n";
    cout << "Resultado: " << jugador.getResultadoFinal() << "\n";

    profe.reaccionar(jugador);

    // aqui se implementa el polimorifsmo, se usan punteros a la clase padre "personaje" para llamar al método
    Personaje* pJugador = &jugador;
    Personaje* pProfe = &profe;

    pJugador->reaccionar();
    pProfe->reaccionar();

    cout << "\nGracias por jugar " << endl;
    return 0;
}
