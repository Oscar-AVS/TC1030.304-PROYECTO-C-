// Este es el progrma creado para la clase "Personaje.h" En esta clase se crea a un Personaje "X" o "Y" esta clase e sla padre de distintas clases que vienenen en el juego, en esta clase solo se  guarda el nombre y como se menciono es  base para personajes como el jugador o el profesor. 
// Creado por: Oscar Alexander Vilchis Soto (A01713207)
// Creado el 20/05/2025
// Modificado el 28/05/2025 Para el tercer avance se incluyó el polimorfismo agregando  un método virtual `reaccionar()`, de igual manera se añade destructor para que se pueda liberar memoria eliminandno objetos  


#ifndef PERSONAJE_H
#define PERSONAJE_H

#include <string>                    
#include <iostream>                  
using namespace std;                 

// Clase base abstracta para cualquier personaje en el juego
class Personaje {
protected:                               // Miembros protegidos (herencia)
    string nombre;                       // Nombre del personaje
    int amistadBecario;                  // Nivel de amistad con el becario

public:                                  // Miembros públicos
    // Constructor: inicializa el nombre y el nivel de amistad con el becario en 0
    Personaje(string nombre) : nombre(nombre), amistadBecario(0) {}

    // Destructor virtual: permite destrucción correcta de objetos derivados
    virtual ~Personaje() {}

    string getNombre() const { return nombre; }

    // Cambia el nombre del personaje
    void setNombre(const string& nuevoNombre) { nombre = nuevoNombre; }

    // Suma (o resta si es negativo) al nivel de amistad con el becario
    void mejorarRelacionBecario(int cantidad) { amistadBecario += cantidad; }

    // Consulta el nivel de amistad con el becario
    int getAmistadBecario() const { return amistadBecario; }

    // Método virtual puro (abstracto): obliga a las hijas a implementarlo
    virtual void reaccionar() = 0;
};

#endif                                 
