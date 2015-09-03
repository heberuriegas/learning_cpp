#ifndef PERSON_H
#define PERSON_H

#include <string>

class Person
{
    public:
        Person(int age, std::string name);
        virtual ~Person();
        Person(const Person& other);
        Person& operator=(const Person& other);
        unsigned int GetCounter() { return m_Counter; }
        void SetCounter(unsigned int val) { m_Counter = val; }

        int age;
        std::string name;
    protected:
    private:
        unsigned int m_Counter;
};

#endif // PERSON_H
