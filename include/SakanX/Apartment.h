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

    // Getters
    int getId() const;
    int getApartmentArea() const;
    bool isGoodBotgaz() const;
    bool hasWifiConnection() const;
    bool hadRats() const;
    Location getLocation() const;
    const std::vector<Student*>& getStudents() const;
    const std::vector<std::pair<std::string, int>>& getRooms() const;
    int getCapacity() const;
    int getCurrentTenants() const;
    int getRentPrice() const;

    // Setters
    void setId(int id);
    void setApartmentArea(int area);
    void setGoodBotgaz(bool value);
    void setHasWifi(bool value);
    void setHadRatsBefore(bool value);
    void setLocation(const Location& loc);
    void setStudents(const std::vector<Student*>& students);
    void setRooms(const std::vector<std::pair<std::string, int>>& rooms);
    void setCapacity(int capacity);
    void setCurrentTenants(int currentTenants);
    void setRentPrice(int rentPrice);

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
    vector<Student*> students;
    vector<std::pair<std::string, int>> rooms; // vector of pair of < room type, number of these rooms> 

    int capacity; // how many can be living in this apartment
    int currentTenants;

    int rentPrice;

};


/*

Future work :D



*/

#endif // APARTMENT_H


