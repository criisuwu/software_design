# Definición del compilador
CC = g++
# Opciones de compilación: -Wall (todas las advertencias) y -g (debug)
CFLAGS = -Wall -g
# La cabecera <cmath> (que usamos para PI) a menudo requiere el flag -lm
LDLIBS = -lm

# Define el prefijo de receta (el carácter que indica una acción)
.RECIPEPREFIX = >

# ==================================
# Target principal: Construye el ejecutable 'main' (el ejecutable que crea main.cpp)
# La dependencia es solo main.o, ya que todo el código está en el .h y main.cpp
# ==================================
main: main.o
>$(CC) $(CFLAGS) -o main main.o $(LDLIBS)

# ==================================
# Target de objeto: Compila main.cpp para crear main.o
# main.o depende de sí mismo y de todas las cabeceras de clases que utiliza.
# ==================================
main.o: main.cpp Shape.h Square.h Circle.h Triangle.h
>$(CC) $(CFLAGS) -c main.cpp
 
# ==================================
# Target para limpiar: Remueve archivos de objeto (*.o) y el ejecutable 'main'
# ==================================
clean:
>rm -f *.o main