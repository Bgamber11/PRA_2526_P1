#ifndef LISTLINKED_H
#define LISTLINKED_H

#include <ostream>
#include <stdexcept>
#include "List.h"
#include "Node.h"

template <typename T>
class ListLinked : public List<T> {

    private:
        // Puntero al primer nodo de la secuencia
        Node<T>* first;

        // Número de elementos en la lista
        int n;

    public:
        // Constructor: Inicializa la lista vacía
        ListLinked() {
            first = nullptr;
            n = 0;
        }

        // Destructor: Libera la memoria de todos los nodos
        ~ListLinked() {
            while (first != nullptr) {
                Node<T>* aux = first->next;
                delete first;
                first = aux;
            }
        }

        // --- MÉTODOS MODIFICADORES ---

        void insert(int pos, T e) override {
            if (pos < 0 || pos > n) {
                throw std::out_of_range("Posición inválida en insert");
            }

            if (pos == 0) {
                // Inserción al principio (prepend)
                // El nuevo nodo apunta al antiguo first
                first = new Node<T>(e, first);
            } else {
                // Inserción en medio o final
                // Buscamos el nodo anterior a la posición de inserción (pos-1)
                Node<T>* prev = first;
                for (int i = 0; i < pos - 1; i++) {
                    prev = prev->next;
                }
                // Creamos el nuevo nodo enlazándolo con el siguiente de prev
                // Y actualizamos prev para que apunte al nuevo
                prev->next = new Node<T>(e, prev->next);
            }
            n++;
        }

        void append(T e) override {
            insert(n, e); // Reutilizamos insert (aunque es O(n) al buscar el final)
        }

        void prepend(T e) override {
            insert(0, e); // Reutilizamos insert (O(1))
        }

        T remove(int pos) override {
            if (pos < 0 || pos >= n) {
                throw std::out_of_range("Posición inválida en remove");
            }

            Node<T>* to_delete;
            T removed_data;

            if (pos == 0) {
                // Borrar el primero
                to_delete = first;
                first = first->next; // Avanzamos first
            } else {
                // Borrar en medio o final
                // Buscamos el nodo anterior (pos-1)
                Node<T>* prev = first;
                for (int i = 0; i < pos - 1; i++) {
                    prev = prev->next;
                }
                to_delete = prev->next;
                prev->next = to_delete->next; // Saltamos el nodo a borrar
            }

            removed_data = to_delete->data;
            delete to_delete;
            n--;

            return removed_data;
        }

        // --- MÉTODOS CONSULTORES ---

        T get(int pos) const override {
            if (pos < 0 || pos >= n) {
                throw std::out_of_range("Posición inválida en get");
            }

            Node<T>* aux = first;
            for (int i = 0; i < pos; i++) {
                aux = aux->next;
            }
            return aux->data;
        }

        int search(T e) const override {
            Node<T>* aux = first;
            for (int i = 0; i < n; i++) {
                if (aux->data == e) {
                    return i;
                }
                aux = aux->next;
            }
            return -1;
        }

        bool empty() const override {
            return n == 0;
        }

        int size() const override {
            return n;
        }

        // --- MÉTODOS ESPECÍFICOS DE LISTLINKED ---

        T operator[](int pos) {
            return get(pos); // Reutilizamos get
        }

        friend std::ostream& operator<<(std::ostream &out, const ListLinked<T> &list) {
            out << "List => [";
            if (list.first != nullptr) {
                out << "\n";
                Node<T>* aux = list.first;
                while (aux != nullptr) {
                    out << "  " << aux->data << "\n";
                    aux = aux->next;
                }
            }
            out << "]";
            return out;
        }
};

#endif
