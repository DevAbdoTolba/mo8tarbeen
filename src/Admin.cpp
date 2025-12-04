#include "SakanX/Admin.h"
#include <iostream>

Admin::Admin(const std::string& name, int id, const std::string& department)
    : Person(name, id)/*, department(department)*/ {
    // TODO: [Mostafa Ahmed] needs to implement logic here.
    this->department = department;
}

Admin::~Admin() {
    // TODO: [Mostafa Ahmed] needs to implement logic here.
}

void Admin::displayInfo() const {
    // TODO: [Mostafa Ahmed] needs to implement logic here.
    std::cout << "=== Admin Information ===\n";
    std::cout << "Name: " << name << "\n";
    std::cout << "ID: " << id << "\n";
    std::cout << "Department: " << department << "\n";
}
