#include <iostream>
#include <cmath>
#include "Shape.h"

// Clase Circulo, hereda de FiguraBidimensional
class Circle : public TwoDimensionalShape {
private:
    double radius; // radio
    const double PI = 3.14159265358979323846;
public:
    Circle(double r) : radius(r) {}

    void draw() const override {
        std::cout << "Dibujando un círculo de radio " << radius << std::endl;
    }

    double area() const override {
        // M_PI es una constante para Pi definida en <cmath> o similar
        return PI * radius * radius;
    }
};