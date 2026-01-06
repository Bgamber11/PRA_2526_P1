#ifndef LISTARRAY_H
#define LISTARRAY_H

#include "List.h"
#include <stdexcept>

template <typename T>
class ListArray : public List<T> {
private:
    T* arr;                 // Array dinámico
    int max;                // Capacidad
    int n;                  // Número de elementos
    static const int MINSIZE = 2;

    // Redimensiona el array
    void resize(int new_size) {
        if (new_size < MINSIZE)
            new_size = MINSIZE;

        T* newArr = new T[new_size];
        for (int i = 0; i < n; i++)
            newArr[i] = arr[i];

        delete[] arr;
        arr = newArr;
        max = new_size;
    }

public:
    // Constructor
    ListArray() : max(MINSIZE), n(0) {
        arr = new T[max];
    }

    // Destructor
    ~ListArray() {
        delete[] arr;
    }

//       Metodos de List<T>

    // Inserta en posición pos
    void insert(int pos, T e) override {
        if (pos < 0 || pos > n)
            throw std::out_of_range("Posición fuera de rango");

        // Redimensionar si está lleno
        if (n == max)
            resize(max * 2);

        // Desplazar elementos a la derecha
        for (int i = n; i > pos; i--)
            arr[i] = arr[i - 1];

        arr[pos] = e;
        n++;
    }

    // Inserta al final
    void append(T e) override {
        insert(n, e);
    }

    // Inserta al principio
    void prepend(T e) override {
        insert(0, e);
    }

    // Elimina y devuelve el elemento en pos
    T remove(int pos) override {
        if (pos < 0 || pos >= n)
            throw std::out_of_range("Posición fuera de rango");

        T removed = arr[pos];

        // Desplazar elementos a la izquierda
        for (int i = pos; i < n - 1; i++)
            arr[i] = arr[i + 1];

        n--;

        // Reducir tamaño si sobra mucho espacio
        if (n <= max / 4 && max / 2 >= MINSIZE)
            resize(max / 2);

        return removed;
    }

    // Devuelve el elemento en pos
    T get(int pos) const override {
        if (pos < 0 || pos >= n)
            throw std::out_of_range("Posición fuera de rango");
        return arr[pos];
    }

    // Busca el elemento y devuelve su posición o -1
    int search(T e) const override {
        for (int i = 0; i < n; i++) {
            if (arr[i] == e)
                return i;
        }
        return -1;
    }

    // ¿Lista vacía?
    bool empty() const override {
        return n == 0;
    }

    // Número de elementos
    int size() const override {
        return n;
    }

      // OPERADOR

    T operator[](int pos) const {
        if (pos < 0 || pos >= n)
            throw std::out_of_range("Posición fuera de rango");
        return arr[pos];
    }
};

#endif

