#include <iostream>
#include <cmath>
#include "Shape.h"

// Clase Cuadrado, hereda de FiguraBidimensional
class Square : public TwoDimensionalShape {
private:
    double side; // lado
public:
    Square(double l) : side(l) {}
    
    void draw() const override {
        std::cout << "Dibujando un cuadrado de lado " << side << std::endl;
    }

    double area() const override {
        return side * side;
    }
};