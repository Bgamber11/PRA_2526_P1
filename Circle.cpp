#include <iostream>
#include <cmath>
#include "Circle.h"

// Constructor por defecto: Círculo rojo, centro (0,0), radio 0 (o 1)
Circle::Circle() : Shape() { // Llama al constructor por defecto de Shape (color="red")
    center = Point2D(0, 0);
    radius = 1.0;
}

// Constructor paramétrico
Circle::Circle(std::string color, Point2D center, double radius) : Shape(color) {
    this->center = center;
    this->radius = radius;
}

Point2D Circle::get_center() const {
    return center;
}

void Circle::set_center(Point2D p) {
    center = p;
}

double Circle::get_radius() const {
    return radius;
}

void Circle::set_radius(double r) {
    radius = r;
}

// Área = pi * r^2
double Circle::area() const {
    return M_PI * std::pow(radius, 2);
}

// Perímetro (Circunferencia) = 2 * pi * r
double Circle::perimeter() const {
    return 2.0 * M_PI * radius;
}

// Traslación: Movemos el centro
void Circle::translate(double incX, double incY) {
    center.x += incX;
    center.y += incY;
}

// Imprimir información
// Formato típico: [Circle: color=..., center=(x,y), radius=...]
void Circle::print() {
    std::cout << "[Circle: color=" << get_color() 
              << "; center=" << center 
              << "; radius=" << radius << "]" << std::endl;
}

// Operador << para imprimir directamente
std::ostream& operator<<(std::ostream &out, const Circle &c) {
    out << "[Circle: color=" << c.get_color() 
        << "; center=" << c.center 
        << "; radius=" << c.radius << "]";
    return out;
}
