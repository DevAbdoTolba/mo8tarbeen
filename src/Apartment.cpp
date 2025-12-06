#include "SakanX/Apartment.h"
#include <iostream>

Apartment::Apartment(const Location& location) : location(location) {
    // TODO: [Abdo Tolba] needs to implement logic here.
}

Apartment::~Apartment() {
    // TODO: [Abdo Tolba] needs to implement logic here.
}

void Apartment::addStudent(Student* student) {
    // TODO: [Abdo Tolba] needs to implement logic here.
}
Student Apartment::removeStudent(Student* student){
    //
}

int Apartment::totalHarmonyScore(){
    //
}


void Apartment::displayApartmentInfo() const {
    // TODO: [Abdo Tolba] needs to implement logic here.
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

const std::vector<Student*>& Apartment::getStudents() const {
    return students;
}

const std::vector<std::pair<std::string, int>>& Apartment::getRooms() const {
    return rooms;
}

int Apartment::getCapacity() const {
    return capacity;
}

void Apartment::setId(int id) {
    this->id = id;
}

void Apartment::setApartmentArea(int area) {
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
    this->location = loc;
}

void Apartment::setStudents(const std::vector<Student*>& students) {
    this->students = students;
}

void Apartment::setRooms(const std::vector<std::pair<std::string, int>>& rooms) {
    this->rooms = rooms;
}

void Apartment::setCapacity(int capacity) {
    this->capacity = capacity;
}