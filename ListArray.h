#ifndef LISTARRAY_H
#define LISTARRAY_H

#include <ostream>
#include <stdexcept>
#include "List.h"

template <typename T>
class ListArray : public List<T> {

    private:
        T* arr;
        int max;
        int n;
        static const int MINSIZE = 2;

        void resize(int new_size) {
            T* new_arr = new T[new_size];
            for (int i = 0; i < n; i++) {
                new_arr[i] = arr[i];
            }
            delete[] arr;
            arr = new_arr;
            max = new_size;
        }

    public:
        ListArray() {
            n = 0;
            max = MINSIZE;
            arr = new T[MINSIZE];
        }

        ~ListArray() {
            delete[] arr;
        }

        // --- MÉTODOS MODIFICADORES (No llevan const) ---

        void insert(int pos, T e) override {
            if (pos < 0 || pos > n) {
                throw std::out_of_range("Posición inválida en insert");
            }
            if (n == max) {
                resize(max * 2);
            }
            for (int i = n; i > pos; i--) {
                arr[i] = arr[i - 1];
            }
            arr[pos] = e;
            n++;
        }

        void append(T e) override {
            insert(n, e);
        }

        void prepend(T e) override {
            insert(0, e);
        }

        T remove(int pos) override {
            if (pos < 0 || pos >= n) {
                throw std::out_of_range("Posición inválida en remove");
            }
            T removed_element = arr[pos];
            for (int i = pos; i < n - 1; i++) {
                arr[i] = arr[i + 1];
            }
            n--;
            return removed_element;
        }

        // --- MÉTODOS CONSULTORES (Llevan const) ---
        // ¡Aquí estaba el error! Deben coincidir con List.h

        T get(int pos) const override {
            if (pos < 0 || pos >= n) {
                throw std::out_of_range("Posición inválida en get");
            }
            return arr[pos];
        }

        int search(T e) const override {
            for (int i = 0; i < n; i++) {
                if (arr[i] == e) {
                    return i;
                }
            }
            return -1;
        }

        bool empty() const override {
            return n == 0;
        }

        int size() const override {
            return n;
        }

        // --- MÉTODOS PROPIOS ---

        T operator[](int pos) {
            if (pos < 0 || pos >= n) {
                throw std::out_of_range("Posición inválida en operator[]");
            }
            return arr[pos];
        }

        friend std::ostream& operator<<(std::ostream &out, const ListArray<T> &list) {
            out << "List => [";
            if (list.n > 0) {
                out << "\n";
                for (int i = 0; i < list.n; i++) {
                    out << "  " << list.arr[i] << "\n";
                }
            }
            out << "]";
            return out;
        }
};

#endif
