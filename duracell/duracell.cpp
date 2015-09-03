#include "duracell.h"

namespace heber {

    // Exception
    const char* DuracellException::what() const throw() {
        return "The heap was oversized.";
    }

    // Constructors
    template <class T>
    Duracell<T>::Duracell() {}

    template <class T>
    Duracell<T>::Duracell(int n){
        this->heap_size = n;
        this->heap = new T [n];
        this->position = 0;
    }

    // Copy constructor
    template <class T>
    Duracell<T>::Duracell(const Duracell& x) : heap(new T [x.heap_size]), heap_size(x.heap_size), position(x.position) {
        for(int i = 0; i < x.position; i++) {
            this->heap[i] = x.heap[i];
        }
    }

    // Destructor
    template <class T>
    Duracell<T>::~Duracell(){
        delete[] this->heap;
    }

    // Operator =
    template <class T>
    Duracell<T>& Duracell<T>::operator= (const Duracell<T>& x) {
        this->position = x.position;
        this->heap_size = x.heap_size;
        for(int i = 0; i < x.position; i++) {
            this->heap[i] = x.heap[i];
        }

        return *this;
    }

    template <class T>
    void Duracell<T>::push(T var){
        if(this->is_full())
            throw duracell_exception;
        this->heap[this->position] = var;
        this->position++;
    }

    template <class T>
    T Duracell<T>::pop() {
        if(this->is_empty())
            throw duracell_exception;

        --this->position;
        T pop_element = this->heap[this->position];
        //this->heap[this->position] = 0 # Doesn't work
        return pop_element;
    }

    template <class T>
    void Duracell<T>::print() {
        for(int i = 0; i < this->position ; i++) {
            std::cout << "heap " << i << ": " << this->heap[i] << "\n";
        }
    }

    template <class T>
    bool Duracell<T>::is_full() {
        return this->position == this->heap_size;
    }

    template <class T>
    bool Duracell<T>::is_empty() {
        return this->position == 0;
    }
}
