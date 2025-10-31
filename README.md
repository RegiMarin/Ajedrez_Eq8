# Tablero de Ajedrez Automático
Este proyecto trata sobre un circuito que simula un tablero de ajedrez pero la diferencia que tiene con los convencionales es que este se juega de manera autónoma, por lo tanto resielve la problematica de que ficha mover y a donde moverla.
Para poder utilizar

## Requisitos e Instalación

Como requisito principal necesitaremos una computadora, ya que todo lo que necesitamos está ahí. También necesitaremos la aplicación de proteus, ya que realizamos la simulación del circuito ahí. Y por último, necesitamos el archivo .hex, que es el archivo con el código que nuestra tarjeta ARDUINO necesita para funcionar.

Clonar el repo
git clone https://github.com/RegiMarin/Ajedrez_Eq8.git
cd Ajedrez_Eq8

Instalar dependencias 
Abrimos hardware//proteus/Ajedrez.pdsprj y aseguramos que el bloque Arduino esta vinculado al AjedrezFinal.ino.hex del sketch.

## Uso

1.- Instalamos el programa de Proteus.
2.- Abrimos el archivo "Ajedrez.pdsprj".
3.- Nos aseguramos que el circuito esté conectado correctamente.
4.- Asegurarnos que la tarjeta de ARDUINO tenga cargado el archivo "AjedrezFinal.ino.hex".
5.- Damos clic al botón "Start", para iniciar con nuestra simulación.
6.- Automáticamente, la simulación iniciará prendiendo las luces LEDs con todas las fichas acomodadas y posteriormente iniciará el juego de ajedrez programada hasta que este termine.

## Estructura del Proyecto

Hardware
•	Microcontrolador: Arduino UNO (ATmega328P)
•	Controlador LED: MAX7219
•	Display: Matriz LED 8x8 cátodo común
•	Comunicación: Protocolo SPI (3-wire)


## FAQ

#### ¿Puedo usar otro microcontrolador?

Sí, pero debe tener soporte SPI

#### ¿Por qué no se encienden los LEDs?

Verifica las conexiones de VCC y GND, y que el MAX7219 esté correctamente vinculado al Arduino.

#### ¿Se puede cambiar el patrón mostrado?

Sí, modificando las coordenadas dentro de setup() o creando nuevas funciones de patrón.

#### ¿El proyecto funciona físicamente?

Sí, puede montarse con componentes reales

