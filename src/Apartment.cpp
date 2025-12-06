#include "SakanX/Apartment.h"
#include <iostream>

using namespace std;

Apartment::Apartment(const Location& location) : location(location) {
    // TODO: [Abdo Tolba] needs to implement logic here.
}

Apartment::~Apartment() {
    // TODO: [Abdo Tolba] needs to implement logic here.
}

void Apartment::addStudent(Student* student) {
    if(currentTenants == capacity) throw "Maximum Capacity has reached";
    students.push_back(student);
    cout << "Student has been added successfully, Student number: " << ++currentTenants << endl; 
    if(currentTenants == capacity) cout << "WARNING! MAXIMUM CAPACITY HAS REACHED" << endl;
    else if(capacity - currentTenants == 1) cout << "There is only one more place ready for rent"; 
    else cout << "There is " << capacity - currentTenants << " more places ready for rent!";
}
Student Apartment::removeStudent(Student* student){
    if(currentTenants == 0) throw "Apartment is already empty lol";

    auto it = find_if(students.begin(), students.end(), [&](Student* s) {
        return s && s->getId() == student->getId();
    });

    if (it == students.end()) throw "Student not found in apartment";
    Student* removedStudent = *it;
    students.erase(it);
    --currentTenants;
    cout << "Student removed successfully, available space now: " << capacity - currentTenants << endl;
    return *removedStudent;
}

int Apartment::totalHarmonyScore(){
    
}


void Apartment::displayApartmentInfo() const {
     cout << "Apartment Information:\n";
     cout << "ID: " << id << "\n";
     cout << "Area: " << apartmentArea << " sqm\n";
     cout << "Capacity: " << capacity << "\n";
     cout << "Location: ";
    location.displayLocation(); // Assuming Location has this method

     cout << "Good Botgaz: " << (goodBotgaz ? "Yes" : "No") << "\n";
     cout << "WiFi Connection: " << (hasWifi ? "Available" : "Not Available") << "\n";
     cout << "Had Rats Before: " << (hadRatsBefore ? "Yes" : "No") << "\n";

     cout << "Rooms:\n";
    for (const auto& room : rooms) {
         cout << "  - " << room.first << ": " << room.second << " sqm\n";
    }

     cout << "Students:\n";
    for (const auto& student : students) {
        if (student) {
            student->displayInfo(); // Assuming Student has this method
        }
    }
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

void Apartment::setStudents(const vector<Student*>& students) {
    this->students = students;
}

void Apartment::setRooms(const vector<pair<string, int>>& rooms) {
    this->rooms = rooms;
}

void Apartment::setCapacity(int capacity) {
    this->capacity = capacity;
}

void Apartment::setCurrentTenants(int currentTenants){
    this->currentTenants = currentTenants;
}
