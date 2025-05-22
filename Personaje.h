// Este es el progrma creado para la clase "Personaje.h" En esta clase se crea a un Personaje "X" o "Y" esta clase e sla padre de distintas clases que vienenen en el juego, en esta clase solo se  guarda el nombre y como se menciono es  base para personajes como el jugador o el profesor. 
// Creado por: Oscar Alexander Vilchis Soto (A01713207)
// Creado el 20/05/2025


#ifndef PERSONAJE_H
#define PERSONAJE_H

#include <string>
using namespace std;

class Personaje {
protected: // Método de acceso que permite a las clases hijas (jugador y profebenji) acceder a estos atributos de manera directa.
    string nombre; // Atributo que guarda el nombre ingresado del usuario (personaje)

public: 
    Personaje(string nombre) : nombre(nombre) {} // Este es el constructor que recibe el nombre como su parametro y lo guardan en el atributo mencionado

    string getNombre() const { return nombre; } // getter que devuelve el nombre se utiliza const para indicar que no se puede modificar el nombre
    void setNombre(const string& nuevoNombre) { nombre = nuevoNombre; } // setter que cambia el nombre 
};

#endif
