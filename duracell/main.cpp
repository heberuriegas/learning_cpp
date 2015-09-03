#include "duracell.h"
#include "duracell.cpp"
#include <iostream>
#include <string>

int strlen(const char* array_pointer){
    int n = 0;
    while(true) {
        if(*(array_pointer+n) == '\0'){
            break;
        }
        n++;
    }

    return n;
}

namespace heber {
    template <class T>
    void swap(T& a, T& b){
        T temp = a;
        a = b;
        b = temp;
    }
}

template <class T>
void copy_generator(heber::Duracell<T> duracell) {
    duracell.print();
}

int main() {
    const char hello_world[] = "Hello World";

    std::cout << strlen(hello_world) << "\n";

    std::cout << "\n\n";

    float a = 1.25;
    float b = 33.4;

    std::cout << "a: " << a << "\n";
    std::cout << "b: " << b << "\n";

    std::cout << "swap!" << "\n";
    heber::swap(a, b);

    std::cout << "a: " << a << "\n";
    std::cout << "b: " << b << "\n";

    std::cout << "\n\n";

    int j = 5;
    int * ptr_int;

    ptr_int = new int;
    *ptr_int = j;

    std::cout << *ptr_int << "\n";
    delete ptr_int;

    std::cout << "\n\n";

    int i;
    std::cin >> i;

    try {
        heber::Duracell<int>* my_heap = new heber::Duracell<int>(i);

        my_heap->push(0);
        (*my_heap).push(1);
        my_heap->pop();
        my_heap->push(1);
        my_heap->push(2);
        my_heap->push(3);
        my_heap->push(4);
        my_heap->push(5);
        my_heap->pop();
        my_heap->push(6);
        my_heap->push(7);
        my_heap->push(8);
        my_heap->push(9);

        std::cout << "Print my_heap:\n";
        my_heap->print();

        std::cout << "Print my_heap copy:\n";
        copy_generator(*my_heap);

        heber::Duracell<int> my_heap2;
        my_heap2 = *my_heap;

        std::cout << "Print my_heap2:\n";
        my_heap2.print();

        delete my_heap;
    } catch (std::exception& e) {
        std::cout << e.what() << '\n';
    }

    return 0;
}
