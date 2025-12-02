#ifndef PERSON_H
#define PERSON_H

#include <string>

class Person {
public:
    Person(const std::string& name, int id);
    virtual ~Person();

    virtual void displayInfo() const = 0; // Pure virtual function

protected:
    std::string name;
    int id;
};

#endif // PERSON_H
