
#include "SakanX/Apartment.h"
#include "SakanX/SmartMatchAI.h"
#include <iostream>
#include <algorithm>

using namespace std;

Apartment::Apartment(const Location& location) : location(location) {
    // Validate location (assuming Location has a valid state if constructed)
    if (location.getBuilding().empty() || location.getFloor() < 0 || location.getRoomNumber() < 0) {
        throw std::invalid_argument("Invalid location for Apartment");
    }
}

Apartment::~Apartment() {
    // TODO: [Abdo Tolba] needs to implement logic here.
}

void Apartment::addStudent(Student* student) {
    if (!student) throw std::invalid_argument("Null student pointer");
    if (currentTenants >= capacity) throw std::invalid_argument("Maximum Capacity has been reached");
    students.push_back(student);
    ++currentTenants;
}
Student Apartment::removeStudent(Student* student){
    if (!student) throw std::invalid_argument("Null student pointer");
    if (currentTenants == 0) throw std::invalid_argument("Apartment is already empty");
    auto it = find_if(students.begin(), students.end(), [&](Student* s) {
        return s && s->getId() == student->getId();
    });
    if (it == students.end()) throw std::invalid_argument("Student not found in apartment");
    Student* removedStudent = *it;
    students.erase(it);
    --currentTenants;
    return *removedStudent;
}

int Apartment::totalHarmonyScore(){
    int total = 0;
    // Sum harmony for all unique pairs of students
    for (size_t i = 0; i < students.size(); ++i) {
        for (size_t j = i + 1; j < students.size(); ++j) {
            if (students[i] && students[j]) {
                total += static_cast<int>(SmartMatchAI::calculateHarmony(*students[i], *students[j]));
            }
        }
    }
    return total;
}


void Apartment::displayApartmentInfo() const {
    // No output as per requirements
}


int Apartment::getId() const {
    return id;
}

int Apartment::getApartmentArea() const {
    return apartmentArea;
}

bool Apartment::isGoodBotgaz() const {
    return goodBotgaz;
}

bool Apartment::hasWifiConnection() const {
    return hasWifi;
}

bool Apartment::hadRats() const {
    return hadRatsBefore;
}

Location Apartment::getLocation() const {
    return location;
}

const  vector<Student*>& Apartment::getStudents() const {
    return students;
}

const  vector< pair< string, int>>& Apartment::getRooms() const {
    return rooms;
}

int Apartment::getCapacity() const {
    return capacity;
}

int Apartment::getCurrentTenants() const{
    return currentTenants;
}

int Apartment::getRentPrice() const{
    return rentPrice;
}


void Apartment::setId(int id) {
    if (id < 0) throw std::invalid_argument("Apartment id must be non-negative");
    this->id = id;
}

void Apartment::setApartmentArea(int area) {
    if (area <= 0) throw std::invalid_argument("Apartment area must be positive");
    this->apartmentArea = area;
}

void Apartment::setGoodBotgaz(bool value) {
    this->goodBotgaz = value;
}

void Apartment::setHasWifi(bool value) {
    this->hasWifi = value;
}

void Apartment::setHadRatsBefore(bool value) {
    this->hadRatsBefore = value;
}

void Apartment::setLocation(const Location& loc) {
    if (loc.getBuilding().empty() || loc.getFloor() < 0 || loc.getRoomNumber() < 0) {
        throw std::invalid_argument("Invalid location for Apartment");
    }
    this->location = loc;
}

void Apartment::setStudents(const vector<Student*>& students) {
    for (auto* s : students) {
        if (!s) throw std::invalid_argument("Null student pointer in students list");
    }
    this->students = students;
}

void Apartment::setRooms(const vector<pair<string, int>>& rooms) {
    for (const auto& room : rooms) {
        if (room.first.empty() || room.second <= 0) throw std::invalid_argument("Invalid room data");
    }
    this->rooms = rooms;
}

void Apartment::setCapacity(int capacity) {
    if (capacity <= 0) throw std::invalid_argument("Capacity must be positive");
    this->capacity = capacity;
}

void Apartment::setCurrentTenants(int currentTenants){
    if (currentTenants < 0 || currentTenants > capacity) throw std::invalid_argument("Invalid number of current tenants");
    this->currentTenants = currentTenants;
}

void Apartment::setRentPrice(int rentPrice){
    if (rentPrice < 0) throw std::invalid_argument("Rent price must be non-negative");
    this->rentPrice = rentPrice;
}
