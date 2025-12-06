#include "SakanX/DormSupervisor.h"
#include <iostream>

using namespace std;

DormSupervisor::DormSupervisor(const std::string& name, int id, const std::string& major, const std::string& department)
    : Person(name, id), Student(name, id, major), Admin(name, id, department) {}

DormSupervisor::~DormSupervisor() {}

void DormSupervisor::displayInfo() const {
    cout<<"==== Dorm Supervisor Data ===="<<endl;
    cout<<"Name: "<<name<<endl;
    cout<<"ID: "<<id<<endl;
    cout<<"Major: "<<major<<endl;
    cout<<"Department: "<<department<<endl;
}
