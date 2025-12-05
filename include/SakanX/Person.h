#ifndef PERSON_H
#define PERSON_H

#include <iostream>
#include <string>

using namespace std;

class Person {
public:
    Person(const string& name, int id);
    virtual ~Person();

    virtual void displayInfo() const = 0; // Pure virtual function

protected:
    string name;
    int id;
};

#endif // PERSON_H
