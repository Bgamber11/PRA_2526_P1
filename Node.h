#ifndef NODE_H
#define NODE_H

#include <ostream>

template <typename T> 
class Node {
    public:
        T data;         
        Node<T>* next;   // Puntero al siguiente nodo

        // Constructor
        // 'next' es nullptr por defecto si no se especifica
        Node(T data, Node<T>* next = nullptr) {
            this->data = data;
            this->next = next;
        }

        // Sobrecarga global del operador << para imprimir el nodo
        friend std::ostream& operator<<(std::ostream &out, const Node<T> &node) {
            out << node.data;
            return out;
        }
};

#endif
