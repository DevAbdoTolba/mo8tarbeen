#include "SakanX/Admin.h"
#include <iostream>


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
