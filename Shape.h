#ifndef SHAPE_H
#define SHAPE_H

#include <string>
#include "Point2D.h" // Incluimos Point2D aquí para que las hijas lo tengan disponible

class Shape {
    protected:
        // Atributo protegido para que las clases hijas puedan acceder si fuera necesario
        std::string color;

    public:
        // Constructores
        Shape(); 
        Shape(std::string color);

        // Destructor virtual (Fundamental en clases base)
        virtual ~Shape() {}

        // Métodos consultores y modificadores
        std::string get_color() const;
        void set_color(std::string c);

        // Métodos virtuales puros (hacen que la clase sea abstracta)
        virtual double area() const = 0;
        virtual double perimeter() const = 0;
        virtual void translate(double incX, double incY) = 0;
        virtual void print() = 0;
};

#endif
