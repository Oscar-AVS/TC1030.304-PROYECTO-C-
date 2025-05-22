# TC1030.304-PROYECTO-C++ 

Proyecto: Juego interactivo: POV eres ITC

Contexto, problemática y objetivo.
Hola, bienvenidos a este juego. 

Este juego es un proyecto en el que mediante entradas y salidas de texto, entre el usuario  y el programa, se genera una historia interactiva  que representa el día a día de un estudiante de Ingeniería en Tecnologías Computacionales (ITC) en el Tecnológico de Monterrey. El jugador tomará decisiones durante las diferentes  situaciones cotidianas que se plantean en cada escenario. Cada decisión tendrá consecuencias en su experiencia (XP), la percepción del profesor y su calificación final. 
Aunque si bien no es un proyecto que busqué solucionar un problema, es la primera vez que me motivó a hacer un juego como proyecto, por lo tanto decidí realizarlo de algo con lo que convivo día a día. 

Como ya mencioné, este juego no busca resolver algún problema, sin embargo se intenta dar una perspectiva inmersiva al usuario de qué tipo de acciones pueden o ser positivas para el usuario otorgando aprendizajes y cuáles no. 

Funcionalidad y restricciones. 

Este proyecto se pensó para que existieran 7 clases, 3 dedicadas a los personajes dentro del juego en donde 1 es la clase "madre" y 2 son su heredadas, donde 1 de ellas es la clase de Jugador donde el usuario ingresa su nombre y decide el rumbo de la historia así como acumula puntos. La otra clase es la del profesor que es en este escenario como un NPC que aprueba o desaprueba las acciones del jugador sumándole o restándole los puntos de experiencia y cambiando su estado de humor. 

Otra clase es la que administra y lleva el conteo de los puntos de experiencia que acumula el usuario así como su progreso dentro del juego. Las últimas clases son exclusivas del desarrollo de la historia en donde se tienen diferentes capítulos  y cada uno a su vez tiene una escena principal y dependiendo de cada decisión que el usuario tome en estas escenas se le irá redirigiendo a las escenas secundarias. 

Ahora hablando de errores, me parece que si el código se implementa bien, el  principal error que yo pude determinar es: 
* Que el jugador seleccione opciones inválidas en las escenas
  Ya que de esta manera, realmente el programa se estancara y marcaría error. 




En el segundo avance se agregaron las clases para el funcionamiento del juego y un main para que se pueda correr aunque sea este pedazo del juego, si bien la historia no está completa se le da a todo aquel que llegue a este repositorio una idea de como es el juego, en donde se le presenta al usuario una situación y el escoge que hace para ir acumulando XP y llegar a un resultado donde se le evalua por el personaje ProfeBenji. De igual manera se hacen correcciones en el readme que se mencionaron en la primera entrega y de igual manera s emodifica el UML para agregar setters y getters que faltaron en el primer avance y las correcciones que se dieron en la retro del primer avance. 

:)


