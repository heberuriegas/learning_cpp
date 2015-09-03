#include "person.h"
#include "person.cpp"
#include <iostream>

int main() {
    Person person = Person(15, "Heber");

    std::string person_name = person.name;
    std::cout << person_name;
}
