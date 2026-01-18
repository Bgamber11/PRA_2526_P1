#include "Rectangle.h"
#include <cmath>

// Método privado estático para validar rectángulo
// Comprueba que lados opuestos sean iguales: d(v0,v1)==d(v2,v3) y d(v1,v2)==d(v3,v0)
bool Rectangle::check(Point2D* vertices) {    
    double d01 = Point2D::distance(vertices[0], vertices[1]);
    double d23 = Point2D::distance(vertices[2], vertices[3]);
    double d12 = Point2D::distance(vertices[1], vertices[2]);
    double d30 = Point2D::distance(vertices[3], vertices[0]);

    return (d01 == d23) && (d12 == d30);
}

// Constructor por defecto
Rectangle::Rectangle() : Shape() { // color "red" por defecto
    vs = new Point2D[N_VERTICES];
    vs[0] = Point2D(-1, 0.5);
    vs[1] = Point2D(1, 0.5);
    vs[2] = Point2D(1, -0.5);
    vs[3] = Point2D(-1, -0.5);
}

// Constructor con parámetros
Rectangle::Rectangle(std::string color, Point2D* vertices) : Shape(color) {
    if (!check(vertices)) {
        throw std::invalid_argument("Los vértices no forman un rectángulo válido");
    }
    
    vs = new Point2D[N_VERTICES];
    for (int i = 0; i < N_VERTICES; i++) {
        vs[i] = vertices[i];
    }
}

// Constructor de copia
Rectangle::Rectangle(const Rectangle &r) : Shape(r.color) {
    vs = new Point2D[N_VERTICES];
    for (int i = 0; i < N_VERTICES; i++) {
        vs[i] = r.vs[i];
    }
}

// Destructor
Rectangle::~Rectangle() {
    delete[] vs;
}

// Obtener vértice
Point2D Rectangle::get_vertex(int ind) const {
    if (ind < 0 || ind >= N_VERTICES) {
        throw std::out_of_range("Índice de vértice inválido");
    }
    return vs[ind];
}

// Operador []
Point2D Rectangle::operator[](int ind) const {
    return get_vertex(ind);
}

// Modificar vértices
void Rectangle::set_vertices(Point2D* vertices) {
    if (!check(vertices)) {
        throw std::invalid_argument("Provided vertices do not build a valid rectangle!");
    }
    for (int i = 0; i < N_VERTICES; i++) {
        vs[i] = vertices[i];
    }
}

// Operador de asignación (Deep Copy)
Rectangle& Rectangle::operator=(const Rectangle &r) {
    if (this != &r) {
        // Copiamos atributos de Shape
        this->color = r.color; // color es protected, podemos acceder

        // Copiamos vértices
        for (int i = 0; i < N_VERTICES; i++) {
            vs[i] = r.vs[i];
        }
    }
    return *this;
}

// Área = base * altura
double Rectangle::area() const {
    // Base = distancia(v0, v1)
    double base = Point2D::distance(vs[0], vs[1]);
    // Altura = distancia(v1, v2)
    double height = Point2D::distance(vs[1], vs[2]);
    return base * height;
}

// Perímetro = 2 * (base + altura)
double Rectangle::perimeter() const {
    double base = Point2D::distance(vs[0], vs[1]);
    double height = Point2D::distance(vs[1], vs[2]);
    return 2 * (base + height);
}

// Traslación
void Rectangle::translate(double incX, double incY) {
    for (int i = 0; i < N_VERTICES; i++) {
        vs[i].x += incX;
        vs[i].y += incY;
    }
}

// Print
void Rectangle::print() {
    std::cout << *this << std::endl;
}

// Operador global <<
std::ostream& operator<<(std::ostream &out, const Rectangle &r) {
    out << "[Rectangle: color = " << r.color 
        << "; v0 = " << r.vs[0]
        << "; v1 = " << r.vs[1]
        << "; v2 = " << r.vs[2]
        << "; v3 = " << r.vs[3] << "]";
    return out;
}
