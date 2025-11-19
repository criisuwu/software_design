// Ejemplo de uso
#include <iostream>
#include "Square.h"
#include "Circle.h"
#include "Triangle.h"

int main() {
    // Cuadrado c(5);
    Square s(5);
    // Circulo ci(3);
    Circle c(3);
    // Triangulo t(4, 6);
    Triangle t(4, 6);

    // Dibujar y mostrar área del cuadrado
    s.draw();
    std::cout << "Área: " << s.area() << std::endl;

    // Dibujar y mostrar área del círculo
    c.draw();
    std::cout << "Área: " << c.area() << std::endl;

    // Dibujar y mostrar área del triángulo
    t.draw();
    std::cout << "Área: " << t.area() << std::endl;

    return 0;
}