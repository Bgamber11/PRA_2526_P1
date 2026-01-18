#include "Drawing.h"
#include "ListArray.h" // O #include "ListLinked.h"
#include "Circle.h"
#include "Square.h"

// Constructor: Inicializa la lista de figuras
Drawing::Drawing() {
    // Aquí decidimos qué implementación usar. 
    // Puedes cambiar ListArray por ListLinked si prefieres.
    shapes = new ListArray<Shape*>();
}

// Destructor: Libera la lista y las figuras que contiene
Drawing::~Drawing() {
    // IMPORTANTE: ListArray/ListLinked borran los nodos/array, 
    // pero NO borran los objetos Shape* almacenados (el contenido T).
    // Como Drawing es dueño de las figuras, debemos borrarlas manualmente.
    
    // Vaciamos la lista y borramos cada figura
    /* Nota: Si tu implementación de List no tiene iteradores, 
       podemos vaciarla sacando elementos hasta que esté vacía.
    */
    while (!shapes->empty()) {
        Shape* s = shapes->remove(0);
        delete s; // Borra el objeto concreto (Circle, Square, etc.)
    }
    
    // Finalmente borramos la estructura de la lista
    delete shapes;
}

// Añadir al frente (posición 0)
void Drawing::add_front(Shape* shape) {
    shapes->prepend(shape);
}

// Añadir al fondo (posición n)
void Drawing::add_back(Shape* shape) {
    shapes->append(shape);
}

// Imprimir todas las figuras
void Drawing::print_all() {
    std::cout << "Drawing contents:" << std::endl;
    for (int i = 0; i < shapes->size(); i++) {
        // Obtenemos la figura i
        Shape* s = shapes->get(i);
        // Polimorfismo: llama al print() específico de la figura
        s->print(); 
    }
}

// Calcular área total de los círculos
double Drawing::get_area_all_circles() {
    double total_area = 0.0;
    
    for (int i = 0; i < shapes->size(); i++) {
        Shape* s = shapes->get(i);
        
        // Intentamos convertir Shape* a Circle*
        Circle* c = dynamic_cast<Circle*>(s);
        
        // Si el cast funciona (c != nullptr), es un círculo
        if (c != nullptr) {
            total_area += c->area();
        }
    }
    
    return total_area;
}

// Mover solo los cuadrados
void Drawing::move_squares(double incX, double incY) {
    for (int i = 0; i < shapes->size(); i++) {
        Shape* s = shapes->get(i);
        
        // Intentamos convertir Shape* a Square*
        Square* sq = dynamic_cast<Square*>(s);
        
        // Si es un cuadrado, lo movemos
        if (sq != nullptr) {
            sq->translate(incX, incY);
        }
    }
}
