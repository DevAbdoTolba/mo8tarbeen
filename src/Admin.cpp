#include "SakanX/Admin.h"
#include <iostream>


using namespace std;


Admin::Admin(const string& name, int id, const string& ssn, int age, const string& department)
    : Person(name, id, ssn, age), department(department), studentsManaged(0) {
    if (name.empty() || id < 0 || age < 18 || department.empty()) {
        throw std::invalid_argument("Invalid Admin constructor arguments");
    }
}

Admin::Admin(const string& name, int id, const string& ssn, int age, 
             NationalityType nationality, const string& department,
             const vector<pair<string, string>>& contacts)
    : Person(name, id, ssn, age, nationality, contacts), department(department), studentsManaged(0) {
    if (name.empty() || id < 0 || age < 18 || department.empty()) {
        throw std::invalid_argument("Invalid Admin constructor arguments");
    }
}
//               Getters
string Admin::getDepartment() const {
    return department;
}

int Admin::getNumOfStudentsManaged() const {
    return studentsManaged;
}   

//               Setters
void Admin::setDepartment(const string& newDepartment) {
    if (newDepartment.empty()) {
        throw std::invalid_argument("Department cannot be empty");
    }
    department = newDepartment;
}



//                  Admin Privileges

void Admin::assignStudentToApartment(Student* student, Apartment* apartment) {
    if (student == nullptr || apartment == nullptr) {
        throw std::invalid_argument("Invalid student or apartment pointer");
    }
    apartment->addStudent(student);
    studentsManaged++;
}

void Admin::removeStudentFromApartment(Student* student, Apartment* apartment) {
    if (student == nullptr || apartment == nullptr) {
        throw std::invalid_argument("Invalid student or apartment pointer");
    }
    apartment->removeStudent(student);
    studentsManaged--;
}

void Admin::transferStudent(Student* student, Apartment* from, Apartment* to) {
    if (student == nullptr || from == nullptr || to == nullptr) {
        throw std::invalid_argument("Invalid student or apartment pointer for transfer");
    }
    removeStudentFromApartment(student, from);
    assignStudentToApartment(student, to);
}

void Admin::viewAllApartments(const vector<Apartment*>& apartments) const {
    if (apartments.empty()) {
        throw std::invalid_argument("Apartment list is empty");
    }
    for (Apartment* apt : apartments) {
        if (!apt) throw std::invalid_argument("Null apartment pointer in list");
    }
    for (int i = 0; i < apartments.size(); i++) {
        apartments[i]->displayApartmentInfo();
    }
}

// Calculate total revenue from all apartments
void Admin::calculateTotalRevenue(const vector<Apartment*>& apartments) const {
    if (apartments.empty()) {
        throw std::invalid_argument("Apartment list is empty");
    }
    double totalRevenue = 0.0;
    int occupiedCount = 0;
    for (int i = 0; i < apartments.size(); i++) {
        if (!apartments[i]) throw std::invalid_argument("Null apartment pointer in list");
        double rent = apartments[i]->getRentPrice();
        int students = apartments[i]->getCurrentTenants();
        if (students > 0) {
            totalRevenue += rent;
            occupiedCount++;
        }
    }
    // No output, just calculation. If needed, return values or store them.
}

void Admin::displayInfo() const 
{
    // No output as per requirements
}
Admin::~Admin() {}