#include "Square.h"
#include <iostream>
#include <stdexcept>

// Validación: Todos los lados deben ser iguales
// d(v0,v1) == d(v1,v2) == d(v2,v3) == d(v3,v0)
bool Square::check(Point2D* vertices) {
    double d01 = Point2D::distance(vertices[0], vertices[1]);
    double d12 = Point2D::distance(vertices[1], vertices[2]);
    double d23 = Point2D::distance(vertices[2], vertices[3]);
    double d30 = Point2D::distance(vertices[3], vertices[0]);

    // Comprobamos que todos los lados sean iguales entre sí
    // (Aceptando pequeña tolerancia si fuera float, pero con double suele bastar ==)
    return (d01 == d12 && d12 == d23 && d23 == d30);
}

// Constructor por defecto
// Crea un cuadrado centrado en (0,0) con lados de longitud 2
// v0=(-1,1), v1=(1,1), v2=(1,-1), v3=(-1,-1)
Square::Square() : Rectangle() { // Llama al constructor de Rectangle (reserva memoria)
    // Sobrescribimos los valores por defecto del rectángulo
    vs[0] = Point2D(-1, 1);
    vs[1] = Point2D(1, 1);
    vs[2] = Point2D(1, -1);
    vs[3] = Point2D(-1, -1);
}

// Constructor con parámetros
Square::Square(std::string color, Point2D* vertices) : Rectangle(color, vertices) {
    // Nota: Llamamos al constructor de Rectangle, que ya valida si es Rectángulo.
    // PERO aquí debemos validar adicionalmente si es CUADRADO.
    // Si Rectangle acepta pero check(Square) falla, debemos lanzar excepción.
    // Sin embargo, Rectangle hace una copia de vertices a 'vs'. 
    // Si falla el check de cuadrado, el constructor de Rectangle ya habrá reservado memoria.
    // Para ser estrictos y seguros, validamos ANTES o lanzamos excepción después.
    
    if (!check(vertices)) {
        // Al lanzar excepción en el constructor, el destructor de la parte base (Rectangle)
        // se llamará automáticamente, liberando 'vs' si ya se había reservado.
        throw std::invalid_argument("Provided vertices do not build a valid square!");
    }
}

// Set Vertices (Override)
void Square::set_vertices(Point2D* vertices) {
    if (!check(vertices)) {
        throw std::invalid_argument("Provided vertices do not build a valid square!");
    }
    // Si es válido, llamamos al método del padre para copiar los datos
    Rectangle::set_vertices(vertices);
}

// Print (Override)
void Square::print() {
    std::cout << *this << std::endl;
}

// Operador global <<
std::ostream& operator<<(std::ostream &out, const Square &square) {
    out << "[Square: color = " << square.color 
        << "; v0 = " << square.vs[0]
        << "; v1 = " << square.vs[1]
        << "; v2 = " << square.vs[2]
        << "; v3 = " << square.vs[3] << "]";
    return out;
}
