#ifndef SQUARE_H
#define SQUARE_H

#include <iostream>
#include "Rectangle.h"
#include "Point2D.h"

class Square : public Rectangle {
    private:
        // Método privado para validar si los vértices forman un cuadrado
        // (Sobrescribe la lógica de validación, aunque no es virtual estático)
        static bool check(Point2D* vertices);

    public:
        // Constructores
        Square();
        Square(std::string color, Point2D* vertices);

        // Destructor
        // No necesita liberar memoria extra porque 'vs' lo gestiona Rectangle
        // pero se define por buena práctica si fuera necesario en el futuro.
        ~Square() {}

        // Métodos que sobrescriben comportamiento de Rectangle
        void set_vertices(Point2D* vertices) override;
        void print() override;

        // Sobrecarga del operador global <<
        friend std::ostream& operator<<(std::ostream &out, const Square &square);
};

#endif
