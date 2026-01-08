#include "Point2D.h"
#include <cmath>

// Constructor
Point2D::Point2D(double x, double y) {
    this->x = x;
    this->y = y;
}

// Distancia Euclídea: d = sqrt((x2-x1)^2 + (y2-y1)^2)
double Point2D::distance(const Point2D &a, const Point2D &b) {
    return std::sqrt(std::pow(a.x - b.x, 2) + std::pow(a.y - b.y, 2));
}

// Operador de igualdad (==)
bool operator==(const Point2D &a, const Point2D &b) {
    return (a.x == b.x && a.y == b.y);
}

// Operador de desigualdad (!=)
bool operator!=(const Point2D &a, const Point2D &b) {
    // Reutilizamos el operador == para no repetir lógica
    return !(a == b);
}

// Operador de impresión (<<)
// Formato esperado según el test: (x,y)
std::ostream& operator<<(std::ostream &out, const Point2D &p) {
    out << "(" << p.x << "," << p.y << ")";
    return out;
}
