#include "SakanX/Admin.h"
#include <iostream>

Admin::Admin(const std::string& name, int id, const std::string& department)
    : Person(name, id)/*, department(department)*/ {
    // TODO: [Mostafa Ahmed] needs to implement logic here.
    this->department = department;
using namespace std;

Admin::Admin(const string& name, int id, const string& department)
    : Person(name, id), department(department){
}

Admin::~Admin() {
}

void Admin::displayInfo() const {

    cout << "=== Admin Information ===\n";
    cout << "Name: " << name << "\n";
    cout << "ID: " << id << "\n";
    cout << "Department: " << department << "\n";

}
