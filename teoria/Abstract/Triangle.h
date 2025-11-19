#include <iostream>
#include <cmath>
#include "Shape.h"

class Triangle : public TwoDimensionalShape {
private:
    double base, height; // base, altura
public:
    Triangle(double b, double h) : base(b), height(h) {}

    void draw() const override {
        std::cout << "Dibujando un triángulo de base " << base << " y altura " << height << std::endl;
    }

    double area() const override {
        return (base * height) / 2.0;
    }
};