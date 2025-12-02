#ifndef STUDENT_H
#define STUDENT_H

#include "Person.h"
#include <string>

class Student : public virtual Person {
public:
    Student(const std::string& name, int id, const std::string& major);
    ~Student();

    void displayInfo() const override;

private:
    std::string major;
};

#endif // STUDENT_H
