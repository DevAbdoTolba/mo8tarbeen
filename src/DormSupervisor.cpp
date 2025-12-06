#include "SakanX/DormSupervisor.h"
#include <iostream>

using namespace std;

DormSupervisor::DormSupervisor(const std::string& name, int id, const std::string& major, const std::string& department)
        : Person(name, id),
            Student(name, id, 18, NationalityType::Egyptian, "", {}, 'm', major, 0.0),
            Admin(name, id, "", 18, department) {}

DormSupervisor::~DormSupervisor() {}

void DormSupervisor::displayInfo() const {
    cout << "==== Dorm Supervisor Data ====" << endl;
    cout << "Name: " << getName() << endl;
    cout << "ID: " << getId() << endl;
    cout << "Major: " << getMajor() << endl;
    cout << "Department: " << getDepartment() << endl;
}
