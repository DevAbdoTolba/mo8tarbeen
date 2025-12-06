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
    Student removeStudent(Student* student);
    int totalHarmonyScore(); // summtion the diffrances of tolrance result for each student

    void displayApartmentInfo() const;



private:

    int id;
    enum class MetersTypes{
        newMeter,
        oldMeter
    };

    int apartmentArea;

    bool goodBotgaz;
    bool hasWifi;
    bool hadRatsBefore;

    Location location;
    std::vector<Student*> students;
    std::vector<std::pair<std::string, int>> rooms; // vector of pair of < room type, number of these rooms> 

    int capacity; // how many can be living in this apartment

};


/*

Future work :D



*/

#endif // APARTMENT_H


