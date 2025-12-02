#ifndef APARTMENT_H
#define APARTMENT_H

#include "Location.h"
#include "Student.h"
#include <vector>

class Apartment {
public:
    Apartment(const Location& location);
    ~Apartment();

    void addStudent(Student* student);
    void displayApartmentInfo() const;

private:
    Location location;
    std::vector<Student*> students;
};

#endif // APARTMENT_H
