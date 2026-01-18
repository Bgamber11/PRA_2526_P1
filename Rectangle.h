#ifndef RECTANGLE_H
#define RECTANGLE_H

#include <stdexcept>
#include <iostream>
#include "Shape.h"
#include "Point2D.h"

class Rectangle : public Shape {
    protected:
        // Array de vértices
        Point2D* vs;

        // Método privado para validar si los vértices forman un rectángulo
        static bool check(Point2D* vertices);

    public:
        // Constante de número de vértices
        static const int N_VERTICES = 4;

        // Constructores
        Rectangle();
        Rectangle(std::string color, Point2D* vertices);
        
        // Constructor de copia
        Rectangle(const Rectangle &r);

        // Destructor
        ~Rectangle();

        // Getters y operadores
        Point2D get_vertex(int ind) const;
        Point2D operator[](int ind) const;

        // Setters
        virtual void set_vertices(Point2D* vertices);

        // Operador de asignación
        Rectangle& operator=(const Rectangle &r);

        // Métodos heredados de Shape
        double area() const override;
        double perimeter() const override;
        void translate(double incX, double incY) override;
        void print() override;

        // Operador global de impresión
        friend std::ostream& operator<<(std::ostream &out, const Rectangle &r);
};

#endif
