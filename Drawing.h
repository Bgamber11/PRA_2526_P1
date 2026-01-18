#ifndef DRAWING_H
#define DRAWING_H

#include <iostream>
#include "Shape.h"
#include "List.h"

class Drawing {
    private:
        // Puntero a la interfaz List, almacenando punteros a Shape
        List<Shape*>* shapes;

    public:
        // Constructor y Destructor
        Drawing();
        ~Drawing();

        // Métodos de gestión
        void add_front(Shape* shape);
        void add_back(Shape* shape);
        void print_all();
        
        // Métodos con lógica específica (dynamic_cast)
        double get_area_all_circles();
        void move_squares(double incX, double incY);
};

#endif
