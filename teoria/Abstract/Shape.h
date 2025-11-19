// Clase abstracta Figura
#ifndef SHAPE_H
#define SHAPE_H
class Shape {
public:
    // Método abstracto para dibujar la figura
    virtual void draw() const = 0; 
    // Método abstracto para calcular el área
    virtual double area() const = 0;  
    // Destructor virtual
    virtual ~Shape() {}              
};
#endif

#ifndef TWODIMENSIONALSHAPE_H
#define TWODIMENSIONALSHAPE_H
// Clase abstracta FiguraBidimensional, hereda de Figura
class TwoDimensionalShape : public Shape {
public:
    // Se puede redefinir si se desea
    virtual void draw() const = 0; 
    // Se puede redefinir si se desea
    virtual double area() const = 0;  
    virtual ~TwoDimensionalShape() {}
};
#endif