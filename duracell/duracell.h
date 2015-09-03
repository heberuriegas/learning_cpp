#include <iostream>
#include <exception>

#ifndef DURACELL_H
#define DURACELL_H

namespace heber {

    class DuracellException: public std::exception {
        virtual const char* what() const throw();
    } duracell_exception;

    template <class T>
    class Duracell {
        public:
            Duracell();
            Duracell(int);
            Duracell(const Duracell&);
            Duracell& operator= (const Duracell&);
            ~Duracell();
            bool is_full();
            bool is_empty();
            void push(T);
            T pop();
            void print();
        private:
            T * heap;
            int heap_size;
            int position;
    };
}

#endif // DURACELL_H
