#ifndef LOCATION_H
#define LOCATION_H

#include <string>

class Location {
public:
    Location(const std::string& building, int floor, int roomNumber);
    ~Location();

    void displayLocation() const;

private:
    std::string building;
    int floor;
    int roomNumber;
};

#endif // LOCATION_H
