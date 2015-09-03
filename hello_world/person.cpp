#include "person.h"

Person::Person(int age, std::string name)
{
    this->name = name;
    this->age = age;
}

Person::~Person()
{
    //dtor
}

Person::Person(const Person& other)
{
    //copy ctor
}

Person& Person::operator=(const Person& rhs)
{
    if (this == &rhs) return *this; // handle self assignment
    //assignment operator
    return *this;
}
