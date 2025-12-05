#include "SakanX/Student.h"
#include <iostream>

Student::Student(const std::string& name, int id, const std::string& major)
    : Person(name, id), major(major) {}

Student::~Student() {}

void Student::displayInfo() const {
    cout<<"Student Name: " << name <<" - Student ID: " << id <<" - Major: " << major << endl;
}
