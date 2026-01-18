#include "Shape.h"
#include <stdexcept> // Para std::invalid_argument

// Constructor por defecto: color "red"
Shape::Shape() {
    color = "red";
}

// Constructor con parámetro: valida el color usando set_color
Shape::Shape(std::string color) {
    set_color(color);
}

// Devuelve el color
std::string Shape::get_color() const {
    return color;
}

// Modifica el color comprobando que sea válido
void Shape::set_color(std::string c) {
    if (c == "red" || c == "green" || c == "blue") {
        color = c;
    } else {
        throw std::invalid_argument("El color debe ser 'red', 'green' o 'blue'");
    }
}
