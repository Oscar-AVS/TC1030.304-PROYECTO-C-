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
    cout << " Bienvenido al juego interactivo 'POV: Eres ITC' " << endl;
    cout << "Para poder empezar, di tu nombre inge.  ";
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
    cout << "\n Resumen final para " << jugador.getNombre() << ":\n";
    cout << "XP acumulado: " << jugador.getXp() << "\n";
    cout << "Resultado: " << jugador.getResultadoFinal() << "\n";

    profe.reaccion(jugador);
    cout << " Profe Benji dice: \"" << profe.getFrase() << "\"\n";
    cout << " Animo: " << profe.getEstadoAnimo() << "\n";

    cout << "\nGracias por jugar " << endl;
    return 0;
}





